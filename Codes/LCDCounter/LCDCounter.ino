/*************************************************************
 *                     LCD EVENT COUNTER
 *                     =================
 *
 * This is an event counter program with an LCD. Events are 
 * assumed to occur on GPIO port 23 where an event is the HIGH
 * to LOW transition of this pin. In this project events are
 * simulated using a push-button switch connected to GPIO23 and
 * pulled high. An I2C LCD is connected to the ESP32 Devkitc.
 * 
 * File:   LCDCounter
 * Date:   July 2017
 * Author: Dogan Ibrahim
 *************************************************************/
#define EVENTS 23
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
int Count = 0;
char Res[4];

//
// Set the LCD address to 0x27 and the configuration to
// 16 chars and 2 rows display. Also configure port 23 as
// an input
//
LiquidCrystal_I2C lcd(0x27, 16, 2);       // LCD address 0x27

void setup()
{
  pinMode(EVENTS, INPUT);
	lcd.begin();                            // Initialize LCD
	lcd.backlight();                        // Turn ON backlight
	lcd.print("Event Counter");             // Display Text
}


void loop()
{
  while(digitalRead(EVENTS) == 1);        // Wait until event
  delay(150);                             // Contact debounce
  lcd.clear();                            // Clear LCD
  Count++;                                // Incement Count
  snprintf(Res, 4, "%d", Count);          // Convert to string
  lcd.print(Res);                         // Display on LCD
}
