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
int Buzzer = 23;
int duty = 127;
int freq = 200;
int resolution = 8;
int channel = 0;

//
// Set GPIO pin 23 as output. Setup the PWM channel 0 and attach
// GPIO pin 23 to this channel
//
void setup()
{
   pinMode(Buzzer, OUTPUT);
   ledcSetup(channel, freq, resolution);
   ledcAttachPin(Buzzer, channel);
   randomSeed(10);
}

//
// Use the random number generator to generate teh frequency
// values between 100 Hz and 5 kHz. The duty cycle is set to
// 50% (127)
//
void loop()
{
    freq = random(100, 5000);
    ledcWriteTone(channel, freq);
    delay(500);
}
