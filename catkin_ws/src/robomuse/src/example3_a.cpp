#include<sound_play/sound_play.h>
#include "ros/ros.h"
#include "robomuse/chapter2_msg1.h"
#include "geometry_msgs/Point.h"
#include <sstream>
int count;
geometry_msgs::Point msg;
int main(int argc, char **argv)
{
ros::init(argc, argv, "example3_a");
ros::NodeHandle n;
ros::Publisher pub = n.advertise<geometry_msgs::Point>("message", 1000);
ros::Rate loop_rate(10);
    sound_play::SoundClient sc;

    sc.playWaveFromPkg("sound_play", "/home/dell/Downloads/DesiJourney.wav");
while (ros::ok())
{

msg.x = 1+count/2;
msg.y = 1+count/2;
pub.publish(msg);
ros::spinOnce();
loop_rate.sleep();
count++;
}
return 0;
}
