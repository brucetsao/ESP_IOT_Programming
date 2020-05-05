/*************************************************************
 *                    HIGH-LOW GAME
 *                    =============
 *
 * In this project a 4x4 keypad is connected to the ESP32 Devkitc 
 * boars. In addition, an I2C LCD is connected as in the previous
 * project. This project is the classical High-Low game. The
 * processor generates a random number between 1 and 100. The
 * user is required to guess this number. If the number entered
 * is smaller or greater than teh generated number then a
 * message is displayed to help the user guess the correct number.
 * The game continues until the user finds the generated number
 * 
 * The keypad is configured as follows (NU keys are not used):
 * 
 * 1  2  3  4
 * 5  6  7  8
 * 9  0  NU ENTER
 * NU NU NU NU
 *
 *
 * File:   HighLow
 * Date:   July 2017
 * Author: Dogan Ibrahim
 *************************************************************/
#include "Keypad.h"                       // Include Keypad library
#include <Wire.h>                         // Include I2C library
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

long MyGuess;
char MyKey, NewGame = 1;
int Guess, Diff;

//
// Initialize the I2C LCD, turn ON backlight, clear LCD, display
// heading (HIGH-LOW GAME), wait 2 seconds and then clear LCD
//
void setup()
{
   lcd.begin();
   lcd.backlight();
   lcd.clear();
   lcd.print("HIGH-LOW GAME");                 // Display heading
   delay(2000);
   lcd.clear();
   randomSeed(10);
}

//
// Inside the main program, generate a random number between 1
// and 100. The user attempts to guess this number and sees
// messages such as HIGH or LOW to help him in making a choice
// for the next guess
//
void loop()
{  
  if(NewGame == 1)
  {
     lcd.clear();
     lcd.print("Guess Now...");
     Guess = random(1, 101);                  // Generate between 1-100
     NewGame = 0;
  }
   MyGuess = 0;
   MyKey = 0;

   lcd.setCursor(0,1);                        // Col 0, row 0
   while(1)
   {
     do
        MyKey = kpd.getKey();
     while(!MyKey);                           // Wait until key pressed
     if(MyKey == Enter)break;                 // ENTER key
     lcd.print(MyKey);                        // Echo the key
     MyGuess = 10*MyGuess + MyKey - '0';      // Entered number so far
   }

   Diff = MyGuess - Guess;                    // Difference
   if(Diff > 0)                               // High Guess ?
   {
      lcd.setCursor(0,1);
      lcd.print("HIGH - TRY AGAIN");          // Display HIGH
      delay(2000);
      lcd.setCursor(0,1);
      lcd.print("                ");  
   }
   else if(Diff < 0)
   {
      lcd.setCursor(0,1);
      lcd.print("LOW - TRY AGAIN");           // Display LOW
      delay(2000);
      lcd.setCursor(0,1);
      lcd.print("               ");
   }
   else if(Diff == 0)
   {
      lcd.setCursor(0,1);
      lcd.print("Well Done...");              // Correct
      delay(5000);                            // Wait 5 seconds
      NewGame = 1;                            // New game flag set
   }
}


