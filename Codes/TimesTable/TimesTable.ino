/*************************************************************
 *                    LEARNING THE TIMES TABLE
 *                    ========================
 *
 * In this project a 4x4 keypad is connected to the ESP32 Devkitc 
 * boars. In addition, an I2C LCD is connected as in the previous
 * project. This project displays the times table for a chosen
 * number. Each output is displayed for one second.
 * 
 * The keypad is configured as follows (NU keys are not used):
 * 
 * 1  2  3  4
 * 5  6  7  8
 * 9  0  NU ENTER
 * NU NU NU NU
 *
 *
 * File:   TimesTable
 * Date:   July 2017
 * Author: Dogan Ibrahim
 *************************************************************/
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

int Res, MyChoice, NewTable = 1;
char MyKey;

//
// Initialize the I2C LCD, turn ON backlight, clear LCD, display
// heading (TIMES TABLE) for 2 seconds
//
void setup()
{
   lcd.begin();
   lcd.backlight();
   lcd.clear();
   lcd.print("TIMES TABLE");                    // Display heading
   delay(2000);                                 // Wait 2 seconds
}

//
// Inside the main program, read the number whose times table is
// required and then display the times table for this number
//
void loop()
{  
  if(NewTable == 1)                             // If new table
  {
     lcd.clear();
     lcd.print("Which Number ?");               // No for the table
     NewTable = 0;
  }
   
   MyKey = 0;
   MyChoice = 0;

   lcd.setCursor(0,1);                          // Col 0, row 1
   while(1)
   {
     do
        MyKey = kpd.getKey();
     while(!MyKey);                             // Wait until key pressed
     if(MyKey == Enter)break;                   // ENTER key
     lcd.print(MyKey);                          // Echo the key
     MyChoice = 10*MyChoice + MyKey - '0';      // Entered number so far
   }

   lcd.clear();
   lcd.print("Timetable for ");                 // Display heading
   lcd.print(MyChoice,10);                      // Display no
   for(int i = 1; i <=12; i++)                  // Do for 1 to 12
   {
      lcd.setCursor(0, 1);                      // Goto col0, row 1
      lcd.print("          ");
      lcd.setCursor(0,1);
      Res = i * MyChoice;                       // Calculate the result
      lcd.print(i,DEC);                         // Display the times table
      lcd.print(" X ");
      lcd.print(MyChoice, 10);
      lcd.print(" = ");
      lcd.print(Res, 10);
      delay(1000);                               // Wait 1 second
   }
   lcd.clear();
   NewTable = 1;                                 // Set new table flag
}


