/****************************************************************
 *                    Random Buzzer
 *                    =============
 *             
 * In this program a passive Buzzer is conencted to GPIO port 
 * pin 23. The program generates random numbers between 1000 
 * and 5000 and these numbers are used as the random feequency
 * to drive the Buzzer. The net effect is that the Buzzer
 * generates sound with random frequencies. The duty cycle of
 * the waveform is set to 50% (127). 500 ms delay is inserted
 * between each output.
 * 
 * 
 * Program: RandomBuzzer
 * Date   : July, 2017
 **************************************************************/
int Buzzer = 23;                      // Buzzer on GPIO pin 23
int duty = 127;                       // 50% duty cycle
int freq = 1000;                      // Initial freq 1000 Hz
int resolution = 8;                   // Resolution 8 bits
int channel = 0;                      // Channel 0

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
// Use the random number generator to generate the frequency
// values between 1000 Hz and 5000 Hz. The duty cycle is set
// to 50% (127)
//
void loop()
{
    freq = random(1000, 5000);
    ledcWriteTone(channel, freq);
    delay(500);
}

