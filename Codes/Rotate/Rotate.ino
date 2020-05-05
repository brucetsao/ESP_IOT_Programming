/****************************************************************
 *                      ROTATING LEDs
 *                      =============
 *             
 * In this program four LEDs are connected to port GPIO23, 
 * GPIO22, GPIO1, and GPIO3 and of the ESP32 Devkitc. The 
 * program turns ON the LEDs in a rotating pattern. The ON
 * and OFF times are chosen as 500 ms and 100 ms so that a
 * nice rotating effect is displayed
 * 
 * Program: Rotate
 * Date   : July, 2017
 **************************************************************/
int LEDs[] = {23, 22, 1, 3};
#define ON HIGH
#define OFF LOW

//
// Set GPIO pins 23,22,1,3 as outputs and turn OFF the LEDs
// to start with
//
void setup()
{
    unsigned char i;
    for(i=0; i <=3; i++)
    {
        pinMode(LEDs[i], OUTPUT);
        digitalWrite(LEDs[i], OFF);
    }
}


//
// Turn ON/OFF the LEDs in a rotating pattern
//
void loop()
{
    unsigned char j;
    for(j = 0; j <=3; j++)
    {
        digitalWrite(LEDs[j], ON);
        delay(500);
        digitalWrite(LEDs[j], OFF);
        delay(100);
    }
}
