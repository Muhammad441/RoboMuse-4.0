#include "ros/ros.h"
#include "baxter_core_msgs/msg/EndEffectorCommand.h"


int main(int argc, char **argv)
{

  ros::init(argc, argv, "talker");
  ros::NodeHandle node;
  ros::Publisher  gripper_cmd_pub = node.advertise<baxter_core_msgs::EndEffectorCommand>("/robot/end_effector/right_gripper/command",1);

  ros::Time current_time, last_time;
  current_time = ros::Time::now();
  last_time = ros::Time::now();


  ros::Rate loop_rate(20);

  while (ros::ok())
  {

    baxter_core_msgs::EndEffectorCommand gripper_cmd_msg;

    gripper_cmd_msg.id = 65538;
    gripper_cmd_msg.command = "CMD_GO";

    gripper_cmd_msg.sender = "foo";
    gripper_cmd_msg.sequence = 1;


    gripper_cmd_pub.publish(gripper_cmd_msg);


    ROS_INFO("%s", gripper_cmd_msg.command.c_str());

    ros::spinOnce();

    last_time = current_time;

    loop_rate.sleep();
  }


}
