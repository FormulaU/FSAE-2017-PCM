#include "WProgram.h"
#include "read_pps.h"

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
  return (float) acc1 / 1024;
}

float get_brake_pedal_position()
{
  return 0.0;
}
