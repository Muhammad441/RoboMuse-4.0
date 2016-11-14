#ifndef _ROS_brics_actuator_CartesianTwist_h
#define _ROS_brics_actuator_CartesianTwist_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"
#include "brics_actuator/Poison.h"
#include "brics_actuator/CartesianVector.h"

namespace brics_actuator
{

  class CartesianTwist : public ros::Msg
  {
    public:
      ros::Time timeStamp;
      brics_actuator::Poison poisonStamp;
      const char* base_frame_uri;
      const char* target_frame_uri;
      brics_actuator::CartesianVector translation;
      brics_actuator::CartesianVector rotation;

    CartesianTwist():
      timeStamp(),
      poisonStamp(),
      base_frame_uri(""),
      target_frame_uri(""),
      translation(),
      rotation()
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
      offset += this->poisonStamp.serialize(outbuffer + offset);
      uint32_t length_base_frame_uri = strlen(this->base_frame_uri);
      memcpy(outbuffer + offset, &length_base_frame_uri, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->base_frame_uri, length_base_frame_uri);
      offset += length_base_frame_uri;
      uint32_t length_target_frame_uri = strlen(this->target_frame_uri);
      memcpy(outbuffer + offset, &length_target_frame_uri, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->target_frame_uri, length_target_frame_uri);
      offset += length_target_frame_uri;
      offset += this->translation.serialize(outbuffer + offset);
      offset += this->rotation.serialize(outbuffer + offset);
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
      offset += this->poisonStamp.deserialize(inbuffer + offset);
      uint32_t length_base_frame_uri;
      memcpy(&length_base_frame_uri, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_base_frame_uri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_base_frame_uri-1]=0;
      this->base_frame_uri = (char *)(inbuffer + offset-1);
      offset += length_base_frame_uri;
      uint32_t length_target_frame_uri;
      memcpy(&length_target_frame_uri, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_target_frame_uri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_target_frame_uri-1]=0;
      this->target_frame_uri = (char *)(inbuffer + offset-1);
      offset += length_target_frame_uri;
      offset += this->translation.deserialize(inbuffer + offset);
      offset += this->rotation.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "brics_actuator/CartesianTwist"; };
    const char * getMD5(){ return "e86336d0ca57e442a1f55b8cb29e1a22"; };

  };

}
#endif