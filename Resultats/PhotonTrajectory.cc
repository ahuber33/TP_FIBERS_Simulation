#include "PhotonTrajectory.hh"

void PhotonTrajectory()
{
  int noftraj =0;
  float fiber_radius =0.5;
  float inner_radius =0.48;
  float core_radius =0.46;
  float fiber_length = 50;
  float condition_angle =0;
  int condition_status =0;

  Initialisation_Geometrie(fiber_radius, inner_radius, core_radius, fiber_length);

    Create_Trajectory("a.root");
  //  Create_Trajectory("a.root");


  cout << "Which trajectory ? (0 is for all) [" << NTraj_stored -1 << " trajectories stored]"  << endl;
  cin >> noftraj;


  if (noftraj ==0)
    {
      cout << "Condition on creation angle ?" << endl;
      cin >> condition_angle;
      cout << "Condition on final status ?" << endl;
      cin >> condition_status;
      Create_Pad_Canvas();
      Draw_ALL_Results(condition_angle, condition_status);
    }

  if (noftraj >0)
    {
      Create_Pad_Canvas();
      Draw_Particular_Results(noftraj);
    }
  

}
