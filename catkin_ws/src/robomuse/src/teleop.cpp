#include "ros/ros.h"
#include <geometry_msgs/Twist.h>
#include <sstream>
geometry_msgs::Twist msg;
int flag = 0 ;  
void chatterCallback(const geometry_msgs::Twist ptr)
   {
     msg=ptr;
     if(ptr.linear.x == 0 && ptr.angular.z == 0)
	{
		if ( flag == 2) msg = ptr;  		
		else flag++;
	}
     else 
	{
		flag = 0;
		msg = ptr;
	}
	 
   }
int main(int argc, char **argv)
  {
    ros::init(argc, argv, "teleop");
    ros::NodeHandle n;
     ros::NodeHandle nh;   
     ros::Subscriber sub = nh.subscribe<geometry_msgs::Twist>("chatter", 1000, chatterCallback);
     ros::Publisher teleop_pub = n.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
   
 ros::Rate loop_rate(10);
    int count = 0;
    while (ros::ok())
    {
      
    // msg.linear.x=1;
      ROS_INFO("I'm working");
  
      teleop_pub.publish(msg);
  
      ros::spinOnce();
  
      loop_rate.sleep();
      
    }
  
  
   return 0;
  }
