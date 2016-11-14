#ifndef _ROS_brics_actuator_JointValue_h
#define _ROS_brics_actuator_JointValue_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace brics_actuator
{

  class JointValue : public ros::Msg
  {
    public:
      ros::Time timeStamp;
      const char* joint_uri;
      const char* unit;
      float value;

    JointValue():
      timeStamp(),
      joint_uri(""),
      unit(""),
      value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->timeStamp.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timeStamp.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timeStamp.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timeStamp.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timeStamp.sec);
      *(outbuffer + offset + 0) = (this->timeStamp.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timeStamp.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timeStamp.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timeStamp.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timeStamp.nsec);
      uint32_t length_joint_uri = strlen(this->joint_uri);
      memcpy(outbuffer + offset, &length_joint_uri, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->joint_uri, length_joint_uri);
      offset += length_joint_uri;
      uint32_t length_unit = strlen(this->unit);
      memcpy(outbuffer + offset, &length_unit, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->unit, length_unit);
      offset += length_unit;
      offset += serializeAvrFloat64(outbuffer + offset, this->value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->timeStamp.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->timeStamp.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timeStamp.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timeStamp.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timeStamp.sec);
      this->timeStamp.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->timeStamp.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timeStamp.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timeStamp.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timeStamp.nsec);
      uint32_t length_joint_uri;
      memcpy(&length_joint_uri, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_joint_uri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_joint_uri-1]=0;
      this->joint_uri = (char *)(inbuffer + offset-1);
      offset += length_joint_uri;
      uint32_t length_unit;
      memcpy(&length_unit, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_unit; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_unit-1]=0;
      this->unit = (char *)(inbuffer + offset-1);
      offset += length_unit;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->value));
     return offset;
    }

    const char * getType(){ return "brics_actuator/JointValue"; };
    const char * getMD5(){ return "c8dad5a006889ad7de711a684999f0c6"; };

  };

}
#endif