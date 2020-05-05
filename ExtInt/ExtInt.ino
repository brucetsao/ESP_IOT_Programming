/*************************************************************
 *                    EXTERNAL INTERRUPT
 *                    ==================
 *
 * This is an example of using an external interrupt on the
 * ESP32 Devkitc. In this example an LED is connected to GPIO
 * port 23 through a 330 ohm resistor. In addition, a push-button
 * switch is connected to GPIO pin 22 and this button is then
 * configured as an interrupt pin such that pressing the button
 * generates an external interrupt in the program. Normally the
 * LED flashes every 500 ms. If the button is pressed when the
 * LED is flashing then the flashing stops. If on the other hand
 * the flashing is stopped, pressing the button will re-start
 * the LED to flash.
 * 
 *
 * File:   ExtInt
 * Date:   July 2017
 * Author: Dogan Ibrahim
 *************************************************************/
#define LED 23                                // LED on GPIO 23
#define IntPin 22                             // Interrupt pin
int Flag = 1;                                 // LED flag

//
// Configure LED port as output, interrupt pin as input, and
// PULL-UP this pin so that is state is at normally logic HIGH.
// Also, Attach the interrupt pin IntPin to function LEDControl,
// and accept interrupts on the FALLING edge (logic HIGH to LOW)
// of the interrupt pin
//
void setup()
{
   pinMode(LED, OUTPUT);                      // LED is output
   pinMode(IntPin, INPUT_PULLUP);             // Interrupt pin
   attachInterrupt(digitalPinToInterrupt(IntPin),LEDControl,FALLING);
}

//
// Flash the LED every 500 ms. The flashing is stopped and
// re-started by the interrupt pin. When interrupt occurs
// by pressing the IntPin, the state of variable Flag is
// changed (if 0, it becomes 1; and if 1 it becomes 0)
//
void LEDControl()
{
  if(Flag == 0)
     Flag = 1;
  else Flag = 0;
}

//
// Flash the LED every second unless stopped by the interrupt
// 
void loop()
{  
  if(Flag == 1)                              
  {
     digitalWrite(LED, LOW);                  // LED OFF
     delay(500);                              // 500 ms delay
     digitalWrite(LED, HIGH);                 // LED ON
     delay(500);                              // 500 ms delay
  }
  else
  {
      digitalWrite(LED, LOW);                 // LED OFF
  }
}


