#include "Reconstruction_Fibres.hh"

void Reconstruction_Fibres()
{
  gStyle->SetOptStat(0);

  float x[NbinsX], ex[NbinsX], y[NbinsX], ey[NbinsX];
  float x_new[1500], y_new[1500], ex_new[1500], ey_new[1500];
  float xE[NbinsX], exE[NbinsX], yE[NbinsX], eyE[NbinsX];
  float xNph[NbinsX], exNph[NbinsX], yNph[NbinsX], eyNph[NbinsX];

  //string filename = "proton_round_fiber_multicladding_0.2mm_1m_CMOS_Exp_30MeV.root";
  string filename = "test.root";
  //string filename_out_Nph = "Graph_Nph_proton_round_fiber_multicladding_0.2mm_1m_CMOS_Exp_30MeV.root";
  string filename_out_Nph = "Graph_Nph_proton_YAG_0.1mm_round_fiber_multicladding_0.2mm_1m_CMOS_Exp_30MeV.root";
  //string filename_out_Resolution = "Graph_Resolution_proton_round_fiber_multicladding_0.2mm_1m_CMOS_Exp_30MeV.root";
  string filename_out_Resolution = "Graph_Resolution_proton_YAG_0.1mm_round_fiber_multicladding_0.2mm_1m_CMOS_Exp_30MeV.root";
  //string filename_out = "../../../Images/TPSim/Analyses_Scintillateurs/Fibres/Results_proton_round_fiber_multicladding_0.2mm_1m_CMOS_Exp_30MeV.png";
  string filename_out = "../../../Images/TPSim/Analyses_Scintillateurs/Fibres/Results_proton_YAG_0.1mm_round_fiber_multicladding_0.2mm_1m_CMOS_Exp_30MeV.png";
  int Rebin =10;

  cout << "\nStart of 2D Histogram reconstruction !!!" << endl;
  TH2F* Pos = Histo_Reconstruction_2D(filename.c_str(), "2D");
  cout << "End of 2D Histogram reconstruction !!!" << endl;
  cout << "\nStart of EPos Histogram reconstruction !!!" << endl;
  TH2F* EPos = Histo_Reconstruction_Energie_Position(filename.c_str(), "Energie Position");
  cout << "End of EPos Histogram reconstruction !!!" << endl;
  TH1F* Estart = Histo_Reconstruction_Estart(filename.c_str());

  Pos->Rebin(Rebin);

  /*
  new TCanvas;
  Pos->Draw("colz");

  new TCanvas;
  EPos->Draw("colz");
  EPos->RebinX(10);
  */
  
  cout << "\nStart of Resolution part !!! " << endl;

  EPos->RebinX(Rebin);

  // RESOLUTION PART
  TH1D *ProjY = new TH1D("ProjY", "ProjY", 1000, 0, 100);
  Draw_ProjY_Test(EPos, ProjY, 300);
  int n=0;

  
  
  for (int i=20; i<130; i++)
    {

      EPos->ProjectionY("ProjY", i, i, "");
      ProjY->Fit(fit_gaus_Energie, "QN");
      mean = fit_gaus_Energie->GetParameter(1);
      sigma = fit_gaus_Energie->GetParameter(2);
      Resolution = sigma/mean;
      Chi2 = fit_gaus_Energie->GetChisquare();
      Ndf = fit_gaus_Energie->GetNDF();
      Chi2Ndf = Chi2/Ndf;

      cout << "\nMean = " << mean << endl;
      cout << "Sigma = " << sigma << endl;
       cout << "Resolution = " << Resolution << endl;
       cout << "Chi2/Ndf = " << Chi2Ndf << endl;

       if(Chi2Ndf >0.1 && Chi2Ndf <150 && mean >0 && mean <120 && sigma/mean <1)
   	{
	  if (fit_gaus_Energie->GetParameter(1) > y[n-1] && n!=0) continue;
	  y[n] = fit_gaus_Energie->GetParameter(1);
	  ey[n] = fit_gaus_Energie->GetParameter(2);
	  if(ey[n] <0.1)ey[n]=0.1;
	  
	  xE[n] = y[n];
	  exE[n] = fit_gaus_Energie->GetParError(1);
	  if(exE[n] >20)exE[n]=0;
	  yE[n] = Resolution;
	  //if(yE[n] >0.1)yE[n]=-0.1;
	  eyE[n] = fit_gaus_Energie->GetParError(2)/ey[n] + fit_gaus_Energie->GetParError(1)/y[n];
	  if(eyE[n] >0.5)eyE[n]=0.1;
	  cout << "\nResolution[" << i << "] = " << yE[n] << endl;
	  cout << "Chi2/Ndf[" << i << "] = " << Chi2Ndf << endl;
	  n++;
	}
    }

  cout << " n = " << n << endl;

  gResolution = new TGraphErrors(n, xE, yE, exE, eyE);
  

  cout << "End of Resolution part !!! " << endl;

  cout << "\nStart of Nph part !!! " << endl;

  // NPH PART
  TH1D *ProjX = new TH1D("ProjX", "ProjX", 1500, 0, 150);
  Draw_ProjX_Test(EPos, ProjX, Estart, 112);
  int nbis=0;

  
  for (int i=10; i<1200; i++)
    {
      EPos->ProjectionX("ProjX", i, i, "");
      fitX = new TF1("fitX", "gaus", 0, ProjX->GetMean(1) + 2*ProjX->GetRMS(1));
      fitX->SetParameter(1, ProjX->GetMean(1));
      fitX->SetParameter(2, ProjX->GetRMS(1));
      ProjX->Fit(fitX, "QR");
      fitX1 = new TF1("fitX1", "gaus", fitX->GetParameter(1)-2*fitX->GetParameter(2), fitX->GetParameter(1)+2*fitX->GetParameter(2));
      ProjX->Fit(fitX1, "QR");
      
      Eval_Energy = fitX1->Eval(fitX1->GetParameter(1))/2;
      if (Eval_Energy != Eval_Energy) continue; //test NaN condition !!!
      NEvents = Estart->Integral(i, i);
      x_new[nbis] = (i-0.5)/10;
      ex_new[nbis] = 0.5;
      y_new[nbis] = (Eval_Energy/NEvents)/Rebin;
      ey_new[nbis] = y_new[nbis] * ((sqrt(Eval_Energy)/Eval_Energy) + (sqrt(NEvents)/NEvents));
      Chi2 = fitX1->GetChisquare();
      Ndf = fitX1->GetNDF();
      Chi2Ndf = Chi2/Ndf;
      // cout << "\ni = " << i << endl;
      // cout << "Eval = " << Eval_Energy << endl;
      // cout << "Nevents = " << NEvents << endl;
      // cout << "Nph = " << Eval_Energy/NEvents << endl;
      // cout << "Chi2/NdF = " << Chi2Ndf << endl;
      nbis++;
      
    }
  
  Nph = new TGraphErrors(nbis, x_new, y_new, ex_new, ey_new);
  
  cout << "End of Nph part !!! " << endl;
  

  // DRAW AND SAVE
  Draw_Results(Estart, Pos, EPos, gResolution, Nph);
  Save_Results(filename_out, filename_out_Resolution, filename_out_Nph);
  


  
}
