#include <Arduino.h>
#define uS_TO_S_FACTOR 1000000  // Conversion factor for micro seconds to seconds
#define TIME_TO_SLEEP  10       // Time ESP32 will go to sleep (in seconds)

RTC_DATA_ATTR int bootCount = 0;
int normalVar = 0;

void setup() {
    Serial.begin(115200);
    delay(1000);
    
    ++bootCount;
    Serial.println("Boot number: " + String(bootCount));

    ++normalVar;
    Serial.println("Normal Variable: " + String(normalVar));
    
    esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
    Serial.println("Going to sleep for " + String(TIME_TO_SLEEP) + " seconds");
    
    esp_deep_sleep_start();
}

void loop() {
    // This is not going to be called
}