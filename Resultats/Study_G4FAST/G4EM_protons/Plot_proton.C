#include "../Plot.hh"
#include <iostream>
#include <fstream>

using namespace std;

void Plot_proton()
{
  float c=0;
  float d=0;
  
  ifstream file_Alu("Alu_proton.txt");
  float density_Alu = 2.70;
  std::vector<float> vEnergy_Alu;
  std::vector<float> vCSDA_Alu;
  vEnergy_Alu.clear();
  vCSDA_Alu.clear();
  for (int i =0; i<132; i++){
    file_Alu >> c >> d;
    vEnergy_Alu.push_back(c);
    vCSDA_Alu.push_back(d/density_Alu);
    cout << "Energy = " << vEnergy_Alu.at(i) << " & CSDA = " << vCSDA_Alu.at(i) << endl;
  }
  file_Alu.close();

  ifstream file_Sc("Scintillateur_proton.txt");
  float density_Sc = 1.032;
  std::vector<float> vEnergy_Sc;
  std::vector<float> vCSDA_Sc;
  vEnergy_Sc.clear();
  vCSDA_Sc.clear();
  for (int i =0; i<132; i++){
    file_Sc >> c >> d;
    vEnergy_Sc.push_back(c);
    vCSDA_Sc.push_back(d/density_Sc);
  }
  file_Sc.close();


  ifstream file_Cu("Cuivre_proton.txt");
  float density_Cu = 8.96;
  std::vector<float> vEnergy_Cu;
  std::vector<float> vCSDA_Cu;
  vEnergy_Cu.clear();
  vCSDA_Cu.clear();
  for (int i =0; i<132; i++){
    file_Cu >> c >> d;
    vEnergy_Cu.push_back(c);
    vCSDA_Cu.push_back(d/density_Cu);
  }
  file_Cu.close();


  ifstream file_Si("Silicone_proton.txt");
  float density_Si = 2.33;
  std::vector<float> vEnergy_Si;
  std::vector<float> vCSDA_Si;
  vEnergy_Si.clear();
  vCSDA_Si.clear();
  for (int i =0; i<132; i++){
    file_Si >> c >> d;
    vEnergy_Si.push_back(c);
    vCSDA_Si.push_back(d/density_Si);
  }
  file_Si.close();


  // ifstream file_C("Carbon_electron.txt");
  // float density_C = 2.0;
  // std::vector<float> vEnergy_C;
  // std::vector<float> vCSDA_C;
  // vEnergy_C.clear();
  // vCSDA_C.clear();
  // for (int i =0; i<81; i++){
  //   file_C >> c >> d;
  //   vEnergy_C.push_back(c);
  //   vCSDA_C.push_back(d/density_C);
  // }
  // file_C.close();

  
  TGraph *gCSDA_Alu = new TGraph(vEnergy_Alu.size(), &vEnergy_Alu[0], &vCSDA_Alu[0]);
  TGraph *gCSDA_Sc = new TGraph(vEnergy_Sc.size(), &vEnergy_Sc[0], &vCSDA_Sc[0]);
  TGraph *gCSDA_Cu = new TGraph(vEnergy_Cu.size(), &vEnergy_Cu[0], &vCSDA_Cu[0]);
  TGraph *gCSDA_Si = new TGraph(vEnergy_Si.size(), &vEnergy_Si[0], &vCSDA_Si[0]);

  TCanvas* c1 = new TCanvas;
  c1->SetLogy();
  c1->SetLogx();
  gCSDA_Alu->SetLineColor(kGray);
  gCSDA_Sc->SetLineColor(kCyan);
  gCSDA_Sc->SetMarkerColor(kCyan);
  gCSDA_Cu->SetLineColor(kOrange);
  gCSDA_Si->SetLineColor(kGreen);
  gCSDA_Sc->Draw("");
  gCSDA_Alu->Draw("same");
  gCSDA_Cu->Draw("same");
  //gCSDA_Si->Draw("same");


  const int nfiles=13;
  const char* filenames_Sc[14]=
    {
     "data/Scintillateur_proton_10keV.root",
     "data/Scintillateur_proton_100keV.root",
     "data/Scintillateur_proton_250keV.root",
     "data/Scintillateur_proton_500keV.root",
     "data/Scintillateur_proton_750keV.root",
     "data/Scintillateur_proton_1000keV.root",
     "data/Scintillateur_proton_1500keV.root",
     "data/Scintillateur_proton_2000keV.root",
     "data/Scintillateur_proton_3000keV.root",
     "data/Scintillateur_proton_4000keV.root",
     "data/Scintillateur_proton_5000keV.root",
     "data/Scintillateur_proton_10000keV.root",
     "data/Scintillateur_proton_50000keV.root",
     "data/Scintillateur_proton_100000keV.root",
    };


    const char* filenames_Sc_new[13]=
    {
     "data/Scintillateur_proton_new_model_10keV.root",
     "data/Scintillateur_proton_new_model_100keV.root",
     "data/Scintillateur_proton_new_model_250keV.root",
     "data/Scintillateur_proton_new_model_500keV.root",
     "data/Scintillateur_proton_new_model_750keV.root",
     "data/Scintillateur_proton_new_model_1000keV.root",
     "data/Scintillateur_proton_new_model_1500keV.root",
     "data/Scintillateur_proton_new_model_2000keV.root",
     "data/Scintillateur_proton_new_model_3000keV.root",
     "data/Scintillateur_proton_new_model_4000keV.root",
     "data/Scintillateur_proton_new_model_5000keV.root",
     "data/Scintillateur_proton_new_model_10000keV.root",
     "data/Scintillateur_proton_new_model_50000keV.root",
     //"data/Scintillateur_proton_new_model_100000keV.root",
    };

  const char* filenames_Alu[nfiles]=
    {
     "data/Alu_proton_10keV.root",
     "data/Alu_proton_100keV.root",
     "data/Alu_proton_250keV.root",
     "data/Alu_proton_500keV.root",
     "data/Alu_proton_750keV.root",
     "data/Alu_proton_1000keV.root",
     "data/Alu_proton_1500keV.root",
     "data/Alu_proton_2000keV.root",
     "data/Alu_proton_3000keV.root",
     "data/Alu_proton_4000keV.root",
     "data/Alu_proton_5000keV.root",
     "data/Alu_proton_10000keV.root",
     "data/Alu_proton_50000keV.root",
    };


  const char* filenames_Cu[nfiles]=
    {
     "data/Cuivre_proton_10keV.root",
     "data/Cuivre_proton_100keV.root",
     "data/Cuivre_proton_250keV.root",
     "data/Cuivre_proton_500keV.root",
     "data/Cuivre_proton_750keV.root",
     "data/Cuivre_proton_1000keV.root",
     "data/Cuivre_proton_1500keV.root",
     "data/Cuivre_proton_2000keV.root",
     "data/Cuivre_proton_3000keV.root",
     "data/Cuivre_proton_4000keV.root",
     "data/Cuivre_proton_5000keV.root",
     "data/Cuivre_proton_10000keV.root",
     "data/Cuivre_proton_50000keV.root",
    };
   

   const char* filenames_ZnS[nfiles]=
   {
    "data/ZnS_proton_10keV.root",
    "data/ZnS_proton_100keV.root",
    "data/ZnS_proton_250keV.root",
    "data/ZnS_proton_500keV.root",
    "data/ZnS_proton_750keV.root",
    "data/ZnS_proton_1000keV.root",
    "data/ZnS_proton_1500keV.root",
    "data/ZnS_proton_2000keV.root",
    "data/ZnS_proton_3000keV.root",
    "data/ZnS_proton_4000keV.root",
    "data/ZnS_proton_5000keV.root",
    "data/ZnS_proton_10000keV.root",
    "data/ZnS_proton_50000keV.root"
   };

    
  //TGraphErrors* test = ge(filenames, "Tree_electron", "E_start", nfiles);
  // TGraphErrors* f_Silicone = ge(filenames_Silicone, "Tree_electron", "E_start", "TotalLength", nfiles);
   TGraphErrors* f_Alu = ge(filenames_Alu, "Tree_electron", "E_start", "TotalLength", 13);
   TGraphErrors* f_Sc_new = ge(filenames_Sc, "Tree_electron", "E_start", "TotalLength", 13);
   TGraphErrors* f_Cu = ge(filenames_Cu, "Tree_electron", "E_start", "TotalLength", 13);
   //TGraphErrors* f_ZnS = ge(filenames_ZnS, "Tree_electron", "E_start", "TotalLength", nfiles);
    
  //new TCanvas;
  // f_Silicone->Draw("PE3Same");
  // f_Silicone->SetMarkerStyle(8);
  // f_Silicone->SetMarkerSize(0.7);
  // f_Silicone->SetMarkerColor(kGray);
  // f_Silicone->SetFillColor(kGray);
  // f_Silicone->SetFillStyle(3002);
  f_Alu->Draw("PE3Same");
  f_Alu->SetMarkerStyle(8);
  f_Alu->SetMarkerSize(0.7);
  f_Alu->SetMarkerColor(kCyan);
  f_Alu->SetFillColor(kCyan);
  f_Alu->SetFillStyle(3002);
  f_Sc_new->Draw("PE3Same");
  f_Sc_new->SetMarkerStyle(8);
  f_Sc_new->SetMarkerSize(0.7);
  f_Sc_new->SetMarkerColor(kBlue);
  f_Sc_new->SetFillColor(kBlue);
  f_Sc_new->SetFillStyle(3002);
  f_Cu->Draw("PE3Same");
  f_Cu->SetMarkerStyle(8);
  f_Cu->SetMarkerSize(0.7);
  f_Cu->SetMarkerColor(kOrange);
  f_Cu->SetFillColor(kOrange);
  f_Cu->SetFillStyle(3002);
  //f_ZnS->Draw("PE3Same");
  //f_ZnS->SetMarkerStyle(8);
  //f_ZnS->SetMarkerColor(kBlack);
  //f_ZnS->SetFillColor(kBlack);
  //f_ZnS->SetFillStyle(3005);


    auto legend = new TLegend(0.1,0.7,0.48,0.9);
  legend->AddEntry(gCSDA_Sc,"Scintillator data from estar","l");
  legend->AddEntry(f_Sc_new,"Scintillator Simulation","p");
  legend->AddEntry(gCSDA_Alu,"Aluminium data from estar","l");
  legend->AddEntry(f_Alu,"Aluminium Simulation","p");
  legend->AddEntry(gCSDA_Cu,"Copper data from estar","l");
  legend->AddEntry(f_Cu,"Copper Simulation","p");
  legend->Draw();

  
  
}
