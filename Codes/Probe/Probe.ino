/****************************************************************
 *                    LOGIC PROBE
 *                    ===========
 *             
 * This is a logic probe program. Two LEDs, one RED and one
 * GREEN are connected to GPIO ports 23 and 22 respectively.
 * The program determiens the staet of the logic signal applied
 * to GPIO port 5. If the applied logic level is 0 then the
 * RED LED is turned ON. If on teh other hand the applied
 * logic level is 1 then the GREEN LED is turned ON.
 * 
 * 
 * Program: Probe
 * Date   : July, 2017
 **************************************************************/
#define Probe 1
#define RED 23
#define GREEN 22

//
// Configure the LEDs as outputs, and the Probe as input
//
void setup()
{
     pinMode(RED, OUTPUT);
     pinMode(GREEN, OUTPUT);
     pinMode(Probe, INPUT);
}

//
// Examine teh state of teh applied external logic signal. If
// the state is 0, then turn ON the RED LED. if on the other
// hand the external applied logic state is 1, then turn ON the
// GREEN LED
//
void loop()
{
   if(digitalRead(Probe) == 0)                         // Logic state is 0
   {
     digitalWrite(RED, HIGH);             // RED ON
     digitalWrite(GREEN, LOW);            // GREEN OFF
   }
   else                                   // Logic state 1
   {
     digitalWrite(GREEN, HIGH);           // GREEN ON
     digitalWrite(RED, LOW);              // RED OFF
   }
}

