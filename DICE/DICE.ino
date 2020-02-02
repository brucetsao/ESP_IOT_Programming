/****************************************************************
 *                LED DICE
 *                ========
 *             
 * In this program 7 LEDs are connected in to the ESP32 Devkitc
 * to simulate the faces of a dice. In addition, a push-button 
 * switch is used. When the switch is pressed, a random number
 * is generated between 1 and 6 and the LEDs are turned ON to
 * indicate the number as if it is a real dice. The LEDs display
 * the number for 3 seconds and then turn OFF to indicate that
 * the system is ready so that the user can press the button
 * again if desired.
 * 
 * The connections of the LEDs and the push-button switch are
 * as follows:
 * 
 * D1: GPIO23, D2: GPIO1, D3: GPIO19, D4: GPIO21, D5: GPIO22
 * D6: GPIO3,  D7: GPIO18
 * Push button switch: GPIO5
 * 
 * 
 * Program: DICE
 * Date   : July, 2017
 **************************************************************/
#define Button 5
#define D1 23
#define D5 22
#define D2 1
#define D6 3
#define D4 21
#define D3 19
#define D7 18
int LEDs[] = {23, 22, 1, 3, 21, 19, 18};

//
// Configure the LEDs as outputs, and the Button as input
//
void setup()
{
   for(int i = 0; i < 7; i++)
   {
     pinMode(LEDs[i], OUTPUT);
   }
   pinMode(Button, INPUT);
   randomSeed(10);
   
}

//
// Turn all LEDs OFF
//
void ALL_OFF()
{
   for(int i = 0; i < 7; i++)
   {
     digitalWrite(LEDs[i], LOW);
   }  
}

//
// Turn OFF all LEDS so that the system is ready to accept a
// new button press. Wait until the Button is pressed. Then,
// generate a random number between 1 and 6. Turn ON the 
// appropriate LEDs to display the number as a real dice face.
// The program displays the number for 3 seconds and then all
// the LEDs are turned OFF, ready for the next button press.
//
void loop()
{
   ALL_OFF();                             // Turn OFF all LEDs
   while(digitalRead(Button) == 1);       // Wait for Button pressed
   int dice = random(1, 7);               // Generate a random number
   
   switch (dice)
   {
    case 1:                               // Number 1
      digitalWrite(D4, HIGH);             // Turn ON D4
      break;
    case 2:                               // Number 2
      digitalWrite(D2, HIGH);             // Turn ON D2,D6
      digitalWrite(D6, HIGH);
      break;
    case 3:                               // Number 3
      digitalWrite(D2, HIGH);             // Turn ON D2,D4,D6
      digitalWrite(D4, HIGH);
      digitalWrite(D6, HIGH);
      break;
    case 4:                               // Number 4
      digitalWrite(D1, HIGH);             // Turn ON D1,D3,D5,D7
      digitalWrite(D3, HIGH);
      digitalWrite(D5, HIGH);
      digitalWrite(D7, HIGH);
      break; 
    case 5:                               // Number 5
      digitalWrite(D1, HIGH);             // Turn ON D1,D3,D4,D5,D7
      digitalWrite(D3, HIGH);
      digitalWrite(D4, HIGH);
      digitalWrite(D5, HIGH);
      digitalWrite(D7, HIGH);
      break; 
    case 6:                               // Number 6
      digitalWrite(D1, HIGH);             // Turn ON D1,D2,D3,D5,D6,D7
      digitalWrite(D2, HIGH);
      digitalWrite(D3, HIGH);
      digitalWrite(D5, HIGH);
      digitalWrite(D6, HIGH);
      digitalWrite(D7, HIGH);
      break;
   }
   delay(3000);                           // Display for 3 seconds
}

