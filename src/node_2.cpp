#include <iostream>
#include <ros/ros.h>  
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
// #include "my_code_msgs/myString.h"
//  #include <my_code_msgs/CountUntilAction.h>
// #include <my_code_msgs/CountUntilGoal.h>
// #include <my_code_msgs/CountUntilResult.h>
// #include <my_code_msgs/CountUntilFeedback.h>
using namespace std;

//void testAction();
// typedef actionlib::SimpleActionServer<my_code_msgs::CountUntilAction> Server;

// void execute(const int my_code_msgs::CountUtilGoal max_number, const float my_code_msgs::CountUntilGoal wait_duration, Server* as)
// {   
//     // goal.max_number;
//     // goal.wait_duration;
//     int i = 10;
    
//     if(i == goal.max_nuber)
//     {
//     as->setSucceeded();
//     }
// }
// String text(my_code_msgs::myString::str hej)
// {
//     cout << hej << endl;

// }


int main(int argc, char **argv)
{
    ros::init(argc, argv, "node_2");
    ros::NodeHandle n;
    // ros::ServiceServer service = n.advertiseService("myString",text);
    ROS_INFO("Ready to do action.");
    actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> ac("sender", true);

	//wait for the action server to come up
	while(!ac.waitForServer(ros::Duration(5.0))){
		ROS_INFO("Waiting for the move_base action server to come up");
	}

	move_base_msgs::MoveBaseGoal goal;

	//set up the frame parameters
	goal.target_pose.header.frame_id = "map";
	goal.target_pose.header.stamp = ros::Time::now();

	/* moving towards the goal*/

	goal.target_pose.pose.position.x = 1.0;
	goal.target_pose.pose.position.y =  12.0;
	goal.target_pose.pose.position.z =  0.0;
	goal.target_pose.pose.orientation.x = 0.0;
	goal.target_pose.pose.orientation.y = 0.0;
	goal.target_pose.pose.orientation.z = 6.0;
	goal.target_pose.pose.orientation.w = 3.0;

	ROS_INFO("Sending goal location ...");
  cout << goal << '\n';
	ac.sendGoal(goal);
    ac.waitForResult();
    // Server my_server(n, "CountUtil",boost::bind(&execute, _1, &my_server), false);
    // my_server.start();
    ros::spinOnce();
    return 0;
}
