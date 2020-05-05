/*************************************************************
 *                      TIMER INTERRUPT
 *                      ===============
 *
 * This is an example of using a timer interrupt on the
 * ESP32 Devkitc. In this example an LED is connected to GPIO
 * port 23. The LED is flashed every 500 ms inside the interrupt 
 * service routine.
 * 
 *
 * File:   TimerInt
 * Date:   July 2017
 * Author: Dogan Ibrahim
 *************************************************************/
#define LED 23                                // LED on GPIO 23
int state = 0;

hw_timer_t * timer = NULL;                    // Create a hardware timer

//
// Configure LED port as output. We are using timer 0 (1st timer)
// in timerBegin with the prescaler set to 80 and counting mode
// is up (set to true).
//
// The clock frequency is 80 MHz, thus, by using a pre-scaler
// value of 80, we have 1 MHz, or the timer interrupt rate will
// be every microsecond. The interrupt service routine is called
// LEDControl. We are setting to call function LEDControl when
// the timer expires and a timer interrupt is generated. Because
// teh edge mode is set to true in timerAttachInterrupt function,
// interrupts will be accepted on edge of the clock.
//
// In timerAlarmWrite function the timer alarm value is set to
// 500 ms and auto repeat is set to be true so that the interrupt
// service routine (LEDControl) will be called every 500 ms (
// remember that 1 second is equal to 1000000 microseconds).
//
//
void setup()
{
   pinMode(LED, OUTPUT);                      // LED is output
   timer = timerBegin(0, 80, true);           // Timer every microsecond
   timerAttachInterrupt(timer, &LEDControl, true);
   timerAlarmWrite(timer, 500000, true);
   timerAlarmEnable(timer);
}


//
// This is the timer interrupt service routine. Flash the LED
// every 500 ms
//
void LEDControl()
{
   if(state == 0)
   {
      state = 1;
      digitalWrite(LED, LOW);                     // LED OFF
   }
   else
   {
      state = 0;
      digitalWrite(LED, HIGH);                    // LED ON
   }
}


void loop()
{  
  // no code
}


