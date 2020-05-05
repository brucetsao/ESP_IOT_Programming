/*************************************************************
 *                   SAWTOOTH WAVEFORM GENERATION
 *                   ============================
 *
 * In this project a Sawtooth waveform is generated through the
 * DAC at GPIO port 25 of teh ESP32 Devkitc.
 * 
 * The specifications of teh generated waveform are:
 * Output voltage: 0 to +3.3V
 * Frequency: 100 Hz (period 10 ms)
 * Step size: 0.1 ms
 *
 * File:   Sawtooth
 * Date:   July 2017
 * Author: Dogan Ibrahim
 *************************************************************/
#define Sawtooth 25
int DAC_Value;
float Sample = 0.0, Inc = 0.1;

void setup()
{
  pinMode(Sawtooth, ANALOG);                // Configure as analog
}



void loop()
{
     DAC_Value = Sample * 255;
     dacWrite(Sawtooth, DAC_Value);           // Send to DAC
     Sample = Sample + Inc;
     if(Sample > 1.0 || Sample < 0.0)
     {
       Inc = -Inc;
       Sample = Sample + Inc;
     }
     delayMicroseconds(454);                  // 909 us delay
}
