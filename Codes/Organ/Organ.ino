/*************************************************************
 *                   MINI ELECTRONIC ORGAN
 *                   =====================
 *
 * In this project a 4x4 keypad is connected to the ESP32 Devkitc 
 * boars. In addition, a passive buzzer is connected to GPIO
 * port 17. The program configures the keypad so that the
 * musical notes for one octave can be played by using the
 * keypad.
 * 
 * The keypad is configured as follows (A to G are the musical
 * notes):
 * C4  D4  E4  F4
 * G4  A4  B4  C5
 * C4# D4# F4# G4#
 * A4#
 *
 *
 * File:   Organ
 * Date:   July 2017
 * Author: Dogan Ibrahim
 *************************************************************/
#include "Keypad.h"                       // Include Keypad library
#define BUZZER 4
int Notes[] = {0,262,294,330,349,392,440,494,524,277,311,370,415,466};

//
// Define PWM parameters
//
int duty = 127;                           // Duty cycle (50%)
int resolution = 8;                       // 8 bit resolution
int channel = 0;                          // Channel 0
int freq = 1000;                          // To start with
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
  {'9', 'a', 'b', 'c'},
  {'d', 'e', 'f', 'g'}
  };
//
// Define the Keypad connections for the rows and columns
//
byte rowPins[Rows] = {18, 5, 17, 16};             // Rows 1 to 4
byte colPins[Cols] = {19, 21, 22, 23};            // Cols 1 to 4
//
// Initialize the Keypad library with the row and columns defs.
// Here, we have to specify the key map name (keys), row pin
// assignments to GPIO ports (rowPins), and the column pin
// assignments to GPIO ports (colPins)
//
Keypad kpd=Keypad(makeKeymap(keys),rowPins,colPins,Rows,Cols);

//
// Configure BUZZER as an output port. Also, configure the PWM
//
void setup()
{
   pinMode(BUZZER, OUTPUT);
   ledcSetup(channel, freq, resolution);
   ledcAttachPin(BUZZER, channel);
}

//
// Inside the main program, look for a key press. When a key is
// pressed, get its code, convert to a number, find the frequency
// corresponding to this number, and then activate the buzzer by
// sending it the reuired frequency. The buzzer sounds for 150 ms
// where after this time the buzzer stops.
//
void loop()
{
   char keypressed = kpd.getKey();              // Look for key press
   if(keypressed != NO_KEY)                     // If a key is pressed
   {
       if(keypressed >= 'a')                    // Convert to a number
           keypressed = keypressed - 'a' + 10;
       else keypressed -= '0';
      
       freq = Notes[keypressed];                // Get the frequency
       ledcWriteTone(channel, freq);            // Start buzzer
       delay(250);                              // Sound for 250 ms
       ledcWrite(channel, 0);                   // Stop buzzer
   }
}

