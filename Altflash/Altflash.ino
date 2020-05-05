/****************************************************************
 *                      ALTERNATE FLASHING LEDs
 *                      =======================
 *             
 * In this program two LEDs are connected to port GPIO22 and
 * GPIO23 of the ESP32 Devkitc. The program flashes the LEDs 
 * alternately with one second delay between each output
 * 
 * Program: Altflash
 * Date   : July, 2017
 **************************************************************/
#define LED1 22
#define LED2 23
#define ON HIGH
#define OFF LOW

void setup()
{
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
}

void loop()
{
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    delay(1000);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    delay(1000);
}
