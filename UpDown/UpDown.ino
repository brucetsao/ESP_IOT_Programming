/****************************************************************
 *                      BINARY UP/DOWN COUNTER
 *                      ======================
 *             
 * In this program 8 LEDs are connected to port pins GPIO23, 
 * GPIO22, GPIO1, GPIO3, GPIO21, GPIO19, GPIO18, and GPIO5 
 * of the ESP32 Devkitc. In addition, a push-button switch
 * is conencte dto port pin 17. Normally the switch output is
 * at logic 0 and when the switch is pressed its output goes
 * to logic 1. The program normally counte up. When the switch
 * is pressed and held down then the program starts to count
 * down from its last value. The appropriate LEDs are turned
 * ON/OFF
 * 
 * 
 * Program: UpDown
 * Date   : July, 2017
 **************************************************************/
#define Button 17
#define UP 0
#define DOWN 1
int LEDs[] = {23, 22, 1, 3, 21, 19, 18, 5};
unsigned char Count = 0;
unsigned char Button_State;

//
// Set GPIO pins 23,22,1,3,21,19,18,5 as outputs and GPIO pin 17
// as input
//
void setup()
{
    unsigned char i;
    for(i=0; i < 8; i++)
    {
        pinMode(LEDs[i], OUTPUT);
    }
    pinMode(Button, INPUT);
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
// When teh button is not pressed increment Count every second
// and send Count to GPIO pins. When the button is pressed
// count down from the last value and send Count to GPIO pins
// Notice that the width is 8-bits (i.e. there are 8 LEDs)
//
void loop()
{
    Display(Count, 8);
    Button_State = digitalRead(Button);     // Read Button state
    if(Button_State == UP)                  // If UP count
    {
      if(Count == 255)
        Count = 0;                          // Reset Count
      else
        Count++;                            // Increment Count
    }
    else if(Button_State = DOWN)            // If DOWN count
    {
      if(Count == 0)
        Count = 255;                        // Reset Count
      else
        Count--;                            // Decreament Count
    }
    delay(1000);                            // Wait 1 second
}
