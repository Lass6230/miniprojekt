#include <iostream>
#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <std_msgs/String.h>
#include <actionlib/server/simple_action_server.h>
// #include <service_server.h>
using namespace std;

// void callback(const std_msgs::StringConstPtr& msg)
// {
//     ROS_INFO("I heard: [%s]", msg->data.c_str());
//     std::string onOff = msg->data.c_str();

// }


int main(int argc, char **argv)
{   
    ros::init(argc, argv, "drive_and_write");
    ros::NodeHandle n;
    //  ros::ServiceServer service = n.serviceServer("node_2", callback);
    
    ros::spin();

    return 0;

}