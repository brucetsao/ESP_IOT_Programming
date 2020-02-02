/****************************************************************
 *        MEASURING THE LIGHT LEVEL
 *        =========================
 *             
 * In this program a light dependent resistor is connected
 * to analog input GPIO4 of the ESP32 Devkitc. The program
 * measures and then displays the light level through the
 * Serial Monitor. The resistance of the LDR increases in
 * dark and as a result a higher reading is obtained. 
 * 
 * 
 * Program: LDR
 * Date   : July, 2017
 **************************************************************/
#define LDR 4
//
// Set the Serial Monitor baud rate to 9600
//
void setup()
{
   Serial.begin(9600);
}


//
// Read the light level and display through the Serial Monitor
//
void loop()
{
   int ldr = analogRead(LDR);
   Serial.println(ldr);
   delay(1000);
}

