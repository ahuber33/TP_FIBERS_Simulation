#include "Analyse_TP.hh"


vector<int> GetMaximumBin(TH2F* h, int BinMax_i, int BinMax_j)
{

  float Max_Value=0;
  vector<int> Bin;
  
  //cout << "i = " << BinMax_i << endl;
  //cout << "j = " << BinMax_j << endl;
  
  for (int i=1; i<BinMax_i; i++)
    {
      for (int j=1; j<BinMax_j; j++)
	{
	  // cout << "i = " << i << endl;
	  // cout << "j = " << j << endl;
	  //cout << "Value = " << h->GetBinContent(i, j) << endl;
	  if (h->GetBinContent(i, j) >Max_Value)
	    {
	     Max_Value=h->GetBinContent(i, j);
	     Bin.clear();
	     Bin.push_back(i);
	     Bin.push_back(j);
	     //cout << "i = " << i << endl;
	     //cout << "j = " << j << endl;
	     //cout << "Value = " << h->GetBinContent(i, j) << endl;
	    }
	}
    }


  return Bin;
}



TH2F *Histo_2D(TTree* Tree, const char* name)
{
  Tree->ResetBranchAddresses();
  std::vector<float>* x=0;
  std::vector<float>* y=0;
  Tree->SetBranchAddress("PositionX", &x);
  Tree->SetBranchAddress("PositionY", &y);
  const int Entries = Tree->GetEntries();
  TH2F* h = new TH2F(name, name, 6500, -60, 5, 6100, -1, 60);  

  for(int i=0; i<Entries; i++)
  {
    x->clear();
    y->clear();
    Tree->GetEntry(i);
    for(int j=0; j<(x->size()); j++)
      {
	h->Fill(x->at(j),y->at(j));
      }
  }

  return h;  
}

	      


vector<float> Nph_part_surface(TTree* Tree1, float nsigma)
{
  vector<float> Nph;
  TH2F* h;
  h = Histo_2D(Tree1, "test");
  TH2F *hh = (TH2F*)h->Clone();
  hh->RebinX(10);
  hh->RebinY(10);

  vector<int> Bin_Max = GetMaximumBin(hh, hh->GetNbinsX(), hh->GetNbinsY());
  //cout << "Max Value = " << h->GetBinContent(Bin_Max.at(0), Bin_Max.at(1)) << endl;

  float Position_X = -60+0.1*Bin_Max.at(0);
  float Position_Y = -1+0.1*Bin_Max.at(1);

  float Bin_X = (Position_X+60)*100;
  float Bin_Y = (Position_Y+1)*100;

  TH1D *ProjY = new TH1D("ProjY", "ProjY", 6100, -1, 60);
  TH1D *ProjX = new TH1D("ProjX", "ProjX", 6500, -60, 5);

  h->ProjectionY("ProjY", Bin_X, Bin_X, "");
  h->ProjectionX("ProjX", Bin_Y, Bin_Y, "");
  
  TF1*test_fit1 = new TF1("fit1", "gaus", Position_Y-5, Position_Y+5);
  TF1*test_fit2 = new TF1("fit2", "gaus(0)+gaus(3)", Position_Y-5, Position_Y+5);
  ProjY->Fit(test_fit1, "QR");
  test_fit2->SetParameter(0, test_fit1->GetParameter(0));
  test_fit2->SetParameter(1, test_fit1->GetParameter(1));
  test_fit2->SetParameter(2, test_fit1->GetParameter(2));
  test_fit2->SetParameter(3, test_fit1->GetParameter(0)/10);
  test_fit2->SetParameter(4, test_fit1->GetParameter(1));
  test_fit2->SetParameter(5, 6*test_fit1->GetParameter(2));
  test_fit2->SetParLimits(2, 0.05, 0.4);
  test_fit2->SetParLimits(5, 1, 10);
  ProjY->Fit(test_fit2, "QR");

  
  TF1*test_fit3 = new TF1("fit3", "gaus", Position_X-5, Position_X+5);
  TF1*test_fit4 = new TF1("fit4", "gaus(0)+gaus(3)", Position_X-5, Position_X+5);
  ProjX->Fit(test_fit3, "QR");
  test_fit4->SetParameter(0, test_fit3->GetParameter(0));
  test_fit4->SetParameter(1, test_fit3->GetParameter(1));
  test_fit4->SetParameter(2, test_fit3->GetParameter(2));
  test_fit4->SetParameter(3, test_fit2->GetParameter(3));
  test_fit4->SetParameter(4, test_fit2->GetParameter(4));
  test_fit4->SetParameter(5, test_fit2->GetParameter(5));
  //test_fit4->SetParLimits(1, test_fit3->GetParameter(1)-1, test_fit3->GetParameter(1)+1);
  test_fit4->SetParLimits(2, 0.05, 0.4);
  test_fit4->SetParLimits(3, test_fit2->GetParameter(3)/2, test_fit2->GetParameter(3)*2);
  //test_fit4->SetParLimits(4, test_fit3->GetParameter(1)-1, test_fit3->GetParameter(1)+1);
  test_fit4->SetParLimits(5, 1, 10);
  ProjX->Fit(test_fit4, "QR");

  
  TF2* f2 = new TF2("f2", "[0]*TMath::Gaus(x, [1], [2])*TMath::Gaus(y, [3], [4])", -60, 0, 0,60);
  f2->SetNpy(1000);
  f2->SetNpx(1000);
  f2->SetParameter(0, test_fit4->GetParameter(0));
  f2->SetParameter(1, test_fit4->GetParameter(1));
  f2->FixParameter(2, test_fit4->GetParameter(2));
  f2->SetParameter(3, test_fit2->GetParameter(1));
  f2->FixParameter(4, test_fit2->GetParameter(2));
  

  float MeanX = test_fit4->GetParameter(1);
  //cout << "Mean X = " << MeanX << endl;
  float SigmaX = test_fit4->GetParameter(2);
  //cout << "Sigma X = " << SigmaX << endl;
  float ErrorSigmaX = test_fit4->GetParError(2);
  //cout << "Error Sigma X = " << ErrorSigmaX << endl;
  float MeanY = test_fit2->GetParameter(1);
  //cout << "Mean Y = " << MeanY << endl;
  float SigmaY = test_fit2->GetParameter(2);
  //cout << "Sigma Y = " << SigmaY << endl;
  float ErrorSigmaY = test_fit2->GetParError(2);
  //cout << "Error Sigma Y = " << ErrorSigmaY << endl;
  
  TH1F *h2 = (TH1F*)h->Clone("h2");
  h2->Reset();
  float Rmax = sqrt((nsigma*SigmaX)*(nsigma*SigmaX) + (nsigma*SigmaY)*(nsigma*SigmaY));
	      
  for(int i =Bin_X-200; i< Bin_X+200; i++)
    {
      for(int j= Bin_Y-200; j< Bin_Y+200; j++)
	{
	  if(((h->GetXaxis()->GetBinCenter(i)-MeanX)/(nsigma*SigmaX))*((h->GetXaxis()->GetBinCenter(i)-MeanX)/(nsigma*SigmaX)) + ((h->GetYaxis()->GetBinCenter(j)-MeanY)/(nsigma*SigmaY))*((h->GetYaxis()->GetBinCenter(j)-MeanY)/(nsigma*SigmaY)) >1)
	    {
	      continue;
	    }
	  
	  h2->SetBinContent(i, j, h->GetBinContent(i, j));
	}
    }




  float Nsim = Tree1->GetEntries();
  float DeltaN = sqrt(h2->Integral());
  float Pixel = 0.013*0.013;
  float Surface = (TMath::Pi()*nsigma*SigmaX*nsigma*SigmaY)/Pixel;
  float DeltaSurface = (TMath::Pi()*(nsigma*SigmaX*ErrorSigmaY + nsigma*SigmaY*ErrorSigmaX))/Pixel;


  //Pour plot la surface !!!!!!
  //Nph.push_back(Surface);
  //Nph.push_back(DeltaSurface);


  
  Nph.push_back((h2->Integral()/Nsim)/Surface);
  Nph.push_back(DeltaN/(Nsim*Surface) + (h2->Integral()*DeltaSurface)/(Nsim*Surface*Surface));
  //cout << "Nphotons = " << Nph.at(0) << " ph/part/mm^{2}" << endl;

  h2->Reset();


    for(int i =Bin_X-200; i< Bin_X+200; i++)
    {
      for(int j= Bin_Y-200; j< Bin_Y+200; j++)
	{
	  if(((h->GetXaxis()->GetBinCenter(i)-MeanX)/(nsigma*(SigmaX+ErrorSigmaX)))*((h->GetXaxis()->GetBinCenter(i)-MeanX)/(nsigma*(SigmaX+ErrorSigmaX))) + ((h->GetYaxis()->GetBinCenter(j)-MeanY)/(nsigma*(SigmaY+ErrorSigmaY)))*((h->GetYaxis()->GetBinCenter(j)-MeanY)/(nsigma*(SigmaY+ErrorSigmaY))) >1)
	    {
	      continue;
	    }
	  
	  h2->SetBinContent(i, j, h->GetBinContent(i, j));
	}
    }




  Nsim = Tree1->GetEntries();
  DeltaN = sqrt(h2->Integral());
  Surface = (TMath::Pi()*nsigma*(SigmaX+ErrorSigmaX)*nsigma*(SigmaY+ErrorSigmaY))/Pixel;
  DeltaSurface = (TMath::Pi()*(nsigma*SigmaX*ErrorSigmaY + nsigma*SigmaY*ErrorSigmaX))/Pixel;

  
  Nph.push_back((h2->Integral()/Nsim)/Surface);


    h2->Reset();


    for(int i =Bin_X-200; i< Bin_X+200; i++)
    {
      for(int j= Bin_Y-200; j< Bin_Y+200; j++)
	{
	  if(((h->GetXaxis()->GetBinCenter(i)-MeanX)/(nsigma*(SigmaX-ErrorSigmaX)))*((h->GetXaxis()->GetBinCenter(i)-MeanX)/(nsigma*(SigmaX-ErrorSigmaX))) + ((h->GetYaxis()->GetBinCenter(j)-MeanY)/(nsigma*(SigmaY-ErrorSigmaY)))*((h->GetYaxis()->GetBinCenter(j)-MeanY)/(nsigma*(SigmaY-ErrorSigmaY))) >1)
	    {
	      continue;
	    }
	  
	  h2->SetBinContent(i, j, h->GetBinContent(i, j));
	}
    }




  Nsim = Tree1->GetEntries();
  DeltaN = sqrt(h2->Integral());
  Surface = (TMath::Pi()*nsigma*(SigmaX-ErrorSigmaX)*nsigma*(SigmaY-ErrorSigmaY))/Pixel;
  DeltaSurface = (TMath::Pi()*(nsigma*SigmaX*ErrorSigmaY + nsigma*SigmaY*ErrorSigmaX))/Pixel;

  
  Nph.push_back((h2->Integral()/Nsim)/Surface);

  

  return Nph;



}



void Nph_vs_E(const char* cfile, TMultiGraph* mg, Color_t kColor, float nsigma)
{
  float x[10];
  float y[10];
  float ex[10];
  float ey[10];
  int n=0;
  vector<float> Nph;
  float err1=0;
  float err2=0;
  
  for(int i =1; i<=10; i+=1)
    {
      string sfile = Form(cfile, i);
      cout << sfile.c_str() << endl;
      TFile* file = new TFile(sfile.c_str());
      TTree *Tree = (TTree*)file->Get("Optical");
      Nph = Nph_part_surface(Tree, nsigma);
      err1 = abs(Nph.at(0)-Nph.at(2));
      err2 = abs(Nph.at(0)-Nph.at(3));
      
      //cout << "Nph 0 = " << Nph.at(0) << endl;
      //cout << "Nph 1 = " << Nph.at(1) << endl;
      //cout << "Nph 2 = " << Nph.at(2) << endl;

      x[n] = i;
      ex[n] = 0;
      y[n] = Nph.at(0);
      //if(err1>err2) {ey[n] =err2 + Nph.at(1);}
      //if(err1<err2) {ey[n] =err1 + Nph.at(1);}
      ey[n] = Nph.at(1);
      Nph.clear();

      delete file;
      n++;
      //delete Tree;

    }


  TGraphErrors* g = new TGraphErrors(10, x, y, ex, ey);

  //return g;
  g->SetLineColor(kColor);
  mg->Add(g);

}


