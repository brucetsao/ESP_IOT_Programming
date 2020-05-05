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
 * This modified program detects the high impedance state when
 * there is no logic level applied at the input
 * 
 * 
 * Program: Probe2
 * Date   : July, 2017
 **************************************************************/
#define Probe 1
#define RED 23
#define GREEN 22
#define CHECK 3

//
// Configure the LEDs as outputs, and the Probe as input
//
void setup()
{
     pinMode(RED, OUTPUT);
     pinMode(GREEN, OUTPUT);
     pinMode(CHECK, OUTPUT);
     pinMode(Probe, INPUT);
}

//
// Examine the state of teh applied external logic signal. If
// there is nothing connected at the input then assume high
// impedance state and turn OFF both LEDs. If on the other 
// hand the state is 0, then turn ON the RED LED. if on the
// other hand the external applied logic state is 1, then 
// turn ON the GREEN LED
//
void loop()
{
   digitalWrite(CHECK, HIGH);             // Set CHECK = 1
   delay(1);
   if(digitalRead(Probe) == 1)
   {
      digitalWrite(CHECK, LOW);
      delay(1);
      if(digitalRead(Probe) == 0)
      {
        digitalWrite(RED, LOW);           // High impedance state
        digitalWrite(GREEN, LOW);
      }
      else
      {
        digitalWrite(RED, LOW);
        digitalWrite(GREEN, HIGH);
      }
   }
   else
   {
      digitalWrite(CHECK, LOW);
      delay(1);
      if(digitalRead(Probe) == 0)
      {
         digitalWrite(GREEN, LOW);
         digitalWrite(RED, HIGH);
      }
   }
}

