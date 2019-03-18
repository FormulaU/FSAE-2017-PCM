#include "WProgram.h"
#include <RMS_can_gen.h>
#include <can_adapter.h>

void zeroize_message(CAN_message_t& msg)
{
  msg.id = 0x00;
  msg.ext = 0;
  msg.len = 0;
  msg.timeout = 0;
  //Initialize buffer to zeros.
  for (int i = 0; i < 7; i++)
    {
      msg.buf[i] = 0x00;
    }
}

int main(void)
{
  //Setup
  pinMode(13, OUTPUT);
  
  digitalWriteFast(13, HIGH);
  initialize_can();
  struct CAN_message_t lockout_msg;
  zeroize_message(lockout_msg);
  //Send out inverter disable command to release lockout
  lockout_msg.id = 0xC0;
  lockout_msg.len = 8;
  //Initialize message to zeros.
  for (int i = 0; i < 7; i++)
    {
      lockout_msg.buf[i] = 0x00;
    }
  for (int i = 0; i < 40; i++)
  {
    delay(250);
    //Send message.
    can_write(lockout_msg);
  }

  //Initialize the torque command message
  struct CAN_message_t msg;
  zeroize_message(msg);
  msg.id = 0xC0;
  msg.len = 8;
  //Initialize message to zeros.
  for (int i = 0; i < 7; i++)
    {
      msg.buf[i] = 0x00;
    }
  while (1) {
    //Send message.
    delay(125);
    digitalWriteFast(13, HIGH);
    //Generate a torque message
    //int16_t torque = 255;
    int16_t max_torque = 255;
    int16_t zero_pos = 0;
    int16_t max_pos = 1024;
    int acc1 = analogRead(0);
    int16_t torque = static_cast<int16_t>(((float) (acc1 - zero_pos) / 1023) / (((float) max_pos - zero_pos)/1023) * max_torque);
    int16_t speed = 0;
    bool direction = true;
    bool enable = true;
    bool discharge = false;
    int16_t torque_limit = 0;
    gen_cmd(&msg, torque, speed, direction, enable, discharge, torque_limit);
    can_write(msg);
    delay(125);
    digitalWriteFast(13, LOW);
  }
}

