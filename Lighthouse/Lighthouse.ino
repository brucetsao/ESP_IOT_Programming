/****************************************************************
 *                      LIGHHOUSE FLASHING LED
 *                      ======================
 *             
 * In this program an LED is connected to port GPIO23 of the
 * ESP32 Devkitc. The program flashes the LED with the lighthouse
 * lighting sequence GpFl(2)
 * 
 * Program: Lighthouse
 * Date   : July, 2017
 **************************************************************/
#define LED 23
#define ON HIGH
#define OFF LOW

void setup()
{
    pinMode(LED, OUTPUT);
}

void loop()
{
    digitalWrite(LED, ON);
    delay(200);
    digitalWrite(LED, OFF);
    delay(100);
    digitalWrite(LED, ON);
    delay(200);
    digitalWrite(LED, OFF);
    delay(100);
    delay(400);
}
