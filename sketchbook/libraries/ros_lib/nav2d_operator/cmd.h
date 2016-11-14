#ifndef _ROS_nav2d_operator_cmd_h
#define _ROS_nav2d_operator_cmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace nav2d_operator
{

  class cmd : public ros::Msg
  {
    public:
      float Velocity;
      float Turn;
      int8_t Mode;

    cmd():
      Velocity(0),
      Turn(0),
      Mode(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->Velocity);
      offset += serializeAvrFloat64(outbuffer + offset, this->Turn);
      union {
        int8_t real;
        uint8_t base;
      } u_Mode;
      u_Mode.real = this->Mode;
      *(outbuffer + offset + 0) = (u_Mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Mode);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->Velocity));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->Turn));
      union {
        int8_t real;
        uint8_t base;
      } u_Mode;
      u_Mode.base = 0;
      u_Mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->Mode = u_Mode.real;
      offset += sizeof(this->Mode);
     return offset;
    }

    const char * getType(){ return "nav2d_operator/cmd"; };
    const char * getMD5(){ return "90c9a043660646e2102f124332ecb8b7"; };

  };

}
#endif