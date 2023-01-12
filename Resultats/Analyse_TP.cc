#include "Analyse_TP.hh"
//#include "Analyse_TP_backup_first_study.hh"


void Analyse_TP()
{
  gStyle->SetOptStat("");
  gROOT->ProcessLine("#include <vector>");

  float mp = 1.6726e-27; //kg
  float mHe = 4.0026*1.66054e-27;
  float qp = 1.6e-19; //C

  string file_proton = "Pinhole_variation/proton_pinhole.root";
  string file_He1 = "Pinhole_variation/He1+_pinhole.root";
  string file_He2 = "Pinhole_variation/He2+_pinhole.root";
  float pinhole =0.1;
  float B = 0.3; //T
  float E = 1.5e+6; //V/m
  float Le1 = 0.15; //m
  float Le2 = 0.155; //m
  float D = 5e-3; //m
  float Lb1 = 0.05; //m
  float Lb2 = 0.310; //m
  float Sc_length = 0.1; //m
  float Sc_thickness = 100e-6; //m
  float ZnS_thickness = 100e-6; //m
  string Optique_Yes = "Yes";
  string Optique_No = "No";
  bool Optique = false;

  //Analyse("proton_pinhole_200um.root", "He1+_pinhole_200um.root", "He2+_pinhole_200um.root", "TP", "pinhole 200 um", 0.2, B, E, 50, 5, 150, 155, 100, 1, 0.1, false, -15, -10, -2.9, 2);
  //Analyse("proton_pinhole_150um.root", "He1+_pinhole_150um.root", "He2+_pinhole_150um.root", "TP", "pinhole 150 um", 0.15, B, E, 50, 5, 150, 155, 100, 1, 0.1, false, -15, -10, -3, 1.2);
  //Analyse(file_proton.c_str(), file_He1.c_str(), file_He2.c_str(), "TP", "pinhole 100 um", pinhole, B, E, 150, 5, 50, 310, 100, 1, 0., false, -15, -10, -3.1, 1.5);
  //Analyse("proton_pinhole_75um.root", "He1+_pinhole_75um.root", "He2+_pinhole_75um.root", "TP", "pinhole 75 um", 0.075, B, E, 50, 5, 150, 155, 100, 1, 0.1, false, -15, -8, -3.2, 1.3);
  //Analyse("proton_pinhole_50um.root", "He1+_pinhole_50um.root", "He2+_pinhole_50um.root", "TP", "pinhole 50 um", 0.05, B, E, 50, 5, 150, 155, 100, 1, 0.1, false, -15, -8, -3.2, 2);
  //Analyse("proton_pinhole_100um_B_0.6T.root", "He1+_pinhole_100um_B_0.6T.root", "He2+_pinhole_100um_B_0.6T.root", "TP", "pinhole 100 um - B 0.6T", 0.1, 0.6, E, 50, 5, 150, 155, 100, 1, 0.1, false, -15, -10, -3, 1.6);
  //Analyse("proton_pinhole_100um_B_0.9T.root", "He1+_pinhole_100um_B_0.9T.root", "He2+_pinhole_100um_B_0.9T.root", "TP", "pinhole 100 um - B 0.9T", 0.1, 0.9, E, 50, 5, 150, 155, 100, 1, 0.1, false, -15, -15, -9.9, 1.5);
  //Analyse("proton_Config_TP_existante.root", "He1+_Config_TP_existante.root", "He2+_Config_TP_existante.root", "TP", "Config TP existante pinhole 100um", 0.1, 0.6, E, 50.8, 8.45, 40, 108.85, 100, 1, 0.1, false, -20, -10, -3.5, 1);
  //Analyse("proton_Config_TP_ENL_1MeV_10MeV.root", "He1+_Config_TP_ENL_1MeV_10MeV.root", "He2+_Config_TP_ENL_1MeV_10MeV.root", "TP", "Config TP existante pinhole 100um", 0.1, 0.6, 630000, 50., 0, 40, 175, 200, 0, 0., false, -25, -17, -15.5, 1.1);
  //Analyse("proton_Config_TP_ENL_ZnS_0.1_1MeV_10MeV.root", "He1+_Config_TP_ENL_ZnS_0.1_1MeV_10MeV.root", "He2+_Config_TP_ENL_ZnS_0.1_1MeV_10MeV.root", "Optical", "Config TP existante pinhole 100um with ZnS 0.1mm", 0.1, 0.6, 630000, 50., 0, 40, 175, 200, 0., 0.1, true, -25, -17, -15.8, 1.3);
  Analyse("proton_Config_TP_ELFEX_new.root", "He1+_Config_TP_ELFEX_new.root", "He2+_Config_TP_ELFEX_new.root", "TP", "Config TP ELFEX new", 0.3, 0.8, 1200000, 150., 20, 175, 200, 400, 0, 0., false, -100, -70, -52, 3.5);
  Analyse("proton_Config_TP_PETAL.root", "He1+_Config_TP_PETAL.root", "He2+_Config_TP_PETAL.root", "TP", "Config TP PETAL", 0.5, 0.5, 1400000, 62.5, 20.75, 262.1, 745.9, 400, 0, 0., false, -28, -25, -14.8, 6);
  Analyse("proton_Config_TP_PETAL_Exp.root", "He1+_Config_TP_PETAL_Exp.root", "He2+_Config_TP_PETAL_Exp.root", "TP", "Config TP PETAL Exp", 0.5, 0.5, 1400000, 62.5, 20.75, 262.1, 745.9, 400, 0, 0., false, -40, -40, -25, 6);
  Analyse("proton_Config_TP_PETAL_Exp_pinhole_1mm.root", "He1+_Config_TP_PETAL_Exp_pinhole_1mm.root", "He2+_Config_TP_PETAL_Exp_pinhole_1mm.root", "TP", "Config TP PETAL Exp pinhole 1mm", 1, 0.5, 1400000, 62.5, 20.75, 262.1, 745.9, 400, 0, 0., false, -40, -40, -25, 6);
  Analyse("proton_Config_TP_PETAL_pinhole_1mm.root", "He1+_Config_TP_PETAL_pinhole_1mm.root", "He2+_Config_TP_PETAL_pinhole_1mm.root", "TP", "Config TP PETAL pinhole 1mm", 1, 0.5, 1400000, 62.5, 20.75, 262.1, 745.9, 400, 0, 0., false, -30, -25, -15, 6);
  //Analyse("proton_pinhole_100um_B_0.6T_E_1000kV.root", "He1+_pinhole_100um_B_0.6T_E_1000kV.root", "He2+_pinhole_100um_B_0.6T_E_1000kV.root", "TP", "pinhole 100 um - B 0.6T - E 1000 kV/m", 0.1, 0.6, 1e6, 50, 5, 150, 155, 100, 1, 0.1, false, -15, -9, -6.5, 1.4);
  //Analyse("proton_pinhole_100um_B_0.6T_E_2000kV.root", "He1+_pinhole_100um_B_0.6T_E_2000kV.root", "He2+_pinhole_100um_B_0.6T_E_2000kV.root", "TP", "pinhole 100 um - B 0.6T - E 2000 kV/m", 0.1, 0.6, 2e6, 50, 5, 150, 155, 100, 1, 0.1, false, -15, -10, -3, 1.6);
  //Analyse("proton_pinhole_100um_B_0.6T_E_2000kV_Le1_300.root", "He1+_pinhole_100um_B_0.6T_E_2000kV_Le1_300.root", "He2+_pinhole_100um_B_0.6T_E_2000kV_Le1_300.root", "TP", "pinhole 100 um - B 0.6T - E 2000 kV/m - Le1 300 mm", 0.1, 0.6, 2e6, 50, 5, 300, 150, 100, 1, 0.1, false, -15, -10, -3, 2);
  //Analyse("proton_pinhole_100um_B_0.6T_E_2000kV_Le1_300_Optique.root", "He1+_pinhole_100um_B_0.6T_E_2000kV_Le1_300_Optique.root", "He2+_pinhole_100um_B_0.6T_E_2000kV_Le1_300_Optique.root", "Optical", "pinhole 100 um - B 0.6T - E 2000 kV/m - Le1 300 mm Optical", 0.1, 0.6, 2e6, 50, 5, 150, 300, 100, 1, 0., true, -15, -11, -9.5, 2);
  //Analyse("proton_pinhole_200um_B_0.6T_E_2000kV_Le1_300.root", "He1+_pinhole_200um_B_0.6T_E_2000kV_Le1_300.root", "He2+_pinhole_200um_B_0.6T_E_2000kV_Le1_300.root", "TP", "pinhole 200 um - B 0.6T - E 2000 kV/m - Le1 300 mm", 0.2, 0.6, 2e6, 50, 5, 150, 300, 100, 1, 0.1, false, -15, -10, -3, 2);
  //Analyse("proton_ligne_Optique_div10_0.1_0.1.root", "He1+_ligne_Optique_div10_0.1_0.1.root", "He2+_ligne_Optique_div10_0.1_0.1.root", "Optical", "Optical ligne", 0, B, E, 50, 5, 150, 155, 100, 0.1, 0.1, true, -8, -5, -3.1, 2);
  //Analyse("proton_E_1000_B_0.3_pinhole_0.1_Le1_150_Le2_150.root", "He1+_E_1000_B_0.3_pinhole_0.1_Le1_150_Le2_150.root", "He2+_E_1000_B_0.3_pinhole_0.1_Le1_150_Le2_150.root", "TP", "pinhole 100 um - B 0.3T - E 1000 kV/m - Le1 150 mm Le2 150 mm", 0.1, 0.3, 1e6, 50, 5, 150, 150, 100, 1, 0., false, -10, -8, -3, 1.7);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_150_Le2_150.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_150_Le2_150.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_150_Le2_150.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 150 mm Le2 150 mm", 0.1, 0.3, 1.5e6, 50, 5, 150, 150, 100, 1, 0., false, -10, -7, -3, 1.4);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_150_Le2_150.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_150_Le2_150.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_150_Le2_150.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 150 mm Le2 150 mm", 0.1, 0.3, 2e6, 50, 5, 150, 150, 100, 1, 0., false, -10, -6, -3, 1.4);
  //Analyse("proton_E_1000_B_0.6_pinhole_0.1_Le1_150_Le2_150.root", "He1+_E_1000_B_0.6_pinhole_0.1_Le1_150_Le2_150.root", "He2+_E_1000_B_0.6_pinhole_0.1_Le1_150_Le2_150.root", "TP", "pinhole 100 um - B 0.6T - E 1000 kV/m - Le1 150 mm Le2 150 mm", 0.1, 0.6, 1e6, 50, 5, 150, 150, 100, 1, 0., false, -11.5, -9, -6.5, 1.5);
  //Analyse("proton_E_1500_B_0.6_pinhole_0.1_Le1_150_Le2_150.root", "He1+_E_1500_B_0.6_pinhole_0.1_Le1_150_Le2_150.root", "He2+_E_1500_B_0.6_pinhole_0.1_Le1_150_Le2_150.root", "TP", "pinhole 100 um - B 0.6T - E 1500 kV/m - Le1 150 mm Le2 150 mm", 0.1, 0.6, 1.5e6, 50, 5, 150, 150, 100, 1, 0., false, -11.5, -9, -6.5, 1.2);
  //Analyse("proton_E_2000_B_0.6_pinhole_0.1_Le1_150_Le2_150.root", "He1+_E_2000_B_0.6_pinhole_0.1_Le1_150_Le2_150.root", "He2+_E_2000_B_0.6_pinhole_0.1_Le1_150_Le2_150.root", "TP", "pinhole 100 um - B 0.6T - E 2000 kV/m - Le1 150 mm Le2 150 mm", 0.1, 0.6, 2e6, 50, 5, 150, 150, 100, 1, 0., false, -11.5, -9, -6.5, 1.2);
  //Analyse("proton_E_1000_B_0.9_pinhole_0.1_Le1_150_Le2_150.root", "He1+_E_1000_B_0.9_pinhole_0.1_Le1_150_Le2_150.root", "He2+_E_1000_B_0.9_pinhole_0.1_Le1_150_Le2_150.root", "TP", "pinhole 100 um - B 0.9T - E 1000 kV/m - Le1 150 mm Le2 150 mm", 0.1, 0.9, 1e6, 50, 5, 150, 150, 100, 1, 0., false, -20, -15, -9.9, 1.3);
  //Analyse("proton_E_1500_B_0.9_pinhole_0.1_Le1_150_Le2_150.root", "He1+_E_1500_B_0.9_pinhole_0.1_Le1_150_Le2_150.root", "He2+_E_1500_B_0.9_pinhole_0.1_Le1_150_Le2_150.root", "TP", "pinhole 100 um - B 0.9T - E 1500 kV/m - Le1 150 mm Le2 150 mm", 0.1, 0.9, 1.5e6, 50, 5, 150, 150, 100, 1, 0., false, -20, -15, -9.9, 1.6);
  //Analyse("proton_E_2000_B_0.9_pinhole_0.1_Le1_150_Le2_150.root", "He1+_E_2000_B_0.9_pinhole_0.1_Le1_150_Le2_150.root", "He2+_E_2000_B_0.9_pinhole_0.1_Le1_150_Le2_150.root", "TP", "pinhole 100 um - B 0.9T - E 2000 kV/m - Le1 150 mm Le2 150 mm", 0.1, 0.9, 2e6, 50, 5, 150, 150, 100, 1, 0., false, -20, -11, -9.9, 1.2);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_225_Le2_150.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_225_Le2_150.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_225_Le2_150.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 225 mm Le2 150 mm", 0.1, 0.3, 1.5e6, 50, 5, 225, 150, 100, 1, 0., false, -10, -7, -3.9, 1.1);
  //Analyse("proton_E_1500_B_0.6_pinhole_0.1_Le1_225_Le2_150.root", "He1+_E_1500_B_0.6_pinhole_0.1_Le1_225_Le2_150.root", "He2+_E_1500_B_0.6_pinhole_0.1_Le1_225_Le2_150.root", "TP", "pinhole 100 um - B 0.6T - E 1500 kV/m - Le1 225 mm Le2 150 mm", 0.1, 0.6, 1.5e6, 50, 5, 225, 150, 100, 1, 0., false, -15, -10, -8, 1.5);
  //Analyse("proton_E_1500_B_0.9_pinhole_0.1_Le1_225_Le2_150.root", "He1+_E_1500_B_0.9_pinhole_0.1_Le1_225_Le2_150.root", "He2+_E_1500_B_0.9_pinhole_0.1_Le1_225_Le2_150.root", "TP", "pinhole 100 um - B 0.9T - E 1500 kV/m - Le1 225 mm Le2 150 mm", 0.1, 0.9, 1.5e6, 50, 5, 225, 150, 100, 1, 0., false, -20, -15, -12.2, 1.2);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_300_Le2_150.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_300_Le2_150.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_300_Le2_150.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 300 mm Le2 150 mm", 0.1, 0.3, 1.5e6, 50, 5, 300, 150, 100, 1, 0., false, -10, -6, -4.7, 2);
  //Analyse("proton_E_1500_B_0.6_pinhole_0.1_Le1_300_Le2_150.root", "He1+_E_1500_B_0.6_pinhole_0.1_Le1_300_Le2_150.root", "He2+_E_1500_B_0.6_pinhole_0.1_Le1_300_Le2_150.root", "TP", "pinhole 100 um - B 0.6T - E 1500 kV/m - Le1 300 mm Le2 150 mm", 0.1, 0.6, 1.5e6, 50, 5, 300, 150, 100, 1, 0., false, -15, -12, -9.4, 2);
  //Analyse("proton_E_1500_B_0.9_pinhole_0.1_Le1_300_Le2_150.root", "He1+_E_1500_B_0.9_pinhole_0.1_Le1_300_Le2_150.root", "He2+_E_1500_B_0.9_pinhole_0.1_Le1_300_Le2_150.root", "TP", "pinhole 100 um - B 0.9T - E 1500 kV/m - Le1 300 mm Le2 150 mm", 0.1, 0.9, 1.5e6, 50, 5, 300, 150, 100, 1, 0., false, -20, -17, -14.5, 2);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_100_Le2_150.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_100_Le2_150.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_100_Le2_150.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 100 mm Le2 150 mm", 0.1, 0.3, 1.5e6, 50, 5, 100, 150, 100, 1, 0., false, -10, -7, -2.7, 1.8);
  //Analyse("proton_E_1500_B_0.6_pinhole_0.1_Le1_100_Le2_150.root", "He1+_E_1500_B_0.6_pinhole_0.1_Le1_100_Le2_150.root", "He2+_E_1500_B_0.6_pinhole_0.1_Le1_100_Le2_150.root", "TP", "pinhole 100 um - B 0.6T - E 1500 kV/m - Le1 100 mm Le2 150 mm", 0.1, 0.6, 1.5e6, 50, 5, 100, 150, 100, 1, 0., false, -10, -5.9, -2.7, 1.8);
  //Analyse("proton_E_1500_B_0.9_pinhole_0.1_Le1_100_Le2_150.root", "He1+_E_1500_B_0.9_pinhole_0.1_Le1_100_Le2_150.root", "He2+_E_1500_B_0.9_pinhole_0.1_Le1_100_Le2_150.root", "TP", "pinhole 100 um - B 0.9T - E 1500 kV/m - Le1 100 mm Le2 150 mm", 0.1, 0.9, 1.5e6, 50, 5, 100, 150, 100, 1, 0., false, -17, -9.5, -8.4, 1.7);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_225_Le2_75.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_225_Le2_75.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_225_Le2_75.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 225 mm Le2 75 mm", 0.1, 0.3, 1.5e6, 50, 5, 225, 75, 100, 1, 0., false, -10, -6, -3.2, 1.6);
  //Analyse("proton_E_1500_B_0.6_pinhole_0.1_Le1_225_Le2_75.root", "He1+_E_1500_B_0.6_pinhole_0.1_Le1_225_Le2_75.root", "He2+_E_1500_B_0.6_pinhole_0.1_Le1_225_Le2_75.root", "TP", "pinhole 100 um - B 0.6T - E 1500 kV/m - Le1 225 mm Le2 75 mm", 0.1, 0.6, 1.5e6, 50, 5, 225, 75, 100, 1, 0., false, -10, -8, -6.5, 1.5);
  //Analyse("proton_E_1500_B_0.9_pinhole_0.1_Le1_225_Le2_75.root", "He1+_E_1500_B_0.9_pinhole_0.1_Le1_225_Le2_75.root", "He2+_E_1500_B_0.9_pinhole_0.1_Le1_225_Le2_75.root", "TP", "pinhole 100 um - B 0.9T - E 1500 kV/m - Le1 225 mm Le2 75 mm", 0.1, 0.9, 1.5e6, 50, 5, 225, 75, 100, 1, 0., false, -14, -11, -9.9, 1.5);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_300_Le2_0.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_300_Le2_0.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_300_Le2_0.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 300 mm Le2 0 mm", 0.1, 0.3, 1.5e6, 50, 5, 300, 0, 100, 1, 0., false, -10, -6, -3.2, 1.6);
  //Analyse("proton_E_1500_B_0.6_pinhole_0.1_Le1_300_Le2_0.root", "He1+_E_1500_B_0.6_pinhole_0.1_Le1_300_Le2_0.root", "He2+_E_1500_B_0.6_pinhole_0.1_Le1_300_Le2_0.root", "TP", "pinhole 100 um - B 0.6T - E 1500 kV/m - Le1 300 mm Le2 0 mm", 0.1, 0.6, 1.5e6, 50, 5, 300, 0, 100, 1, 0., false, -14, -11, -6.5, 1.4);
  //Analyse("proton_E_1500_B_0.9_pinhole_0.1_Le1_300_Le2_0.root", "He1+_E_1500_B_0.9_pinhole_0.1_Le1_300_Le2_0.root", "He2+_E_1500_B_0.9_pinhole_0.1_Le1_300_Le2_0.root", "TP", "pinhole 100 um - B 0.9T - E 1500 kV/m - Le1 300 mm Le2 0 mm", 0.1, 0.9, 1.5e6, 50, 5, 300, 0, 100, 1, 0., false, -14, -11, -9.9, 1.4);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_100_Le2_200.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_100_Le2_200.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_100_Le2_200.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 100 mm Le2 200 mm", 0.1, 0.3, 1.5e6, 50, 5, 100, 200, 100, 1, 0., false, -10, -6, -3.2, 1.7);
  //Analyse("proton_E_1500_B_0.6_pinhole_0.1_Le1_100_Le2_200.root", "He1+_E_1500_B_0.6_pinhole_0.1_Le1_100_Le2_200.root", "He2+_E_1500_B_0.6_pinhole_0.1_Le1_100_Le2_200.root", "TP", "pinhole 100 um - B 0.6T - E 1500 kV/m - Le1 100 mm Le2 200 mm", 0.1, 0.6, 1.5e6, 50, 5, 100, 200, 100, 1, 0., false, -14, -11, -6.5, 1.4);
  //Analyse("proton_E_1500_B_0.9_pinhole_0.1_Le1_100_Le2_200.root", "He1+_E_1500_B_0.9_pinhole_0.1_Le1_100_Le2_200.root", "He2+_E_1500_B_0.9_pinhole_0.1_Le1_100_Le2_200.root", "TP", "pinhole 100 um - B 0.9T - E 1500 kV/m - Le1 100 mm Le2 200 mm", 0.1, 0.9, 1.5e6, 50, 5, 100, 200, 100, 1, 0., false, -17, -11, -9.9, 1.8);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_100_Le2_275.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_100_Le2_275.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_100_Le2_275.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 100 mm Le2 275 mm", 0.1, 0.3, 1.5e6, 50, 5, 100, 275, 100, 1, 0., false, -10, -6, -3.2, 1.4);
  //Analyse("proton_E_1500_B_0.6_pinhole_0.1_Le1_100_Le2_275.root", "He1+_E_1500_B_0.6_pinhole_0.1_Le1_100_Le2_275.root", "He2+_E_1500_B_0.6_pinhole_0.1_Le1_100_Le2_275.root", "TP", "pinhole 100 um - B 0.6T - E 1500 kV/m - Le1 100 mm Le2 275 mm", 0.1, 0.6, 1.5e6, 50, 5, 100, 275, 100, 1, 0., false, -14, -11, -6.5, 1.7);
  //Analyse("proton_E_1500_B_0.9_pinhole_0.1_Le1_100_Le2_275.root", "He1+_E_1500_B_0.9_pinhole_0.1_Le1_100_Le2_275.root", "He2+_E_1500_B_0.9_pinhole_0.1_Le1_100_Le2_275.root", "TP", "pinhole 100 um - B 0.9T - E 1500 kV/m - Le1 100 mm Le2 275 mm", 0.1, 0.9, 1.5e6, 50, 5, 100, 275, 100, 1, 0., false, -19, -15, -12, 1.1);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_150_Le2_225.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_150_Le2_225.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_150_Le2_225.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 150 mm Le2 225 mm", 0.1, 0.3, 1.5e6, 50, 5, 150, 225, 100, 1, 0., false, -10, -6, -3.2, 1.3);
  //Analyse("proton_E_1500_B_0.6_pinhole_0.1_Le1_150_Le2_225.root", "He1+_E_1500_B_0.6_pinhole_0.1_Le1_150_Le2_225.root", "He2+_E_1500_B_0.6_pinhole_0.1_Le1_150_Le2_225.root", "TP", "pinhole 100 um - B 0.6T - E 1500 kV/m - Le1 150 mm Le2 225 mm", 0.1, 0.6, 1.5e6, 50, 5, 150, 225, 100, 1, 0., false, -14, -11, -6.5, 1.3);
  //Analyse("proton_E_1500_B_0.9_pinhole_0.1_Le1_150_Le2_225.root", "He1+_E_1500_B_0.9_pinhole_0.1_Le1_150_Le2_225.root", "He2+_E_1500_B_0.9_pinhole_0.1_Le1_150_Le2_225.root", "TP", "pinhole 100 um - B 0.9T - E 1500 kV/m - Le1 150 mm Le2 225 mm", 0.1, 0.9, 1.5e6, 50, 5, 150, 225, 100, 1, 0., false, -19, -15, -9.9, 1.2);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_225_Le2_150.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_225_Le2_150.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_225_Le2_150.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 225 mm Le2 150 mm", 0.1, 0.3, 1.5e6, 50, 5, 225, 150, 100, 1, 0., false, -10, -6, -3.2, 1.1);
  //Analyse("proton_E_1500_B_0.6_pinhole_0.1_Le1_225_Le2_150.root", "He1+_E_1500_B_0.6_pinhole_0.1_Le1_225_Le2_150.root", "He2+_E_1500_B_0.6_pinhole_0.1_Le1_225_Le2_150.root", "TP", "pinhole 100 um - B 0.6T - E 1500 kV/m - Le1 225 mm Le2 150 mm", 0.1, 0.6, 1.5e6, 50, 5, 225, 150, 100, 1, 0., false, -13, -11, -6.5, 1.3);
  //Analyse("proton_E_1500_B_0.9_pinhole_0.1_Le1_225_Le2_150.root", "He1+_E_1500_B_0.9_pinhole_0.1_Le1_225_Le2_150.root", "He2+_E_1500_B_0.9_pinhole_0.1_Le1_225_Le2_150.root", "TP", "pinhole 100 um - B 0.9T - E 1500 kV/m - Le1 225 mm Le2 150 mm", 0.1, 0.9, 1.5e6, 50, 5, 225, 150, 100, 1, 0., false, -19, -15, -9.9, 1.2);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_300_Le2_75.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_300_Le2_75.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_300_Le2_75.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 300 mm Le2 75 mm", 0.1, 0.3, 1.5e6, 50, 5, 300, 75, 100, 1, 0., false, -10, -6, -3.2, 1.2);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_375_Le2_0.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_375_Le2_0.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_375_Le2_0.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 375 mm Le2 0 mm", 0.1, 0.3, 1.5e6, 50, 5, 375, 0, 100, 1, 0., false, -10, -6, -3.2, 1.2);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_100_Le2_200.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_100_Le2_200.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_100_Le2_200.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 100 mm Le2 200 mm", 0.1, 0.3, 2e6, 50, 5, 100, 200, 100, 1, 0., false, -10, -6, -3.2, 1.4);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_150_Le2_150.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_150_Le2_150.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_150_Le2_150.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 150 mm Le2 150 mm", 0.1, 0.3, 2e6, 50, 5, 150, 150, 100, 1, 0., false, -10, -6, -3.2, 1.4);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_225_Le2_75.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_225_Le2_75.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_225_Le2_75.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 75 mm", 0.1, 0.3, 2e6, 50, 5, 225, 75, 100, 1, 0., false, -5, -4, -3.2, 1);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_300_Le2_0.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_300_Le2_0.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_300_Le2_0.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 300 mm Le2 0 mm", 0.1, 0.3, 2e6, 50, 5, 300, 0, 100, 1, 0., false, -10, -5, -3.2, 1.);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_100_Le2_275.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_100_Le2_275.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_100_Le2_275.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 100 mm Le2 275 mm", 0.1, 0.3, 2e6, 50, 5, 100, 275, 100, 1, 0., false, -10, -5, -3.2, 1.5);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_150_Le2_225.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_150_Le2_225.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_150_Le2_225.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 150 mm Le2 225 mm", 0.1, 0.3, 2e6, 50, 5, 150, 225, 100, 1, 0., false, -10, -5, -3.2, 1.3);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_225_Le2_150.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_225_Le2_150.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_225_Le2_150.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 150 mm", 0.1, 0.3, 2e6, 50, 5, 225, 150, 100, 1, 0., false, -10, -5, -3.2, 2);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_300_Le2_75.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_300_Le2_75.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_300_Le2_75.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 300 mm Le2 75 mm", 0.1, 0.3, 2e6, 50, 5, 300, 75, 100, 1, 0., false, -10, -5, -3.2, 2);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_100_Le2_245.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_100_Le2_245.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_100_Le2_245.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 100 mm Le2 245 mm", 0.1, 0.3, 2e6, 50, 5, 100, 245, 100, 1, 0., false, -10, -5, -3.2, 1.4);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_150_Le2_195.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_150_Le2_195.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_150_Le2_195.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 150 mm Le2 195 mm", 0.1, 0.3, 2e6, 50, 5, 150, 195, 100, 1, 0., false, -10, -5, -3.2, 1.5);

  //####################################################################################
  //################################# CONFIG 4 #########################################
  //####################################################################################
  //Analyse("Pinhole_variation/proton_E_2000_B_0.3_pinhole_0.1_Le1_225_Le2_120.root", "Pinhole_variation/He1+_E_2000_B_0.3_pinhole_0.1_Le1_225_Le2_120.root", "Pinhole_variation/He2+_E_2000_B_0.3_pinhole_0.1_Le1_225_Le2_120.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 1, 0., false, -10, -5, -3.2, 1.5);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.15_Le1_225_Le2_120.root", "He1+_E_2000_B_0.3_pinhole_0.15_Le1_225_Le2_120.root", "He2+_E_2000_B_0.3_pinhole_0.15_Le1_225_Le2_120.root", "TP", "pinhole 150 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm", 0.15, 0.3, 2e6, 50, 5, 225, 120, 100, 1, 0., false, -10, -5, -3.2, 2.2);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.2_Le1_225_Le2_120.root", "He1+_E_2000_B_0.3_pinhole_0.2_Le1_225_Le2_120.root", "He2+_E_2000_B_0.3_pinhole_0.2_Le1_225_Le2_120.root", "TP", "pinhole 200 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm", 0.2, 0.3, 2e6, 50, 5, 225, 120, 100, 1, 0., false, -10, -5, -3.2, 2.4);

  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_100_Le2_225.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_100_Le2_225.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_100_Le2_225.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 100 mm Le2 225 mm", 0.1, 0.3, 2e6, 50, 5, 100, 225, 100, 1, 0., false, -10, -5, -3.2, 1.6);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_150_Le2_175.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_150_Le2_175.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_150_Le2_175.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 150 mm Le2 175 mm", 0.1, 0.3, 2e6, 50, 5, 150, 175, 100, 1, 0., false, -10, -5, -3.2, 1.3);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_225_Le2_100.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_225_Le2_100.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_225_Le2_100.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 100 mm", 0.1, 0.3, 2e6, 50, 5, 225, 100, 100, 1, 0., false, -10, -5, -3.2, 1.6);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_300_Le2_25.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_300_Le2_25.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_300_Le2_25.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 300 mm Le2 25 mm", 0.1, 0.3, 2e6, 50, 5, 300, 25, 100, 1, 0., false, -10, -5, -3.2, 1.6);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_100_Le2_235.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_100_Le2_235.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_100_Le2_235.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 100 mm Le2 235 mm", 0.1, 0.3, 2e6, 50, 5, 100, 235, 100, 1, 0., false, -10, -5, -3.2, 1.4);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_150_Le2_185.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_150_Le2_185.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_150_Le2_185.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 150 mm Le2 185 mm", 0.1, 0.3, 2e6, 50, 5, 150, 185, 100, 1, 0., false, -10, -5, -3.2, 1.4);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_225_Le2_110.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_225_Le2_110.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_225_Le2_110.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 110 mm", 0.1, 0.3, 2e6, 50, 5, 225, 110, 100, 1, 0., false, -10, -5, -3.2, 1.7);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_300_Le2_35.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_300_Le2_35.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_300_Le2_35.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 300 mm Le2 35 mm", 0.1, 0.3, 2e6, 50, 5, 300, 35, 100, 1, 0., false, -10, -5, -3.2, 1.8);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_200_Le2_205.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_200_Le2_205.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_200_Le2_205.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 200 mm Le2 205 mm", 0.1, 0.3, 1.5e6, 50, 5, 200, 205, 100, 1, 0., false, -10, -5, -3.2, 1.5);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_250_Le2_155.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_250_Le2_155.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_250_Le2_155.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 250 mm Le2 155 mm", 0.1, 0.3, 1.5e6, 50, 5, 250, 155, 100, 1, 0., false, -10, -5, -3.2, 1.6);

  //####################################################################################
  //################################# CONFIG 2 #########################################
  //####################################################################################
  //Analyse("Pinhole_variation/proton_E_1500_B_0.3_pinhole_0.1_Le1_300_Le2_105.root", "Pinhole_variation/He1+_E_1500_B_0.3_pinhole_0.1_Le1_300_Le2_105.root", "Pinhole_variation/He2+_E_1500_B_0.3_pinhole_0.1_Le1_300_Le2_105.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 300 mm Le2 105 mm", 0.1, 0.3, 1.5e6, 50, 5, 300, 105, 100, 1, 0., false, -10, -5, -3.2, 1.5);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.15_Le1_300_Le2_105.root", "He1+_E_1500_B_0.3_pinhole_0.15_Le1_300_Le2_105.root", "He2+_E_1500_B_0.3_pinhole_0.15_Le1_300_Le2_105.root", "TP", "pinhole 150 um - B 0.3T - E 1500 kV/m - Le1 300 mm Le2 105 mm", 0.15, 0.3, 1.5e6, 50, 5, 300, 105, 100, 1, 0., false, -10, -5, -3.2, 2.2);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.2_Le1_300_Le2_105.root", "He1+_E_1500_B_0.3_pinhole_0.2_Le1_300_Le2_105.root", "He2+_E_1500_B_0.3_pinhole_0.2_Le1_300_Le2_105.root", "TP", "pinhole 200 um - B 0.3T - E 1500 kV/m - Le1 300 mm Le2 105 mm", 0.2, 0.3, 1.5e6, 50, 5, 300, 105, 100, 1, 0., false, -10, -5, -3.2, 2.2);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_350_Le2_25.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_350_Le2_25.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_350_Le2_25.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 350 mm Le2 25 mm", 0.1, 0.3, 1.5e6, 50, 5, 350, 25, 100, 1, 0., false, -10, -5, -3.2, 1.5);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_250_Le2_115.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_250_Le2_115.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_250_Le2_115.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 250 mm Le2 115 mm", 0.1, 0.3, 1.5e6, 50, 5, 250, 115, 100, 1, 0., false, -10, -5, -3.2, 2);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_300_Le2_65.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_300_Le2_65.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_300_Le2_65.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 300 mm Le2 65 mm", 0.1, 0.3, 1.5e6, 50, 5, 300, 65, 100, 1, 0., false, -10, -5, -3.2, 1.4);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_350_Le2_15.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_350_Le2_15.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_350_Le2_15.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 350 mm Le2 15 mm", 0.1, 0.3, 1.5e6, 50, 5, 350, 15, 100, 1, 0., false, -10, -5, -3.2, 1.6);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_200_Le2_160.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_200_Le2_160.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_200_Le2_160.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 200 mm Le2 160 mm", 0.1, 0.3, 1.5e6, 50, 5, 200, 160, 100, 1, 0., false, -10, -5, -3.2, 2);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_250_Le2_110.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_250_Le2_110.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_250_Le2_110.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 250 mm Le2 110 mm", 0.1, 0.3, 1.5e6, 50, 5, 250, 110, 100, 1, 0., false, -10, -5, -3.2, 1.8);
  //Analyse("Pinhole_variation/proton_E_1500_B_0.3_pinhole_0.1_Le1_200_Le2_145.root", "Pinhole_variation/He1+_E_1500_B_0.3_pinhole_0.1_Le1_200_Le2_145.root", "Pinhole_variation/He2+_E_1500_B_0.3_pinhole_0.1_Le1_200_Le2_145.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 200 mm Le2 145 mm", 0.1, 0.3, 1.5e6, 50, 5, 200, 145, 100, 1, 0., false, -10, -5, -3.2, 1.3);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_250_Le2_95.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_250_Le2_95.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_250_Le2_95.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 250 mm Le2 95 mm", 0.1, 0.3, 1.5e6, 50, 5, 250, 95, 100, 1, 0., false, -10, -5, -3.2, 1.4);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_300_Le2_45.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_300_Le2_45.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_300_Le2_45.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 300 mm Le2 45 mm", 0.1, 0.3, 1.5e6, 50, 5, 300, 45, 100, 1, 0., false, -10, -5, -3.2, 1.4);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_345_Le2_0.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_345_Le2_0.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_345_Le2_0.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 345 mm Le2 0 mm", 0.1, 0.3, 1.5e6, 50, 5, 345, 0, 100, 1, 0., false, -10, -5, -3.2, 1.1);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_200_Le2_115.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_200_Le2_115.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_200_Le2_115.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 200 mm Le2 115 mm", 0.1, 0.3, 2e6, 50, 5, 200, 115, 100, 1, 0., false, -10, -5, -3.2, 1.1);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_250_Le2_65.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_250_Le2_65.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_250_Le2_65.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 250 mm Le2 65 mm", 0.1, 0.3, 2e6, 50, 5, 250, 65, 100, 1, 0., false, -10, -5, -3.2, 1.5);

  //####################################################################################
  //################################# CONFIG 3 #########################################
  //####################################################################################
  //Analyse("Pinhole_variation/proton_E_2000_B_0.3_pinhole_0.1_Le1_280_Le2_35.root", "Pinhole_variation/He1+_E_2000_B_0.3_pinhole_0.1_Le1_280_Le2_35.root", "Pinhole_variation/He2+_E_2000_B_0.3_pinhole_0.1_Le1_280_Le2_35.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 280 mm Le2 35 mm", 0.1, 0.3, 2e6, 50, 5, 280, 35, 100, 1, 0., false, -8, -5, -3.2, 1.3);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.15_Le1_280_Le2_35.root", "He1+_E_2000_B_0.3_pinhole_0.15_Le1_280_Le2_35.root", "He2+_E_2000_B_0.3_pinhole_0.15_Le1_280_Le2_35.root", "TP", "pinhole 150 um - B 0.3T - E 2000 kV/m - Le1 280 mm Le2 35 mm", 0.15, 0.3, 2e6, 50, 5, 280, 35, 100, 1, 0., false, -8, -4, -3.2, 2);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.2_Le1_280_Le2_35.root", "He1+_E_2000_B_0.3_pinhole_0.2_Le1_280_Le2_35.root", "He2+_E_2000_B_0.3_pinhole_0.2_Le1_280_Le2_35.root", "TP", "pinhole 200 um - B 0.3T - E 2000 kV/m - Le1 280 mm Le2 35 mm", 0.2, 0.3, 2e6, 50, 5, 280, 35, 100, 1, 0., false, -8, -5, -3.2, 2.);

  //####################################################################################
  //################################# CONFIG 1 #########################################
  //####################################################################################
  //Analyse("Pinhole_variation/proton_E_1500_B_0.3_pinhole_0.1_Le1_320_Le2_25.root", "Pinhole_variation/He1+_E_1500_B_0.3_pinhole_0.1_Le1_320_Le2_25.root", "Pinhole_variation/He2+_E_1500_B_0.3_pinhole_0.1_Le1_320_Le2_25.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 320 mm Le2 25 mm", 0.1, 0.3, 1.5e6, 50, 5, 320, 25, 100, 1, 0., false, -8, -5, -3.2, 1.0);

  //Analyse("Pinhole_variation/proton_E_1500_B_0.3_pinhole_0.15_Le1_320_Le2_25.root", "Pinhole_variation/He1+_E_1500_B_0.3_pinhole_0.15_Le1_320_Le2_25.root", "Pinhole_variation/He2+_E_1500_B_0.3_pinhole_0.15_Le1_320_Le2_25.root", "TP", "pinhole 150 um - B 0.3T - E 1500 kV/m - Le1 320 mm Le2 25 mm", 0.15, 0.3, 1.5e6, 50, 5, 320, 25, 100, 1, 0., false, -8, -5, -3.2, 1.4);
  //Analyse("Pinhole_variation/proton_E_1500_B_0.3_pinhole_0.2_Le1_320_Le2_25.root", "Pinhole_variation/He1+_E_1500_B_0.3_pinhole_0.2_Le1_320_Le2_25.root", "Pinhole_variation/He2+_E_1500_B_0.3_pinhole_0.2_Le1_320_Le2_25.root", "TP", "pinhole 200 um - B 0.3T - E 1500 kV/m - Le1 320 mm Le2 25 mm", 0.2, 0.3, 1.5e6, 50, 5, 320, 25, 100, 1, 0., false, -8, -5, -3.2, 2);



  //####################################################################################
  //################################# CONFIG 4 W SC#####################################
  //####################################################################################
  //Analyse("proton_Config4_Sc_0.05.root", "He1+_Config4_Sc_0.05.root", "He2+_Config4_Sc_0.05.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - EJ 212 0.05 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.05, 0., true, -6, -5, -3.7, 1.2);
  //Analyse("proton_Config4_Sc_0.1.root", "He1+_Config4_Sc_0.1.root", "He2+_Config4_Sc_0.1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - EJ 212 0.1 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.1, 0., true, -6, -5, -3.2, 1.5);
  //Analyse("proton_Config4_Sc_0.25.root", "He1+_Config4_Sc_0.25.root", "He2+_Config4_Sc_0.25.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - EJ 212 0.25 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.25, 0., true, -6, -5, -3.2, 1.7);
  //Analyse("proton_Config4_Sc_0.5.root", "He1+_Config4_Sc_0.5.root", "He2+_Config4_Sc_0.5.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - EJ 212 0.5 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.5, 0., true, -6, -5, -3.8, 1.8);
  //Analyse("proton_Config4_Sc_1.root", "He1+_Config4_Sc_1.root", "He2+_Config4_Sc_1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - EJ 212 1 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 1, 0., true, -6, -4.5, -3.8, 2);
  //Analyse("proton_Config4_Sc_1.root", "He1+_Config4_Sc_1.root", "He2+_Config4_Sc_1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - EJ 212 1 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 1, 0., true, -6, -4.5, -3.8, 3);
  //Analyse("proton_Config4_ZnS_0.05.root", "He1+_Config4_ZnS_0.05.root", "He2+_Config4_ZnS_0.05.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.05 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0, 0.1, true, -6, -4.5, -3.8, 1.1);
  //Analyse("proton_Config4_ZnS_0.1.root", "He1+_Config4_ZnS_0.1.root", "He2+_Config4_ZnS_0.1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.1 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0, 0.1, true, -6, -4.5, -3.8, 1.1);
  //Analyse("proton_Config4_ZnS_0.25.root", "He1+_Config4_ZnS_0.25.root", "He2+_Config4_ZnS_0.25.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.25 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0, 0.25, true, -6, -4.5, -3.8, 1.4);
  //Analyse("proton_Config4_ZnS_0.5.root", "He1+_Config4_ZnS_0.5.root", "He2+_Config4_ZnS_0.5.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.5 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0, 0.5, true, -6, -4.5, -3.8, 1.6);
  //Analyse("proton_Config4_ZnS_1.root", "He1+_Config4_ZnS_1.root", "He2+_Config4_ZnS_1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 1 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0, 1, true, -5, -3.8, -3.7, 1.6);
  //Analyse("proton_Config4_ZnS_2.root", "He1+_Config4_ZnS_2.root", "He2+_Config4_ZnS_2.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 2 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0, 2, true, -5, -4.5, -3.8, 1.5);
  //Analyse("proton_Config4_NoWaSH_0.05.root", "He1+_Config4_NoWaSH_0.05.root", "He2+_Config4_NoWaSH_0.05.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 0.05 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.05, 0., true, -5, -4.5, -3.8, 1.2);
  //Analyse("proton_Config4_NoWaSH_0.1.root", "He1+_Config4_NoWaSH_0.1.root", "He2+_Config4_NoWaSH_0.1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 0.1 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.1, 0., true, -6, -4.5, -3.8, 1.6);
  //Analyse("proton_Config4_NoWaSH_0.25.root", "He1+_Config4_NoWaSH_0.25.root", "He2+_Config4_NoWaSH_0.25.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 0.25 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.25, 0., true, -6, -4.5, -3.8, 1.);
  //Analyse("proton_Config4_NoWaSH_0.5.root", "He1+_Config4_NoWaSH_0.5.root", "He2+_Config4_NoWaSH_0.5.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 0.5 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.5, 0., true, -6, -4.5, -3.8, 1.4);
  //Analyse("proton_Config4_NoWaSH_1.root", "He1+_Config4_NoWaSH_1.root", "He2+_Config4_NoWaSH_1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 1 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 1, 0., true, -6, -4.5, -3.8, 1);
  //Analyse("proton_Config4_NoWaSH_2.root", "He1+_Config4_NoWaSH_2.root", "He2+_Config4_NoWaSH_2.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 2 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 2, 0., true, -5.5, -4.5, -3.8, 1.3);



  //####################################################################################
  //################################# CONFIG 3 W SC#####################################
  //####################################################################################
  //Analyse("proton_Config3_Sc_0.05.root", "He1+_Config3_Sc_0.05.root", "He2+_Config3_Sc_0.05.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - EJ 212 0.05 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.05, 0., true, -6, -5, -3.2, 1);
  //Analyse("proton_Config3_Sc_0.1.root", "He1+_Config3_Sc_0.1.root", "He2+_Config3_Sc_0.1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - EJ 212 0.1 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.1, 0., true, -6, -5, -3.2, 1.8);
  //Analyse("proton_Config3_Sc_0.25.root", "He1+_Config3_Sc_0.25.root", "He2+_Config3_Sc_0.25.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - EJ 212 0.25 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.25, 0., true, -6, -5, -3.2, 1.3);
  //Analyse("proton_Config3_Sc_0.5.root", "He1+_Config3_Sc_0.5.root", "He2+_Config3_Sc_0.5.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - EJ 212 0.5 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.5, 0., true, -6, -5, -3.2, 1.5);
  //Analyse("proton_Config3_Sc_1.root", "He1+_Config3_Sc_1.root", "He2+_Config3_Sc_1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - EJ 212 1 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 1, 0., true, -6, -5, -3.2, 1.3);
  //Analyse("proton_Config3_ZnS_0.05.root", "He1+_Config3_ZnS_0.05.root", "He2+_Config3_ZnS_0.05.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.05 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0., 0.05, true, -3.5, -5, -3.2, 0.9);
  //Analyse("proton_Config3_ZnS_0.1.root", "He1+_Config3_ZnS_0.1.root", "He2+_Config3_ZnS_0.1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.1 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0., 0.1, true, -3.5, -5, -3.2, 1.6);
  //Analyse("proton_Config3_ZnS_0.25.root", "He1+_Config3_ZnS_0.25.root", "He2+_Config3_ZnS_0.25.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.25 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0., 0.25, true, -5, -5, -3.4, 1.2);
  //Analyse("proton_Config3_ZnS_0.5.root", "He1+_Config3_ZnS_0.5.root", "He2+_Config3_ZnS_0.5.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.5 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0., 0.5, true, -5., -5, -3.2, 1.1);
  //Analyse("proton_Config3_ZnS_1.root", "He1+_Config3_ZnS_1.root", "He2+_Config3_ZnS_1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 1 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0., 1, true, -5., -5, -3.2, 1.3);
  //Analyse("proton_Config3_NoWaSH_0.05.root", "He1+_Config3_NoWaSH_0.05.root", "He2+_Config3_NoWaSH_0.05.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 0.05 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.05, 0., true, -6, -4.5, -3.8, 1.6);
  //Analyse("proton_Config3_NoWaSH_0.1.root", "He1+_Config3_NoWaSH_0.1.root", "He2+_Config3_NoWaSH_0.1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 0.1 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.1, 0., true, -6, -4.5, -3.8, 1.7);
  //Analyse("proton_Config3_NoWaSH_0.25.root", "He1+_Config3_NoWaSH_0.25.root", "He2+_Config3_NoWaSH_0.25.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 0.25 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.25, 0., true, -6, -4.5, -3.8, 1.5);
  //Analyse("proton_Config3_NoWaSH_0.5.root", "He1+_Config3_NoWaSH_0.5.root", "He2+_Config3_NoWaSH_0.5.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 0.5 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.5, 0., true, -6, -4.5, -3.8, 1.5);
  //Analyse("proton_Config3_NoWaSH_1.root", "He1+_Config3_NoWaSH_1.root", "He2+_Config3_NoWaSH_1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 1 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 1, 0., true, -6, -4.5, -3.8, 1.8);



  //####################################################################################
  //################################# CONFIG 1 W SC#####################################
  //####################################################################################
  //Analyse("proton_Config1_Sc_0.05.root", "He1+_Config1_Sc_0.05.root", "He2+_Config1_Sc_0.05.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - Sc 0.05 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.05, 0., true, -5, -5, -3.2, 1.);
  //Analyse("proton_Config1_Sc_0.1.root", "He1+_Config1_Sc_0.1.root", "He2+_Config1_Sc_0.1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - Sc 0.1 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.1, 0., true, -5, -5, -3.2, 1.8);
  //Analyse("proton_Config1_Sc_0.25.root", "He1+_Config1_Sc_0.25.root", "He2+_Config1_Sc_0.25.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - Sc 0.25 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.25, 0., true, -5, -5, -3.2, 1.3);
  //Analyse("proton_Config1_Sc_0.5.root", "He1+_Config1_Sc_0.5.root", "He2+_Config1_Sc_0.5.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - Sc 0.5 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.5, 0., true, -5, -5, -3.2, 1.5);
  //Analyse("proton_Config1_Sc_1.root", "He1+_Config1_Sc_1.root", "He2+_Config1_Sc_1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - Sc 1 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 1, 0., true, -5, -5, -3.2, 1.5);
  //Analyse("proton_Config1_ZnS_0.05.root", "He1+_Config1_ZnS_0.05.root", "He2+_Config1_ZnS_0.05.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.05 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0., 0.05, true, -5, -5, -3.2, 1.1);
  //Analyse("proton_Config1_ZnS_0.1.root", "He1+_Config1_ZnS_0.1.root", "He2+_Config1_ZnS_0.1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.1 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0., 0.1, true, -5, -5, -3.2, 1.3);
  //Analyse("proton_Config1_ZnS_0.25.root", "He1+_Config1_ZnS_0.25.root", "He2+_Config1_ZnS_0.25.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.25 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0., 0.25, true, -5, -5, -3.2, 1.3);
  //Analyse("proton_Config1_ZnS_0.5.root", "He1+_Config1_ZnS_0.5.root", "He2+_Config1_ZnS_0.5.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.5 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0., 0.5, true, -6, -5, -3.2, 1.4);
  //Analyse("proton_Config1_ZnS_1.root", "He1+_Config1_ZnS_1.root", "He2+_Config1_ZnS_1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 1 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0., 1, true, -5, -5, -3.2, 1.6);
  //Analyse("proton_Config1_NoWaSH_0.05.root", "He1+_Config1_NoWaSH_0.05.root", "He2+_Config1_NoWaSH_0.05.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 0.05 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.05, 0., true, -6, -4.5, -3.8, 1.1);
  //Analyse("proton_Config1_NoWaSH_0.1.root", "He1+_Config1_NoWaSH_0.1.root", "He2+_Config1_NoWaSH_0.1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 0.1 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.1, 0., true, -6, -4.5, -3.8, 1.1);
  //Analyse("proton_Config1_NoWaSH_0.25.root", "He1+_Config1_NoWaSH_0.25.root", "He2+_Config1_NoWaSH_0.25.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 0.25 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.25, 0., true, -6, -4.5, -3.8, 1.4);
  //Analyse("proton_Config1_NoWaSH_0.5.root", "He1+_Config1_NoWaSH_0.5.root", "He2+_Config1_NoWaSH_0.5.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 0.5 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.5, 0., true, -6, -4.5, -3.8, 1.4);
  //Analyse("proton_Config1_NoWaSH_1.root", "He1+_Config1_NoWaSH_1.root", "He2+_Config1_NoWaSH_1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 1 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 1, 0., true, -6, -4.5, -3.8, 1.4);



  //####################################################################################
  //################################# CONFIG 2 W SC#####################################
  //####################################################################################
  //Analyse("proton_Config2_Sc_0.05.root", "He1+_Config2_Sc_0.05.root", "He2+_Config2_Sc_0.05.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - Sc 0.05 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.05, 0., true, -5.5, -5, -4.3, 1.4);
  //Analyse("proton_Config2_Sc_0.1.root", "He1+_Config2_Sc_0.1.root", "He2+_Config2_Sc_0.1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - Sc 0.1 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.1, 0., true, -5, -5, -3.2, 1.8);
  //Analyse("proton_Config2_Sc_0.25.root", "He1+_Config2_Sc_0.25.root", "He2+_Config2_Sc_0.25.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - Sc 0.25 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.25, 0., true, -7, -5, -3.2, 1.5);
  //Analyse("proton_Config2_Sc_0.5.root", "He1+_Config2_Sc_0.5.root", "He2+_Config2_Sc_0.5.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - Sc 0.5 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.5, 0., true, -7, -5, -3.2, 1.5);
  //Analyse("proton_Config2_Sc_1.root", "He1+_Config2_Sc_1.root", "He2+_Config2_Sc_1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - Sc 1 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 1, 0., true, -7, -5, -3.2, 1.2);
  //Analyse("proton_Config2_ZnS_0.05.root", "He1+_Config2_ZnS_0.05.root", "He2+_Config2_ZnS_0.05.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.05 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0., 0.05, true, -5.5, -5, -3.2, 1.5);
  //Analyse("proton_Config2_ZnS_0.1.root", "He1+_Config2_ZnS_0.1.root", "He2+_Config2_ZnS_0.1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.1 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0., 0.1, true, -7, -5, -3.2, 1.5);
  //Analyse("proton_Config2_ZnS_0.25.root", "He1+_Config2_ZnS_0.25.root", "He2+_Config2_ZnS_0.25.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.25 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0., 0.25, true, -7, -5, -3.8, 1.8);
  //Analyse("proton_Config2_ZnS_0.5.root", "He1+_Config2_ZnS_0.5.root", "He2+_Config2_ZnS_0.5.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.5 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0., 0.5, true, -5, -5, -3.2, 1.5);
  //Analyse("proton_Config2_ZnS_1.root", "He1+_Config2_ZnS_1.root", "He2+_Config2_ZnS_1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 1 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0., 1, true, -6, -5, -4.2, 1.3);
  //Analyse("proton_Config2_NoWaSH_0.05.root", "He1+_Config2_NoWaSH_0.05.root", "He2+_Config2_NoWaSH_0.05.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 0.05 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.05, 0., true, -6, -4.5, -3.8, 1.5);
  //Analyse("proton_Config2_NoWaSH_0.1.root", "He1+_Config2_NoWaSH_0.1.root", "He2+_Config2_NoWaSH_0.1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 0.1 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.1, 0., true, -6, -4.5, -3.8, 1.);
  //Analyse("proton_Config2_NoWaSH_0.25.root", "He1+_Config2_NoWaSH_0.25.root", "He2+_Config2_NoWaSH_0.25.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 0.25 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.25, 0., true, -6, -4.5, -3.8, 1.4);
  //Analyse("proton_Config2_NoWaSH_0.5.root", "He1+_Config2_NoWaSH_0.5.root", "He2+_Config2_NoWaSH_0.5.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 0.5 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.5, 0., true, -6, -4.5, -3.8, 1.4);
  //Analyse("proton_Config2_NoWaSH_1.root", "He1+_Config2_NoWaSH_1.root", "He2+_Config2_NoWaSH_1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 1 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 1, 0., true, -6, -4.5, -3.8, 1.4);



  //Analyse("proton_Config3_ZnS_0.5_Sc_0.1.root", "He1+_Config3_ZnS_0.5_Sc_0.1.root", "He2+_Config3_ZnS_0.5_Sc_0.1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.5 mm & EJ-212 0.1 mm ", 0.1, 0.3, 2e6, 50, 5, 280, 35, 100, 0.1, 0.5, true, -7, -5, -3.2, 1.7);
  //Analyse("proton_Config4_ZnS_0.5_Sc_0.1.root", "He1+_Config4_ZnS_0.5_Sc_0.1.root", "He2+_Config4_ZnS_0.5_Sc_0.1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.5 mm & EJ-212 0.1 mm ", 0.1, 0.3, 2e6, 50, 5, 280, 35, 100, 0.1, 0.5, true, -5, -5, -3.2, 1.7);
  //Analyse("proton_Config1_ZnS_0.5_Sc_0.1.root", "He1+_Config1_ZnS_0.5_Sc_0.1.root", "He2+_Config1_ZnS_0.5_Sc_0.1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.5 mm & EJ-212 0.1 mm ", 0.1, 0.3, 2e6, 50, 5, 280, 35, 100, 0.1, 0.5, true, -5, -5, -3.2, 1.4);


  //Analyse("proton_Config2_High_Stat.root", "He1+_Config2_High_Stat.root", "He2+_Config2_High_Stat.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 300 mm Le2 105 mm", 0.1, 0.3, 1.5e6, 50, 5, 300, 105, 100, 0., 0., false, -5, -5, -3.2, 1.4);
  //Analyse("proton_Config2_High_Stat_maxtheta_0.3mrad.root", "He1+_Config2_High_Stat_maxtheta_0.3mrad.root", "He2+_Config2_High_Stat_maxtheta_0.3mrad.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 300 mm Le2 105 mm maxtheta 0.3mrad", 0.1, 0.3, 1.5e6, 50, 5, 300, 105, 100, 0., 0., false, -5, -5, -3.2, 1.4);
  //Analyse("proton_Config2_High_Stat_Pinhole_thick_12mm.root", "He1+_Config2_High_Stat_Pinhole_thick_12mm.root", "He2+_Config2_High_Stat_Pinhole_thick_12mm.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 300 mm Le2 105 mm Pinhole thickness 12 mm", 0.1, 0.3, 1.5e6, 50, 5, 300, 105, 100, 0., 0., false, -5, -5, -3.2, 1.4);
  //Analyse("proton_Config2_High_Stat_dist_bet_plate_Elec_36mm.root", "He1+_Config2_High_Stat_dist_bet_plate_Elec_36mm.root", "He2+_Config2_High_Stat_dist_bet_plate_Elec_36mm.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 300 mm Le2 105 mm dist between plates elec 36mm", 0.1, 0.3, 1.5e6, 50, 5, 300, 105, 100, 0., 0., false, -5, -5, -3.2, 1.4);
  //Analyse("proton_Config2_High_Stat_dist_bet_plate_Elec_25mm.root", "He1+_Config2_High_Stat_dist_bet_plate_Elec_25mm.root", "He2+_Config2_High_Stat_dist_bet_plate_Elec_25mm.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 300 mm Le2 105 mm dist between plates elec 25mm", 0.1, 0.3, 1.5e6, 50, 5, 300, 105, 100, 0., 0., false, -5, -5, -3.2, 1.4);
  //Analyse("proton_Config2_High_Stat_dist_bet_plate_Elec_50mm.root", "He1+_Config2_High_Stat_dist_bet_plate_Elec_50mm.root", "He2+_Config2_High_Stat_dist_bet_plate_Elec_50mm.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 300 mm Le2 105 mm dist between plates elec 50mm", 0.1, 0.3, 1.5e6, 50, 5, 300, 105, 100, 0., 0., false, -5, -5, -3.2, 1.4);
  //Analyse("proton_Config2_High_Stat_dist_detecteur_plaques_200mm.root", "He1+_Config2_High_Stat_dist_detecteur_plaques_200mm.root", "He2+_Config2_High_Stat_dist_detecteur_plaques_200mm.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 300 mm Le2 200 mm", 0.1, 0.3, 1.5e6, 50, 5, 300, 200, 100, 0., 0., false, -5, -5, -3.2, 1.4);
  //Analyse("proton_Config2_High_Stat_dist_detecteur_plaques_0mm.root", "He1+_Config2_High_Stat_dist_detecteur_plaques_0mm.root", "He2+_Config2_High_Stat_dist_detecteur_plaques_0mm.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 300 mm Le2 0 mm", 0.1, 0.3, 1.5e6, 50, 5, 300, 0, 100, 0., 0., false, -5, -5, -3.2, 1.4);
  //Analyse("proton_Config2_High_Stat_thick_elec_plate_10mm.root", "He1+_Config2_High_Stat_thick_elec_plate_10mm.root", "He2+_Config2_High_Stat_thick_elec_plate_10mm.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 300 mm Le2 105 mm thickness elec plate 10mm", 0.1, 0.3, 1.5e6, 50, 5, 300, 105, 100, 0., 0., false, -5, -5, -3.2, 1.4);


  //void Analyse(const char* file_proton, const char* file_He1, const char* file_He2, const char* TreeName, const char* CanvasName, float pinhole, float B, float E, float Lb1, float D, float Le1, float Le2, float Sc_length, float Sc_thickness, float ZnS_thickness, bool Optique, float xmin_proton, float xmin_He1, float xmax_proton, float sigma)




  /*
  //DEBUG

   int npeaks =2;
   int bin_start = (-15+40.1)*10;
   int bin_end = (-9+40.1)*10;
   double par[3000];
   int p;
   int n=0;
   int nfound=0;
   double xp;
   int bin;
   double yp;
   TH1D *Output_resolution = new TH1D("Output_resolution", "Output_resolution", 610, -1, 60);
   int number_of_peaks = npeaks;

   TFile* file1 = new TFile("proton_pinhole_100um_B_0.6T_E_2000kV_Le1_300_Optique.root");
   TTree *Tree1 = (TTree*)file1->Get("Optical");
   TFile* file2 = new TFile("He1+_pinhole_100um_B_0.6T_E_2000kV_Le1_300_Optique.root");
   TTree *Tree2 = (TTree*)file2->Get("Optical");
   TFile* file3 = new TFile("He2+_pinhole_100um_B_0.6T_E_2000kV_Le1_300_Optique.root");
   TTree *Tree3 = (TTree*)file3->Get("Optical");

   TH2F* h_proton;
   TH2F* h_ALL;
   TH2F* h_proton_He1;
   TH2F* h_proton_He2;
   TH2F* h_He1;
   TH2F* h_He2;

   h_proton = Histo_Parabole_Optique(Tree1, "proton");
   h_ALL = Histo_Parabole_Optique(Tree1, "ALL");
   h_proton_He1 = Histo_Parabole_Optique(Tree1, "proton_He1");
   h_proton_He2 = Histo_Parabole_Optique(Tree1, "proton_He2");
   h_He1 = Histo_Parabole_Optique(Tree2, "He1");
   h_He2 = Histo_Parabole_Optique(Tree3, "He2");



   h_proton_He2->Add(h_He2, 1);
   h_proton_He2->Draw("colz");

   TCanvas* c1 = new TCanvas();
   c1->cd();

   TH1D *proj = new TH1D("proj", "proj", 610, -1, 60);
   TH1D *proj_clean = new TH1D("proj_clean", "proj_clean", 610, -1, 60);
   TH1D *bg = new TH1D("bg", "bg", 610, -1, 60);

   //for (int i=bin_start; i<bin_end; i++)
   //{
   //cout << "i = " << i << endl;
       TH2F *h_proton_He2_bis = (TH2F*)h_proton_He2->Clone();
       h_proton_He2_bis->ProjectionY("proj", 302, 302, "");
       //h_proton->Draw();
       proj->Draw();
       TSpectrum *s = new TSpectrum(2);
       // Estimate background using TSpectrum::Background
       TH1 *hb = s->Background(proj,20,"same");
       if (hb) c1->Update();

       // for (int j=0; j<proj->GetNbinsX(); j++)
       // 	 {
       // 	   proj_clean->SetBinContent(j, proj->GetBinContent(j)-hb->GetBinContent(j));
       // 	 }


       nfound = s->Search(proj, 2,"",0.2);
       printf("Found %d candidate peaks to fit\n",nfound);


       //estimate linear background using a fitting method
       TF1 *fline = new TF1("fline","pol1",-1,60);
       proj->Fit("fline","same");
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
   	par[3*npeaks+4] = 0.1; // "sigma"
   	npeaks++;
       }

       TF1*test_fit1 = new TF1("fit1", "gaus", par[3]-0.6, par[3]+0.4);
       test_fit1->SetParameter(1, par[3]);
       TF1*test_fit2 = new TF1("fit2", "gaus", par[6]-0.4, par[6]+0.5);
       test_fit2->SetParameter(1, par[6]);
       TF1*test_fit3 = new TF1("fit3", "gaus(0)+gaus(3)+gaus(6)", -1, par[6]+10);
       TH1F *h2 = (TH1F*)proj->Clone("h2");
       h2->Draw();
       h2->Fit(test_fit1, "R");
       h2->Fit(test_fit2, "R");
       test_fit3->SetParameter(1, test_fit1->GetParameter(1));
       test_fit3->SetParameter(2, test_fit1->GetParameter(2));
       test_fit3->SetParLimits(2, 0.1, 0.5);
       test_fit3->SetParameter(4, test_fit2->GetParameter(1));
       test_fit3->SetParameter(5, test_fit2->GetParameter(2));
       test_fit3->SetParLimits(5, 0.1, 1);
       test_fit3->SetParameter(7, (test_fit2->GetParameter(1)+test_fit2->GetParameter(1))/2);
       test_fit3->SetParLimits(8, 1, 10);
       h2->Fit(test_fit3, "R+");
       cout << "Eval = " << test_fit1->Eval(par[3]-0.5);

       for (int i=0; i<h2->GetNbinsX(); i++)
	 {
	   bg->SetBinContent(i, h2->GetBinContent(i) - test_fit1->Eval(h2->GetBinCenter(i)) - test_fit2->Eval(h2->GetBinCenter(i)));
	 }

       bg->SetLineColor(kGreen);
       bg->Draw("same");

       printf("Found %d useful peaks to fit\n",npeaks);
       printf("Now fitting: Be patient\n");
       TF1 *fit = new TF1("fit",fpeaks,-1,60,2+3*npeaks);
       // We may have more than the default 25 parameters
       TVirtualFitter::Fitter(h2,10+3*npeaks);
       fit->SetParameters(par);
       fit->SetParLimits(2,10, 1000000);
       fit->SetParLimits(3,2, 3);
       fit->SetParLimits(4,0.1, 0.5);
       fit->SetParLimits(5,10, 1000000);
       fit->SetParLimits(6, 4.5, 5.5);
       fit->SetParLimits(7, 0.1, 0.5);
       fit->SetNpx(1000);
       fit->SetLineColor(kRed);
       //h2->Fit("fit", "");

       //proj_clean->Draw("same");
       //proj_clean->SetLineColor(kCyan);;
       //c1->Modified();
       //c1->Update();
       //getchar();

       //}


       */

      // c1->cd(2);
      // TH1F *h2 = (TH1F*)proj_clean->Clone("h2");
      // //h2->Draw();
      // printf("Found %d useful peaks to fit\n",npeaks);
      // printf("Now fitting: Be patient\n");
      // TF1 *fit = new TF1("fit",fpeaks,-1,60,2+3*npeaks);
      // // We may have more than the default 25 parameters
      // TVirtualFitter::Fitter(h2,10+3*npeaks);
      // fit->SetParameters(par);
      // fit->SetParLimits(2,10, 1000000);
      // fit->SetParLimits(3,0, 60);
      // fit->SetParLimits(4,0.1, 0.5);
      // fit->SetParLimits(5,10, 1000000);
      // fit->SetParLimits(6,0, 60);
      // fit->SetParLimits(7, 0.1, 0.5);
      // fit->SetNpx(1000);
      // fit->SetLineColor(kRed);
      // h2->Fit("fit", "");
      // //  proj_clean->Draw("same");
      // c1->Modified();
      // c1->Update();
      // getchar();

      // }





}
