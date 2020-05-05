/****************************************************************
 *                      FLASHING LED
 *                      ============
 *             
 * In this program an LED is connected to port GPIO23 of the
 * ESP32 Devkitc. The program flashes the LED every second
 * 
 * Program: FlashLED
 * Date   : July, 2017
 **************************************************************/
#define LED 23

void setup()
{
    pinMode(LED, OUTPUT);
}

void loop()
{
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
    delay(1000);
}
