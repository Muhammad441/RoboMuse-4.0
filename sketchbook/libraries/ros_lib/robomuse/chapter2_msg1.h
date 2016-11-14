#ifndef _ROS_robomuse_chapter2_msg1_h
#define _ROS_robomuse_chapter2_msg1_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robomuse
{

  class chapter2_msg1 : public ros::Msg
  {
    public:
      int32_t A;
      int32_t B;
      int32_t th;
      int32_t vx;
      int32_t vy;
      int32_t vth;

    chapter2_msg1():
      A(0),
      B(0),
      th(0),
      vx(0),
      vy(0),
      vth(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_A;
      u_A.real = this->A;
      *(outbuffer + offset + 0) = (u_A.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_A.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_A.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_A.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->A);
      union {
        int32_t real;
        uint32_t base;
      } u_B;
      u_B.real = this->B;
      *(outbuffer + offset + 0) = (u_B.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_B.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_B.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_B.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->B);
      union {
        int32_t real;
        uint32_t base;
      } u_th;
      u_th.real = this->th;
      *(outbuffer + offset + 0) = (u_th.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_th.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_th.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_th.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->th);
      union {
        int32_t real;
        uint32_t base;
      } u_vx;
      u_vx.real = this->vx;
      *(outbuffer + offset + 0) = (u_vx.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vx.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vx.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vx.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vx);
      union {
        int32_t real;
        uint32_t base;
      } u_vy;
      u_vy.real = this->vy;
      *(outbuffer + offset + 0) = (u_vy.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vy.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vy.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vy.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vy);
      union {
        int32_t real;
        uint32_t base;
      } u_vth;
      u_vth.real = this->vth;
      *(outbuffer + offset + 0) = (u_vth.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vth.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vth.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vth.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vth);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_A;
      u_A.base = 0;
      u_A.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_A.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_A.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_A.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->A = u_A.real;
      offset += sizeof(this->A);
      union {
        int32_t real;
        uint32_t base;
      } u_B;
      u_B.base = 0;
      u_B.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_B.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_B.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_B.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->B = u_B.real;
      offset += sizeof(this->B);
      union {
        int32_t real;
        uint32_t base;
      } u_th;
      u_th.base = 0;
      u_th.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_th.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_th.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_th.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->th = u_th.real;
      offset += sizeof(this->th);
      union {
        int32_t real;
        uint32_t base;
      } u_vx;
      u_vx.base = 0;
      u_vx.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vx.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vx.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vx.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vx = u_vx.real;
      offset += sizeof(this->vx);
      union {
        int32_t real;
        uint32_t base;
      } u_vy;
      u_vy.base = 0;
      u_vy.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vy.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vy.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vy.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vy = u_vy.real;
      offset += sizeof(this->vy);
      union {
        int32_t real;
        uint32_t base;
      } u_vth;
      u_vth.base = 0;
      u_vth.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vth.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vth.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vth.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vth = u_vth.real;
      offset += sizeof(this->vth);
     return offset;
    }

    const char * getType(){ return "robomuse/chapter2_msg1"; };
    const char * getMD5(){ return "1b257d9da54433962cd96747b8ec421c"; };

  };

}
#endif