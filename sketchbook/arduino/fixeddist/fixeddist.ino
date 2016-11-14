#include <Encoder.h>
#include<ros.h>
#include<ArduinoHardware.h>
#include"robomuse/chapter2_msg1.h"
#include<geometry_msgs/Twist.h>
#include<geometry_msgs/Point.h>
double x,y;
void messageCb( const geometry_msgs::Point& msg)
{

 x=msg.x;
 y=msg.y;
}
ros::Subscriber<geometry_msgs::Point> sub("topic", messageCb );
int distanceleft,distanceright,lastDl,lastDr;
Encoder knobLeft(19, 18);
Encoder knobRight(2, 3);
ros::NodeHandle  nh;
ros::NodeHandle  n;
//geometry_msgs::Point a;
geometry_msgs::Twist a;
int flag;
ros::Publisher chatter("chatter", &a);
void setup() {
   n.initNode();
    n.subscribe(sub);
  nh.initNode();
  nh.advertise(chatter);
  Serial.begin(115200);
  Serial.println("TwoKnobs Encoder Test:");
}
long positionLeft  = -999;
long positionRight = -999;
long counter=0;
double m;
long current_time,last_time;
void loop() 
{  

 
 double Dl = knobLeft.read();
  double Dr = knobRight.read();
  Serial.print("Dl  ");
  Serial.println(Dl);
  Serial.print("Dr  ");
  Serial.print(Dr);
  if(flag==0)
  {
  a.linear.x = 0.5;
  a.linear.y = 0;
  }
  else
  {
    a.linear.x=0;
    a.linear.y=0;
  }
  if(x>1) flag=1;
  if(counter%5==0)chatter.publish( &a );
  nh.spinOnce();
  counter++;
  
   

}
