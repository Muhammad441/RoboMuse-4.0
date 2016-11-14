#ifndef _ROS_nav2d_navigator_MoveToPosition2DActionGoal_h
#define _ROS_nav2d_navigator_MoveToPosition2DActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "nav2d_navigator/MoveToPosition2DGoal.h"

namespace nav2d_navigator
{

  class MoveToPosition2DActionGoal : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalID goal_id;
      nav2d_navigator::MoveToPosition2DGoal goal;

    MoveToPosition2DActionGoal():
      header(),
      goal_id(),
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->goal_id.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->goal_id.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "nav2d_navigator/MoveToPosition2DActionGoal"; };
    const char * getMD5(){ return "2aeb8511cfece324b06e73656a6a7d93"; };

  };

}
#endif