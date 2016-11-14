//#include <USBSabertooth.h>

#include <Kangaroo.h>
#include<ros.h>
#include<ArduinoHardware.h>
#include"robomuse/chapter2_msg1.h"
int distanceleft,distanceright,lastDl,lastDr;
KangarooSerial  K(Serial3);
KangarooChannel K1(K, '1');
KangarooChannel K2(K, '2');
ros::NodeHandle  nh;
robomuse::chapter2_msg1 a;
ros::Publisher chatter("message", &a);
void setup() {
    nh.initNode();
  nh.advertise(chatter);
Serial3.begin(115200);
Serial.begin(115200);
Serial.println("Code is started");
  K1.start();
  K1.home().wait();
  K2.start();
  K2.home().wait();
  /*
 minimum = K2.getMin().value();
 maximum = K2.getMax().value();
  
  Serial.print("Minimum Speed of M2 = ");
  Serial.println(minimum);
  Serial.print("Maximum Speed of M2= ");
  Serial.println(maximum);

  minimum = K1.getMin().value();
  maximum = K1.getMax().value();
  Serial.print("Minimum Speed of M1 = ");
  Serial.println(minimum);
  Serial.print("Maximum Speed of M1= ");
  Serial.println(maximum);
  */
//  Serial.println("-----Code is initiated --------");

}



void loop() {


  double Dl=-K1.getP().value();
  double Dr=K2.getP().value(); //reading position command
  K1.s(-200);       //setting speed of invidual motor
  K2.s(200);
  Serial.print("Dl  ");
  Serial.println(Dl);
  Serial.print("Dr  ");
  Serial.print(Dr);
  
  a.A = Dl;
  a.B = Dr;
  chatter.publish( &a );
  nh.spinOnce();
  }
