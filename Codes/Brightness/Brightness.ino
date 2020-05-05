/****************************************************************
 *                    CHANGING THE LED BRIGHTNESS
 *                    ===========================
 *             
 * In this program an LED is conencte dto GPIO port pin 23. 
 * The program changes teh brightness of the LED by varying
 * the voltage applied to the LED. The LED PWM function is used
 * in this project where the duty cycle of the PWM waveform is
 * varied from 0 to its full value of 255
 * 
 * Program: Brightness
 * Date   : July, 2017
 **************************************************************/
int LED = 23;
int frequency = 1000;
int resolution = 8;
int channel = 0;

//
// Set GPIO pin 23 as output. Setup the PWM channel 0 and attach
// GPIO pin 23 to this channel
//
void setup()
{
   pinMode(LED, OUTPUT);
   ledcSetup(channel, frequency, resolution);
   ledcAttachPin(LED, channel);
}


//
// Change the brightness of the LED by varying the duty cycle
// from 0% (0) to 100% (255)
//
void loop()
{
    for(int duty = 0; duty < 255; duty +=5)
    {
      ledcWrite(channel, duty);
      delay(50);
    }
    
    for(int duty = 255; duty >= 0; duty -=5)
    {
      ledcWrite(channel, duty);
      delay(50);
    }
    delay(500);
}

