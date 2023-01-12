void Plot_2D_cross_talk()
{
  gStyle->SetPalette(kTemperatureMap);

  TGraph2D * square = new TGraph2D();

  square->AddPoint(0.1, 201, 140);
  square->AddPoint(0.25, 201, 110.8);
  square->AddPoint(0.5, 201, 76.6);
  square->AddPoint(1, 201, 44.1);
  square->AddPoint(2, 201, 21.6);
  square->AddPoint(3, 201, 14.1);
  square->AddPoint(4, 201, 10.4);
  square->AddPoint(5, 201, 8.9);
  square->AddPoint(7.5, 201, 6.0);
  square->AddPoint(10, 201, 5.5);

  square->AddPoint(0.1, 101, 109.2);
  square->AddPoint(0.25, 101, 64.1);
  square->AddPoint(0.5, 101, 33.9);
  square->AddPoint(1, 101, 14.9);
  square->AddPoint(2, 101, 5.8);
  square->AddPoint(3, 101, 3.5);
  square->AddPoint(4, 101, 2.5);
  square->AddPoint(5, 101, 2.0);
  square->AddPoint(7.5, 101, 1.6);
  square->AddPoint(10, 101, 1.5);

  square->AddPoint(0.1, 51, 44.1);
  square->AddPoint(0.25, 51, 19.6);
  square->AddPoint(0.5, 51, 7.9);
  square->AddPoint(1, 51, 2.5);
  square->AddPoint(2, 51, 0.8);
  square->AddPoint(3, 51, 0.5);
  square->AddPoint(4, 51, 0.3);
  square->AddPoint(5, 51, 0.2);
  square->AddPoint(7.5, 51, 0.2);
  square->AddPoint(10, 51, 0.3);

  square->AddPoint(0.1, 35, 26.1);
  square->AddPoint(0.25, 35, 9.9);
  square->AddPoint(0.5, 35, 3.1);
  square->AddPoint(1, 35, 0.8);
  square->AddPoint(2, 35, 0.2);
  square->AddPoint(3, 35, 0.2);
  square->AddPoint(4, 35, 0.1);
  square->AddPoint(5, 35, 0.1);
  square->AddPoint(7.5, 35, 0.1);
  square->AddPoint(10, 35, 0.1);

  square->AddPoint(0.1, 11, 3.5);
  square->AddPoint(0.25, 11, 0.7);
  square->AddPoint(0.5, 11, 0.1);
  square->AddPoint(1, 11, 0);
  square->AddPoint(2, 11, 0);
  square->AddPoint(3, 11, 0);
  square->AddPoint(4, 11, 0);
  square->AddPoint(5, 11, 0);
  square->AddPoint(7.5, 11, 0);
  square->AddPoint(10, 11, 0);

  cout << "test = " << square->Interpolate(1.5, 51) << endl;

  square->SetMinimum(0.01);
  square->SetMaximum(200);
  //square->Draw("colzcont4");

  TH2D* h_square = new TH2D();
  h_square = square->GetHistogram();
  h_square->Draw("colzcont4");
  h_square->SetContour(99);


  new TCanvas;

  TGraph2D * round = new TGraph2D();

  round->AddPoint(0.1, 201, 189.2);
  round->AddPoint(0.25, 201, 140.9);
  round->AddPoint(0.5, 201, 92.1);
  round->AddPoint(1, 201, 55.1);
  round->AddPoint(2, 201, 39.6);
  round->AddPoint(3, 201, 40.3);
  round->AddPoint(4, 201, 44.0);
  round->AddPoint(5, 201, 49.2);
  round->AddPoint(7.5, 201, 73.1);
  round->AddPoint(10, 201, 113.0);

  round->AddPoint(0.1, 101, 144.7);
  round->AddPoint(0.25, 101, 72.7);
  round->AddPoint(0.5, 101, 39.4);
  round->AddPoint(1, 101, 25.2);
  round->AddPoint(2, 101, 19.8);
  round->AddPoint(3, 101, 19.0);
  round->AddPoint(4, 101, 20.4);
  round->AddPoint(5, 101, 22.2);
  round->AddPoint(7.5, 101, 32.6);
  round->AddPoint(10, 101, 51.6);

  round->AddPoint(0.1, 51, 48.4);
  round->AddPoint(0.25, 51, 22.6);
  round->AddPoint(0.5, 51, 13.7);
  round->AddPoint(1, 51, 8.7);
  round->AddPoint(2, 51, 6.2);
  round->AddPoint(3, 51, 5.8);
  round->AddPoint(4, 51, 5.7);
  round->AddPoint(5, 51, 6.3);
  round->AddPoint(7.5, 51, 10.0);
  round->AddPoint(10, 51, 14.6);

  round->AddPoint(0.1, 35, 28.1);
  round->AddPoint(0.25, 35, 13.1);
  round->AddPoint(0.5, 35, 7.4);
  round->AddPoint(1, 35, 4.4);
  round->AddPoint(2, 35, 3.0);
  round->AddPoint(3, 35, 2.7);
  round->AddPoint(4, 35, 2.7);
  round->AddPoint(5, 35, 3.0);
  round->AddPoint(7.5, 35, 4.2);
  round->AddPoint(10, 35, 6.8);

  round->AddPoint(0.1, 11, 3.9);
  round->AddPoint(0.25, 11, 1.5);
  round->AddPoint(0.5, 11, 0.7);
  round->AddPoint(1, 11, 0.3);
  round->AddPoint(2, 11, 0.2);
  round->AddPoint(3, 11, 0.2);
  round->AddPoint(4, 11, 0.1);
  round->AddPoint(5, 11, 0.1);
  round->AddPoint(7.5, 11, 0.3);
  round->AddPoint(10, 11, 0.2);

  cout << "test = " << round->Interpolate(1.5, 51) << endl;

  round->SetMinimum(0.01);
  round->SetMaximum(200);
  //round->Draw("colzcont4");

  TH2D* h_round = new TH2D();
  h_round = round->GetHistogram();
  h_round->Draw("colzcont4");
  h_round->SetContour(99);
  
}
