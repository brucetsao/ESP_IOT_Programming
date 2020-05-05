
/****************************************************************
 *                    7-SEGMENT LED COUNTER
 *                    =====================
 *             
 * In this project a 7-segment LED is connecte dto the ESP32
 * Devkitc. The program counts up from 0 to 9 with one second
 * intervals. The connections between the GPIO pins and the
 * 7-segment LED segments are as follows:
 * 
 * Segment    GPIO pin
 *   a          23
 *   b          22
 *   c          1
 *   d          3
 *   e          21
 *   f          19
 *   g          18
 * 
 * 
 * Program: SevenSegment2
 * Date   : July, 2017
 **************************************************************/
int Num[] = {0x7E, 0x30, 0x6D, 0x79, 0x33, 0x5B, 0x1F, 0x70, 0x7F, 0x73};
int LEDs[] = {23, 22, 1, 3, 21, 19, 18};
int Ports[] = {0, 23, 22, 1, 3, 21, 19, 18};
int Count = 0;

//
// Configure the LEDs as outputs
//
void setup()
{
  for(int i = 0; i < 7; i++)
  {
    pinMode(LEDs[i], OUTPUT);
  }
}

//
// Turn ON the appropriate LED
//
void Display(int No, unsigned char L)
{
    unsigned char j, m, i;
    m = L - 1;
    for(i = 0; i < L; i++)
    {
      j = pow(2, m);
      digitalWrite(Ports[i], (No & j)); 
      m--;
    }
}

//
// Increment variable Count by 1 and display on the 7-segment
// display every second
//
//
void loop()
{
   Display(Num[Count], 8);
   delay(1000);
   Count++;
   if(Count == 10)Count = 0;
}


