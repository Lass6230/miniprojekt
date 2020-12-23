#include <iostream>
#include "ros/ros.h"
#include <actionlib/server/simple_action_server.h>
#include <move_base_msgs/MoveBaseAction.h>
// #include "my_code_msgs/myString.h"

// #include <my_code_msgs/CountUntilAction.h>
// #include <my_code_msgs/CountUntilGoal.h>
// #include <my_code_msgs/CountUntilResult.h>
// #include <my_code_msgs/CountUntilFeedback.h>
using namespace std;

void ExecuteCallback(const move_base_msgs::MoveBaseGoal::ConstPtr &msg);
  

// typedef actionlib::SimpleActionClient<my_code_msgs::CountUntilAction> Client;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "thing");
   ros::NodeHandle nh;
    actionlib::SimpleActionServer<move_base_msgs::MoveBaseAction> ac(nh,"sender", ExecuteCallback , false);
    ac.start();
    ros::ServiceServer service = nh.advertiseService("sevice_ting",);
    
    
    ros::spin();

    
    // Client my_client("CountUntil", true);
    // my_client.waitForServer();
    // my_code_msgs::CountUntilGoal goal;
    // goal.max_number = 10;
    // goal.wait_duration = 10.0;
    // my_client.sendGoal(goal);
    // my_client.waitForResult(ros::Duration(5.0));

    // if(my_client.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    // {
    //     cout << "det lykkes :)" << '\n';
    //     cout << "Current State: %s\n", my_client.getState().toString().c_str();
    //     return 0;
    // }

    // ros::ServiceClient client = n.serviceClient<my_code_msgs::myString>("myString");
    // my_code_msgs::myString srv;
    // stringstream ss;
    // ss << "hej";
    // srv = ss;
    // if(client.call(srv))
    // {
    //     ROS_INFO("jeps så er den send");
    // }
    // else
    // {
    //     ROS_INFO("det virkede ikke");
    // }
    ROS_INFO("første hey");
    // ac.result(true);
    ROS_INFO("hey");
    return 0;
}

void ExecuteCallback(const move_base_msgs::MoveBaseGoalConstPtr &msg){
    ROS_INFO("hej med jer");
    move_base_msgs::MoveBaseGoal mg;
    
    double x = static_cast<double>(msg->target_pose.pose.position.x);
    double y = static_cast<double>(msg->target_pose.pose.position.y);
    double z = static_cast<double>(msg->target_pose.pose.orientation.z);
    double w = static_cast<double>(msg->target_pose.pose.orientation.w);
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    cout << "z: " << z << endl;
    cout << "w: " << w << endl;
    cout << mg << endl;
    
}
