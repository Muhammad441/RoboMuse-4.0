#include <ArduinoHardware.h>
#include <ros.h>
#include <std_msgs/String.h>
#include"robomuse/chapter2_msg1.h"
ros::NodeHandle  nh;
robomuse::chapter2_msg1 a;
std_msgs::String str_msg;
ros::Publisher chatter("message", &a);
void setup()
{
  nh.initNode();
  nh.advertise(chatter);
}

void loop()
{
  a.A = 1;
  a.B = .5;
  chatter.publish( &a );
  nh.spinOnce();
  delay(1000);
}
