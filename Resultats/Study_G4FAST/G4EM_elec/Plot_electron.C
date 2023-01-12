#include "../Plot.hh"
#include <iostream>
#include <fstream>

using namespace std;

void Plot_electron()
{
  string Path = "Alu_500keV.root";

  //int a =0;
  //a = Compteur(Path);

  ifstream file_Alu("Aluminium_electron.txt");
  float density_Alu = 2.70;
  float c=0;
  float d=0;
  std::vector<float> vEnergy_Alu;
  std::vector<float> vCSDA_Alu;
  vEnergy_Alu.clear();
  vCSDA_Alu.clear();
  for (int i =0; i<81; i++){
    file_Alu >> c >> d;
    vEnergy_Alu.push_back(c);
    vCSDA_Alu.push_back(d/density_Alu);
    //cout << "Energy = " << vEnergy.at(i) << " & CSDA = " << vCSDA.at(i) << endl;
  }
  file_Alu.close();

  ifstream file_Sc("Scintillator_electron.txt");
  float density_Sc = 1.032;
  std::vector<float> vEnergy_Sc;
  std::vector<float> vCSDA_Sc;
  vEnergy_Sc.clear();
  vCSDA_Sc.clear();
  for (int i =0; i<81; i++){
    file_Sc >> c >> d;
    vEnergy_Sc.push_back(c);
    vCSDA_Sc.push_back(d/density_Sc);
  }
  file_Sc.close();


  ifstream file_Cu("Cuivre_electron.txt");
  float density_Cu = 8.96;
  std::vector<float> vEnergy_Cu;
  std::vector<float> vCSDA_Cu;
  vEnergy_Cu.clear();
  vCSDA_Cu.clear();
  for (int i =0; i<81; i++){
    file_Cu >> c >> d;
    vEnergy_Cu.push_back(c);
    vCSDA_Cu.push_back(d/density_Cu);
  }
  file_Cu.close();


  ifstream file_C("Carbon_electron.txt");
  float density_C = 2.0;
  std::vector<float> vEnergy_C;
  std::vector<float> vCSDA_C;
  vEnergy_C.clear();
  vCSDA_C.clear();
  for (int i =0; i<81; i++){
    file_C >> c >> d;
    vEnergy_C.push_back(c);
    vCSDA_C.push_back(d/density_C);
  }
  file_C.close();

  
  TGraph *gCSDA_Alu = new TGraph(vEnergy_Alu.size(), &vEnergy_Alu[0], &vCSDA_Alu[0]);
  TGraph *gCSDA_Sc = new TGraph(vEnergy_Sc.size(), &vEnergy_Sc[0], &vCSDA_Sc[0]);
  TGraph *gCSDA_Cu = new TGraph(vEnergy_Cu.size(), &vEnergy_Cu[0], &vCSDA_Cu[0]);
  TGraph *gCSDA_C = new TGraph(vEnergy_C.size(), &vEnergy_C[0], &vCSDA_C[0]);

  new TCanvas;
  gCSDA_Alu->SetLineColor(kGray);
  gCSDA_Sc->SetLineColor(kCyan);
  gCSDA_Cu->SetLineColor(kOrange);
  gCSDA_C->SetLineColor(kBlack);
  gCSDA_Sc->Draw("");
  gCSDA_Alu->Draw("same");
  gCSDA_Cu->Draw("same");
  //gCSDA_C->Draw("same");


  //  float Mean_Alu_1000keV = Mean("Scintillateur_1000keV.root", "Tree_electron","TotalLength");
  //float Sigma_Alu_1000keV = Sigma("Scintillateur_1000keV.root", "Tree_electron","TotalLength", Mean_Alu_1000keV);

  const int nfiles=13;
  const char* filenames_Sc[nfiles]=
    {
     "data/Scintillateur_10keV.root",
     "data/Scintillateur_100keV.root",
     "data/Scintillateur_250keV.root",
     "data/Scintillateur_500keV.root",
     "data/Scintillateur_750keV.root",
     "data/Scintillateur_1000keV.root",
     "data/Scintillateur_1500keV.root",
     "data/Scintillateur_2000keV.root",
     "data/Scintillateur_3000keV.root",
     "data/Scintillateur_4000keV.root",
     "data/Scintillateur_5000keV.root",
     "data/Scintillateur_10000keV.root",
     "data/Scintillateur_50000keV.root"
    };

    const char* filenames_Alu[nfiles]=
    {
     "data/Alu_10keV.root",
     "data/Alu_100keV.root",
     "data/Alu_250keV.root",
     "data/Alu_500keV.root",
     "data/Alu_750keV.root",
     "data/Alu_1000keV.root",
     "data/Alu_1500keV.root",
     "data/Alu_2000keV.root",
     "data/Alu_3000keV.root",
     "data/Alu_4000keV.root",
     "data/Alu_5000keV.root",
     "data/Alu_10000keV.root",
     "data/Alu_50000keV.root"
    };


    const char* filenames_Cu[nfiles]=
    {
     "data/Cuivre_10keV.root",
     "data/Cuivre_100keV.root",
     "data/Cuivre_250keV.root",
     "data/Cuivre_500keV.root",
     "data/Cuivre_750keV.root",
     "data/Cuivre_1000keV.root",
     "data/Cuivre_1500keV.root",
     "data/Cuivre_2000keV.root",
     "data/Cuivre_3000keV.root",
     "data/Cuivre_4000keV.root",
     "data/Cuivre_5000keV.root",
     "data/Cuivre_10000keV.root",
     "data/Cuivre_50000keV.root"
    };


    const char* filenames_C[nfiles]=
    {
     "data/Carbon_10keV.root",
     "data/Carbon_100keV.root",
     "data/Carbon_250keV.root",
     "data/Carbon_500keV.root",
     "data/Carbon_750keV.root",
     "data/Carbon_1000keV.root",
     "data/Carbon_1500keV.root",
     "data/Carbon_2000keV.root",
     "data/Carbon_3000keV.root",
     "data/Carbon_4000keV.root",
     "data/Carbon_5000keV.root",
     "data/Carbon_10000keV.root",
     "data/Carbon_50000keV.root"
    };

    
  //TGraphErrors* test = ge(filenames, "Tree_electron", "E_start", nfiles);
  TGraphErrors* f_Alu = ge(filenames_Alu, "Tree_electron", "E_start", "TotalLength", nfiles);
  TGraphErrors* f_Sc = ge(filenames_Sc, "Tree_electron", "E_start", "TotalLength", nfiles);
  TGraphErrors* f_Cu = ge(filenames_Cu, "Tree_electron", "E_start", "TotalLength", nfiles);
  TGraphErrors* f_C = ge(filenames_C, "Tree_electron", "E_start", "TotalLength", nfiles);
    
  //new TCanvas;
  f_Alu->Draw("PE3Same");
  f_Alu->SetMarkerStyle(8);
  f_Alu->SetMarkerColor(kGray);
  f_Alu->SetFillColor(kGray);
  f_Alu->SetFillStyle(3005);
  f_Sc->Draw("PE3Same");
  f_Sc->SetMarkerStyle(8);
  f_Sc->SetMarkerColor(kCyan);
  f_Sc->SetFillColor(kCyan);
  f_Sc->SetFillStyle(3005);
  f_Cu->Draw("PE3Same");
  f_Cu->SetMarkerStyle(8);
  f_Cu->SetMarkerColor(kOrange);
  f_Cu->SetFillColor(kOrange);
  f_Cu->SetFillStyle(3005);
  // f_C->Draw("PE3Same");
  // f_C->SetMarkerStyle(8);
  // f_C->SetMarkerColor(kBlack);
  // f_C->SetFillColor(kBlack);
  // f_C->SetFillStyle(3005);


  auto legend = new TLegend(0.1,0.7,0.48,0.9);
  legend->AddEntry(gCSDA_Sc,"Scintillator data from estar","l");
  legend->AddEntry(f_Sc,"Scintillator Simulation","p");
  legend->AddEntry(gCSDA_Alu,"Aluminium data from estar","l");
  legend->AddEntry(f_Alu,"Aluminium Simulation","p");
  legend->AddEntry(gCSDA_Cu,"Copper data from estar","l");
  legend->AddEntry(f_Cu,"Copper Simulation","p");
  legend->Draw();
  
  
}
