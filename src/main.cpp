#include "WProgram.h"
#include <RMS_can_gen.h>

int main(void)
{
  while (1) {
    delay(250);
    //Generate a torque message
    struct CAN_message_t msg;
    gen_cmd(&msg, 10, 10, true, true, false, 0);
  }
}

