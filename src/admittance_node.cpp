#include "ros/ros.h"
#include "nrs_admittance_control_pkg/nrs_admittance.hpp"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "admittance_node");
    ros::NodeHandle nh;

    ros::Rate rate(100); // 100Hz
    NRS_admittance_control adm_ctrl(0.01); // 10ms sampling time

    /* Set initial mass, damping, and stiffness */ 
    adm_ctrl.adm_1D_MDK(1.0, 5.0, 50.0);

    double xd = 0.0;
    double Fd = 0.0;
    double Fext = 0.0;

    while (ros::ok())
    {
        Fext = 5.0 * sin(ros::Time::now().toSec());
        xd += 0.001;
        double output = adm_ctrl.adm_1D_control(xd, Fd, Fext); // output : position control cmd

        ROS_INFO("xd: %.3f, Fext: %.3f, xc: %.3f", xd, Fext, output);

        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}
