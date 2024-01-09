TGraphErrors* GetGraph(const char* filename)
{
  TFile* file = new TFile(filename);
  TGraphErrors* g = (TGraphErrors*)file->Get("Graph");

  return g;
}
  



void Plot()
{
  TGraphErrors* g_Res_1 = GetGraph("Graph_Resolution_proton_EJ262_0.1mm_round_fiber_multicladding_0.2mm_1m_CMOS_Exp_30MeV.root");
  TGraphErrors* g_Nph_1 = GetGraph("Graph_Nph_proton_EJ262_0.1mm_round_fiber_multicladding_0.2mm_1m_CMOS_Exp_30MeV.root");

  TGraphErrors* g_Res_2 = GetGraph("Graph_Resolution_proton_EJ262_0.5mm_round_fiber_multicladding_0.2mm_1m_CMOS_Exp_30MeV.root");
  TGraphErrors* g_Nph_2 = GetGraph("Graph_Nph_proton_EJ262_0.5mm_round_fiber_multicladding_0.2mm_1m_CMOS_Exp_30MeV.root");

  TGraphErrors* g_Res_3 = GetGraph("Graph_Resolution_proton_EJ262_1mm_round_fiber_multicladding_0.2mm_1m_CMOS_Exp_30MeV.root");
  TGraphErrors* g_Nph_3 = GetGraph("Graph_Nph_proton_EJ262_1mm_round_fiber_multicladding_0.2mm_1m_CMOS_Exp_30MeV.root");



  new TCanvas;
  g_Res_1->Draw("APE2");
  g_Res_2->Draw("samePE2");
  g_Res_3->Draw("samePE2");
  //g_Res_4->Draw("samePE2");
  //g_Res_5->Draw("samePE2");
  //g_Res_0->Draw("samePE2");

  g_Res_1->SetMarkerColor(kBlack);
  g_Res_2->SetMarkerColor(kRed);
  g_Res_3->SetMarkerColor(kCyan);
  //g_Res_4->SetMarkerColor(kBlue);
  //g_Res_5->SetMarkerColor(kGreen);
  //g_Res_0->SetMarkerColor(kOrange);

  g_Res_1->SetFillColor(kBlack);
  g_Res_2->SetFillColor(kRed);
  g_Res_3->SetFillColor(kCyan);
  //g_Res_4->SetFillColor(kBlue);
  //g_Res_5->SetFillColor(kGreen);
  //g_Res_0->SetFillColor(kOrange);

  g_Res_1->SetLineColor(kBlack);
  g_Res_2->SetLineColor(kRed);
  g_Res_3->SetLineColor(kCyan);
  //g_Res_4->SetLineColor(kBlue);
  //g_Res_5->SetLineColor(kGreen);
  //g_Res_0->SetLineColor(kOrange);

  g_Res_1->SetMarkerStyle(6);
  g_Res_2->SetMarkerStyle(7);
  g_Res_3->SetMarkerStyle(7);
  //g_Res_4->SetMarkerStyle(7);
  //g_Res_5->SetMarkerStyle(6);
  //g_Res_0->SetMarkerStyle(6);


  
  TLegend* legend = new TLegend(0.1, 0.5, 0.3, 0.9);
  legend->SetHeader("EJ-262");
  //legend->AddEntry(g_Res_0, "thickness = 0.025 mm", "PF");
  legend->AddEntry(g_Res_1, "thickness = 0.1 mm", "PF");
  legend->AddEntry(g_Res_2, "thickness = 0.5 mm", "PF");
  legend->AddEntry(g_Res_3, "thickness = 1 mm", "PF");
  //legend->AddEntry(g_Res_4, "thickness = 2 mm", "PF");
  //legend->AddEntry(g_Res_5, "thickness = 5 mm", "PF");
  legend->Draw();



  new TCanvas;
  g_Nph_1->Draw("APE2");
  g_Nph_2->Draw("samePE2");
  g_Nph_3->Draw("samePE2");
  //g_Nph_4->Draw("samePE2");
  //g_Nph_5->Draw("samePE2");
  //g_Nph_0->Draw("samePE2");

  g_Nph_1->SetMarkerColor(kBlack);
  g_Nph_2->SetMarkerColor(kRed);
  g_Nph_3->SetMarkerColor(kCyan);
  //g_Nph_4->SetMarkerColor(kBlue);
  //g_Nph_5->SetMarkerColor(kGreen);
  //g_Nph_0->SetMarkerColor(kOrange);

  g_Nph_1->SetFillColor(kBlack);
  g_Nph_2->SetFillColor(kRed);
  g_Nph_3->SetFillColor(kCyan);
  //g_Nph_4->SetFillColor(kBlue);
  //g_Nph_5->SetFillColor(kGreen);
  //g_Nph_0->SetFillColor(kOrange);

  g_Nph_1->SetLineColor(kBlack);
  g_Nph_2->SetLineColor(kRed);
  g_Nph_3->SetLineColor(kCyan);
  //g_Nph_4->SetLineColor(kBlue);
  //g_Nph_5->SetLineColor(kGreen);
  //g_Nph_0->SetLineColor(kOrange);

  g_Nph_1->SetMarkerStyle(6);
  g_Nph_2->SetMarkerStyle(7);
  g_Nph_3->SetMarkerStyle(7);
  //g_Nph_4->SetMarkerStyle(7);
  //g_Nph_5->SetMarkerStyle(6);
  //g_Nph_0->SetMarkerStyle(6);


  
  TLegend* legend1 = new TLegend(0.1, 0.5, 0.3, 0.9);
  legend1->SetHeader("EJ-262");
  //legend1->AddEntry(g_Nph_0, "thickness = 0.025 mm", "PF");
  legend1->AddEntry(g_Nph_1, "thickness = 0.1 mm", "PF");
  legend1->AddEntry(g_Nph_2, "thickness = 0.5 mm", "PF");
  legend1->AddEntry(g_Nph_3, "thickness = 1 mm", "PF");
  //legend1->AddEntry(g_Nph_4, "thickness = 2 mm", "PF");
  //legend1->AddEntry(g_Nph_5, "thickness = 5 mm", "PF");
  legend1->Draw();



  
  TGraphErrors* g_Res_EJ262_1 = GetGraph("Graph_Resolution_proton_EJ262_0.1mm_round_fiber_multicladding_0.2mm_1m_CMOS_Exp_30MeV.root");
  TGraphErrors* g_Nph_EJ262_1 = GetGraph("Graph_Nph_proton_EJ262_0.1mm_round_fiber_multicladding_0.2mm_1m_CMOS_Exp_30MeV.root");
  TGraphErrors* g_Res_YAG_1 = GetGraph("Graph_Resolution_proton_YAG_0.1mm_round_fiber_multicladding_0.2mm_1m_CMOS_Exp_30MeV.root");
  TGraphErrors* g_Nph_YAG_1 = GetGraph("Graph_Nph_proton_YAG_0.1mm_round_fiber_multicladding_0.2mm_1m_CMOS_Exp_30MeV.root");

  g_Nph_YAG_1->SetLineColor(kRed);
  g_Nph_YAG_1->SetMarkerColor(kRed);
  g_Nph_YAG_1->SetFillColor(kRed);

  g_Nph_EJ262_1->SetLineColor(kBlue);
  g_Nph_EJ262_1->SetMarkerColor(kBlue);
  g_Nph_EJ262_1->SetFillColor(kBlue);


  new TCanvas;
  g_Nph_EJ262_1->Draw("APE2");
  g_Nph_YAG_1->Draw("samePE2");

  TLegend* legend2 = new TLegend(0.1, 0.5, 0.3, 0.9);
  legend2->SetHeader("Thickness  = 0.1 mm");
  legend2->AddEntry(g_Nph_YAG_1, "YAG", "PF");
  legend2->AddEntry(g_Nph_EJ262_1, "EJ262", "PF");
  legend2->Draw();



  g_Res_YAG_1->SetLineColor(kRed);
  g_Res_YAG_1->SetMarkerColor(kRed);
  g_Res_YAG_1->SetFillColor(kRed);

  g_Res_EJ262_1->SetLineColor(kBlue);
  g_Res_EJ262_1->SetMarkerColor(kBlue);
  g_Res_EJ262_1->SetFillColor(kBlue);


  new TCanvas;
  g_Res_EJ262_1->Draw("APE2");
  g_Res_YAG_1->Draw("samePE2");

  TLegend* legend5 = new TLegend(0.1, 0.5, 0.3, 0.9);
  legend5->SetHeader("Thickness  = 0.1 mm");
  legend5->AddEntry(g_Res_YAG_1, "YAG", "PF");
  legend5->AddEntry(g_Res_EJ262_1, "EJ262", "PF");
  legend5->Draw();



}