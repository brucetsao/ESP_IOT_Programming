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
 * File:   Testkeypad2
 * Date:   July 2017
 * Author: Dogan Ibrahim
 *************************************************************/
#include "Keypad.h"                       // Include Keypad library
//
// Define Keypad parameters
//
const byte Rows = 4;                      // Number of rows
const byte Cols = 4;                      // Number of columns
//
// Define the keymap on the keypad
//
char keys[Rows][Cols] =
{
  {'1', '2', '3', '4'},
  {'5', '6', '7', '8'},
  {'9', '0', ' ', 'E'},
  {'+', '-', 'X', '/'}
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


void setup()
{
   Serial.begin(9600);
}


void loop()
{
   char keypressed = kpd.getKey();              // Look for key press
   if(keypressed != NO_KEY)                     // If a key is pressed
   {
      Serial.print(keypressed);                 // Display on Serial Monitor
   }
