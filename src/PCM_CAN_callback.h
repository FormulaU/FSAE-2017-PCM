#ifndef PCM_CAN_CALLBACK_H
#define PCM_CAN_CALLBACK_H

#include <can_adapter.h>
#include <RMS_CAN_driver.h>

class PCM_CAN_callback
{
 public:
  PCM_CAN_callback();

  ~PCM_CAN_callback();
  
  RMS_CAN_driver* m_p_RMS_driver;
  
  void setup_callback();
  
  static void callback(const CAN_message_t*, void*);
 private:
};

#endif //PCM_CAN_CALLBACK_H
