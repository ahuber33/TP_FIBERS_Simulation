#include "TROOT.h"
#include <TStyle.h>
#include "TGraph.h"
#include "TFile.h"
#include "TTree.h"
#include "TH2F.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TPad.h"
#include "TLine.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TCanvas.h"
#include <string.h>
#include <vector>

float Param_Parabole(float masse, float charge, float Le1, float Le2, float E, float Lb1, float Lb2, float B)
{
  float Num = masse*E*((Le1*Le1)/2 + Le1*Le2);
  float Denum = charge*B*B*(((Lb1*Lb1)/2+Lb1*Lb2)*((Lb1*Lb1)/2+Lb1*Lb2));
  
  float param = Num/(1000*Denum);

  return param;

}


TGraph *Graph_Parabole(const char* filename, const char* TreeName)
{
  TFile* file = new TFile(filename);
  float x,y;
  TTree *Tree = (TTree*)file->Get(TreeName);
  Tree->SetBranchAddress("PositionX", &x);
  Tree->SetBranchAddress("PositionY", &y);
  const int Entries = Tree->GetEntries();

  float PosX[Entries];
  float PosY[Entries];

  for(int i=0; i<Entries; i++)
  {
    Tree->GetEntry(i);
    PosX[i] = x;
    PosY[i] = y;
  }

  TGraph* graph = new TGraph(Entries, PosX, PosY);

  return graph;
  
}



TH2F *Histo_Parabole(TTree* Tree, const char* name)
{
  Tree->ResetBranchAddresses();
  float x,y;
  Tree->SetBranchAddress("PositionX", &x);
  Tree->SetBranchAddress("PositionY", &y);
  const int Entries = Tree->GetEntries();
  TH2F* h = new TH2F(name, name, 450, -40, 5, 610, -1, 60);  //Etude
  //TH2F* h = new TH2F(name, name, 1024, -13.312, 0, 1024, 0, 13.312);  //ORCA II
  //TH2F* h = new TH2F(name, name, 2304, -10.598, 0, 4096, 0, 18.841);  //ORCA Quest

  for(int i=0; i<Entries; i++)
  {
    Tree->GetEntry(i);
    h->Fill(x,y);
  }

  return h;  
}


TH2F *Histo_Parabole_Optique(TTree* Tree, const char* name)
{
  Tree->ResetBranchAddresses();
  std::vector<float>* x=0;
  std::vector<float>* y=0;
  Tree->SetBranchAddress("PositionX", &x);
  Tree->SetBranchAddress("PositionY", &y);
  const int Entries = Tree->GetEntries();
  TH2F* h = new TH2F(name, name, 450, -40, 5, 610, -1, 60); //Etude
  //TH2F* h = new TH2F(name, name, 1024, -13.312, 0, 1024, 0, 13.312);  //ORCA II

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

TGraphErrors* Fit_LargeurY_Parabole(TH2F* h, int parametre)
{
  TH1D* projj = new TH1D("projj", "projj", 610, -1, 60);
  float Bin_Max;
  float Min;
  float Max;
  float x[610];
  float y[610];
  float ex[610];
  float ey[610];
  int n=0;

  for (int i=0; i<450; i++)
    {
      h->ProjectionY("projj", i, i, "");
      x[n] = -40 + i*0.1 -0.05;
      ex[n] =0.05;
      //cout << "Bin Center = " << x[i] << endl;
      Bin_Max = projj->GetMaximumBin();
      Min = (-1+0.1*Bin_Max)-2;
      Max = (-1+0.1*Bin_Max)+2;

      TF1 *gaus = new TF1("gaus", "gaus", Min, Max);
      projj->Fit("gaus", "QNR");
      if(gaus->GetParError(2)>0.1 || gaus->GetParameter(parametre)==0){continue;}
      y[n] = gaus->GetParameter(parametre);
      ey[n] = gaus->GetParError(parametre);
      n++;
      delete gaus;
      projj->Reset();
    }

  TGraphErrors* g = new TGraphErrors(n, x, y, ex, ey);

  delete projj;

  return g;

}

float flag_resolution(TGraphErrors* g)
{

  int n = g->GetN();
  cout << "n = " << n << endl;
  float x=0;

  for (int i=0; i<n; i++)
    {
      //cout << "x[" << i << "] = " << g->GetPointY(i) << endl;
      if(g->GetPointY(i) <1 && (g->GetPointY(i)+g->GetErrorY(i))<1)
	{
	  x=g->GetPointX(i-1);
	  //cout << " x = " << x << endl;
	  break;
	}
    }


  return x;
}


TGraphErrors* Fit_LargeurY_Parabole_NORM(TH2F* h, int parametre)
{
  TH1D* proj = new TH1D("proj", "proj", 610, -1, 60);
  float Bin_Max;
  float Min;
  float Max;
  float x[610];
  float y[610];
  float ex[610];
  float ey[610];
  int n=0;

  for (int i=250; i<400; i++)
    {
      h->ProjectionY("proj", i, i, "");
      x[n] = -40 + i*0.1 -0.05;
      ex[n] =0.05;
      //cout << "Bin Center = " << x[i] << endl;
      Bin_Max = proj->GetMaximumBin();
      Min = (-1+0.1*Bin_Max)-0.4;
      Max = (-1+0.1*Bin_Max)+0.4;

      TF1 *gaus = new TF1("gaus", "gaus", Min, Max);
      proj->Fit("gaus", "QNR");
      //if(gaus->GetParError(2)>0.1 || gaus->GetParameter(2)==0){continue;}
      y[n] = gaus->GetParameter(parametre);
      ey[n] = gaus->GetParError(parametre);
      n++;
      delete gaus;
      proj->Reset();
    }

  TGraphErrors* g = new TGraphErrors(n, x, y, ex, ey);
  

  delete proj;
  return g;

}



TGraphErrors* Resolution(TGraphErrors* gMean1, TGraphErrors* gMean2, TGraphErrors* gSigma1, TGraphErrors* gSigma2, float nsigma)
{

  float Resolution[150];
  float eResolution[150];
  float x[150];
  float ex[150];
  float M=0;
  float eM=0;
  float DM=0;
  float eDM=0;
  float n=0;
  
  for (int i=0; i<150; i++)
    {
      M = abs(gMean1->GetPointY(i) - gMean2->GetPointY(i));
      eM = sqrt(gMean1->GetErrorY(i)*gMean1->GetErrorY(i) + gMean2->GetErrorY(i)*gMean2->GetErrorY(i));
      DM = abs(nsigma*gSigma1->GetPointY(i) + nsigma*gSigma2->GetPointY(i));
      eDM = sqrt((nsigma*gSigma1->GetErrorY(i))*(nsigma*gSigma1->GetErrorY(i)) + (nsigma*gSigma2->GetErrorY(i))*(nsigma*gSigma2->GetErrorY(i)));
      Resolution[i] = M/DM;
      eResolution[i] = Resolution[i]*(eM/M + eDM/DM);

      x[i] = gMean1->GetPointX(i);
      ex[i] = 0.05;
      n++;
    }

  TGraphErrors* g = new TGraphErrors(n, x, Resolution, ex, eResolution);
  
  return g;
  
}



TF1 *fit_gaus_resolution(TH1D* proj, TF1* fit_mean1, TF1* fit_mean2, TF1* fit_sigma1, TF1 *fit_sigma2, float flag_resolution)
{
  
  TF1* fit_gaus1 = new TF1("fit_gaus1", "gaus(0)", fit_mean1->Eval(flag_resolution)-3*fit_sigma1->Eval(flag_resolution), fit_mean1->Eval(flag_resolution)+2*fit_sigma1->Eval(flag_resolution));
  fit_gaus1->SetParameter(1, fit_mean1->Eval(flag_resolution));
  fit_gaus1->SetParameter(2, fit_sigma1->Eval(flag_resolution));
  proj->Fit(fit_gaus1, "QNR+");
  
  TF1* fit_gaus2 = new TF1("fit_gaus2", "gaus(0)", fit_mean2->Eval(flag_resolution)-fit_sigma2->Eval(flag_resolution), fit_mean2->Eval(flag_resolution)+3*fit_sigma2->Eval(flag_resolution));
  fit_gaus2->SetParameter(1, fit_mean2->Eval(flag_resolution));
  fit_gaus2->SetParameter(2, fit_sigma2->Eval(flag_resolution));
  proj->Fit(fit_gaus2, "QNR+");

  
  TF1* fit_gaus = new TF1("fit_gaus", "gaus(0) + gaus(3)",-1, -flag_resolution);
  fit_gaus->SetParameter(0, fit_gaus1->GetParameter(0));
  fit_gaus->SetParameter(1, fit_gaus1->GetParameter(1));
  fit_gaus->SetParameter(2, fit_gaus1->GetParameter(2));
  fit_gaus->SetParameter(3, fit_gaus2->GetParameter(0));
  fit_gaus->SetParameter(4, fit_gaus2->GetParameter(1));
  fit_gaus->SetParameter(5, fit_gaus2->GetParameter(2));

  fit_gaus->SetParLimits(0, fit_gaus1->GetParameter(0)-3*fit_gaus1->GetParError(0), fit_gaus1->GetParameter(0)+3*fit_gaus1->GetParError(0));
  fit_gaus->SetParLimits(1, fit_gaus1->GetParameter(1)-3*fit_gaus1->GetParError(1), fit_gaus1->GetParameter(1)+3*fit_gaus1->GetParError(1));
  fit_gaus->SetParLimits(2, fit_gaus1->GetParameter(2)-fit_gaus1->GetParameter(2), fit_gaus1->GetParameter(2)+fit_gaus1->GetParameter(2));
    fit_gaus->SetParLimits(3, fit_gaus2->GetParameter(0)-3*fit_gaus2->GetParError(0), fit_gaus2->GetParameter(0)+3*fit_gaus2->GetParError(0));
  fit_gaus->SetParLimits(4, fit_gaus2->GetParameter(1)-3*fit_gaus2->GetParError(1), fit_gaus2->GetParameter(1)+3*fit_gaus2->GetParError(1));
  fit_gaus->SetParLimits(5, fit_gaus2->GetParameter(2)-fit_gaus2->GetParameter(2), fit_gaus2->GetParameter(2)+fit_gaus2->GetParameter(2));

  delete fit_gaus1;
  delete fit_gaus2;
  
  return fit_gaus;

}



TF1 *fit_gaus_resolution_test(TH1D* proj, TGraphErrors* fit_mean1, TGraphErrors* fit_mean2, TGraphErrors* fit_sigma1, TGraphErrors *fit_sigma2, float flag_resolution)
{
  
  TF1* fit_gaus1 = new TF1("fit_gaus1", "gaus(0)", fit_mean1->Eval(flag_resolution)-1*fit_sigma1->Eval(flag_resolution), fit_mean1->Eval(flag_resolution)+0.75*fit_sigma1->Eval(flag_resolution));
  fit_gaus1->SetParameter(1, fit_mean1->Eval(flag_resolution));
  fit_gaus1->SetParameter(2, fit_sigma1->Eval(flag_resolution));
  proj->Fit(fit_gaus1, "QNR+");
  
  TF1* fit_gaus2 = new TF1("fit_gaus2", "gaus(0)", fit_mean2->Eval(flag_resolution)-0.75*fit_sigma2->Eval(flag_resolution), fit_mean2->Eval(flag_resolution)+1*fit_sigma2->Eval(flag_resolution));
  fit_gaus2->SetParameter(1, fit_mean2->Eval(flag_resolution));
  fit_gaus2->SetParameter(2, fit_sigma2->Eval(flag_resolution));
  proj->Fit(fit_gaus2, "QNR+");

  
  TF1* fit_gaus = new TF1("fit_gaus", "gaus(0) + gaus(3)",-1, -flag_resolution);
  fit_gaus->SetParameter(0, fit_gaus1->GetParameter(0));
  fit_gaus->SetParameter(1, fit_gaus1->GetParameter(1));
  fit_gaus->SetParameter(2, fit_gaus1->GetParameter(2));
  fit_gaus->SetParameter(3, fit_gaus2->GetParameter(0));
  fit_gaus->SetParameter(4, fit_gaus2->GetParameter(1));
  fit_gaus->SetParameter(5, fit_gaus2->GetParameter(2));

  fit_gaus->SetParLimits(0, fit_gaus1->GetParameter(0)-3*fit_gaus1->GetParError(0), fit_gaus1->GetParameter(0)+3*fit_gaus1->GetParError(0));
  fit_gaus->SetParLimits(1, fit_gaus1->GetParameter(1)-3*fit_gaus1->GetParError(1), fit_gaus1->GetParameter(1)+3*fit_gaus1->GetParError(1));
  fit_gaus->SetParLimits(2, fit_gaus1->GetParameter(2)-fit_gaus1->GetParameter(2), fit_gaus1->GetParameter(2)+fit_gaus1->GetParameter(2));
    fit_gaus->SetParLimits(3, fit_gaus2->GetParameter(0)-3*fit_gaus2->GetParError(0), fit_gaus2->GetParameter(0)+3*fit_gaus2->GetParError(0));
  fit_gaus->SetParLimits(4, fit_gaus2->GetParameter(1)-3*fit_gaus2->GetParError(1), fit_gaus2->GetParameter(1)+3*fit_gaus2->GetParError(1));
  fit_gaus->SetParLimits(5, fit_gaus2->GetParameter(2)-fit_gaus2->GetParameter(2), fit_gaus2->GetParameter(2)+fit_gaus2->GetParameter(2));

  delete fit_gaus1;
  delete fit_gaus2;
  
  return fit_gaus;

}


TH2F* Plot_E_Position(TTree* Tree, const char* Position)
{
  Tree->ResetBranchAddresses();
  float Pos=0;
  float E=0;
  Tree->SetBranchAddress(Position, &Pos);
  Tree->SetBranchAddress("E_start", &E);
  const int Entries = Tree->GetEntries();
  TH2F* h = new TH2F("EvsX", "EvsX", 450, -40, 5, 1000, 0, 100000);
  //TH2F* h = new TH2F("test", "test", 1000, 0, 100000, 450, -40, 5);  

  for(int i=0; i<Entries; i++)
  {
    Tree->GetEntry(i);
    h->Fill(Pos,E);
    //h->Fill(E,Pos);
  }

  return h;  
}


TH2F* Plot_E_Position_Optique(TTree* Tree, const char* Position)
{
  Tree->ResetBranchAddresses();
  float E=0;;
  vector<float>* Pos=0;
  Tree->SetBranchAddress(Position, &Pos);
  Tree->SetBranchAddress("IncidentE", &E);
  const int Entries = Tree->GetEntries();
  TH2F* h = new TH2F("test", "test", 450, -40, 5, 1000, 0, 100000);
  //TH2F* h = new TH2F("test", "test", 1000, 0, 100000, 450, -40, 5);  

  for(int i=0; i<Entries; i++)
  {
    Pos->clear();
    Tree->GetEntry(i);
    for (int j =0; j<Pos->size(); j++)
      {
	h->Fill(Pos->at(j),E);
      }
  }


  return h;  
}



Double_t fpeaks(Double_t *x, Double_t *par)
{
  Double_t result = par[0] + par[1]*x[0];
  for (Int_t p=0;p<3;p++) {
    Double_t norm  = par[3*p+2]; // "height" or "area"
    Double_t mean  = par[3*p+3];
    Double_t sigma = par[3*p+4];
    result += norm*TMath::Gaus(x[0],mean,sigma);
  }
  return result;
}



int Find_bin_resolution(TH2F* h_ALL, float xmin, float xmax, int npeaks, float sigma)
{
  int bin_start = (xmin+40.1)*10;
  int bin_end = (xmax+40.1)*10;
  double par[3000];
  int p;
  int n=bin_end;
  int nfound=0;
  double xp;
  int bin;
  double yp;
  TH1D *proj = new TH1D("proj", "proj", 610, -1, 60);
  int number_of_peaks = npeaks;
  cout << "bin start = " << bin_start << endl;
  cout << "bin end = " << bin_end << endl;
  
  
  for (int i=bin_start; i<bin_end; i++)
    {
      h_ALL->ProjectionY("proj", i, i, "");
      TSpectrum *s = new TSpectrum(npeaks);
      nfound = s->Search(proj,sigma,"",0.1);
      
      //estimate linear background using a fitting method
      TF1 *fline = new TF1("fline","pol1",-1,60);
      proj->Fit("fline","qn");
      // Loop on all found peaks. Eliminate peaks at the background level
      par[0] = fline->GetParameter(0);
      par[1] = fline->GetParameter(1);
      npeaks = 0;
      Double_t *xpeaks;
      xpeaks = s->GetPositionX();
      for (p=0;p<nfound;p++) {
	xp = xpeaks[p];
	bin = proj->GetXaxis()->FindBin(xp);
	yp = proj->GetBinContent(bin);
	if (yp-TMath::Sqrt(yp) < fline->Eval(xp)) continue;
	par[3*npeaks+2] = yp; // "height"
	par[3*npeaks+3] = xp; // "mean"
	par[3*npeaks+4] = 0.03; // "sigma"
	npeaks++;
      }


      delete s;
      proj->Reset();
      
      if(npeaks==number_of_peaks-1)
	{
	  n =i;
	  cout << "n =" << n << endl;
	  break;
	}

    }
  
  return n;

}



void Fit_YProjection_at_Resolution(TH1D* Output_resolution, int npeaks, float a, Color_t kColor)
{
  double par[3000];
  int p;
  TH1F *h2 = (TH1F*)Output_resolution->Clone("h2");
  
  h2->GetXaxis()->SetRangeUser(-1, a);
  TSpectrum *s = new TSpectrum(npeaks);
  Int_t nfound = s->Search(Output_resolution, 1,"",0.05);
  printf("Found %d candidate peaks to fit\n",nfound);
  // // Estimate background using TSpectrum::Background
  // TH1 *hb = s->Background(Output_resolution,20,"same");
  // hb->SetLineColor(kCyan);

  //if (hb) c1->Update();
  //if (np <0) return;
  TF1 *fline = new TF1("fline","pol1",-1,60);
  Output_resolution->Fit("fline","sameqn");
  // Loop on all found peaks. Eliminate peaks at the background level
  par[0] = fline->GetParameter(0);
  par[1] = fline->GetParameter(1);
  npeaks = 0;
  Double_t *xpeaks;
  xpeaks = s->GetPositionX();
  for (p=0;p<nfound;p++) {
    Double_t xp = xpeaks[p];
    Int_t bin = Output_resolution->GetXaxis()->FindBin(xp);
    Double_t yp = Output_resolution->GetBinContent(bin);
    if (yp-TMath::Sqrt(yp) < fline->Eval(xp)) continue;
    par[3*npeaks+2] = yp; // "height"
    par[3*npeaks+3] = xp; // "mean"
    par[3*npeaks+4] = 0.1; // "sigma"
    npeaks++;
  }
  
  printf("Found %d useful peaks to fit\n",npeaks);
  printf("Now fitting: Be patient\n");

  TF1*test_fit1 = new TF1("fit1", "gaus", par[3]-0.4, par[3]+0.4);
  test_fit1->SetParameter(1, par[3]);
  TF1*test_fit2 = new TF1("fit2", "gaus", par[6]-0.4, par[6]+0.4);
  test_fit2->SetParameter(1, par[6]);
  TF1*test_fit3 = new TF1("fit3", "gaus(0)+gaus(3)+gaus(6)", -1, par[6]+10);
  h2->Draw();
  h2->Fit(test_fit1, "R");
  h2->Fit(test_fit2, "R");
  test_fit3->SetParLimits(0, 0, test_fit1->GetParameter(0)+100);
  test_fit3->SetParameter(1, test_fit1->GetParameter(1));
  test_fit3->SetParLimits(1, test_fit1->GetParameter(1)-0.05, test_fit1->GetParameter(1)+0.05);
  test_fit3->SetParameter(2, test_fit1->GetParameter(2));
  test_fit3->SetParLimits(2, 0.08, 0.5);
  test_fit3->SetParLimits(3, 0, test_fit2->GetParameter(0)+10);
  test_fit3->SetParameter(4, test_fit2->GetParameter(1));
  test_fit3->SetParLimits(4, test_fit2->GetParameter(1)-0.1, test_fit2->GetParameter(1)+0.1);
  test_fit3->SetParameter(5, test_fit2->GetParameter(2));
  test_fit3->SetParLimits(5, 0.1, 1);
  test_fit3->SetParLimits(6, 0, 1000);
  test_fit3->SetParameter(7, (test_fit2->GetParameter(1)+test_fit2->GetParameter(1))/2);
  test_fit3->SetParLimits(8, 1, 10);
  h2->Fit(test_fit3, "R");
  test_fit3->SetLineColor(kColor);
  test_fit3->Draw("same");
  TF1* fitgaus1 = new TF1("fitgaus1", "gaus", -1, 60);
  fitgaus1->FixParameter(0, test_fit3->GetParameter(0));
  fitgaus1->FixParameter(1, test_fit3->GetParameter(1));
  fitgaus1->FixParameter(2, test_fit3->GetParameter(2));
  fitgaus1->SetLineStyle(2);
  fitgaus1->SetLineColor(kColor);
  fitgaus1->Draw("same");
  TF1* fitgaus2 = new TF1("fitgaus2", "gaus", -1, 60);
  fitgaus2->FixParameter(0, test_fit3->GetParameter(3));
  fitgaus2->FixParameter(1, test_fit3->GetParameter(4));
  fitgaus2->FixParameter(2, test_fit3->GetParameter(5));
  fitgaus2->SetLineStyle(2);
  fitgaus2->SetLineColor(kColor);
  fitgaus2->Draw("same");
  TF1* fitgaus3 = new TF1("fitgaus3", "gaus", -1, 60);
  fitgaus3->FixParameter(0, test_fit3->GetParameter(6));
  fitgaus3->FixParameter(1, test_fit3->GetParameter(7));
  fitgaus3->FixParameter(2, test_fit3->GetParameter(8));
  fitgaus3->SetLineStyle(2);
  fitgaus3->SetLineColor(kGreen+2);
  fitgaus3->Draw("same");
  h2->GetXaxis()->SetRangeUser(-1, test_fit3->GetParameter(1) + 20*test_fit3->GetParameter(2));
  

  
  // TF1 *fit = new TF1("fit",fpeaks,-1,60,2+3*npeaks);
  // // We may have more than the default 25 parameters
  // TVirtualFitter::Fitter(h2,10+3*npeaks);
  // fit->SetParameters(par);
  // fit->SetParLimits(2, 10., 1000000);
  // fit->SetParLimits(3, 0., 10);
  // fit->SetParLimits(4, 0.1, 0.4);
  // fit->SetParLimits(5, 10., 1000000);
  // fit->SetParLimits(6, 1.5, 1.7);
  // fit->SetParLimits(7, 0.1, 0.4);
  // fit->SetNpx(1000);
  // fit->SetLineColor(kColor);
  // h2->Fit("fit", "QR");
  // hb->Draw("same");
  // hb->SetLineColor(kGreen+2);;


}




void Analyse(const char* file_proton, const char* file_He1, const char* file_He2, const char* TreeName, const char* CanvasName, float pinhole, float B, float E, float Lb1, float D, float Le1, float Le2, float Sc_length, float Sc_thickness, float ZnS_thickness, bool Optique, float xmin_proton, float xmin_He1, float xmax_proton, float sigma)
{
  TCanvas *c1 = new TCanvas(CanvasName, CanvasName, 0, 10, 1600, 900);
  TPad *pad1 = new TPad("pad1", "", 0, 0.51, 0.32, 1);
  TPad *pad2 = new TPad("pad2", "", 0.34, 0.51, 0.59, 1);
  TPad *pad3 = new TPad("pad3", "", 0.60, 0.51, 0.85, 1);
  TPad *pad4 = new TPad("pad4", "", 0., 0., 0.32, 0.24);
  TPad *pad5 = new TPad("pad5", "", 0., 0.25, 0.32, 0.49);
  TPad *pad6 = new TPad("pad6", "", 0.34, 0., 0.66, 0.24);
  TPad *pad7 = new TPad("pad7", "", 0.34, 0.25, 0.66, 0.49);
  TPad *pad8 = new TPad("pad8", "", 0.68, 0., 1, 0.49);
  TPad *pad9 = new TPad("pad9", "", 0.86, 0.51, 1, 1);
  pad1->Draw();
  pad1->SetLogz();
  pad2->Draw();
  pad3->Draw();
  pad4->Draw();
  pad5->Draw();
  pad6->Draw();
  pad7->Draw();
  pad8->Draw();
  pad8->SetLogz();
  pad9->Draw();

  cout << TreeName << endl;
 

  TFile* file1 = new TFile(file_proton);
  TTree *Tree1 = (TTree*)file1->Get(TreeName);
  TFile* file2 = new TFile(file_He1);
  TTree *Tree2 = (TTree*)file2->Get(TreeName);
  TFile* file3 = new TFile(file_He2);
  TTree *Tree3 = (TTree*)file3->Get(TreeName);


  
  TH2F* h_proton;
  TH2F* h_ALL;
  TH2F* h_proton_He1;
  TH2F* h_proton_He2;
  TH2F* h_He1;
  TH2F* h_He2;

  //Declaration of graphs
  if (Optique == false)
    {
      h_proton = Histo_Parabole(Tree1, file_proton);
      h_ALL = Histo_Parabole(Tree1, "ALL");
      h_proton_He1 = Histo_Parabole(Tree1, "proton_He1");
      h_proton_He2 = Histo_Parabole(Tree1, "proton_He2");
      h_He1 = Histo_Parabole(Tree2, file_He1);
      h_He2 = Histo_Parabole(Tree3,  file_He2);
    }

  if (Optique == true)
    {
      h_proton = Histo_Parabole_Optique(Tree1, file_proton);
      h_ALL = Histo_Parabole_Optique(Tree1, "ALL");
      h_proton_He1 = Histo_Parabole_Optique(Tree1, "proton_He1");
      h_proton_He2 = Histo_Parabole_Optique(Tree1, "proton_He2");
      h_He1 = Histo_Parabole_Optique(Tree2, file_He1);
      h_He2 = Histo_Parabole_Optique(Tree3, file_He2);
    }

  h_proton_He1->Add(h_He1, 1);
  h_proton_He2->Add(h_He2, 1);

  // new TCanvas;
  // h_proton->Draw("colz");
  // h_proton->Scale(1./2500.);

  // new TCanvas;
  // h_He1->Draw("colz");
  // h_He1->Scale(1./500.);

  // new TCanvas;
  // h_He2->Draw("colz");
  // h_He2->Scale(1./500.);


  //######################################################################
  //############################# PAD 1 ##################################
  //######################################################################
  pad1->cd();

  
  //Draw & Color
  h_ALL->Add(h_He1, 1);
  h_ALL->Add(h_He2, 1);
  h_ALL->Draw("colz");

  //Title & Legend
  h_ALL->SetTitle("Detector response");
  h_ALL->GetXaxis()->SetTitle("X Position [mm]");
  h_ALL->GetYaxis()->SetTitle("Y Position [mm]");


  
  //######################################################################
  //############################# PAD 2 ##################################
  //######################################################################
  pad2->cd();

  //Declaration of graphs
  TGraphErrors* MeanY_proton = Fit_LargeurY_Parabole(h_proton, 1);
  TGraphErrors* MeanY_He1 = Fit_LargeurY_Parabole(h_He1, 1);
  TGraphErrors* MeanY_He2 = Fit_LargeurY_Parabole(h_He2, 1);
  TF1* fit_mean_proton = new TF1("fit_mean_proton", "pol2", -11, -3);
  TF1* fit_mean_He1 = new TF1("fit_mean_He1", "pol2", -6, -1);
  TF1* fit_mean_He2 = new TF1("fit_mean_He2", "pol2", -12, -3.5);

  //Draw & Color
  MeanY_proton->Draw();
  MeanY_proton->GetYaxis()->SetRangeUser(0., 60.);
  MeanY_He1->Draw("same");
  MeanY_He2->Draw("same");
  MeanY_proton->SetLineColor(kRed);
  MeanY_He1->SetLineColor(kBlue);
  MeanY_He2->SetLineColor(kGreen+3);

  MeanY_proton->Fit(fit_mean_proton, "QNR");
  fit_mean_proton->Draw("same");
  fit_mean_proton->SetLineColor(kOrange);
  MeanY_He1->Fit(fit_mean_He1, "QNR");
  fit_mean_He1->Draw("same");
  fit_mean_He1->SetLineColor(kCyan);
  MeanY_He2->Fit(fit_mean_He2, "QNR");
  fit_mean_He2->Draw("same");
  fit_mean_He2->SetLineColor(kGreen);

  //Title & Legend
  MeanY_proton->SetTitle("Mean Value Fit");
  MeanY_proton->GetXaxis()->SetTitle("X Position [mm]");
  MeanY_proton->GetYaxis()->SetTitle("Y Position [mm]");
  auto legend = new TLegend(0.65,0.6,0.9,0.9);
  legend->AddEntry(MeanY_proton,"proton","e");
  legend->AddEntry(MeanY_He1,"He1+","e");
  legend->AddEntry(MeanY_He2,"He2+","e");
  legend->AddEntry(fit_mean_proton,"fit proton","l");
  legend->AddEntry(fit_mean_He1,"fit He1+","l");
  legend->AddEntry(fit_mean_He2,"fit He2+","l");
  legend->Draw();
  


  //######################################################################
  //############################# PAD 3 ##################################
  //######################################################################
  pad3->cd();

  //Declaration of graphs
  TGraphErrors* Sigma_proton = Fit_LargeurY_Parabole(h_proton, 2);
  TGraphErrors* Sigma_He1 = Fit_LargeurY_Parabole(h_He1, 2);
  TGraphErrors* Sigma_He2 = Fit_LargeurY_Parabole(h_He2, 2);
  TF1* fit_sigma_proton = new TF1("fit_sigma_proton", "pol1", -30, -3);
  TF1* fit_sigma_He1 = new TF1("fit_sigma_He1", "pol1", -12, -3);
  TF1* fit_sigma_He2 = new TF1("fit_sigma_He2", "pol1", -30, -3);

  //Draw & Color
  Sigma_proton->Draw();
  Sigma_He1->Draw("same");
  Sigma_He2->Draw("same");
  Sigma_proton->SetLineColor(kRed);
  Sigma_He1->SetLineColor(kBlue);
  Sigma_He2->SetLineColor(kGreen+3);
  Sigma_proton->Fit(fit_sigma_proton, "QNR");
  fit_sigma_proton->Draw("same");
  fit_sigma_proton->SetLineColor(kOrange);
  Sigma_He1->Fit(fit_sigma_He1, "QNR");
  fit_sigma_He1->Draw("same");
  fit_sigma_He1->SetLineColor(kCyan);
  Sigma_He2->Fit(fit_sigma_He2, "QNR");
  fit_sigma_He2->Draw("same");
  fit_sigma_He2->SetLineColor(kGreen);

  TLine* l1 = new TLine(-38,pinhole, 0, pinhole);
  l1->Draw("same");
  l1->SetLineColor(kBlack);
  l1->SetLineWidth(2);
  l1->SetLineStyle(2);

  //Title & Legend
  string s = Form("r_{pinhole} =  %g mm", pinhole);
  TLatex *t1 = new TLatex(-42,pinhole-0.1, s.c_str());
  t1->SetTextColor(kBlack);
  t1->SetTextFont(43);
  t1->SetTextSize(15);
  t1->SetTextAngle(90);
  t1->Draw("same");
  Sigma_proton->SetTitle("#sigma Value Fit");
  Sigma_proton->GetXaxis()->SetTitle("X Position [mm]");
  Sigma_proton->GetYaxis()->SetTitle("Y Position [mm]");
  auto legend1 = new TLegend(0.65,0.6,0.9,0.9);
  legend1->AddEntry(Sigma_proton,"proton","e");
  legend1->AddEntry(Sigma_He1,"He1+","e");
  legend1->AddEntry(Sigma_He2,"He2+","e");
  legend1->AddEntry(fit_sigma_proton,"fit proton","l");
  legend1->AddEntry(fit_sigma_He1,"fit He1+","l");
  legend1->AddEntry(fit_sigma_He2,"fit He2+","l");
  legend1->Draw();


  //######################################################################
  //############################# PAD 4 ##################################
  //######################################################################
  pad4->cd();
  
  int npeaks = 2;
  TH1D *Output_resolution = new TH1D("Output_resolution", "Output_resolution", 610, -1, 60);
  TH2F *h_proton_He2_bis = (TH2F*)h_proton_He2->Clone();
  int n = Find_bin_resolution(h_proton_He2_bis, xmin_proton, xmax_proton, npeaks, sigma);
  float a = -40+0.1*(n-1)-0.05;
  cout << "bin = " << n << endl;
  cout << "a = " << a << endl;
  
  h_proton_He2->ProjectionY("Output_resolution", n-1, n-1, "");
  Output_resolution->Draw();
  Fit_YProjection_at_Resolution(Output_resolution, npeaks, -a, kRed);



  //######################################################################
  //############################# PAD 5 ##################################
  //######################################################################
  pad5->cd();

  TH2F* Parabole_zoom = (TH2F*)h_proton_He2->Clone();
  Parabole_zoom->Draw("colz");
  Parabole_zoom->GetXaxis()->SetRangeUser(a-2, a+2);
  Parabole_zoom->GetYaxis()->SetRangeUser(-1, -a);
  TLine* l4 = new TLine(a-0.05,-1, a-0.05, -a);
  TLine* l5 = new TLine(a+0.05,-1, a+0.05, -a);

  //Draw & Color
  l4->SetLineColor(kRed);
  l4->SetLineWidth(2);
  l4->Draw("same");
  l5->SetLineColor(kRed);
  l5->SetLineWidth(2);
  l5->Draw("same");

  //Title & Legend
  Parabole_zoom->SetTitle("Detector response zoom on x_{cut} with only p^{+} & He^{2+}");
  Parabole_zoom->GetXaxis()->SetTitle("X Position [mm]");
  Parabole_zoom->GetYaxis()->SetTitle("Y Position [mm]");

  //######################################################################
  //############################# PAD 6 ##################################
  //######################################################################
  pad6->cd();
  TH1D *Output_resolution_bis = new TH1D("Output_resolution_bis", "Output_resolution_bis", 610, -1, 60);
  h_proton_He1->Draw("colz");
  TH2F *h_proton_He1_bis = (TH2F*)h_proton_He1->Clone();
  int nbis = Find_bin_resolution(h_proton_He1_bis, xmin_He1, xmax_proton, 2, sigma);
  float abis = -40+0.1*(nbis-1)-0.05;
  cout << "bin bis = " << nbis << endl;
  cout << "a bis = " << abis << endl;

  h_proton_He1->ProjectionY("Output_resolution_bis", nbis-1, nbis-1, "");
  Output_resolution_bis->Draw();
  Fit_YProjection_at_Resolution(Output_resolution_bis, 2, -abis, kCyan);


  //######################################################################
  //############################# PAD 7 ##################################
  //######################################################################
  pad7->cd();

  TH2F* Parabole_zoom_bis = (TH2F*)h_proton_He1->Clone();
  Parabole_zoom_bis->Draw("colz");
  Parabole_zoom_bis->GetXaxis()->SetRangeUser(abis-2, abis+2);
  Parabole_zoom_bis->GetYaxis()->SetRangeUser(-1, -abis);
  TLine* l4bis = new TLine(abis-0.05,-1, abis-0.05, -abis);
  TLine* l5bis = new TLine(abis+0.05,-1, abis+0.05, -abis);

  //Draw & Color
  l4bis->SetLineColor(kCyan);
  l4bis->SetLineWidth(2);
  l4bis->Draw("same");
  l5bis->SetLineColor(kCyan);
  l5bis->SetLineWidth(2);
  l5bis->Draw("same");

  //Title & Legend
  Parabole_zoom_bis->SetTitle("Detector response zoom on x_{cut} only with p^{+} & He^{+}");
  Parabole_zoom_bis->GetXaxis()->SetTitle("X Position [mm]");
  Parabole_zoom_bis->GetYaxis()->SetTitle("Y Position [mm]");

  //######################################################################
  //############################# PAD 8 ##################################
  //######################################################################
  pad8->cd();
  
  TH2F* aze;
  
  if (Optique == false)
    {
      aze = Plot_E_Position(Tree1, "PositionX");
    }
  
    if (Optique == true)
      {
        aze = Plot_E_Position_Optique(Tree1, "PositionX");
      }
  
  aze->Draw("colz");

  TH1D *proj2 = new TH1D("proj2", "proj2", 1000, 0, 100000);
  aze->ProjectionY("proj2", n-1, n-1, "");
  TF1* fit_gaus_Energie = new TF1("fit_gaus_Energie", "gaus", 0, 100000);
  proj2->Fit(fit_gaus_Energie, "QN");

  TH1D *proj2bis = new TH1D("proj2bis", "proj2bis", 1000, 0, 100000);
  aze->ProjectionY("proj2bis", nbis-1, nbis-1, "");
  TF1* fit_gaus_Energie_bis = new TF1("fit_gaus_Energie_bis", "gaus", 0, 100000);
  proj2bis->Fit(fit_gaus_Energie_bis, "QN");
  
  TLine* l6 = new TLine(a,0, a, fit_gaus_Energie->GetParameter(1));
  l6->SetLineColor(kRed);
  l6->SetLineWidth(2);
  l6->Draw("same");
  TLine* l7 = new TLine(-40, fit_gaus_Energie->GetParameter(1), a, fit_gaus_Energie->GetParameter(1));
  l7->SetLineColor(kRed);
  l7->SetLineWidth(2);
  l7->Draw("same");

  TLine* l6bis = new TLine(abis, 0, abis, fit_gaus_Energie_bis->GetParameter(1));
  l6bis->SetLineColor(kCyan);
  l6bis->SetLineWidth(2);
  l6bis->Draw("same");
  TLine* l7bis = new TLine(-40, fit_gaus_Energie_bis->GetParameter(1), abis, fit_gaus_Energie_bis->GetParameter(1));
  l7bis->SetLineColor(kCyan);
  l7bis->SetLineWidth(2);
  l7bis->Draw("same");

  //Title & Legend
  s = Form("#bf{E_{cut} p^{+}/He^{2+} =  %d MeV}", (int)fit_gaus_Energie->GetParameter(1)/1000);
  TLatex *t3 = new TLatex(-30.,(int)fit_gaus_Energie->GetParameter(1) +5000, s.c_str());
  t3->SetTextColor(kRed+2);
  t3->SetTextFont(43);
  t3->SetTextSize(20);
  t3->Draw("same");
  s = Form("#bf{E_{cut} p^{+}/He^{+} =  %d MeV}", (int)fit_gaus_Energie_bis->GetParameter(1)/1000);
  TLatex *t3bis = new TLatex(-30.,(int)fit_gaus_Energie_bis->GetParameter(1) +3000, s.c_str());
  t3bis->SetTextColor(kCyan+2);
  t3bis->SetTextFont(43);
  t3bis->SetTextSize(20);
  t3bis->Draw("same");
  aze->SetTitle("Evolution of energy according x deviation");
  aze->GetXaxis()->SetTitle("X Position [mm]");
  aze->GetYaxis()->SetTitle("E [keV]");


  //######################################################################
  //############################# PAD 9 ##################################
  //######################################################################
  
  pad9->cd();
  TLatex *param = new TLatex(0,0.85, "Simulation parameters :");
  param->SetTextSize(0.085);
  param->SetTextColor(kRed);
  param->Draw();

  string sPinhole = Form("r_{pinhole} =  %g mm", pinhole);
  TLatex *lPinhole = new TLatex(0,0.78, sPinhole.c_str());
  lPinhole->Draw();
  lPinhole->SetTextSize(0.06);
  
  string sBValue = Form("B value =  %g T", B);
  TLatex *lBValue = new TLatex(0,0.72, sBValue.c_str());
  lBValue->Draw();
  lBValue->SetTextSize(0.06);
  
  string sEValue = Form("E value =  %g V/m", E);
  TLatex *lEValue = new TLatex(0,0.66, sEValue.c_str());
  lEValue->Draw();
  lEValue->SetTextSize(0.06);

  string sLe1 = Form("Magnet Length =  %g mm", Lb1);
  TLatex *lLe1 = new TLatex(0,0.60, sLe1.c_str());
  lLe1->Draw();
  lLe1->SetTextSize(0.06);

  string sD = Form("Ecart plates D =  %g mm", D);
  TLatex *lD = new TLatex(0,0.54, sD.c_str());
  lD->Draw();
  lD->SetTextSize(0.06);

  string sLb1 = Form("Electric length =  %g mm", Le1);
  TLatex *lLb1 = new TLatex(0,0.48, sLb1.c_str());
  lLb1->Draw();
  lLb1->SetTextSize(0.06);

  string sLb2 = Form("Distance plate/detector =  %g mm", Le2);
  TLatex *lLb2 = new TLatex(0,0.42, sLb2.c_str());
  lLb2->Draw();
  lLb2->SetTextSize(0.06);

  float Ltot = Lb1 + D + Le1 + Le2;
  string sLtot = Form("L_{tot} =  %g mm", Ltot);
  TLatex *lLtot = new TLatex(0,0.36, sLtot.c_str());
  lLtot->Draw();
  lLtot->SetTextSize(0.06);

  string sScLength = Form("Sc length =  %g mm", Sc_length);
  TLatex *lScLength = new TLatex(0,0.3, sScLength.c_str());
  lScLength->Draw();
  lScLength->SetTextSize(0.06);

  string sScThickness = Form("Sc thickness =  %g mm", Sc_thickness);
  TLatex *lScThickness = new TLatex(0,0.24, sScThickness.c_str());
  lScThickness->Draw();
  lScThickness->SetTextSize(0.06);

  string sZnSThickness = Form("ZnS thickness =  %g mm", ZnS_thickness);
  TLatex *lZnSThickness = new TLatex(0,0.18, sZnSThickness.c_str());
  lZnSThickness->Draw();
  lZnSThickness->SetTextSize(0.06);

  string textOpt;
  if (Optique ==true){textOpt = "Yes";}
  if (Optique ==false){textOpt = "No";}
  string sOptique = Form("Optique ? :  %s", textOpt.c_str());
  TLatex *lOptique = new TLatex(0,0.12, sOptique.c_str());
  lOptique->Draw();
  lOptique->SetTextSize(0.06);
  

}



