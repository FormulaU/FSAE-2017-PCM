#include "WProgram.h"
#include "read_pps.h"

extern "C" int main(void)
{
  
  
  //Set up resources:
  initialize_pps_read();
  
  //Set up the LED pin as an output.
  pinMode(13, OUTPUT);
  //Set up the USB serial link.
  Serial.begin(9600);
	
  //Control Loop:
  while (1)
    {
      digitalWriteFast(13, HIGH);
      delay(250);
      digitalWriteFast(13, LOW);
      delay(250);
      Serial.print("Pedal Position: ");
      Serial.println(get_acc_pedal_position());
    }
}

