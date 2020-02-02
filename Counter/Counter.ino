/****************************************************************
 *                      BINARY UP COUNTER
 *                      ==================
 *             
 * In this program 8 LEDs are connected to port pins GPIO23, 
 * GPIO22, GPIO1, GPIO3, GPIO21, GPIO19, GPIO18, and GPIO5 
 * of the ESP32 Devkitc. The program counts up by one and
 * sends the count to he GPIO pins to turn ON/OFF the 
 * appropriate LEDs so that the LEDs count up by one in binary.
 * A one secodn delay is inserted between each output
 * 
 * 
 * Program: Counter
 * Date   : July, 2017
 **************************************************************/
int LEDs[] = {23, 22, 1, 3, 21, 19, 18, 5};
unsigned char Count = 0;

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
// Increment Count every second and send Count to GPIO 
// pins. Notice that the width is 8-bits (i.e. there are
// 8 LEDs)
//
void loop()
{
    Display(Count, 8);
    if(Count == 255)
      Count = 0;
    else
      Count++;
    delay(1000);
}

