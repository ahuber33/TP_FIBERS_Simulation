#include "/home/local1/Simulations/TP_Simulation/Resultats/Plot.hh"
#include <iostream>
#include <fstream>

using namespace std;

void Plot_part_Sc_ZnS()
{
  
  const int nfiles=14;
  
  const char* filenames_Sc_proton[nfiles]=
    {
     "G4EM_protons/data/Scintillateur_proton_10keV.root",
     "G4EM_protons/data/Scintillateur_proton_100keV.root",
     "G4EM_protons/data/Scintillateur_proton_250keV.root",
     "G4EM_protons/data/Scintillateur_proton_500keV.root",
     "G4EM_protons/data/Scintillateur_proton_750keV.root",
     "G4EM_protons/data/Scintillateur_proton_1000keV.root",
     "G4EM_protons/data/Scintillateur_proton_1500keV.root",
     "G4EM_protons/data/Scintillateur_proton_2000keV.root",
     "G4EM_protons/data/Scintillateur_proton_3000keV.root",
     "G4EM_protons/data/Scintillateur_proton_4000keV.root",
     "G4EM_protons/data/Scintillateur_proton_5000keV.root",
     "G4EM_protons/data/Scintillateur_proton_10000keV.root",
     "G4EM_protons/data/Scintillateur_proton_50000keV.root",
     "G4EM_protons/data/Scintillateur_proton_100000keV.root"
    };

  
  const char* filenames_ZnS_proton[13]=
    {
     "G4EM_protons/data/ZnS_proton_10keV.root",
     "G4EM_protons/data/ZnS_proton_100keV.root",
     "G4EM_protons/data/ZnS_proton_250keV.root",
     "G4EM_protons/data/ZnS_proton_500keV.root",
     "G4EM_protons/data/ZnS_proton_750keV.root",
     "G4EM_protons/data/ZnS_proton_1000keV.root",
     "G4EM_protons/data/ZnS_proton_1500keV.root",
     "G4EM_protons/data/ZnS_proton_2000keV.root",
     "G4EM_protons/data/ZnS_proton_3000keV.root",
     "G4EM_protons/data/ZnS_proton_4000keV.root",
     "G4EM_protons/data/ZnS_proton_5000keV.root",
     "G4EM_protons/data/ZnS_proton_10000keV.root",
     "G4EM_protons/data/ZnS_proton_50000keV.root",
     //     "G4EM_protons/data/ZnS_proton_100000keV.root"
    };


    const char* filenames_Sc_alpha[nfiles]=
    {
     "G4EM_alpha/data/Scintillateur_alpha_10keV.root",
     "G4EM_alpha/data/Scintillateur_alpha_100keV.root",
     "G4EM_alpha/data/Scintillateur_alpha_250keV.root",
     "G4EM_alpha/data/Scintillateur_alpha_500keV.root",
     "G4EM_alpha/data/Scintillateur_alpha_750keV.root",
     "G4EM_alpha/data/Scintillateur_alpha_1000keV.root",
     "G4EM_alpha/data/Scintillateur_alpha_1500keV.root",
     "G4EM_alpha/data/Scintillateur_alpha_2000keV.root",
     "G4EM_alpha/data/Scintillateur_alpha_3000keV.root",
     "G4EM_alpha/data/Scintillateur_alpha_4000keV.root",
     "G4EM_alpha/data/Scintillateur_alpha_5000keV.root",
     "G4EM_alpha/data/Scintillateur_alpha_10000keV.root",
     "G4EM_alpha/data/Scintillateur_alpha_50000keV.root",
     "G4EM_alpha/data/Scintillateur_alpha_100000keV.root"
    };

  
  const char* filenames_ZnS_alpha[nfiles]=
    {
     "G4EM_alpha/data/ZnS_alpha_10keV.root",
     "G4EM_alpha/data/ZnS_alpha_100keV.root",
     "G4EM_alpha/data/ZnS_alpha_250keV.root",
     "G4EM_alpha/data/ZnS_alpha_500keV.root",
     "G4EM_alpha/data/ZnS_alpha_750keV.root",
     "G4EM_alpha/data/ZnS_alpha_1000keV.root",
     "G4EM_alpha/data/ZnS_alpha_1500keV.root",
     "G4EM_alpha/data/ZnS_alpha_2000keV.root",
     "G4EM_alpha/data/ZnS_alpha_3000keV.root",
     "G4EM_alpha/data/ZnS_alpha_4000keV.root",
     "G4EM_alpha/data/ZnS_alpha_5000keV.root",
     "G4EM_alpha/data/ZnS_alpha_10000keV.root",
     "G4EM_alpha/data/ZnS_alpha_50000keV.root",
     "G4EM_alpha/data/ZnS_alpha_100000keV.root"
    };


  const char* filenames_Sc_C12[7]=
    {
     "G4EM_C12/data/Scintillateur_C12_2000keV.root",
     "G4EM_C12/data/Scintillateur_C12_3000keV.root",
     "G4EM_C12/data/Scintillateur_C12_4000keV.root",
     "G4EM_C12/data/Scintillateur_C12_5000keV.root",
     "G4EM_C12/data/Scintillateur_C12_10000keV.root",
     "G4EM_C12/data/Scintillateur_C12_50000keV.root",
     "G4EM_C12/data/Scintillateur_C12_100000keV.root"
    };

  
  const char* filenames_ZnS_C12[8]=
    {
     "G4EM_C12/data/ZnS_C12_100keV.root",
     "G4EM_C12/data/ZnS_C12_500keV.root",
     "G4EM_C12/data/ZnS_C12_1000keV.root",
     "G4EM_C12/data/ZnS_C12_2000keV.root",
     "G4EM_C12/data/ZnS_C12_3000keV.root",
     "G4EM_C12/data/ZnS_C12_4000keV.root",
     "G4EM_C12/data/ZnS_C12_5000keV.root",
     "G4EM_C12/data/ZnS_C12_10000keV.root",
     //"G4EM_C12/data/ZnS_C12_50000keV.root",
     //"G4EM_C12/data/ZnS_C12_100000keV.root"
    };



  TGraphErrors* f_Sc_proton = ge(filenames_Sc_proton, "Tree_electron", "E_start", "TotalLength", nfiles);
  TGraphErrors* f_ZnS_proton = ge(filenames_ZnS_proton, "Tree_electron", "E_start", "TotalLength", 13);
  TGraphErrors* f_Sc_alpha = ge(filenames_Sc_alpha, "Tree_electron", "E_start", "TotalLength", nfiles);
  TGraphErrors* f_ZnS_alpha = ge(filenames_ZnS_alpha, "Tree_electron", "E_start", "TotalLength", nfiles);
  TGraphErrors* f_Sc_C12 = ge(filenames_Sc_C12, "Tree_electron", "E_start", "TotalLength", 7);
  TGraphErrors* f_ZnS_C12 = ge(filenames_ZnS_C12, "Tree_electron", "E_start", "TotalLength", 8);
    

  TCanvas* c1 = new TCanvas;
  c1->SetLogy();
  c1->SetLogx();
  f_Sc_proton->Draw("");
  f_Sc_proton->SetMarkerStyle(8);
  f_Sc_proton->SetMarkerSize(0.7);
  f_Sc_proton->SetMarkerColor(kBlue);
  f_Sc_proton->SetFillColor(kBlue);
  f_Sc_proton->SetFillStyle(3002);

  f_ZnS_proton->Draw("PE3same");
  f_ZnS_proton->SetMarkerStyle(8);
  f_ZnS_proton->SetMarkerSize(0.7);
  f_ZnS_proton->SetMarkerColor(kRed);
  f_ZnS_proton->SetFillColor(kRed);
  f_ZnS_proton->SetFillStyle(3002);

  f_Sc_alpha->Draw("PE3same");
  f_Sc_alpha->SetMarkerStyle(21);
  f_Sc_alpha->SetMarkerSize(0.7);
  f_Sc_alpha->SetMarkerColor(kBlue);
  f_Sc_alpha->SetFillColor(kBlue);
  f_Sc_alpha->SetFillStyle(3002);

  f_ZnS_alpha->Draw("PE3same");
  f_ZnS_alpha->SetMarkerStyle(21);
  f_ZnS_alpha->SetMarkerSize(0.7);
  f_ZnS_alpha->SetMarkerColor(kRed);
  f_ZnS_alpha->SetFillColor(kRed);
  f_ZnS_alpha->SetFillStyle(3002);

  // f_Sc_C12->Draw("PE3same");
  // f_Sc_C12->SetMarkerStyle(22);
  // f_Sc_C12->SetMarkerSize(0.7);
  // f_Sc_C12->SetMarkerColor(kBlue);
  // f_Sc_C12->SetFillColor(kBlue);
  // f_Sc_C12->SetFillStyle(3002);

  // f_ZnS_C12->Draw("PE3same");
  // f_ZnS_C12->SetMarkerStyle(22);
  // f_ZnS_C12->SetMarkerSize(0.7);
  // f_ZnS_C12->SetMarkerColor(kRed);
  // f_ZnS_C12->SetFillColor(kRed);
  // f_ZnS_C12->SetFillStyle(3002);
  

  auto legend = new TLegend(0.1,0.7,0.48,0.9);
  //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
  legend->AddEntry(f_Sc_proton,"Scintillator proton","p");
  legend->AddEntry(f_ZnS_proton,"ZnS proton","p");
  legend->AddEntry(f_Sc_alpha,"Scintillator alpha","p");
  legend->AddEntry(f_ZnS_alpha,"ZnS alpha","p");
  //legend->AddEntry(f_Sc_C12,"Scintillator C12","p");
  //legend->AddEntry(f_ZnS_C12,"ZnS C12","p");
  legend->Draw();


  
  
}
