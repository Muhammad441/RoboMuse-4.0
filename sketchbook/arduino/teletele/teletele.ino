#include <Encoder.h>
#include<ros.h>
#include<ArduinoHardware.h>
#include"robomuse/chapter2_msg1.h"
#include<geometry_msgs/Point.h>
int distanceleft,distanceright,lastDl,lastDr;
Encoder knobLeft(19, 18);
Encoder knobRight(20, 21);
ros::NodeHandle  nh;
geometry_msgs::Point a;

ros::Publisher chatter("message", &a);
void setup() {
  nh.initNode();
  nh.advertise(chatter);
  Serial.begin(115200);
  Serial.println("TwoKnobs Encoder Test:");
}
long positionLeft  = -999;
long positionRight = -999;
long counter=0;
long current_time,last_time;
void loop() 
{  

 
 double Dl = knobLeft.read();
  double Dr = knobRight.read();
  Serial.print("Dl  ");
  Serial.println(Dl);
  Serial.print("Dr  ");
  Serial.print(Dr);
  
  a.x = Dl;
  a.y = Dr;
 if(counter%5==0) chatter.publish( &a );
  nh.spinOnce();
  counter++;
   

}
