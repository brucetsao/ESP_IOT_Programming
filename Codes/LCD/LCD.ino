/*************************************************************
 *                        LCD TEXT
 *                        ========
 *
 * This proram displays text "Hello From ESP32" on an I2C LCD.
 * The LCD is connected to SDA and SCL port pins of the ESP32
 * Devkitc.
 * 
 * File:   LCD
 * Date:   July 2017
 * Author: Dogan Ibrahim
 *************************************************************/
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//
// Set the LCD address to 0x27 and the configuration to
// 16 chars and 2 rows display
//
LiquidCrystal_I2C lcd(0x27, 16, 2);       // LCD address 0x27

void setup()
{
	lcd.begin();                            // Initialize LCD
	lcd.backlight();                        // Turn ON backlight
	lcd.print("Hello from ESP32");          // Display Text
}


void loop()
{
	// No code here
}
