#include "KeyboardOutputCallbacks.h"

#if defined(CONFIG_ARDUHAL_ESP_LOG)
  #include "esp32-hal-log.h"
  #define LOG_TAG ""
#else
  #include "esp_log.h"
  static const char* LOG_TAG = "BLEDevice";
#endif

KeyboardOutputCallbacks::KeyboardOutputCallbacks(void) {
}

void KeyboardOutputCallbacks::onWrite(BLECharacteristic* me) {
  uint8_t* value = me->getData();
  size_t valueLength = me->getLength();
  if (valueLength == 0 || value == nullptr) {
    return;
  }
  ESP_LOGI(LOG_TAG, "special keys: %d", *value);
}

