/*************************************************************
 *                     ON-OFF TEMPERATURE CONTROL
 *                     ==========================
 *
 * This is an ON-OFF temperature control project. A temperature 
 * sensor measures the temperature of the place (e.g. a room) 
 * where the temperature is to be controlled and compares it 
 * with a set temperature. A heater is connected to the ESP32 
 * Devkitc through a relay. If the measured temperature is below 
 * the set temperature then the heater is turned ON. If on the 
 * other hand the measured temperature is above the set point
 * temperature then the heater is turned OFF. An I2C LCD is used 
 * to show both the set temperature and the measured temperature. 
 * In addition, a push-button switch is connected to the Devkitc 
 * and the required temperature is set using this push-button 
 * switch and the LCD. The temperature can be set between 15ºC 
 * and 30ºC. Every time the push-button switch is pressed the set 
 * point temperature is increased by one Degree Centigrade and 
 * this is shown on the LCD. The temperature control process
 * starts when another push-button switch is pressed.
 *
 * File:   ONOFF
 * Date:   July 2017
 * Author: Dogan Ibrahim
 *************************************************************/
#define SetPoint 23                           // SetPoint button
#define RELAY 1                               // RELAY
#define START 19                              // START button
//
// I2C LCD libraries
//
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
//
// DHT11 libraries
//
#include <Adafruit_Sensor.h>
#include "DHT.h"
#define DHT11_PIN 18
#define DHTTYPE DHT11
//
// Temperature variables
//
int MinTemperature = 15;                        // Min setting
int MaxTemperature = 30;                         // Max setting
int RequiredTemperature;
int First = 1;

DHT dht(DHT11_PIN, DHTTYPE);

//
// Set the LCD address to 0x27 and the configuration to
// 16 chars and 2 rows display. Also, initialize the LCD
// and the DHT11 sensor chip, turn the RELAY OFF to start
// with and clear the LCD
//
LiquidCrystal_I2C lcd(0x27, 16, 2);       // LCD address 0x27

void setup()
{
  pinMode(RELAY, OUTPUT);                 // Configure output
  pinMode(SetPoint, INPUT);               // Configure input
  pinMode(START, INPUT);                  // Configure input
  digitalWrite(RELAY, LOW);               // RELAY OFF to start with
  dht.begin();                            // Initialize DHT11
	lcd.begin();                            // Initialize LCD
	lcd.backlight();                        // Turn ON backlight
}

//
// This function sets the required temperature. Pressing the
// SetPoint button increases teh required temperature value by
// 1. When teh required setting is reached, you should press
// the START button to exit from this function. The required
// temperature can be between 15 and 30 degrees Centigrade
//
int SetTemperature()
{
  int ExitFlag = 0;
  lcd.setCursor(0, 0);                    // Go to col 0, row 0
  lcd.print("Req. Temperature");          // Display "Req. Temperature"
  lcd.setCursor(0, 1);                    // Go to col 0, row 1
  RequiredTemperature = MinTemperature;
  lcd.print(RequiredTemperature);         // Display req temp
  
  while(ExitFlag == 0)                    // Do until START pressed
  {
     if(digitalRead(SetPoint) == 0)
     {
         RequiredTemperature++;
         if(RequiredTemperature > MaxTemperature)
         {
            RequiredTemperature = MinTemperature;
         }
         lcd.setCursor(0, 1);
         lcd.print(RequiredTemperature);
         delay(150);
     }
     else if(digitalRead(START) == 0)
     {
         ExitFlag = 1;
     }
   }
   lcd.clear();
   return RequiredTemperature;
}

//
// Main program. At the beginning the required temperature is read
// from the user. The program then implements the ON-OFF temp
// algorithm to control the temperature. Both the measured and
// the required temperature values are displayed on the LCD. If
// the require dtemperature is greater than the measured one
// then the relay is turned ON, otherwise the relay is turned
// OFF. Texts ON or OFF are also displayed at the second row of
// the LCD to show whether or not the relay is ON or OFF
//
void loop()
{
  if(First == 1)                                // If First time
  {
     RequiredTemperature = SetTemperature();
     First = 0;
  }
  int Measured = dht.readTemperature();         // Read the temperature
  lcd.setCursor(0,0);                           // Go to col 0,row 0
  lcd.print("Measured=");                       // Display "Measured"
  lcd.print(Measured);
  lcd.print(char(223));                         // Display degree sign
  lcd.setCursor(0,1);                           // Go to col 0,row 1
  lcd.print("Required=");                       // Display "Required"
  lcd.print(RequiredTemperature);
  lcd.print(char(223));                         // Dislay degree sign
  if(RequiredTemperature > Measured)
  {
    digitalWrite(RELAY, HIGH);                  // Turn RELAY ON
    lcd.print(" ON ");                          // Display "ON"
  }
  else
  {
    digitalWrite(RELAY, LOW);                   // Turn RELAY OFF
    lcd.print(" OFF");                          // Display "OFF"
  }
  delay(1000);                                  // Wait 1 second
}
