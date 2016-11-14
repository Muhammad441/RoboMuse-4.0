#ifndef _ROS_SERVICE_SendCommand_h
#define _ROS_SERVICE_SendCommand_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace nav2d_navigator
{

static const char SENDCOMMAND[] = "nav2d_navigator/SendCommand";

  class SendCommandRequest : public ros::Msg
  {
    public:
      int8_t command;

    SendCommandRequest():
      command(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_command;
      u_command.real = this->command;
      *(outbuffer + offset + 0) = (u_command.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->command);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_command;
      u_command.base = 0;
      u_command.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->command = u_command.real;
      offset += sizeof(this->command);
     return offset;
    }

    const char * getType(){ return SENDCOMMAND; };
    const char * getMD5(){ return "481ac5a494c3140a2539020bd74c82c7"; };

  };

  class SendCommandResponse : public ros::Msg
  {
    public:
      int8_t response;

    SendCommandResponse():
      response(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_response;
      u_response.real = this->response;
      *(outbuffer + offset + 0) = (u_response.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->response);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_response;
      u_response.base = 0;
      u_response.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->response = u_response.real;
      offset += sizeof(this->response);
     return offset;
    }

    const char * getType(){ return SENDCOMMAND; };
    const char * getMD5(){ return "2cea8cb5717c628edaef5080f770244d"; };

  };

  class SendCommand {
    public:
    typedef SendCommandRequest Request;
    typedef SendCommandResponse Response;
  };

}
#endif
