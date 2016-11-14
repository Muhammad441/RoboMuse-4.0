#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "my_tf_broadcaster");
  ros::NodeHandle node;
  tf::TransformListener listener;
  bool found = 0;
  while (!found){
	   found = listener.waitForTransform("/map", "/object_7",ros::Time(0),ros::Duration(0.001));
	}
    
  static tf::TransformBroadcaster br;
  tf::Transform transform;
  transform.setOrigin(tf::Vector3(0.4, 0, 0.0) );
  tf::Quaternion q(0,0,1,0);
  transform.setRotation(q);
  while(ros::ok())
  br.sendTransform(tf::StampedTransform(transform, ros::Time(0), "/object_7", "final_pos"));
};
