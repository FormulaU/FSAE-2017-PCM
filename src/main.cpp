#include "WProgram.h"
#include <RMS_can_gen.h>
#include <can_adapter.h>
int main(void)
{
  //Setup
  pinMode(13, OUTPUT);
  digitalWriteFast(13, HIGH);
  initialize_can();
  struct CAN_message_t msg;
  
  //Send out inverter disable command to release lockout
  msg.id = 0xC0;
  msg.len = 8;
  //Initialize message to zeros.
  for (int i = 0; i < 7; i++)
    {
      msg.buf[i] = 0x00;
    }
  //Send message.
  can_write(msg);
  
  while (1) {
    delay(125);
    digitalWriteFast(13, HIGH);
    //Generate a torque message
    int16_t torque = 10;
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

