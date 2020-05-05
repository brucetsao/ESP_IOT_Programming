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
 * Program: SevenSegment
 * Date   : July, 2017
 **************************************************************/
int Num[]= {6, 23, 22, 1, 3, 21, 19,          //0
            2, 22, 1,                         //1
            5, 23, 22, 18, 21, 3,             //2
            5, 23, 22, 18, 1, 3,              //3
            4, 19, 18, 22,1,                  //4
            5, 23, 19, 18, 1, 3,              //5
            5, 19, 18, 1, 3, 21,              //6
            3, 23, 22, 1,                     //7
            7, 23, 22, 1, 3, 21, 19, 18,      //8
            5, 23, 22, 19, 18, 1};            //9
int Strt[] = {0, 7, 10, 16, 22, 27, 33, 39, 43, 51};
int LEDs[] = {23, 22, 1, 3, 21, 19, 18};
int Count = 0;

//
// Configure the LEDs as outputs, and also turn OFF all segments
//
void setup()
{
  for(int i = 0; i < 7; i++)
  {
    pinMode(LEDs[i], OUTPUT);
    ALL_OFF();
  }
}

//
// Turn OFF all segments
//
void ALL_OFF()
{
  for(int i = 0; i < 8; i++)
  {
    digitalWrite(LEDs[i], LOW);
  }
}
//
// This function display a given number N on the 7-segment display
//
void Display(int N)
{
  int i, k;
  k = Strt[N];                            // Starting index
  i = Num[k];                             // Length
  for(int m = k + 1; m < k + 1 + i; m++)
  {
    digitalWrite(Num[m], HIGH);
  }
}
//
// Increment variable Count by 1 and display on the 7-segment
// display every second
//
//
void loop()
{
   Display(Count);
   delay(1000);
   ALL_OFF();
   Count++;
   if(Count == 10)Count = 0;
}

