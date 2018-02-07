/******************************************************************************
| lane_keep.h                                                                 |
| ...                                                                         |
******************************************************************************/

#ifndef LANE_CHANGE_H
#define LANE_CHANGE_H

#include "behavior.h"
#include "trajectory.h"
#include <cmath>

class LaneChange: public Behavior {
  public:
    LaneChange();
    ~LaneChange();
    void add_trajectories(TrajectorySet &t_set,
                          double si, double si_dot, double si_dot_dot,
                          double di, double di_dot, double di_dot_dot,
                          const int &current_lane, const Road &r,
                          ObstacleTracker &o) const;

    double cost(const Trajectory &traj, const double &target_s, const double &target_d, const double &target_s_dot) const;
    double cost2(const Trajectory &traj, const double &target_speed, const double &target_d, const double &speed_limit) const;

    std::string name() const;

  private:

    // Constants for time gap and distance buffer
    double distance_buffer; // D_0
    double time_gap;        // Tau

    // Cost calculation variables
    double dt;  // time step size for integral costs
    double k_j; // Coeff for jerk cost
    double k_t; // Coeff for time cost
    double k_s; // Coeff for lat movement cost
    double k_d; // Coeff for lon movement cost

    double k_lat; // weight of lat costs
    double k_lon; // weight of lon costs
};

#endif // __LANE_CHANGE_H__