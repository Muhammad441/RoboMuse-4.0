#ifndef _ROS_brics_actuator_JointConstraint_h
#define _ROS_brics_actuator_JointConstraint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "brics_actuator/JointValue.h"

namespace brics_actuator
{

  class JointConstraint : public ros::Msg
  {
    public:
      const char* type;
      brics_actuator::JointValue value;

    JointConstraint():
      type(""),
      value()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_type = strlen(this->type);
      memcpy(outbuffer + offset, &length_type, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_type);
      offset += length_type;
      offset += this->value.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_type;
      memcpy(&length_type, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type-1]=0;
      this->type = (char *)(inbuffer + offset-1);
      offset += length_type;
      offset += this->value.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "brics_actuator/JointConstraint"; };
    const char * getMD5(){ return "f77db04949b26b64f80564df22f00ecb"; };

  };

}
#endif