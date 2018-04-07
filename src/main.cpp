#include "WProgram.h"
#include <RMS_can_gen.h>

int main(void)
{
  while (1) {
    delay(250);
    //Generate a torque message
    struct CAN_message_t msg;
    int16_t torque = 10;
    int16_t speed = 0;
    bool direction = true;
    bool enable = true;
    bool discharge = false;
    int16_t torque_limit = 0;
    gen_cmd(&msg, torque, speed, direction, enable, discharge, torque_limit);

    
  }
}

