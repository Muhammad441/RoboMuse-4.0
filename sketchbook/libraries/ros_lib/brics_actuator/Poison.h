#ifndef _ROS_brics_actuator_Poison_h
#define _ROS_brics_actuator_Poison_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace brics_actuator
{

  class Poison : public ros::Msg
  {
    public:
      const char* originator;
      const char* description;
      float qos;

    Poison():
      originator(""),
      description(""),
      qos(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_originator = strlen(this->originator);
      memcpy(outbuffer + offset, &length_originator, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->originator, length_originator);
      offset += length_originator;
      uint32_t length_description = strlen(this->description);
      memcpy(outbuffer + offset, &length_description, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->description, length_description);
      offset += length_description;
      union {
        float real;
        uint32_t base;
      } u_qos;
      u_qos.real = this->qos;
      *(outbuffer + offset + 0) = (u_qos.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_qos.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_qos.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_qos.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->qos);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_originator;
      memcpy(&length_originator, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_originator; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_originator-1]=0;
      this->originator = (char *)(inbuffer + offset-1);
      offset += length_originator;
      uint32_t length_description;
      memcpy(&length_description, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_description; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_description-1]=0;
      this->description = (char *)(inbuffer + offset-1);
      offset += length_description;
      union {
        float real;
        uint32_t base;
      } u_qos;
      u_qos.base = 0;
      u_qos.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_qos.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_qos.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_qos.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->qos = u_qos.real;
      offset += sizeof(this->qos);
     return offset;
    }

    const char * getType(){ return "brics_actuator/Poison"; };
    const char * getMD5(){ return "b16420a6fd4cc18f64b776ee10e98bb0"; };

  };

}
#endif