/****************************************************************
 *    RELATIVE HUMIDITY AND TEMPERATURE WITH SERIAL MONITOR
 *    =====================================================
 *             
 * In this program a DHT11 type relative humidity and temperature
 * sensor chip is connected to GPIO pin 23. The relative humidity
 * and the ambient temperature are read every second and the
 * readings are displayed on the Serial monitor.
 * 
 * Program: DHT11
 * Date   : July, 2017
 **************************************************************/
#include <Adafruit_Sensor.h>
#include "DHT.h"
#define DHT11_PIN 23
#define DHTTYPE DHT11

DHT dht(DHT11_PIN, DHTTYPE);

//
// Set the Serial Monitor baud rate to 9600 and initislize the
// DHT library
//
void setup()
{
   Serial.begin(9600);
   dht.begin();
}



//
// Read the relative humidity and the ambient temperaure and
// display teh results on teh Serial Monitor
//
void loop()
{
   float humidity = dht.readHumidity();         // Read humidity
   float temperature = dht.readTemperature();   // Read temperature
   Serial.print("Temperature = ");              // Display "Temperature="
   Serial.print(temperature);                   // Display temperature
   Serial.print("  Humidity = ");               // Display "Humidity="
   Serial.println(humidity);                    // Display humidity
   delay(1000);                                 // Wait 1 second
}
