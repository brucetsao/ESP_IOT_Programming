/****************************************************************
 *                      CHRISTMAS LIGHTS
 *                      ================
 *             
 * In this program four LEDs are connected to port GPIO23, 
 * GPIO22, GPIO1, and GPIO3 and of the ESP32 Devkitc. The 
 * program turns ON the LEDs in a random manner every second
 * to give the effect of for example Christmas lights
 * 
 * Program: Christmas
 * Date   : July, 2017
 **************************************************************/
int LEDs[] = {23, 22, 1, 3};
unsigned char Ran;

//
// Set GPIO pins 23,22,1,3 as outputs
//
void setup()
{
    unsigned char i;
    for(i=0; i <=3; i++)
    {
        pinMode(LEDs[i], OUTPUT);
    }
    randomSeed(10);
}

//
// Turn ON the appropriate LED
//
void Display(unsigned char No, unsigned char L)
{
    unsigned char j, m, i;
    m = L - 1;
    for(i = 0; i < L; i++)
    {
      j = pow(2, m);
      digitalWrite(LEDs[i], (No & j)); 
      m--;
    }
}

//
// Turn ON/OFF the LEDs randomly by generating a random number
// between 1 and 15
//
void loop()
{
    //Ran = random(1, 16);
    Display(1, 4);
    delay(2000);
    Display(3, 4);
    delay(2000);
    Display(7, 4);
    delay(2000);
    Display(12, 4);
    delay(2000);
    Display(15, 4);
    delay(2000);
    delay(1000);
}
