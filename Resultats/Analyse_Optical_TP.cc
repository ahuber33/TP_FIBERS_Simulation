#include "Analyse_Optical_TP.hh"

void Analyse_Optical_TP()
{
  TMultiGraph *mg = new TMultiGraph();
  // Nph_vs_E("He1+_Config1_ZnS_0.5_Sc_0.25_%dMeV.root", mg, kBlack, 1.);
  // Nph_vs_E("He1+_Config2_ZnS_0.5_Sc_0.25_%dMeV.root", mg, kBlue, 1.);
  // Nph_vs_E("He1+_Config3_ZnS_0.5_Sc_0.25_%dMeV.root", mg, kRed, 1.);
  // Nph_vs_E("He1+_Config4_ZnS_0.5_Sc_0.25_%dMeV.root", mg, kCyan, 1.);
  // TFile rootfile("He1+_ZnS_0.5_Sc_0.25_PIXEL_13um.root","recreate");
  // mg->Write("mg");

  // Nph_vs_E("proton_Config_TP_ENL_ZnS_0.1_%dMeV.root", mg, kRed, 1.);
  // Nph_vs_E("He1+_Config_TP_ENL_ZnS_0.1_%dMeV.root", mg, kBlue, 1.);
  // Nph_vs_E("He2+_Config_TP_ENL_ZnS_0.1_%dMeV.root", mg, kCyan, 1.);
  // Nph_vs_E("He2+_Config2_ZnS_0.1_%MeV.root", mg, kGreen, 1.);
  // TFile rootfile("Config_TP_ENL_ZnS_0.1_1MeV_10MeV.root","recreate");
  // mg->Write("mg");


  
  //Config 4 avec Sc
  //Nph_vs_E("proton_Config4_Sc_0.1_%dMeV.root", mg, kRed, 1.);
  //Nph_vs_E("proton_Config4_Sc_0.25_%dMeV.root", mg, kCyan, 1.);
  //Nph_vs_E("proton_Config4_Sc_0.5_%dMeV.root", mg, kGreen, 1.);
  //Nph_vs_E("proton_Config4_Sc_1_%dMeV.root", mg, kBlue, 1.);

  //Config 4 avec ZnS
  //Nph_vs_E("proton_Config4_ZnS_0.1_%dMeV.root", mg, kRed, 1.);
  //Nph_vs_E("proton_Config4_ZnS_0.25_%dMeV.root", mg, kCyan, 1.);
  //Nph_vs_E("proton_Config4_ZnS_0.5_%dMeV.root", mg, kGreen, 1.);
  //Nph_vs_E("proton_Config4_ZnS_1_%dMeV.root", mg, kBlue, 1.);

  //Config 4 avec NoWaSH
  //Nph_vs_E("proton_Config4_NoWaSH_0.1_%dMeV.root", mg, kRed, 1.);
  //Nph_vs_E("proton_Config4_NoWaSH_0.25_%dMeV.root", mg, kCyan, 1.);
  //Nph_vs_E("proton_Config4_NoWaSH_0.5_%dMeV.root", mg, kGreen, 1.);
  //Nph_vs_E("proton_Config4_NoWaSH_1_%dMeV.root", mg, kBlue, 1.);

  //Config 3 avec Sc
  //Nph_vs_E("proton_Config3_Sc_0.1_%dMeV.root", mg, kRed, 1.);
  //Nph_vs_E("proton_Config3_Sc_0.25_%dMeV.root", mg, kCyan, 1.);
  //Nph_vs_E("proton_Config3_Sc_0.5_%dMeV.root", mg, kRed, 1.);
  //Nph_vs_E("proton_Config3_Sc_1_%dMeV.root", mg, kBlue, 1.);

  //Config 3 avec ZnS
  //Nph_vs_E("proton_Config3_ZnS_0.1_%dMeV.root", mg, kRed, 1.);
  //Nph_vs_E("proton_Config3_ZnS_0.25_%dMeV.root", mg, kCyan, 1.);
  //Nph_vs_E("proton_Config3_ZnS_0.5_%dMeV.root", mg, kGreen, 1.);
  //Nph_vs_E("proton_Config3_ZnS_1_%dMeV.root", mg, kBlue, 1.);

  //Config 3 avec NoWaSH
  //Nph_vs_E("proton_Config3_NoWaSH_0.1_%dMeV.root", mg, kRed, 1.);
  //Nph_vs_E("proton_Config3_NoWaSH_0.25_%dMeV.root", mg, kCyan, 1.);
  //Nph_vs_E("proton_Config3_NoWaSH_0.5_%dMeV.root", mg, kGreen, 1.);
  //Nph_vs_E("proton_Config3_NoWaSH_1_%dMeV.root", mg, kBlue, 1.);

  mg->Draw("AC");

  //DEBUG
  
  
  TFile* file = new TFile("He2+_Config2_ZnS_0.1_10MeV.root");
  TTree *Tree1 = (TTree*)file->Get("Optical");
  TH2F* h;
  h = Histo_2D(Tree1, "test");
  TH2F *hh = (TH2F*)h->Clone();
  TH2F *h_bis = (TH2F*)h->Clone();
  h_bis->RebinX(10);
  h_bis->RebinY(10);

  

  vector<int> Bin_Max = GetMaximumBin(h_bis, h_bis->GetNbinsX(), h_bis->GetNbinsY());
  cout << "Max Value = " << h_bis->GetBinContent(Bin_Max.at(0), Bin_Max.at(1)) << endl;

  float Position_X = -60+0.1*Bin_Max.at(0);
  float Position_Y = -1+0.1*Bin_Max.at(1);
  cout << "Position X = " << Position_X << endl;
  cout << "Position Y = " << Position_Y << endl;

  float Bin_X = (Position_X+60)*100;
  float Bin_Y = (Position_Y+1)*100;

  TH1D *ProjY = new TH1D("ProjY", "ProjY", 6100, -1, 60);
  TH1D *ProjX = new TH1D("ProjX", "ProjX", 6500, -60, 5);

  h->ProjectionY("ProjY", Bin_X, Bin_X, "");
  h->ProjectionX("ProjX", Bin_Y, Bin_Y, "");

  TCanvas* c1 = new TCanvas;
  c1->cd();
  ProjY->Draw();

  
  TF1*test_fit1 = new TF1("fit1", "gaus", Position_Y-5, Position_Y+5);
  TF1*test_fit2 = new TF1("fit2", "gaus(0)+gaus(3)", Position_Y-5, Position_Y+5);
  test_fit2->SetLineColor(kCyan);
  c1->cd();
  ProjY->Draw();
  ProjY->Fit(test_fit1, "Q");
  test_fit2->SetParameter(0, test_fit1->GetParameter(0));
  test_fit2->SetParameter(1, test_fit1->GetParameter(1));
  test_fit2->SetParameter(2, test_fit1->GetParameter(2));
  test_fit2->SetParameter(3, test_fit1->GetParameter(0)/10);
  test_fit2->SetParameter(4, test_fit1->GetParameter(1));
  test_fit2->SetParameter(5, 6*test_fit1->GetParameter(2));
  test_fit2->SetParLimits(2, 0.01, 0.4);
  test_fit2->SetParLimits(5, 1, 10);
  ProjY->Fit(test_fit2, "R+");



  TCanvas* c2 = new TCanvas;
  c2->cd();
  ProjX->Draw();
  
  
  TF1*test_fit3 = new TF1("fit3", "gaus", Position_X-5, Position_X+5);
  TF1*test_fit4 = new TF1("fit4", "gaus(0)+gaus(3)", Position_X-5, Position_X+5);
  c2->cd();
  ProjX->Draw();
  ProjX->Fit(test_fit3, "Q");
  test_fit4->SetParameter(0, test_fit3->GetParameter(0));
  test_fit4->SetParameter(1, test_fit3->GetParameter(1));
  test_fit4->SetParameter(2, test_fit3->GetParameter(2));
  test_fit4->SetParameter(3, test_fit2->GetParameter(3));
  test_fit4->SetParameter(4, test_fit2->GetParameter(4));
  test_fit4->SetParameter(5, test_fit2->GetParameter(5));
  test_fit4->SetParLimits(1, test_fit3->GetParameter(1)-1, test_fit3->GetParameter(1)+1);
  test_fit4->SetParLimits(2, 0.01, 0.4);
  test_fit4->SetParLimits(3, test_fit2->GetParameter(3)/2, test_fit2->GetParameter(3)*2);
  //test_fit4->SetParLimits(4, test_fit3->GetParameter(1)-1, test_fit3->GetParameter(1)+1);
  test_fit4->SetParLimits(5, 1, 10);
  ProjX->Fit(test_fit4, "R+");


  new TCanvas;
  hh->Draw("colz");
  TF2* f2 = new TF2("f2", "[0]*TMath::Gaus(x, [1], [2])*TMath::Gaus(y, [3], [4])", -60, 0, 0,60);
  f2->SetNpy(1000);
  f2->SetNpx(1000);
  f2->SetParameter(0, test_fit4->GetParameter(0));
  f2->SetParameter(1, test_fit4->GetParameter(1));
  f2->FixParameter(2, test_fit4->GetParameter(2));
  f2->SetParameter(3, test_fit2->GetParameter(1));
  f2->FixParameter(4, test_fit2->GetParameter(2));
  hh->Fit(f2, "R+");



  

  float MeanX = test_fit4->GetParameter(1);
  cout << "Mean X = " << MeanX << endl;
  float SigmaX = test_fit4->GetParameter(2);
  cout << "Sigma X = " << SigmaX << endl;
  float ErrorSigmaX = test_fit4->GetParError(2);
  cout << "Error Sigma X = " << ErrorSigmaX << endl;
  float MeanY = test_fit2->GetParameter(1);
  cout << "Mean Y = " << MeanY << endl;
  float SigmaY = test_fit2->GetParameter(2);
  cout << "Sigma Y = " << SigmaY << endl;
  float ErrorSigmaY = test_fit2->GetParError(2);
  cout << "Error Sigma Y = " << ErrorSigmaY << endl;
  float nsigma =1.;
  
  TH1F *h2 = (TH1F*)h->Clone("h2");
  h2->Reset();
  float R;
  float Rmax = sqrt((nsigma*SigmaX)*(nsigma*SigmaX) + (nsigma*SigmaY)*(nsigma*SigmaY));
  cout << "Rmax = " << Rmax << endl;

  float condition =0;
	      
  for(int i =0; i< 6500; i++)
    {
      for(int j=0; j< 6100; j++)
	{
	  if(((h->GetXaxis()->GetBinCenter(i)-MeanX)/(nsigma*(SigmaX-ErrorSigmaX)))*((h->GetXaxis()->GetBinCenter(i)-MeanX)/(nsigma*(SigmaX-ErrorSigmaX))) + ((h->GetYaxis()->GetBinCenter(j)-MeanY)/(nsigma*(SigmaY-ErrorSigmaY)))*((h->GetYaxis()->GetBinCenter(j)-MeanY)/(nsigma*(SigmaY-ErrorSigmaY))) >1)
	    {
	      continue;
	    }
	  
	  h2->SetBinContent(i, j, h->GetBinContent(i, j));
	}
    }


  new TCanvas;
  h2->Draw("colz");

  float Aire_ellipse_sigma = TMath::Pi()*nsigma*SigmaX*nsigma*SigmaY;
  cout << "Aire ellipse = " << Aire_ellipse_sigma << endl;
  cout << "Aire pixel = " << 13e-3*13e-3 << endl;
  cout << "Rapport Aire = " << Aire_ellipse_sigma/(13e-3*13e-3) << endl;
  cout << "Integral = " << h2->Integral() << endl;
  cout << "Nph/part = " << h2->Integral()/Tree1->GetEntries() << endl;
  float Nph = (h2->Integral()/Tree1->GetEntries())/(Aire_ellipse_sigma/(13e-3*13e-3));
  cout << "Nphotons = " << Nph << " ph/part/pixel" << endl;
    
  








  

  // TF2* f2 = new TF2("f2", "[0]*TMath::Gaus(x, [1], [2])*TMath::Gaus(y, [3], [4])", -40, 0, 0,60);
  // f2->SetNpy(1000);
  // f2->SetNpx(1000);
  // // f2->SetParameter(0, zp);
  // // f2->SetParameter(1, xp);
  // // f2->SetParLimits(1, xp-0.4, xp+0.4);
  // // f2->SetParameter(2, 0.5);
  // // f2->SetParLimits(2, 0, 1.3);
  // // f2->SetParameter(3, yp);
  // // f2->SetParameter(4, 1);

  // new TCanvas;
  // h->Draw("colz");
  // //h->Fit(f2, "");
  // h->GetXaxis()->SetRangeUser(f2->GetParameter(1)-10*f2->GetParameter(2), f2->GetParameter(1)+10*f2->GetParameter(2));
  // h->GetYaxis()->SetRangeUser(f2->GetParameter(3)-10*f2->GetParameter(4), f2->GetParameter(3)+10*f2->GetParameter(4));

  // float MeanX = f2->GetParameter(1);
  // float SigmaX = f2->GetParameter(2);
  // float MeanY = f2->GetParameter(3);
  // float SigmaY = f2->GetParameter(4);
  
  // TH1F *h2 = (TH1F*)h->Clone("h2");
  // h2->Reset();
  // float R;
  // float nsigma =1.;
  // float Rmax = sqrt((nsigma*SigmaX)*(nsigma*SigmaX) + (nsigma*SigmaY)*(nsigma*SigmaY));
	      


  // for(int i =0; i< h->GetNbinsX(); i++)
  //   {
  //     for(int j=0; j< h->GetNbinsY(); j++)
  // 	{
  // 	  //R = sqrt((h->GetXaxis()->GetBinCenter(i) - MeanX)*(h->GetXaxis()->GetBinCenter(i) - MeanX) +  (h->GetYaxis()->GetBinCenter(j) - MeanY)*(h->GetYaxis()->GetBinCenter(j) - MeanY));
  // 	  if(((h->GetXaxis()->GetBinCenter(i)-MeanX)/(nsigma*SigmaX))*((h->GetXaxis()->GetBinCenter(i)-MeanX)/(nsigma*SigmaX)) + ((h->GetYaxis()->GetBinCenter(j)-MeanY)/(nsigma*SigmaY))*((h->GetYaxis()->GetBinCenter(j)-MeanY)/(nsigma*SigmaY)) >1)
  // 	    {
  // 	      continue;
  // 	    }
	  
  // 	  h2->SetBinContent(i, j, h->GetBinContent(i, j));
  // 	}
  //   }

  // float Aire_pixel = 0.01*0.01;
  // cout << "Integral histo = " << h2->Integral()/Tree1->GetEntries() << endl;
  // float Aire_ellipse_sigma = TMath::Pi()*nsigma*SigmaX*nsigma*SigmaY;
  // cout << "Aire ellipse = " << Aire_ellipse_sigma << endl;
  // cout << "Nphotons = " << (h2->Integral()/Tree1->GetEntries())/Aire_ellipse_sigma << " ph/part/mm^{2}" << endl;
  // cout << "Nphotons/pixel [10µm] = " << ((h2->Integral()/Tree1->GetEntries())/Aire_ellipse_sigma)*Aire_pixel << "ph/part/pixel" << endl;


  // cout << Tree1->GetEntries() << endl;
  
  // new TCanvas;
  // h2->Draw("colz");
  //f2->Draw("same");
    

}
