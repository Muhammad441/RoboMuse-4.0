#include <Encoder.h>
#include<ros/ros.h>
#include<ArduinoHardware.h>
#include <tf/transform_broadcaster.h>
#include"robomuse/chapter2_msg1.h"
#include<geometry_msgs/Point.h>
#include<ros/time.h>
#include <nav_msgs/Odometry.h>
int distanceleft,distanceright,lastDl,lastDr;
     double x = 0.0;
     double y = 0.0;
     double th = 0.0;
     double vx ;
     double vy ;
     double vth ;
     double Dl;
     double Dr;
     double Distancel,Distancer,LastDistancel,LastDistancer;
     double L=0.558;
Encoder knobLeft(19, 18);
Encoder knobRight(2, 3);
ros::NodeHandle  nh;
robomuse::chapter2_msg1 a;
  ros::NodeHandle n;
     ros::Publisher odom_pub = n.advertise<nav_msgs::Odometry>("odom", 50);
     tf::TransformBroadcaster odom_broadcaster;
ros::Publisher chatter("message", &a);
void setup() {
  nh.initNode();
  nh.advertise(chatter);
  Serial.begin(115200);
  Serial.println("TwoKnobs Encoder Test:");
}
ros::Time current_time,last_time;
long positionLeft  = -999;
long positionRight = -999;
void loop() 
{  
   double Dol = knobLeft.read();
  double Dor = knobRight.read();
  Serial.print("Dl  ");
  Serial.println(Dol);
  Serial.print("Dr  ");
  Serial.print(Dor);
  
  current_time = nh.now();
 last_time = nh.now();
 
  double dt=.2 ;//= (current_time - last_time).toSec();
Distancel=Dol;
Distancer=Dol;
  Distancel=Distancel/2048*2*3.14*.12;
  Distancer=Distancer/2048*2*3.14*.12;
  	
Dl=Distancel-LastDistancel;
  Dr=Distancer-LastDistancer;
  LastDistancel=Distancel;
  LastDistancer=Distancer;	
	double Dc=0;
	Dc=(Dl+Dr)/2;
	double delta_x=Dc*cos(th);
	double delta_y=Dc*sin(th);
	double delta_th=(Dr-Dl)/L; 
       x += delta_x;
       y += delta_y;
       th += delta_th;
   	vx=delta_x/dt;
	vy=delta_y/dt;
	vth=delta_th/dt;
 tf::createQuaternionMsgFromYaw(th);
  
       //first, we'll publish the transform over tf
       geometry_msgs::TransformStamped odom_trans;
      odom_trans.header.stamp = current_time;
       odom_trans.header.frame_id = "odom";
       odom_trans.child_frame_id = "base_link";
  
       odom_trans.transform.translation.x =x;
       odom_trans.transform.translation.y =y;
       odom_trans.transform.translation.z = 0.0;
       odom_trans.transform.rotation = odom_quat;
       //send the transform
       odom_broadcaster.sendTransform(odom_trans);
   
       //next, we'll publish the odometry message over ROS
       nav_msgs::Odometry odom;
       odom.header.stamp = current_time;
       odom.header.frame_id = "odom";
   
       //set the position
      odom.pose.pose.position.x = x;
       odom.pose.pose.position.y = y;
     odom.pose.pose.position.z = 0.0;
       odom.pose.pose.orientation = odom_quat;
   
       //set the velocity
       odom.child_frame_id = "base_link";
       odom.twist.twist.linear.x = vx;
       odom.twist.twist.linear.y = vy;
       odom.twist.twist.angular.z =vth;
   
       //publish the message
      odom_pub.publish(odom);
   
       last_time = current_time;
  nh.spinOnce();
}

