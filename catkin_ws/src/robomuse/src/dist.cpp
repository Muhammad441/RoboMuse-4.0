#include "ros/ros.h"
#include "std_msgs/String.h"
#include"geometry_msgs/Point.h"
#include"geometry_msgs/Twist.h"
double x,y,th;
void chatterCallback(const geometry_msgs::Point::ConstPtr& msg)
   {  x=msg->x;
      y=msg->y;
      th=msg->z;
     
   }
   int main(int argc, char **argv)
   {
     
     ros::init(argc, argv, "dist");
     ros::NodeHandle n;   
     ros::Subscriber sub = n.subscribe("topic", 1000, chatterCallback);
     ros::NodeHandle nh;
     ros::Publisher chatter_pub = nh.advertise<geometry_msgs::Twist>("chatter", 1000);
 while (n.ok())
    {  
         ROS_INFO("x : %f",x);
         ROS_INFO("y : %f",y);
         ROS_INFO("th : %f",th);     
      ros::spinOnce(); 
      geometry_msgs::Twist a;
      if(x>0.75) a.linear.x=0;
      else a.linear.x= 0.5;
      if(a.linear.x==0)
	{
		if(th<1.57) a.angular.z=0.5;
		else 
			{
				a.angular.z=0;
				if(y<0.75) a.linear.x=0.5;
				else a.linear.x=0;
			}
		
        }

      chatter_pub.publish(a); 
    }     
ros::spin();
   
     return 0;
   }
