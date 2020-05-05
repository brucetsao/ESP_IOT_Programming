/*************************************************************
 *                     LCD COMMANDS
 *                     ============
 *
 * This program uses various LCD commands with the aim of making
 * the programmer aware of the available commands.
 *
 * File:   LCDCommands
 * Date:   July 2017
 * Author: Dogan Ibrahim
 *************************************************************/
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
int Count = 100;

//
// Set the LCD address to 0x27 and the configuration to
// 16 chars and 2 rows display
//
LiquidCrystal_I2C lcd(0x27, 16, 2);       // LCD address 0x27

void setup()
{
	lcd.begin();                            // Initialize LCD
	lcd.backlight();                        // Turn ON backlight
  lcd.clear();                            // Clear LCD
  lcd.setCursor(7, 0);                    // column 7, row 0
  lcd.print("At 7,0");                    // Display "At 7,0"
  lcd.setCursor(7, 1);                    // Column 7, row 1
  lcd.print("At 7,1");                    // Display "At 7,1"
  delay(1000);                            // Wait 1 second
  lcd.clear();                            // Clear LCD
  lcd.noCursor();                         // Disable cursor
	lcd.print("No cursor");                 // Display "No cursor"
  delay(1000);                            // Wait 1 second
  lcd.cursor();                           // Enable cursor
  lcd.scrollDisplayRight();               // Scroll right
  delay(1000);                            // Wait 1 second
  lcd.clear();
  lcd.setCursor(10,0);
  lcd.rightToLeft();                      // Right to left
  lcd.print("Hello");                     // Display "Hello"
  lcd.leftToRight();                      // Left to right
  delay(1000);                            // Wait 1 second
  Count = 100;                            // Count = 100
  lcd.clear();                            // Clear LCD
  lcd.print(Count);                       // Display Count
}


void loop()
{
  // No code
}
