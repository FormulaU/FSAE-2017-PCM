#include "WProgram.h"
#include "read_pps.h"
#include "logger.h"

int main()
{
 
  //Set up resources:
  initialize_logging(DEBUG);
  initialize_pps_read();
   
  //Set up the LED pin as an output.
  pinMode(13, OUTPUT);
	
  //Control Loop:
  while (1)
    {
      digitalWriteFast(13, HIGH);
      delay(250);
      digitalWriteFast(13, LOW);
      delay(250);
      String logpps = String("Pedal Position: ") + get_acc_pedal_position();
      FSAE_log(DEBUG, logpps.c_str());
    }
}
