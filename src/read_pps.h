#ifndef READ_PPS_H
#define READ_PPS_H
// Initializes the resources required to read pedal positions
void initialize_pps_read();

// Returns a float, with range between 0 and 1, indicating the position of the
// accelerator pedal.
float get_acc_pedal_position();

// Returns a float, with range between 0 and 1, indicating the position of the
// break pedal.
float get_brake_pedal_position();

#endif
