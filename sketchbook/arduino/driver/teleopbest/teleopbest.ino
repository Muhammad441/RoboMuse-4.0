/*
 * rosserial PubSub Example
 * Prints "hello world!" and toggles led
 */
#include <Kangaroo.h>
#include <ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Empty.h>
KangarooSerial  K(Serial3);
KangarooChannel K1(K, '1');
KangarooChannel K2(K, '2');
ros::NodeHandle  nh;
double x,y;

void messageCb( const geometry_msgs::Twist& msg)
{

 x=msg.linear.x;
 x=x*-500;
 y=msg.angular.z;
 y=y*500;
}

ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", messageCb );


void setup()
{
    nh.initNode();
    nh.subscribe(sub);
    Serial3.begin(115200);
Serial.begin(115200);
Serial.println("Code is started");
  K1.start();
  K1.home().wait();
  K2.start();
  K2.home().wait();
}

void loop()
{

 if(y>0)
 {
 K1.s(x+y);
 K2.s(-x);
 }
 else
 {
 K1.s(x);
 K2.s(-x+y);
 }
 
nh.spinOnce();
}
