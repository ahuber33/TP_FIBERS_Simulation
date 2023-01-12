#include "/mnt/hgfs/Partage/Simulations/TP_Simulation/Resultats/Plot.hh"
#include <iostream>
#include <fstream>

using namespace std;

void Plot_C12()
{
  float c=0;
  float d=0;
  
  // ifstream file_Sc("Scintillateur_proton.txt");
  // float density_Sc = 1.032;
  // std::vector<float> vEnergy_Sc;
  // std::vector<float> vCSDA_Sc;
  // vEnergy_Sc.clear();
  // vCSDA_Sc.clear();
  // for (int i =0; i<132; i++){
  //   file_Sc >> c >> d;
  //   vEnergy_Sc.push_back(c);
  //   vCSDA_Sc.push_back(d/density_Sc);
  // }
  // file_Sc.close();



  
  //TGraph *gCSDA_Sc = new TGraph(vEnergy_Sc.size(), &vEnergy_Sc[0], &vCSDA_Sc[0]);


  TCanvas* c1 = new TCanvas;
  c1->SetLogy();
  c1->SetLogx();
  // gCSDA_Sc->SetLineColor(kCyan);
  // gCSDA_Sc->SetMarkerColor(kCyan);
  // gCSDA_Sc->Draw("");


  const int nfiles=8;
  const char* filenames_Sc[nfiles]=
    {
     "data/Scintillateur_C12_100keV.root",
     "data/Scintillateur_C12_500keV.root",
     "data/Scintillateur_C12_1000keV.root",
     "data/Scintillateur_C12_2000keV.root",
     "data/Scintillateur_C12_3000keV.root",
     "data/Scintillateur_C12_4000keV.root",
     "data/Scintillateur_C12_5000keV.root",
     "data/Scintillateur_C12_10000keV.root",
    };

    const char* filenames_Sc_Gas[nfiles]=
    {
     "data/Scintillateur_C12_Gas_100keV.root",
     "data/Scintillateur_C12_Gas_500keV.root",
     "data/Scintillateur_C12_Gas_1000keV.root",
     "data/Scintillateur_C12_Gas_2000keV.root",
     "data/Scintillateur_C12_Gas_3000keV.root",
     "data/Scintillateur_C12_Gas_4000keV.root",
     "data/Scintillateur_C12_Gas_5000keV.root",
     "data/Scintillateur_C12_Gas_10000keV.root",
    };


   const char* filenames_ZnS[nfiles]=
   {
    "data/ZnS_C12_100keV.root",
    "data/ZnS_C12_500keV.root",
    "data/ZnS_C12_1000keV.root",
    "data/ZnS_C12_2000keV.root",
    "data/ZnS_C12_3000keV.root",
    "data/ZnS_C12_4000keV.root",
    "data/ZnS_C12_5000keV.root",
    "data/ZnS_C12_10000keV.root",
   };


    
   TGraphErrors* f_Sc = ge(filenames_Sc, "Tree_electron", "E_start", "TotalLength", nfiles);
   TGraphErrors* f_Sc_Gas = ge(filenames_Sc_Gas, "Tree_electron", "E_start", "TotalLength", nfiles);
   //TGraphErrors* f_ZnS = ge(filenames_ZnS, "Tree_electron", "E_start", "TotalLength", nfiles);



  f_Sc->Draw("");
  f_Sc->SetMarkerStyle(8);
  f_Sc->SetMarkerSize(0.7);
  f_Sc->SetMarkerColor(kCyan);
  f_Sc->SetFillColor(kCyan);
  f_Sc->SetFillStyle(3002);
  f_Sc_Gas->Draw("PE3Same");
  f_Sc_Gas->SetMarkerStyle(8);
  f_Sc_Gas->SetMarkerSize(0.7);
  f_Sc_Gas->SetMarkerColor(kBlue);
  f_Sc_Gas->SetFillColor(kBlue);
  f_Sc_Gas->SetFillStyle(3002);
  // f_ZnS->Draw("PE3SAME");
  // f_ZnS->SetMarkerStyle(8);
  // f_ZnS->SetMarkerColor(kBlack);
  // f_ZnS->SetFillColor(kBlack);
  // f_ZnS->SetFillStyle(3005);
  
}
