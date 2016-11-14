/*
 * rosserial PubSub Example
 * Prints "hello world!" and toggles led
 */
#include <Kangaroo.h>
#include <ros.h>
#include <geometry_msgs/Twist.h>
KangarooSerial  K(Serial3);
KangarooChannel K1(K, '1');
KangarooChannel K2(K, '2');
ros::NodeHandle  nh;
int flag=0;
double x,y,newx;
int count1;
void messageCb( const geometry_msgs::Twist& msg)
{
if(msg.linear.y==1)
{ x=0;
y=0;
flag=1;
}
 newx=msg.linear.x;
 newx=newx*1500;
 if(newx==0) count1++;
 else count1=0;
 if(newx==0) 
 {
   if(count1>2) x=0;
 }
 else x=newx;
 y=msg.angular.z;
 y=y*2000;
}

ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", messageCb );



void setup() 
{
    nh.initNode();
    pinMode(2,OUTPUT);
    digitalWrite(2,HIGH);
    delay(1000);
    digitalWrite(2,LOW);
delay(1000);
    digitalWrite(2,HIGH);
    delay(1000);
    digitalWrite(2,LOW);
    delay(1000);
    digitalWrite(2,HIGH);
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
 K1.s(y+x);
 K2.s(x-y);
  }
 else
 {
 K1.s(x+y);
 K2.s(-y+x);
 }
 if(flag==1)
 {
 while(1)
{ 
  K1.s(0);
  K2.s(0);
digitalWrite(2,HIGH);
    delay(1000);
    digitalWrite(2,LOW);
delay(1000);

}

 }
 nh.spinOnce();
}
