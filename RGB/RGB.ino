/****************************************************************
 *                    RGB LED
 *                    =======
 *             
 * In this program an RGB LED is connected to the ESP32 Devkitc 
 * where Red pin to GPIO23, Green pin to GPIO22, and the Blue pin 
 * to GPIO1. The LEDs are turned ON and OFF randomly.
 * 
 * 
 * Program: RGB
 * Date   : July, 2017
 **************************************************************/
#define RED 23
#define GREEN 22
#define BLUE 1
int R, G, B;

//
// Set GPIO pin 23, 22 and 1 as outputs
//
void setup()
{
   pinMode(RED, OUTPUT);
   pinMode(GREEN, OUTPUT);
   pinMode(BLUE, OUTPUT);
   randomSeed(10);
}


//
// Use the random number generator to generate ON (1) or OFF
// (0) values for the three colours
//
void loop()
{
   R = random(0, 2);
   G = random(0, 2);
   B = random(0, 2);
   
   digitalWrite(RED, R);
   digitalWrite(GREEN, G);
   digitalWrite(BLUE, B);
   delay(500);
}
