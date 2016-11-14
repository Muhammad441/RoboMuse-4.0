#include <ArduinoHardware.h>
#include <ros.h>
#include <geometry_msgs/Twist.h>

void chatterCallback(const geometry_msgs::Twist msg)
   {
     ROS_INFO("I heard: [%d]", msg->linear.x);
   }
void setup()
{
     ros::NodeHandle n;   
     ros::Subscriber sub = n.subscribe("cmd_vel", 1000, chatterCallback);
}

void loop()
{
  a.A = 1;
  a.B = .5;
  chatter.publish( &a );
  nh.spinOnce();
  delay(1000);
}

   int main(int argc, char **argv)
   {
     
         ros::spin();
   
     return 0;
   }
