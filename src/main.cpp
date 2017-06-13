#include "WProgram.h"
#include "logger.h"

int main()
{
  initialize_logging(DEBUG);
  #include "read_pps.h"
  
   //Set up resources:
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
// extern "C" int main(void)
// {
// #include "read_pps.h"
  
//   //Set up resources:
//   initialize_pps_read();

  
//   //Set up the LED pin as an output.
//   pinMode(13, OUTPUT);
	
//   //Control Loop:
//   while (1)
//     {
//       digitalWriteFast(13, HIGH);
//       delay(250);
//       digitalWriteFast(13, LOW);
//       delay(250);
//       Serial.print("Pedal Position: "); 
//       Serial.println(get_acc_pedal_position(), 20);
//     }
// }

