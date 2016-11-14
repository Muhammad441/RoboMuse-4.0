/*
 * rosserial PubSub Example
 * Prints "hello world!" and toggles led
 */
#include <Kangaroo.h>
#include <ros.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Point.h>
int flag=0;
KangarooSerial  K(Serial3);
KangarooChannel K1(K, '1');
KangarooChannel K2(K, '2');
ros::NodeHandle  nh;
ros::NodeHandle  n;
double x,y;
void messageCb( const geometry_msgs::Point& msg)
{

 x=msg.x;
 y=msg.y;
 
}

ros::Subscriber<geometry_msgs::Point> sub("topic", messageCb );


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
  Serial.println(x);
  if(x>0.5) flag=1;
  if(flag==0)
 {
 K1.s(200);
 K2.s(200);
  }
 else if(flag==1)
 {
 K1.s(0);
 K2.s(0);
 }
 
nh.spinOnce();
}
