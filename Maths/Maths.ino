/*************************************************************
 *                    BASIC MATHEMATICS
 *                    =================
 *
 * In this project an I2C LCD is connected to the ESP32 Devkitc. 
 * The program generates two integer random numbers between 1 and
 * 100 and multiplies these numbers. The result is not shown for
 * 30 seconds where the program waits so that the user can
 * calculate the result. After 30 seconds the result is displayed
 * so that the user can check with his/her own result.
 * 
 * The I2C LCD is conencted to the ESP332 Devkitc as in the
 * previous projects, i.e. using the SDA and SCL I2C lines
 *
 * File:   Maths
 * Date:   July 2017
 * Author: Dogan Ibrahim
 *************************************************************/
#include <Wire.h>                           // Include I2C library
#include <LiquidCrystal_I2C.h>

//
// Set the LCD address to 0x27 and the configuration to 16 chars
// by 2 rows display
//
LiquidCrystal_I2C lcd(0x27, 16, 2);

int FirstNumber, SecondNumber, Res;

//
// Initialize the I2C LCD, turn ON backlight, clear LCD, display
// heading (MATHS) for 2 seconds
//
void setup()
{
   lcd.begin();                                 // Initialize LCD
   lcd.backlight();                             // Backlight ON
   lcd.clear();                                 // Clear LCD
   lcd.print("BASIC MATHS");                    // Display heading
   delay(2000);                                 // Wait 2 seconds
   randomSeed(10);
}

//
// Inside the main program, read the number whose times table is
// required and then display the times table for this number
//
void loop()
{ 
   lcd.clear();
   lcd.print("Multiplication");                     // Display heading
   FirstNumber = random(1, 101);                    // First number
   SecondNumber = random(1, 101);                   // Second number
   Res = FirstNumber * SecondNumber;                // Result
   lcd.setCursor(0, 1);                             // Go to col 0, row 1
   lcd.print("          ");
   lcd.setCursor(0,1);
   lcd.print(FirstNumber,DEC);                      // Display the question
   lcd.print(" X ");
   lcd.print(SecondNumber, 10);
   lcd.print(" = ");
   delay(30000);                                    // Wait 30 seconds
   lcd.print(Res, 10);
   delay(2000);                                     // Wait 2 seconds
}


