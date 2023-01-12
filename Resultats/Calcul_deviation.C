float deviation_B(float m, float B, float Le1, float Le2, float Lb1, float Lb2, float En)
{
  float x;
  float alpha;
  float D = Le1+Le2+Lb1+Lb2;

  //Definition of parameters
  float c = 3e08;
  float q = 1.6e-19;

  //Preliminary calculs
  float mrepos = ((m*c*c)/q)/1000; // en keV
  //cout << "mrepos = " << mrepos << endl;
  float beta = sqrt(1-pow(mrepos/(En+mrepos),2));
  //  cout << "beta = " << beta << endl;

  //  cout << "D = " << D << endl;
  if(beta>0.01){D = sqrt(D*D*(1-beta*beta));}
  //  cout << "D new = " << D << endl;

  alpha = q/(m*beta*c);

  x = alpha*B*((Lb1*Lb1)/2 + Lb1*Lb2) *1000;
  //cout << "x = " << x << " m" << endl;

  return x;
}

float deviation_E(float m, float E, float Le1, float Le2, float Lb1, float Lb2, float En)
{
  float x;
  float alpha;
  float D = Le1+Le2+Lb1+Lb2;

  //Definition of parameters
  float c = 3e08;
  float q = 1.6e-19;

  //Preliminary calculs
  float mrepos = ((m*c*c)/q)/1000; // en keV
  //cout << "mrepos = " << mrepos << endl;
  float beta = sqrt(1-pow(mrepos/(En+mrepos),2));
  //  cout << "beta = " << beta << endl;

  //  cout << "D = " << D << endl;
  if(beta>0.01){D = sqrt(D*D*(1-beta*beta));}
  //  cout << "D new = " << D << endl;

  alpha = q/(m*beta*c);

  x = alpha*alpha*E*(m/q)*((Le1*Le1)/2 + Le1*Le2) *1000;
  
  //cout << "x = " << x << " m" << endl;

  return x;
}

void Calcul_deviation()
{
  float x;
  
  //Definition of parameters
  float me = 9.1e-31; //kg
  float mp = 1.672e-27;

  //Defintion of variables
  float B = 0.3; //Tesla
  float E = 1.5E6; // V/m
  float Le1 = 0.25;
  float Le2 =0;
  float Lb1 = 0.;
  float Lb2 = 0;
  float D=0.25;
  float E_start = 300; //keV
  float E_end = 10000; //keV


  TFile* file = new TFile("test_deviation_E_1.5MVm.root");
  //TFile* file = new TFile("a.root");
  float a,c,d;
  TTree *Tree = (TTree*)file->Get("Tree_electron");
  float Entries = Tree->GetEntries();
  TH1F* histo_E = new TH1F("histo_B","histo_B", 10001, 0, 10000);
  TH1F* histo_B = new TH1F("histo_E","histo_E", 10001, 0, 10000);
  //TH2F* h = new TH2F("h","h", 10001, 0, 10000, 2000, 0, 200);

  for (int i=0; i<Entries; i++)
    {
      Tree->GetEntry(i);
      a = Tree->GetLeaf("E_start")->GetValue();
      c = Tree->GetLeaf("PositionX")->GetValue();
      d = Tree->GetLeaf("PositionY")->GetValue();
      //h->Fill(a,b);
      histo_B->SetBinContent(a, c);
      histo_E->SetBinContent(a, d);

    }

  //file->Close();
  //  file->Delete();

  int n=0;
  TGraph* g_E = new TGraph();
  TGraph* g_B = new TGraph();
  TGraph* g_err_E = new TGraph();
  TGraph* g_err_B = new TGraph();
  
  for (int i=E_start; i<E_end; i+=10)
    {
      x = deviation_B(mp, B, Le1, Le2, Lb1, Lb2, i); 
      g_B->SetPoint(n, i, -x);
      g_err_B->SetPoint(n, i, (g_B->Eval(i) - histo_B->Interpolate(i)));

      x = deviation_E(mp, E, Le1, Le2, Lb1, Lb2, i); 
      g_E->SetPoint(n, i, x);
      g_err_E->SetPoint(n, i, (g_E->Eval(i) - histo_E->Interpolate(i)));
      n++;
    }

  //cout << deviation_E(mp, E, D, 200) << endl;
  

  new TCanvas;
  histo_E->Draw("L");
  histo_E->SetLineColor(kRed);
  g_E->Draw("same");
  g_E->SetLineColor(kCyan);
  g_E->SetMarkerColor(kCyan);

  new TCanvas;
  g_err_E->Draw();
  
  new TCanvas;
  histo_B->Draw("L");
  histo_B->SetLineColor(kRed);
  g_B->Draw("same");
  g_B->SetLineColor(kCyan);
  g_B->SetMarkerColor(kCyan);

  new TCanvas;
  g_err_B->Draw();


  




}
