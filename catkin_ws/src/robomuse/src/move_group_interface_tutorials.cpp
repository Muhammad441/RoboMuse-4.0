/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2013, SRI International
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of SRI International nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/

/* Author: Sachin Chitta */
#include <moveit/move_group_interface/move_group.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>
//#include <tf.h>
#include <tf/transform_listener.h>
#include <pluginlib/class_loader.h>
#include <nav2d_operator/cmd.h>
#include<fstream>
#include<iostream>
int flag;
const std::string PLUGIN = "youbot_arm_kinematics_moveit::KinematicsPlugin";
typedef boost::shared_ptr<kinematics::KinematicsBase> KinematicsBasePtr;

int main(int argc, char **argv)
{ std::ofstream myfile;
  ros::init(argc, argv, "move_group_interface_tutorial");
  ros::NodeHandle node_handle,n;  
  ros::AsyncSpinner spinner(1);
  spinner.start();
  bool obj_found = 0;
  tf::TransformListener listener;
  sleep(1.0);
  tf::StampedTransform transform; 
  try{
    listener.lookupTransform("/map", "/object_19", ros::Time(0), transform);
  }
  catch (tf::TransformException ex){
    ROS_ERROR("%s",ex.what());
    ros::Duration(1.0).sleep();
  }
  ros::Publisher pub_nav2d = node_handle.advertise<nav2d_operator::cmd>("cmd", 1000, true);
  ros::Publisher chatter_pub = n.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
  nav2d_operator::cmd command;
double begin = ros::Time::now().toSec();
  command.Velocity = 0.1;
  command.Turn = 0.0;
  command.Mode = 0;
//system("rosrun sound_play soundplay_node.py");

  while(!obj_found)
  {
	  pub_nav2d.publish(command);
	  obj_found = listener.waitForTransform("/map", "/object_18",ros::Time(0),ros::Duration(0.001));  //change the object number for different settings
          if(!obj_found)
	  obj_found = listener.waitForTransform("/map", "/object_19",ros::Time(0),ros::Duration(0.001));
	  else 
		{ flag=1;
			break;}
	  if(!obj_found)
	  obj_found = listener.waitForTransform("/map", "/object_20",ros::Time(0),ros::Duration(0.001));
	  else 
		{ flag=2;
			break;}
	  if(!obj_found)
	  obj_found = listener.waitForTransform("/map", "/object_21",ros::Time(0),ros::Duration(0.001));
	  else 
		{ flag=3;
			break;}
	  if(!obj_found)
	  obj_found = listener.waitForTransform("/map", "/object_22",ros::Time(0),ros::Duration(0.001));
	  else 
		{ flag=4;
			break;}
	  if(!obj_found)
	  obj_found = listener.waitForTransform("/map", "/object_23",ros::Time(0),ros::Duration(0.001));
	  else 
		{ flag=5;
			break;}
	  if(!obj_found)
	  obj_found = listener.waitForTransform("/map", "/object_26",ros::Time(0),ros::Duration(0.001));
	  else 
		{ flag=6;
			break;}
	  if(!obj_found)
	  obj_found = listener.waitForTransform("/map", "/object_27",ros::Time(0),ros::Duration(0.001));
	 else 
		{ flag=7;
			break;}
	  if(!obj_found)
	  obj_found = listener.waitForTransform("/map", "/object_28",ros::Time(0),ros::Duration(0.001));
	 else 
		{ flag=8;
			break;}
	  if(!obj_found)
	  obj_found = listener.waitForTransform("/map", "/object_29",ros::Time(0),ros::Duration(0.001));
	 else 
		{ flag=9;
			break;}
	  if(!obj_found)
	  obj_found = listener.waitForTransform("/map", "/object_30",ros::Time(0),ros::Duration(0.001));
	 else 
		{ flag=10;
			break;}
	  if(!obj_found)
	  obj_found = listener.waitForTransform("/map", "/object_31",ros::Time(0),ros::Duration(0.001));
	 else 
		{ flag=11;
			break;}
	  if(!obj_found)
	  obj_found = listener.waitForTransform("/map", "/object_32",ros::Time(0),ros::Duration(0.001));
	 else 
		{ flag=12;
			break;}
	  if(!obj_found)
	  obj_found = listener.waitForTransform("/map", "/object_33",ros::Time(0),ros::Duration(0.001));
	 else 
		{ flag=13;
			break;}
	  if(!obj_found)
	  obj_found = listener.waitForTransform("/map", "/object_34",ros::Time(0),ros::Duration(0.001));
	 else 
		{ flag=14;
			break;}
	  if(!obj_found)
	   obj_found = listener.waitForTransform("/map", "/object_35",ros::Time(0),ros::Duration(0.001));
	 else 
		{ flag=15;
			break;}
	  if(!obj_found)
	   obj_found = listener.waitForTransform("/map", "/object_36",ros::Time(0),ros::Duration(0.001));
	 else 
		{ flag=16;
			break;}
	  if(!obj_found)
	   obj_found = listener.waitForTransform("/map", "/object_37",ros::Time(0),ros::Duration(0.001));
	 else 
		{ flag=17;
			break;}
	  if(!obj_found)
	   obj_found = listener.waitForTransform("/map", "/object_38",ros::Time(0),ros::Duration(0.001));
	 else 
		{ flag=18;
			break;}
	  if(!obj_found)
	   obj_found = listener.waitForTransform("/map", "/object_39",ros::Time(0),ros::Duration(0.001));
	 else 
		{ flag=19;
			break;}
	  if(!obj_found)
	   obj_found = listener.waitForTransform("/map", "/object_40",ros::Time(0),ros::Duration(0.001));
	 else 
		{ flag=20;
			break;}
	  if(!obj_found)
	   obj_found = listener.waitForTransform("/map", "/object_41",ros::Time(0),ros::Duration(0.001));
	 else 
		{ flag=21;
			break;}
	  if(!obj_found)
	   obj_found = listener.waitForTransform("/map", "/object_42",ros::Time(0),ros::Duration(0.001));
	 else 
		{ flag=22;
			break;}
	  if(!obj_found)
	   obj_found = listener.waitForTransform("/map", "/object_43",ros::Time(0),ros::Duration(0.001));
	 else 
		{ flag=23;
			break;}
	  if(!obj_found)
	   obj_found = listener.waitForTransform("/map", "/object_44",ros::Time(0),ros::Duration(0.001));
	 else 
		{ flag=24;
			break;}
	  if(!obj_found)
	   obj_found = listener.waitForTransform("/map", "/object_47",ros::Time(0),ros::Duration(0.001));
	 else 
		{ flag=25;
			break;}
	  if(!obj_found)
	   obj_found = listener.waitForTransform("/map", "/object_48",ros::Time(0),ros::Duration(0.001));
	 else 
		{ flag=26;
			break;}
	  if(!obj_found)
	   obj_found = listener.waitForTransform("/map", "/object_49",ros::Time(0),ros::Duration(0.001));
	 else 
		{ flag=27;
			break;}
	  if(!obj_found)
	   obj_found = listener.waitForTransform("/map", "/object_50",ros::Time(0),ros::Duration(0.001));
	 else 
		{ flag=28;
			break;}
	  if(!obj_found)
	   obj_found = listener.waitForTransform("/map", "/object_51",ros::Time(0),ros::Duration(0.001));
	 else 
		{ flag=29;
			break;}
	  if(!obj_found)
	   obj_found = listener.waitForTransform("/map", "/object_52",ros::Time(0),ros::Duration(0.001));
	 else 
		{ flag=30;
			break;}
	  if(!obj_found)
	   obj_found = listener.waitForTransform("/map", "/object_53",ros::Time(0),ros::Duration(0.001));
	 else 
		{ flag=31;
			break;}
	  if(!obj_found)
	   obj_found = listener.waitForTransform("/map", "/object_54",ros::Time(0),ros::Duration(0.001));
	 else 
		{ flag=32;
			break;}
	  if(!obj_found)
	   obj_found = listener.waitForTransform("/map", "/object_55",ros::Time(0),ros::Duration(0.001));
	 else 
		{ flag=33;
			break;}
	  if(!obj_found)
	   obj_found = listener.waitForTransform("/map", "/object_56",ros::Time(0),ros::Duration(0.001));
	 else 
		{ flag=34;
			break;}
	  if(!obj_found)
	   obj_found = listener.waitForTransform("/map", "/object_57",ros::Time(0),ros::Duration(0.001));
	 else 
		{ flag=35;
			break;}
	  
	  // obj_found = listener.lookupTransform("/map", "/odom1", ros::Time(0), transform);
  }  
  ROS_INFO("TF %d",flag);    
  
  command.Velocity = 0;
  pub_nav2d.publish(command);
  if(flag==1)
  listener.lookupTransform("/map", "/object_18", ros::Time(0), transform);
  if(flag==2)
  listener.lookupTransform("/map", "/object_19", ros::Time(0), transform);
  if(flag==3)
  listener.lookupTransform("/map", "/object_20", ros::Time(0), transform);
  if(flag==4)
  listener.lookupTransform("/map", "/object_21", ros::Time(0), transform);
  if(flag==5)
  listener.lookupTransform("/map", "/object_22", ros::Time(0), transform);
  if(flag==6)
  listener.lookupTransform("/map", "/object_23", ros::Time(0), transform);
  if(flag==7)
  listener.lookupTransform("/map", "/object_26", ros::Time(0), transform);
  if(flag==8)
  listener.lookupTransform("/map", "/object_27", ros::Time(0), transform);
  if(flag==9)
  listener.lookupTransform("/map", "/object_28", ros::Time(0), transform);
  if(flag==10)
  listener.lookupTransform("/map", "/object_29", ros::Time(0), transform);
  if(flag==11)
  listener.lookupTransform("/map", "/object_30", ros::Time(0), transform);
  if(flag==12)
  listener.lookupTransform("/map", "/object_31", ros::Time(0), transform);
  if(flag==13)
  listener.lookupTransform("/map", "/object_32", ros::Time(0), transform);
  if(flag==14)
  listener.lookupTransform("/map", "/object_33", ros::Time(0), transform);
  if(flag==15)
  listener.lookupTransform("/map", "/object_34", ros::Time(0), transform);
  if(flag==16)
  listener.lookupTransform("/map", "/object_35", ros::Time(0), transform);
  if(flag==17)
  listener.lookupTransform("/map", "/object_36", ros::Time(0), transform);
  if(flag==18)
  listener.lookupTransform("/map", "/object_37", ros::Time(0), transform);
  if(flag==19)
  listener.lookupTransform("/map", "/object_38", ros::Time(0), transform);
  if(flag==20)
  listener.lookupTransform("/map", "/object_39", ros::Time(0), transform);
  if(flag==21)
  listener.lookupTransform("/map", "/object_40", ros::Time(0), transform);
  if(flag=22)
  listener.lookupTransform("/map", "/object_41", ros::Time(0), transform);
  if(flag==23)
  listener.lookupTransform("/map", "/object_42", ros::Time(0), transform);
  if(flag==24)
  listener.lookupTransform("/map", "/object_43", ros::Time(0), transform);
  if(flag==25)
  listener.lookupTransform("/map", "/object_44", ros::Time(0), transform);
  if(flag==26)
  listener.lookupTransform("/map", "/object_47", ros::Time(0), transform);
  if(flag==27)
  listener.lookupTransform("/map", "/object_48", ros::Time(0), transform);
  if(flag==28)
  listener.lookupTransform("/map", "/object_49", ros::Time(0), transform);
  if(flag==29)
  listener.lookupTransform("/map", "/object_50", ros::Time(0), transform);
  if(flag==30)
  listener.lookupTransform("/map", "/object_51", ros::Time(0), transform);
  if(flag==31)
  listener.lookupTransform("/map", "/object_52", ros::Time(0), transform);
  if(flag==32)
  listener.lookupTransform("/map", "/object_53", ros::Time(0), transform);
  if(flag==33)
  listener.lookupTransform("/map", "/object_54", ros::Time(0), transform);
  if(flag==34)
  listener.lookupTransform("/map", "/object_55", ros::Time(0), transform);
  if(flag==35)
  listener.lookupTransform("/map", "/object_56", ros::Time(0), transform);
  if(flag==0)
  listener.lookupTransform("/map", "/object_57", ros::Time(0), transform);
double end = ros::Time::now().toSec() - begin;
myfile.open("time");
	myfile<<end<<"\n";
	myfile.close();
	
  ROS_INFO("TF %f %f %f",transform.getOrigin().getX(),transform.getOrigin().getY(),transform.getOrigin().getZ());
  ROS_INFO("TF %f %f %f %f",transform.getRotation().getAxis().getX(),transform.getRotation().getAxis().getY(),transform.getRotation().getAxis().getZ(),transform.getRotation().getW());

while(1)
{
geometry_msgs::Twist a;
a.angular.z=0;
a.linear.x=0;
chatter_pub.publish(a);
} 
/* ros::Publisher pub = node_handle.advertise<geometry_msgs::PoseStamped>("move_base_simple/goal", 1000, true);

  // Loop at 2Hz until the node is shut down.
  // Create and fill in the message.  The other four
  // fields, which are ignored by turtlesim, default to 0.
  
  geometry_msgs::PoseStamped move_pose;
  move_pose.pose.position.x = transform.getOrigin().getX() - 0.4;
  move_pose.pose.position.y = transform.getOrigin().getY();
  
  move_pose.pose.orientation.x = 0;
  move_pose.pose.orientation.y = 0;
  move_pose.pose.orientation.z = 0;
  move_pose.pose.orientation.w = 1; 

  move_pose.header.frame_id = "map";
  
  // Publish the message.
  pub.publish(move_pose);
  sleep(10);*/
/*  
  // BEGIN_TUTORIAL
  // 
  // Setup		
  // ^^^^^
  // 
  // The :move_group_interface:`MoveGroup` class can be easily 
  // setup using just the name
  // of the group you would like to control and plan for.
  moveit::planning_interface::MoveGroup group("arm_1");

  // We will use the :planning_scene_interface:`PlanningSceneInterface`
  // class to deal directly with the world.
  moveit::planning_interface::PlanningSceneInterface planning_scene_interface;  

  // (Optional) Create a publisher for visualizing plans in Rviz.
  ros::Publisher display_publisher = node_handle.advertise<moveit_msgs::DisplayTrajectory>("/move_group/display_planned_path", 1, true);
  moveit_msgs::DisplayTrajectory display_trajectory;

  // Getting Basic Information
  // ^^^^^^^^^^^^^^^^^^^^^^^^^
  //
  // We can print the name of the reference frame for this robot.
  ROS_INFO("Reference frame: %s", group.getPlanningFrame().c_str());
  
  // We can also print the name of the end-effector link for this group.
  ROS_INFO("Reference frame: %s", group.getEndEffectorLink().c_str());

  // Planning to a Pose goal
  // ^^^^^^^^^^^^^^^^^^^^^^^
  // We can plan a motion for this group to a desired pose for the 
  // end-effector.
  geometry_msgs::PoseStamped pose = group.getCurrentPose(group.getEndEffectorLink().c_str());
  ROS_INFO("Current Pose Position %f %f %f",pose.pose.position.x,pose.pose.position.y,pose.pose.position.z);
  ROS_INFO("Current Pose Orientation %f %f %f %f",pose.pose.orientation.x,pose.pose.orientation.y,pose.pose.orientation.z,pose.pose.orientation.w);
  ROS_INFO("Tolerance %f", group.getGoalPositionTolerance());

  pluginlib::ClassLoader<kinematics::KinematicsBase> loader(
          "moveit_core", "kinematics::KinematicsBase");
  KinematicsBasePtr kinematics = loader.createInstance(PLUGIN);
  kinematics->initialize("/robot_description", "arm_1", "arm_link_0",
          "arm_link_5", 0.0);
            
  geometry_msgs::Pose target_pose1;
  target_pose1.orientation.x = 0.707;
  target_pose1.orientation.y = 0.707;
  target_pose1.orientation.z = 0;
  target_pose1.orientation.w = 0;
  target_pose1.position.x = 0.4;
  target_pose1.position.y = 0.0;
  target_pose1.position.z = 0.18;
  //target_pose1 = pose.pose;
  
  std::vector<double> seed(5, 0.0);
  std::vector<double> solution;
  moveit_msgs::MoveItErrorCodes error_code;  
    
  //group.setRandomTarget();
  group.setPoseTarget(target_pose1);
  group.setGoalTolerance(0.01);
  
  kinematics->getPositionIK(target_pose1, seed, solution, error_code);
  
  ROS_INFO("0 %f", solution[0]);
  ROS_INFO("1 %f", solution[1]);
  ROS_INFO("2 %f", solution[2]);
  ROS_INFO("3 %f", solution[3]);
  ROS_INFO("4 %f", solution[4]);

  // Now, we call the planner to compute the plan
  // and visualize it.
  // Note that we are just planning, not asking move_group 
  // to actually move the robot.
  group.setPlannerId("RRTConnectkConfigDefault");
  moveit::planning_interface::MoveGroup::Plan my_plan;
  bool success = group.plan(my_plan);

  ROS_INFO("Visualizing plan 1 (pose goal) %s",success?"":"FAILED");    
  // Sleep to give Rviz time to visualize the plan. 
  sleep(5.0);

  // Visualizing plans
  // ^^^^^^^^^^^^^^^^^
  // Now that we have a plan we can visualize it in Rviz.  This is not
  // necessary because the group.plan() call we made above did this
  // automatically.  But explicitly publishing plans is useful in cases that we
  // want to visualize a previously created plan.
  if (1)
  {
    ROS_INFO("Visualizing plan 1 (again)");    
    display_trajectory.trajectory_start = my_plan.start_state_;
    display_trajectory.trajectory.push_back(my_plan.trajectory_);
    display_publisher.publish(display_trajectory);
    // Sleep to give Rviz time to visualize the plan. 
    sleep(5.0);
  }
  
  // Moving to a pose goal
  // ^^^^^^^^^^^^^^^^^^^^^
  //
  // Moving to a pose goal is similar to the step above
  // except we now use the move() function. Note that
  // the pose goal we had set earlier is still active 
  // and so the robot will try to move to that goal. We will
  // not use that function in this tutorial since it is 
  // a blocking function and requires a controller to be active
  // and report success on execution of a trajectory.
 
  // Uncomment below line when working with a real robot
  //group.move();

  // Planning to a joint-space goal 
  // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  //
  // Let's set a joint space goal and move towards it.  This will replace the
  // pose target we set above.
  //
  // First get the current set of joint values for the group.
*/
  ros::shutdown();  
  return 0;
}
