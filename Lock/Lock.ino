/*************************************************************
 *                    KEYPAD LOCK
 *                    ===========
 *
 * This is an electronic lock project using a keypad, LCD, and
 * a buzzer. A 4 digit secret number is stored in memory. The
 * lock mechanism is electrically operated and is connected to
 * a relay. The user must enter the correct code in order to 
 * activate the relay and open the door. If wrong code is entered
 * on three consequent attempts then 30 second delay is introduced
 * to the system for security.
 * 
 * The relay is connected to GPIO port 2 of the ESP32 Devkitc.
 * 
 * The keypad is configured as follows (NU keys are not used):
 * 
 * 1  2  3  4
 * 5  6  7  8
 * 9  0  NU ENTER
 * NU NU NU NU
 *
 * File:   Lock
 * Date:   July 2017
 * Author: Dogan Ibrahim
 *************************************************************/
#define SecretNumber 1234                   // Secret number
#define RELAY 2                             // Relay at port 0
#include "Keypad.h"                         // Include Keypad library
#include <Wire.h>                           // Include I2C library
#include <LiquidCrystal_I2C.h>
//
// Keypad non-numeric keys
//
#define Enter 'E'

//
// Set the LCD address to 0x27 and the configuration to 16 chars
// by 2 rows display
//
LiquidCrystal_I2C lcd(0x27, 16, 2);

//
// Define Keypad parameters
//
const byte Rows = 4;                        // Number of rows
const byte Cols = 4;                        // Number of columns
//
// Define the keymap on the keypad
//
char keys[Rows][Cols] =
{
  {'1', '2', '3', '4'},
  {'5', '6', '7', '8'},
  {'9', '0', ' ', 'E'},
  {' ', ' ', ' ', ' '}
  };
//
// Define the Keypad connections for the rows and columns
//
byte rowPins[Rows] = {17, 16, 4, 0};             // Rows 1 to 4
byte colPins[Cols] = {5, 18, 19, 23};            // Cols 1 to 4
//
// Initialize the Keypad library with the row and columns defs.
// Here, we have to specify the key map name (keys), row pin
// assignments to GPIO ports (rowPins), and the column pin
// assignments to GPIO ports (colPins)
//
Keypad kpd=Keypad(makeKeymap(keys),rowPins,colPins,Rows,Cols);

int Res, MyNumber, Attempts = 0;
char MyKey;

//
// Initialize the I2C LCD, turn ON backlight, clear LCD
//
void setup()
{
   pinMode(RELAY, OUTPUT);                      // Relay is output
   digitalWrite(RELAY, LOW);                    // Relay off
   lcd.begin();                                 // Initialize LCD
   lcd.backlight();                             // Backlight ON
   lcd.clear();                                 // Clear LCD
   attachInterrupt(digitalPinToInterrupt(4),blink,CHANGE);
}

void blink()
{
}

//
// Inside the main program, prompt for the code to be entered.
// If the code is correct then open the door (activate the relay).
// If teh code is wrong, display message to say that it is wrong.
// After three failures stop the system for 1 minute for security.
//
void loop()
{  
   lcd.clear();
   lcd.print("Enter code:");                    // Prompt for the code   
   
   MyKey = 0;
   MyNumber = 0;

   lcd.setCursor(0,1);                          // Col 0, row 1
   while(1)                                     // Get user code
   {
     do
        MyKey = kpd.getKey();
     while(!MyKey);                             // Wait until key pressed
     if(MyKey == Enter)break;                   // ENTER key
     lcd.print(MyKey);                          // Echo the key
     MyNumber = 10*MyNumber + MyKey - '0';      // Entered number so far
   }

   if(MyNumber == SecretNumber)                 // Correct code ?
   {
      Attempts = 0;
      digitalWrite(RELAY, HIGH);                // Open door
      lcd.clear();
      lcd.print("Door Opened");                 // Display opened
      delay(10000);                             // Wait 10 seconds
      digitalWrite(RELAY, LOW);                 // Close door
   }
   else                                         // Wrong code
   {
      Attempts++;                               // Increment attempts
      if(Attempts == 3)                         // 3 failures ?
      {
         Attempts = 0;                          // Clear attempts
         lcd.setCursor(0,1);                    // Go to col 0, row 1
         lcd.print("Failed to open");           // Display Wrong code
         delay(60000);                          // Wait 1 minute
      }
      else                                      // Less than 3 attempts
      {
         lcd.setCursor(0,1);                    // Goto col 0, row 1
         lcd.print("Wrong code...");            // Dislay wrong code
         delay(2000);                           // Wait 2 seconds
         lcd.clear();                           // Clear LCD
      }
   }
}


