TGraph2D* Tubs_3D;
TGraph2D* Inner_3D;
TGraph2D* Core_3D;
TGraph* Tubs_xy;
TGraph* Tubs_sq_xy;
TGraph* Inner_xy;
TGraph* Inner_sq_xy;
TGraph* Core_xy;
TGraph* Tubs_xz;
TGraph* Inner_xz;
TGraph* Core_xz;
TGraph* Tubs_yz;
TGraph* Inner_yz;
TGraph* Core_yz;
float Traj_X[10000000];
float Traj_Y[10000000];
float Traj_Z[10000000];
float Angle[10000000];
int Final_State_Photon[10000000];
float Pos_X[10000000];
float Pos_Y[10000000];
TGraph2D* g[10000000];
TGraph* xy[10000000];
TGraph* xz[10000000];
TGraph* yz[10000000];
TPad *pad1;
TPad *pad2;
TPad *pad3;
TPad *pad4;
int NTraj_stored;


void Draw_ALL_Results(float condition_angle, int condition_status)
{

  for(int i = 0; i< NTraj_stored; i++)
    {
      if (Angle[i] > condition_angle && Final_State_Photon[i] == condition_status)
	{

	  getchar();
	  cout << "TRAJECTORY NUMBER " << i << " with creation angle = " << Angle[i] << endl;
	  cout << "Final Status of photon = " << Final_State_Photon[i] << endl;
	  
	  pad1->cd();
	  Tubs_3D->SetTitle("3D");
	  Tubs_3D->Draw("P");
	  Inner_3D->Draw("PSAME");
	  Core_3D->Draw("PSAME");
	  Tubs_3D->SetMarkerColor(kBlue);
	  Inner_3D->SetMarkerColor(kCyan);
	  Core_3D->SetMarkerColor(kRed);
	  g[i]->Draw("SAMELINE");
	  g[i]->SetLineColor(kGreen);
	  pad1->Update();

	  string sAngle = Form("Angle depart=  %g deg", Angle[i]);
	  TLatex *lAngle = new TLatex(-0.8,0.85, sAngle.c_str());
	  lAngle->Draw();
	  lAngle->SetTextSize(0.04);
	  lAngle->SetTextColor(kRed);

	  pad2->cd();
	  //Tubs_xy->SetTitle("Plan XY");
	  //Tubs_xy->Draw("AP");
	  //Tubs_xy->GetXaxis()->SetLimits(-1.1,0.1);
	  //Tubs_xy->GetHistogram()->SetMinimum(-0.1);
	  //Tubs_xy->GetHistogram()->SetMaximum(1.1);
	  //Tubs_xy->SetMarkerColor(kBlue);
	  //Inner_xy->SetMarkerColor(kCyan);
	  //Core_xy->SetMarkerColor(kRed);
	  //Inner_xy->Draw("PSAME");
	  //Core_xy->Draw("PSAME");
	  //xy[i]->Draw("SAME");
	  //xy[i]->SetLineColor(kGreen);

	  Tubs_sq_xy->SetTitle("Plan XY");
	  Tubs_sq_xy->Draw("AP");
	  Inner_sq_xy->Draw("PSAME");
	  Tubs_sq_xy->SetMarkerColor(kBlue);
	  Inner_sq_xy->SetMarkerColor(kCyan);
	  xy[i]->Draw("SAME");
	  xy[i]->SetLineColor(kGreen);
	  
	  pad2->Update();


	  pad3->cd();
	  Tubs_xz->SetTitle("Plan XZ");
	  Tubs_xz->Draw("AP");
	  // Tubs_xz->GetXaxis()->SetLimits(-50,50);
	  // Tubs_xz->GetHistogram()->SetMinimum(-1);
	  // Tubs_xz->GetHistogram()->SetMaximum(0);
	  Tubs_xz->SetMarkerColor(kBlue);
	  Inner_xz->SetMarkerColor(kCyan);
	  Core_xz->SetMarkerColor(kRed);
	  Inner_xz->Draw("PSAME");
	  //Core_xz->Draw("PSAME");
	  xz[i]->Draw("SAME");
	  xz[i]->SetLineColor(kGreen);
	  pad3->Update();


	  pad4->cd();
	  Tubs_yz->SetTitle("Plan YZ");
	  Tubs_yz->Draw("AP");
	  //Tubs_yz->GetXaxis()->SetLimits(-55,55);
	  //Tubs_yz->GetHistogram()->SetMinimum(-0.6);
	  //Tubs_yz->GetHistogram()->SetMaximum(0);
	  Tubs_yz->SetMarkerColor(kBlue);
	  Inner_yz->SetMarkerColor(kCyan);
	  Core_yz->SetMarkerColor(kRed);
	  Inner_yz->Draw("PSAME");
	  //Core_yz->Draw("PSAME");
	  yz[i]->Draw("SAME");
	  yz[i]->SetLineColor(kGreen);
	  pad4->Update();


	}

        else continue;
    }

  
}

void Draw_Particular_Results(int i)
{

  pad1->cd();
  Tubs_3D->SetTitle("3D");
  Tubs_3D->Draw("P");
  Inner_3D->Draw("PSAME");
  Core_3D->Draw("PSAME");
  Tubs_3D->SetMarkerColor(kBlue);
  Inner_3D->SetMarkerColor(kCyan);
  Core_3D->SetMarkerColor(kRed);
  g[i]->Draw("SAMELINE");
  g[i]->SetLineColor(kGreen);

  string sAngle = Form("Angle depart=  %g deg", Angle[i]);
  TLatex *lAngle = new TLatex(-0.8,0.85, sAngle.c_str());
  lAngle->Draw();
  lAngle->SetTextSize(0.04);
  lAngle->SetTextColor(kRed);

  pad2->cd();
  Tubs_xy->SetTitle("Plan XY");
  Tubs_xy->Draw("AP");
  // Tubs_xy->GetXaxis()->SetLimits(-1,0);
  // Tubs_xy->GetHistogram()->SetMinimum(0);
  // Tubs_xy->GetHistogram()->SetMaximum(1);
  Tubs_xy->SetMarkerColor(kBlue);
  Inner_xy->SetMarkerColor(kCyan);
  Core_xy->SetMarkerColor(kRed);
  Inner_xy->Draw("PSAME");
  Core_xy->Draw("PSAME");
  xy[i]->Draw("SAME");
  xy[i]->SetLineColor(kGreen);


  pad3->cd();
  Tubs_xz->SetTitle("Plan XZ");
  Tubs_xz->Draw("AP");
  // Tubs_xz->GetXaxis()->SetLimits(-50,50);
  // Tubs_xz->GetHistogram()->SetMinimum(-1);
  // Tubs_xz->GetHistogram()->SetMaximum(0);
  Tubs_xz->SetMarkerColor(kBlue);
  Inner_xz->SetMarkerColor(kCyan);
  Core_xz->SetMarkerColor(kRed);
  Inner_xz->Draw("PSAME");
  Core_xz->Draw("PSAME");
  xz[i]->Draw("SAME");
  xz[i]->SetLineColor(kGreen);


  pad4->cd();
  Tubs_yz->SetTitle("Plan YZ");
  Tubs_yz->Draw("AP");
  //Tubs_yz->GetXaxis()->SetLimits(-55,55);
  //Tubs_yz->GetHistogram()->SetMinimum(-0.1);
  //Tubs_yz->GetHistogram()->SetMaximum(0);
  Tubs_yz->SetMarkerColor(kBlue);
  Inner_yz->SetMarkerColor(kCyan);
  Core_yz->SetMarkerColor(kRed);
  Inner_yz->Draw("PSAME");
  Core_yz->Draw("PSAME");
  yz[i]->Draw("SAME");
  yz[i]->SetLineColor(kGreen);


}


void Create_Pad_Canvas()
{
  TCanvas *c1 = new TCanvas("TRAJECTORY", "TRAJECTORY", 0, 10, 1200, 900);
  c1->SetWindowPosition(600, 0);
  pad1 = new TPad("pad1", "", 0, 0.51, 0.49, 1);
  pad2 = new TPad("pad2", "", 0.51, 0.51, 1, 1);
  pad3 = new TPad("pad3", "", 0, 0, 0.49, 0.49);
  pad4 = new TPad("pad4", "", 0.51, 0., 1, 0.49);
  
  pad1->Draw();
  pad2->Draw();
  pad3->Draw();
  pad4->Draw();
}

void Create_Trajectory(const char* filename)
{
  NTraj_stored =0;
  
  TFile* file = new TFile(filename);
  TTree *Tree = (TTree*)file->Get("Optical");

  std::vector<float>* x=0;
  std::vector<float>* y=0;
  std::vector<float>* z=0;
  std::vector<int>* N=0;
  std::vector<int>* FinalState=0;
  std::vector<float>* vAngle=0;
  std::vector<float>* Posx=0;
  std::vector<float>* Posy=0;
  
  Tree->SetBranchAddress("PhotonTrajectoryX", &x);
  Tree->SetBranchAddress("PhotonTrajectoryY", &y);
  Tree->SetBranchAddress("PhotonTrajectoryZ", &z);
  Tree->SetBranchAddress("PhotonTrajectoryNStep", &N);
  Tree->SetBranchAddress("Angle_creation", &vAngle);
  Tree->SetBranchAddress("Final_state_photon", &FinalState);
  // Tree->SetBranchAddress("PositionX", &Posx);
  // Tree->SetBranchAddress("PositionY", &Posy);

  const int Entries = Tree->GetEntries();

  cout << "entries = " << Entries << endl;

  int NStep_TOT=0;
  int Trajectory_Number=1;
  int TrajectoryStep_Number=0;  

  for(int i=0; i<Entries; i++)
    {
      x->clear();
      y->clear();
      z->clear();
      Tree->GetEntry(i);
      cout << "N photons trajectory stored = " << N->size() << endl;
      NTraj_stored = N->size();
      
    for (int j=0; j<N->size(); j++)
      {
	//cout << "Photon trajectory number " << j+1 << " with " << N->at(j) << " steps" << endl;
	NStep_TOT += N->at(j);
	Angle[j] = vAngle->at(j);
	if (Angle[j]>90) {Angle[j] =180-Angle[j];}
	Final_State_Photon[j] = FinalState->at(j);
	//cout << "j = " << j << endl;
      }
    
    }

  //cout << "N Step TOT = " << NStep_TOT << endl;

    for (int i=0; i< NStep_TOT; i++)
      {
	Traj_X[TrajectoryStep_Number] = x->at(i);
	Traj_Y[TrajectoryStep_Number] = y->at(i);
	Traj_Z[TrajectoryStep_Number] = z->at(i);
	// Pos_X[TrajectoryStep_Number] = Posx->at(i);
	// Pos_Y[TrajectoryStep_Number] = Posy->at(i);
	//cout << "x[" << i << "] = " << x->at(i) << endl;
	// cout << "y[" << i << "] = " << y->at(i) << endl;
	// cout << "z[" << i << "] = " << z->at(i) << endl;
	//	cout << "i = " << i << endl;
	TrajectoryStep_Number++;

	if (TrajectoryStep_Number == N->at(Trajectory_Number-1))
	  {
	    //cout << "Trajectory Number = " << Trajectory_Number << " with a creation angle of " << Angle[Trajectory_Number-1] <<  endl;
	    //cout << "Trajectory Step Number = " << TrajectoryStep_Number << " : " << endl;
	    g[Trajectory_Number-1] = new TGraph2D (TrajectoryStep_Number, Traj_Z, Traj_X, Traj_Y);
	    string sName = Form("Trajectory  %d", Trajectory_Number);
	    g[Trajectory_Number-1]->SetName(sName.c_str());
	    xy[Trajectory_Number-1] = new TGraph(TrajectoryStep_Number, Traj_X, Traj_Y);
	    xz[Trajectory_Number-1] = new TGraph(TrajectoryStep_Number, Traj_Z, Traj_X);
	    yz[Trajectory_Number-1] = new TGraph(TrajectoryStep_Number, Traj_Z, Traj_Y);
	    Trajectory_Number++;
	    TrajectoryStep_Number=0;
	  }
      }

    
}















TGraph2D* Create_Fiber_3D(float fiber_radius, float inner_radius, float core_radius, float fiber_length)
{
  float TubsX[100000];
  float TubsY[100000];
  float TubsZ[100000];
  int n=0;
  
    for (float z=-fiber_length; z <fiber_length; z+=5)
    {
      for (float x=-fiber_radius; x<fiber_radius; x+=0.1)
	{
	  TubsX[n] = x;
	  //TubsY[n] = sqrt(fiber_radius*fiber_radius-(x+fiber_radius)*(x+fiber_radius))+fiber_radius;
	  TubsY[n] = sqrt(fiber_radius*fiber_radius - x*x);
	  TubsZ[n] = z;
	  n++;
	  TubsX[n] = x;
	  //TubsY[n] = -sqrt(fiber_radius*fiber_radius-(x+fiber_radius)*(x+fiber_radius))+fiber_radius;
	  TubsY[n] = -sqrt(fiber_radius*fiber_radius - x*x);
	  TubsZ[n] = z;
	  n++;
	}	      
    }

    TGraph2D* g = new TGraph2D (n, TubsZ, TubsX, TubsY);

    return g;

}


TGraph2D* Create_Inner_3D(float fiber_radius, float inner_radius, float core_radius, float fiber_length)
{
  float TubsX[100000];
  float TubsY[100000];
  float TubsZ[100000];
  int n=0;
  
    for (float z=-fiber_length; z <fiber_length; z+=5)
    {
      for (float x=-inner_radius; x<inner_radius; x+=0.1)
	{
	  TubsX[n] = x;
	  //TubsY[n] = sqrt(core_radius*core_radius-(x+fiber_radius)*(x+fiber_radius))+fiber_radius;
	  TubsY[n] = sqrt(inner_radius*inner_radius-x*x);
	  TubsZ[n] = z;
	  n++;
	  TubsX[n] = x;
	  //TubsY[n] = -sqrt(core_radius*core_radius-(x+fiber_radius)*(x+fiber_radius))+fiber_radius;
	  TubsY[n] = -sqrt(inner_radius*inner_radius-x*x);
	  TubsZ[n] = z;
	  n++;
	}	      
    }

    TGraph2D* g = new TGraph2D (n, TubsZ, TubsX, TubsY);

    return g;

}


TGraph2D* Create_Core_3D(float fiber_radius, float inner_radius, float core_radius, float fiber_length)
{
  float TubsX[100000];
  float TubsY[100000];
  float TubsZ[100000];
  int n=0;
  
    for (float z=-fiber_length; z <fiber_length; z+=5)
    {
      for (float x=-core_radius; x<core_radius; x+=0.1)
	{
	  TubsX[n] = x;
	  //TubsY[n] = sqrt(core_radius*core_radius-(x+fiber_radius)*(x+fiber_radius))+fiber_radius;
	  TubsY[n] = sqrt(core_radius*core_radius-x*x);
	  TubsZ[n] = z;
	  n++;
	  TubsX[n] = x;
	  //TubsY[n] = -sqrt(core_radius*core_radius-(x+fiber_radius)*(x+fiber_radius))+fiber_radius;
	  TubsY[n] = -sqrt(core_radius*core_radius-x*x);
	  TubsZ[n] = z;
	  n++;
	}	      
    }

    TGraph2D* g = new TGraph2D (n, TubsZ, TubsX, TubsY);

    return g;

}


TGraph* Create_Fiber_XY(float fiber_radius, float inner_radius, float core_radius, float fiber_length)
{
  float TubsX[1000];
  float TubsY[1000];
  int n=0;
  
  for (float x=-fiber_radius; x<fiber_radius; x+=0.01)
    {
      TubsX[n] = x;
      //TubsY[n] = sqrt(fiber_radius*fiber_radius-(x+fiber_radius)*(x+fiber_radius))+fiber_radius;
      TubsY[n] = sqrt(fiber_radius*fiber_radius - x*x);
      n++;
      TubsX[n] = x;
      //TubsY[n] = -sqrt(fiber_radius*fiber_radius-(x+fiber_radius)*(x+fiber_radius))+fiber_radius;
      TubsY[n] = -sqrt(fiber_radius*fiber_radius - x*x);
      n++;
    }	      
  
  TGraph* g = new TGraph (n, TubsX, TubsY);
  
  return g;

}


TGraph* Create_Inner_XY(float fiber_radius, float inner_radius, float core_radius, float fiber_length)
{
  float TubsX[1000];
  float TubsY[1000];
  int n=0;
  
  for (float x=-inner_radius; x<inner_radius; x+=0.01)
    {
      TubsX[n] = x;
      //TubsY[n] = sqrt(fiber_radius*fiber_radius-(x+fiber_radius)*(x+fiber_radius))+fiber_radius;
      TubsY[n] = sqrt(inner_radius*inner_radius - x*x);
      n++;
      TubsX[n] = x;
      //TubsY[n] = -sqrt(fiber_radius*fiber_radius-(x+fiber_radius)*(x+fiber_radius))+fiber_radius;
      TubsY[n] = -sqrt(inner_radius*inner_radius - x*x);
      n++;
    }	      
  
  TGraph* g = new TGraph (n, TubsX, TubsY);
  
  return g;

}


TGraph* Create_Core_XY(float fiber_radius, float inner_radius, float core_radius, float fiber_length)
{
  float TubsX[1000];
  float TubsY[1000];
  int n=0;
  
  for (float x=-core_radius; x<core_radius; x+=0.01)
    {
      TubsX[n] = x;
      //TubsY[n] = sqrt(core_radius*core_radius-(x+fiber_radius)*(x+fiber_radius))+fiber_radius;
      TubsY[n] = sqrt(core_radius*core_radius-x*x);
      n++;
      TubsX[n] = x;
      //TubsY[n] = -sqrt(core_radius*core_radius-(x+fiber_radius)*(x+fiber_radius))+fiber_radius;
      TubsY[n] = -sqrt(core_radius*core_radius-x*x);
      n++;
    }	      
  
  TGraph* g = new TGraph (n, TubsX, TubsY);
  
  return g;

}


TGraph* Create_Square_Fiber_XY(float fiber_radius, float inner_radius, float core_radius, float fiber_length)
{
  float TubsX[10000];
  float TubsY[10000];
  int n=0;
  
  for (float x=-fiber_radius; x<fiber_radius; x+=0.01)
    {
      TubsX[n] = x;
      TubsY[n] = -fiber_radius;
      n++;
      TubsX[n] = x;
      TubsY[n] = fiber_radius;
      n++;

      
      if(x==-fiber_radius)
	{
	  for (float y=-fiber_radius; y<fiber_radius; y+=0.01)
	    {
	      TubsX[n] = x;
	      TubsY[n] = y;
	      n++;
	    }
	}

      if(x>fiber_radius-0.01)
	{
	  for (float z=-fiber_radius; z<fiber_radius; z+=0.01)
	    {
	      TubsX[n] = x;
	      TubsY[n] = z;
	      n++;
	    }
	}
      
    }	      
  
  TGraph* g = new TGraph (n, TubsX, TubsY);
  
  return g;

}


TGraph* Create_Square_Inner_XY(float fiber_radius, float inner_radius, float core_radius, float fiber_length)
{
  float TubsX[10000];
  float TubsY[10000];
  int n=0;

    for (float x=-inner_radius; x<inner_radius; x+=0.01)
    {
      TubsX[n] = x;
      TubsY[n] = -inner_radius;
      n++;
      TubsX[n] = x;
      TubsY[n] = inner_radius;
      n++;

      
      if(x==-inner_radius)
	{
	  for (float y=-inner_radius; y<inner_radius; y+=0.01)
	    {
	      TubsX[n] = x;
	      TubsY[n] = y;
	      n++;
	    }
	}

      if(x>inner_radius-0.01)
	{
	  for (float z=-inner_radius; z<inner_radius; z+=0.01)
	    {
	      TubsX[n] = x;
	      TubsY[n] = z;
	      n++;
	    }
	}
      
    }	      

  
  TGraph* g = new TGraph (n, TubsX, TubsY);
  
  return g;

}


TGraph* Create_Fiber_XZ(float fiber_radius, float inner_radius, float core_radius, float fiber_length)
{
  float TubsX[10000];
  float TubsZ[10000];
  int n=0;


  for (float z=-fiber_length; z <fiber_length; z+=0.5)
    {
      TubsX[n] = -fiber_radius;
      TubsZ[n] = z;
      n++;
      TubsX[n] = fiber_radius;
      TubsZ[n] = z;
      n++;
    }
  
  TGraph* g = new TGraph (n, TubsZ, TubsX);

  return g;
}


TGraph* Create_Inner_XZ(float fiber_radius, float inner_radius, float core_radius, float fiber_length)
{
  float TubsX[10000];
  float TubsZ[10000];
  int n=0;

  for (float z=-fiber_length; z <fiber_length; z+=0.5)
    {
      TubsX[n] = -inner_radius;
      TubsZ[n] = z;
      n++;
      TubsX[n] = inner_radius;
      TubsZ[n] = z;
      n++;
    }
  
  TGraph* g = new TGraph (n, TubsZ, TubsX);

  return g;

}


TGraph* Create_Core_XZ(float fiber_radius, float inner_radius, float core_radius, float fiber_length)
{
  float TubsX[10000];
  float TubsZ[10000];
  int n=0;


  for (float z=-fiber_length; z <fiber_length; z+=0.5)
    {
      TubsX[n] = -core_radius;
      TubsZ[n] = z;
      n++;
      TubsX[n] = core_radius;
      TubsZ[n] = z;
      n++;
    }
  
  TGraph* g = new TGraph (n, TubsZ, TubsX);

  return g;

}


TGraph* Create_Fiber_YZ(float fiber_radius, float inner_radius, float core_radius, float fiber_length)
{
  float TubsY[10000];
  float TubsZ[10000];
  int n=0;

  for (float z=-fiber_length; z <fiber_length; z+=0.5)
    {
      TubsY[n] = -fiber_radius;
      TubsZ[n] = z;
      n++;
      TubsY[n] = fiber_radius;
      TubsZ[n] = z;
      n++;
    }
  
  TGraph* g = new TGraph (n, TubsZ, TubsY);

  return g;

}


TGraph* Create_Inner_YZ(float fiber_radius, float inner_radius, float core_radius, float fiber_length)
{
  float TubsY[10000];
  float TubsZ[10000];
  int n=0;

  for (float z=-fiber_length; z <fiber_length; z+=0.5)
    {
      TubsY[n] = -inner_radius;
      TubsZ[n] = z;
      n++;
      TubsY[n] = inner_radius;
      TubsZ[n] = z;
      n++;
    }
  
  TGraph* g = new TGraph (n, TubsZ, TubsY);

  return g;

}


TGraph* Create_Core_YZ(float fiber_radius, float inner_radius, float core_radius, float fiber_length)
{
  float TubsY[10000];
  float TubsZ[10000];
  int n=0;

  for (float z=-fiber_length; z <fiber_length; z+=0.5)
    {
      TubsY[n] = -core_radius;
      TubsZ[n] = z;
      n++;
      TubsY[n] = core_radius;
      TubsZ[n] = z;
      n++;
    }
  
  TGraph* g = new TGraph (n, TubsZ, TubsY);

  return g;

}


void Initialisation_Geometrie(float fiber_radius, float inner_radius, float core_radius, float fiber_length)
{

  Tubs_3D = Create_Fiber_3D(fiber_radius, inner_radius, core_radius, fiber_length);
  Inner_3D = Create_Inner_3D(fiber_radius, inner_radius, core_radius, fiber_length);
  Core_3D = Create_Core_3D(fiber_radius, inner_radius, core_radius, fiber_length);
  Tubs_xy = Create_Fiber_XY(fiber_radius, inner_radius, core_radius, fiber_length);
  Tubs_sq_xy = Create_Square_Fiber_XY(fiber_radius, inner_radius, core_radius, fiber_length);
  Inner_sq_xy = Create_Square_Inner_XY(fiber_radius, inner_radius, core_radius, fiber_length);
  Inner_xy = Create_Inner_XY(fiber_radius, inner_radius, core_radius, fiber_length);
  Core_xy = Create_Core_XY(fiber_radius, inner_radius, core_radius, fiber_length);
  Tubs_xz = Create_Fiber_XZ(fiber_radius, inner_radius, core_radius, fiber_length);
  Inner_xz = Create_Inner_YZ(fiber_radius, inner_radius, core_radius, fiber_length);
  Core_xz = Create_Core_XZ(fiber_radius, inner_radius, core_radius, fiber_length);
  Tubs_yz = Create_Fiber_YZ(fiber_radius, inner_radius, core_radius, fiber_length);
  Inner_yz = Create_Inner_YZ(fiber_radius, inner_radius, core_radius, fiber_length);
  Core_yz = Create_Core_YZ(fiber_radius, inner_radius, core_radius, fiber_length);

}
