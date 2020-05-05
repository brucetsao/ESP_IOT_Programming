/****************************************************************
 *                THERMOMETER WITH SERIAL MONITOR
 *                ===============================
 *             
 * In this program a TMP36 type analog temperature sensor chip 
 * is connected to GPIO pin 4 which is also an analog input.
 * The program reads the ambient temperature every second and
 * sends the readings to the Serial Monitor
 * 
 * 
 * Program: TMP36
 * Date   : July, 2017
 **************************************************************/
#define TMP36 4

void setup()
{
   Serial.begin(9600);
}


//
// Read the ambient temperaure, convert into Degrees Centigrade
// and send the readings to the Serial Monitor. Repeat this
// process every second
//
void loop()
{
   int Temp = analogRead(TMP36);
   float mV = Temp * 3300.0 / 4096.0;
   float Temperature = (mV - 500.0) / 10.0;
   Serial.println(Temperature);  
   delay(1000);
}

