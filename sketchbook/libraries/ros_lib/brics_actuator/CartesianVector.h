#ifndef _ROS_brics_actuator_CartesianVector_h
#define _ROS_brics_actuator_CartesianVector_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace brics_actuator
{

  class CartesianVector : public ros::Msg
  {
    public:
      const char* unit;
      float x;
      float y;
      float z;

    CartesianVector():
      unit(""),
      x(0),
      y(0),
      z(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_unit = strlen(this->unit);
      memcpy(outbuffer + offset, &length_unit, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->unit, length_unit);
      offset += length_unit;
      offset += serializeAvrFloat64(outbuffer + offset, this->x);
      offset += serializeAvrFloat64(outbuffer + offset, this->y);
      offset += serializeAvrFloat64(outbuffer + offset, this->z);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_unit;
      memcpy(&length_unit, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_unit; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_unit-1]=0;
      this->unit = (char *)(inbuffer + offset-1);
      offset += length_unit;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->z));
     return offset;
    }

    const char * getType(){ return "brics_actuator/CartesianVector"; };
    const char * getMD5(){ return "fd973c0064b8c462dbcc9784beb041ca"; };

  };

}
#endif