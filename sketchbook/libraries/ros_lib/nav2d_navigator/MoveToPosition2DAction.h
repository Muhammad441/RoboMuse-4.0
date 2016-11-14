#ifndef _ROS_nav2d_navigator_MoveToPosition2DAction_h
#define _ROS_nav2d_navigator_MoveToPosition2DAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "nav2d_navigator/MoveToPosition2DActionGoal.h"
#include "nav2d_navigator/MoveToPosition2DActionResult.h"
#include "nav2d_navigator/MoveToPosition2DActionFeedback.h"

namespace nav2d_navigator
{

  class MoveToPosition2DAction : public ros::Msg
  {
    public:
      nav2d_navigator::MoveToPosition2DActionGoal action_goal;
      nav2d_navigator::MoveToPosition2DActionResult action_result;
      nav2d_navigator::MoveToPosition2DActionFeedback action_feedback;

    MoveToPosition2DAction():
      action_goal(),
      action_result(),
      action_feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->action_goal.serialize(outbuffer + offset);
      offset += this->action_result.serialize(outbuffer + offset);
      offset += this->action_feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->action_goal.deserialize(inbuffer + offset);
      offset += this->action_result.deserialize(inbuffer + offset);
      offset += this->action_feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "nav2d_navigator/MoveToPosition2DAction"; };
    const char * getMD5(){ return "3a15e7e3456f54b21786f4359b2c3e43"; };

  };

}
#endif