#include <iostream>
#include "ros/ros.h"
#include <ros/ros.h>
#include <string>
#include <std_msgs/String.h>
using namespace std;
ros::NodeHandle n;
void pub(int i);

int main(int argc, char **argv)
{
    ros::init(argc, argv, "node_2");
    //ros::NodeHandle n;
    ros::spinOnce();
return 0;

}

void pub(int i){

    ros::Publisher int_pub = n.advertise<std_msgs::String>("int_chat", 1000);
    std_msgs::String msg;
    stringstream msg_data;
    msg_data << "davs";
    msg.data = msg_data.str();
    ROS_INFO("%S", msg.data.c_str());
    int_pub.publish(msg);
    ros::spinOnce();

}