//#include <USBSabertooth.h>

#include <Kangaroo.h>
#include<ros.h>
#include<ArduinoHardware.h>
#include"robomuse/chapter2_msg1.h"
#include <geometry_msgs/Twist.h>
int distanceleft,distanceright,lastDl,lastDr;
KangarooSerial  K(Serial3);
KangarooChannel K1(K, '1');
KangarooChannel K2(K, '2');
ros::NodeHandle  nh;
ros::NodeHandle  nh1;
double x,y;
robomuse::chapter2_msg1 a;
ros::Publisher chatter("message", &a);
void messageCb( const geometry_msgs::Twist& msg)
{

 x=msg.linear.x;
 x=x*-500;
 y=msg.angular.z;
 y=y*-500;
}
ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", messageCb );
void setup() 
{
 nh.initNode();
    nh.subscribe(sub);  
  nh.initNode();
  nh.advertise(chatter);
Serial3.begin(115200);
Serial.begin(115200);
Serial.println("Code is started");
  K1.start();
  K1.home().wait();
  K2.start();
  K2.home().wait();
}



void loop() {

 if(y>0)
 {
 K1.s(x-y);
 K2.s(-x);
 }
 else
 {
 K1.s(x);
 K2.s(-x-y);
 }
  double Dl=-K1.getP().value();
  double Dr=K2.getP().value(); //reading position command
  
  Serial.print("Dl  ");
  Serial.println(Dl);
  Serial.print("Dr  ");
  Serial.print(Dr);
  
  a.A = Dl;
  a.B = Dr;
  chatter.publish( &a );
  nh.spinOnce();
  }
