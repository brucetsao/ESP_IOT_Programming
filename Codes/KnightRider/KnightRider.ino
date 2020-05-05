/****************************************************************
 *                      KNIGHT RIDER LEDs
 *                      =================
 *             
 * In this program 8 LEDs are connected to port pins GPIO23, 
 * GPIO22, GPIO1, GPIO3, GPIO21, GPIO19, GPIO18, and GPIO5 
 * of the ESP32 Devkitc. The program simulates the lights of 
 * the Knight Rider car as in the TV action movie Knight Rider.
 * 
 * 
 * Program: KnightRider
 * Date   : July, 2017
 **************************************************************/
int LEDs[] = {23, 22, 1, 3, 21, 19, 18, 5};
unsigned char Count = 0;
unsigned char del = 100;

//
// Set GPIO pins 23,22,1,3,21,19,18,5 as outputs
//
void setup()
{
    unsigned char i;
    for(i=0; i < 8; i++)
    {
        pinMode(LEDs[i], OUTPUT);
    }
}


//
// Turn the LEDs ON/OFF to simulate the Knight Rider car
//
void loop()
{
    for(int k = 0; k < 8; k++)
    {
      digitalWrite(LEDs[k], HIGH);
      delay(del);
      digitalWrite(LEDs[k], LOW);
    }
    
    for(int k = 6; k > 0; k--)
    {
      digitalWrite(LEDs[k], HIGH);
      delay(del);
      digitalWrite(LEDs[k], LOW);
    }
}

