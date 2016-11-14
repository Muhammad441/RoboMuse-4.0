#include <Encoder.h>
#include<ros.h>
#include<ArduinoHardware.h>
#include"robomuse/chapter2_msg1.h"
int distanceleft,distanceright,lastDl,lastDr;
Encoder knobLeft(19, 18);
Encoder knobRight(2, 3);
ros::NodeHandle  nh;
robomuse::chapter2_msg1 a;
ros::Publisher chatter("message", &a);
void setup() {
  nh.initNode();
  nh.advertise(chatter);
  Serial.begin(115200);
  Serial.println("TwoKnobs Encoder Test:");
}
long positionLeft  = -999;
long positionRight = -999;
void loop() 
{
   double Dl = knobLeft.read();
  double Dr = knobRight.read();
  Serial.print("Dl  ");
  Serial.println(Dl);
  Serial.print("Dr  ");
  Serial.print(Dr);
  
  a.A = Dl;
  a.B = Dr;
  chatter.publish( &a );
  nh.spinOnce();
}
