#include <Encoder.h>
#include<ros.h>
#include<ArduinoHardware.h>
#include <tf/transform_broadcaster.h>
#include"robomuse/chapter2_msg1.h"
#include<geometry_msgs/Point.h>
#include<ros/time.h>
int distanceleft,distanceright,lastDl,lastDr;
     double x = 0.0;
     double y = 0.0;
     double th = 0.0;
     double vx ;
     double vy ;
     double vth ;
     double Dl;
     double Dr;
     double Distancel,Distancer,LastDistancel,LastDistancer;
     double L=0.558;
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
ros::Time current_time,last_time;
long positionLeft  = -999;
long positionRight = -999;
void loop() 
{  
   double Dol = knobLeft.read();
  double Dor = knobRight.read();
  Serial.print("Dl  ");
  Serial.println(Dol);
  Serial.print("Dr  ");
  Serial.print(Dor);
  
  current_time = nh.now();
 last_time = nh.now();
 
  double dt=.2 ;//= (current_time - last_time).toSec();
Distancel=Dol;
Distancer=Dol;
  Distancel=Distancel/2048*2*3.14*.12;
  Distancer=Distancer/2048*2*3.14*.12;
  	
Dl=Distancel-LastDistancel;
  Dr=Distancer-LastDistancer;
  LastDistancel=Distancel;
  LastDistancer=Distancer;	
	double Dc=0;
	Dc=(Dl+Dr)/2;
	double delta_x=Dc*cos(th);
	double delta_y=Dc*sin(th);
	double delta_th=(Dr-Dl)/L; 
       x += delta_x;
       y += delta_y;
       th += delta_th;
   	vx=delta_x/dt;
	vy=delta_y/dt;
	vth=delta_th/dt;
 a.A=x;
 a.B=y;
 a.th=th;
 a.vx=vx;
 a.vy=vy;
 a.vth=vth;
 chatter.publish( &a );
  last_time = current_time;
  nh.spinOnce();
}

