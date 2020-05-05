#include "PMS.h"
PMS pms(Serial2);
PMS::DATA data;
void setup()
{
  Serial.begin(9600);   // GPIO1, GPIO3 (TX/RX pin on ESP-12E Development Board)
  Serial2.begin(9600);  // GPIO2 (D4 pin on ESP-12E Development Board)
  pms.passiveMode();    // Switch to passive mode
 // Serial.println("Waking up, wait 30 seconds for stable readings...");
  pms.wakeUp();
  delay(3000);
}
void loop()
{
 // Serial.println("Send read request...");
  pms.requestRead();
 // Serial.println("Wait max. 1 second for read...");
  if (pms.readUntil(data))
  {
    Serial.print("PM 1.0 (ug/m3): ");
    Serial.println(data.PM_AE_UG_1_0);
    Serial.print("PM 2.5 (ug/m3): ");
    Serial.println(data.PM_AE_UG_2_5);
    Serial.print("PM 10.0 (ug/m3): ");
    Serial.println(data.PM_AE_UG_10_0);
  }
  else
  {
    Serial.println("No data.");
  }
  Serial.println("Going to sleep for 60 seconds.");
  pms.sleep();
  delay(10000);
}
