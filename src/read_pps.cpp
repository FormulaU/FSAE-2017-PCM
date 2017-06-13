#include "WProgram.h"
#include "read_pps.h"

//The analogRead value that corresponds to a pedal position of "zero"
//(lowest voltage)
static int zero_pos = 50;
//The analogRead value that corresponds to a pedal position of "1"
//(highest voltage)
static int max_pos = 970;

static int acc_read_pin_0 = 0;
// static int acc_read_pin_1 = 1;
// static int brake_read_pin_0 = 2;
// static int brake_read_pin_1 = 3;

void initialize_pps_read()
{
  //Nothing, for now.
}

float get_acc_pedal_position()
{
  //Test code: read from a single pin, return the corrected value.
  int acc1 = analogRead(acc_read_pin_0);
  //Hack: correct for .05-.95 range
  return ((float) (acc1 - zero_pos) / 1023) / (((float) max_pos - zero_pos)/1023);
}

float get_brake_pedal_position()
{
  return 0.0;
}
