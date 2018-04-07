#include <PCM_CAN_callback.h>
static const uint16_t RMS_IDs [] = {
  RMS_CAN_driver::CAN_OFFSET+0x0000,
  RMS_CAN_driver::CAN_OFFSET+0x0001,
  RMS_CAN_driver::CAN_OFFSET+0x0002,
  RMS_CAN_driver::CAN_OFFSET+0x0003,
  RMS_CAN_driver::CAN_OFFSET+0x0004,
  RMS_CAN_driver::CAN_OFFSET+0x0005,
  RMS_CAN_driver::CAN_OFFSET+0x0006,
  RMS_CAN_driver::CAN_OFFSET+0x0007,
  RMS_CAN_driver::CAN_OFFSET+0x0008,
  RMS_CAN_driver::CAN_OFFSET+0x0009,
  RMS_CAN_driver::CAN_OFFSET+0x000A,
  RMS_CAN_driver::CAN_OFFSET+0x000B,
  RMS_CAN_driver::CAN_OFFSET+0x000C,
  RMS_CAN_driver::CAN_OFFSET+0x000D,
  RMS_CAN_driver::CAN_OFFSET+0x000E,
  RMS_CAN_driver::CAN_OFFSET+0x000F
};

PCM_CAN_callback::PCM_CAN_callback()
{
  
}

PCM_CAN_callback::~PCM_CAN_callback()
{

}

void PCM_CAN_callback::callback(const CAN_message_t* msg, void* ctx)
{
  PCM_CAN_callback* PCM_callback = static_cast<PCM_CAN_callback*>(ctx);
  

}
