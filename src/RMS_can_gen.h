// Methods to generate and decode CAN message structs in order to communicate with the RMS PM100RDX Motor Controller

#include <FlexCAN.h>

static const uint8_t BASE_ID = 10;

//Generates a Command message struct with the specified data.
void gen_cmd(CAN_message_t* msg,
	     int16_t torque, int16_t speed,
	     bool direction, bool enable,
	     bool discharge, int16_t torque_limit));
