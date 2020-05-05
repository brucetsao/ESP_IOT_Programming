/****************************************************************
 *            DARKNESS REMINDER
 *            =================
 *             
 * In this program a light dependent resistor is connected
 * to analog input GPIO4 of the ESP32 Devkitc. In addition,
 * a buzzer and an LED are connecte dto GPIO ports 23 and 22
 * respectively. Normally both the buzzer and the LED are OFF
 * and they turn ON when it becomes dark. Darkness is assumed
 * when the LDR reading is above 2000.
 * 
 * 
 * Program: LDRALARM
 * Date   : July, 2017
 **************************************************************/
#define LDR 4
#define BUZZER 23
#define LED 22

//
// Configure both the BUZZER and the LED as outputs
//
void setup()
{
   pinMode(BUZZER, OUTPUT);
   pinMode(LED, OUTPUT);
   digitalWrite(BUZZER, LOW);
   digitalWrite(LED, LOW);
}


//
// Read the light level and turn on both the BUZZER and the LED
// when it becomes dark. In this project the darkness has been
// assumed when the LDR reading is above 2000
//
void loop()
{
   int ldr = analogRead(LDR);
   if(ldr > 2000)
   {
      digitalWrite(BUZZER, HIGH);
      digitalWrite(LED, HIGH);
   }
   else
   {
      digitalWrite(BUZZER, LOW);
      digitalWrite(LED, LOW);
   }
}

