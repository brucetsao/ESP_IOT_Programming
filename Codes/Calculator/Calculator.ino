/*************************************************************
 *                 CALCULATOR WITH KEYPAD AND LCD
 *                 ==============================
 *
 * In this project a 4x4 keypad is connected to the ESP32 Devkitc 
 * boars. In addition, an I2C LCD is connected. The program is a 
 * simple integer calculator that can perform the arithmetic
 * operations of addition, subtraction, multiplication and
 * division.
 * 
 * The keypad is configured as follows (the key between 0 and
 * ENTER is not used:
 * 
 * 1  2  3  4
 * 5  6  7  8
 * 9  0     ENTER
 * +  -  X  /
 *
 *
 * File:   Calculator
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
#define Plus '+'
#define Minus '-'
#define Multiply '*'
#define Divide '/'

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
  {'+', '-', '*', '/'}
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

char MyKey;
long Calc, Op1, Op2;

//
// Initialize the I2C LCD, turn ON backlight, clear LCD, display
// heading (CALCULATOR), wait 2 seconds and then clear LCD
//
void setup()
{
   lcd.begin();
   lcd.backlight();
   lcd.clear();
   lcd.print("CALCULATOR");                 // Display heading
   delay(2000);
   lcd.clear();
}

//
// Inside the main program, read the first number, the second
// number, and the required operation. The program displays the
// result for 5 seconds and after this time the process is
// repeated
//
void loop()
{  
   Op1 = 0;
   Op2 = 0;
   MyKey = 0;

   lcd.setCursor(0,0);                        // Col 0, row 0
   lcd.print("No1: ");                        // Display No1:
   while(1)
   {
     do
        MyKey = kpd.getKey();
     while(!MyKey);                           // Wait until key pressed
     if(MyKey == Enter)break;                 // ENTER key
     lcd.print(MyKey);                        // Echo the key
     Op1 = 10*Op1 + MyKey - '0';              // Entered number so far
   }

   lcd.setCursor(0,1);                        // Col0, row 1
   lcd.print("No2: ");                        // Display No2:
   while(1)
   {
     do
        MyKey = kpd.getKey();
     while(!MyKey);                           // Wait until key pressed
     if(MyKey == Enter)break;                 // ENTER key
     lcd.print(MyKey);                        // Echo the key
     Op2 = 10*Op2 + MyKey - '0';              // Entered number so far
   }

   lcd.clear();
   lcd.setCursor(0,0);                        // Col 0, row 0
   lcd.print("Op: ");                         // Display Op:
   do
      MyKey = kpd.getKey();
   while(!MyKey);
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("Res=");                         // Display "Res="
//
// Calculate the result and display on the LCD
//
   switch(MyKey)
   {
     case Plus:
       Calc = Op1 + Op2;
       break;
     case Minus:
        Calc = Op1 - Op2;
        break;
     case Multiply:
        Calc = Op1 * Op2;
        break;
     case Divide:
        Calc = Op1 / Op2;
        break;
    }
    lcd.print(Calc);                          // Display result
    delay(5000);                              // Wait 5 seconds
    lcd.clear();  
}


