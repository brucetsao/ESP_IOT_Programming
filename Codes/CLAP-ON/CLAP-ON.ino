/**************************************************************                      
 *                     CLAP ON - CLAP OFF
 *                     ================== 
 *                       
 * In this project a sound sensor module (called the Small
 * Microphone Module) is connected to GPIO port 23 of the
 * ESP32 Devkitc. In addition, an LED is connected to GPIO
 * port 22. The LED is normally OFF and is turned ON when
 * sound is detected by the sensor (e.g. by clapping hands).
 * The LED is toggled every time sound is detected by the
 * sensor.
 *  
**************************************************************/
#define LED 22
#define SoundSensor 23
int state = 0;

//
// Configure GPIO ports LED as output and SoundSensor as input
//
void setup () 
{
  pinMode (LED, OUTPUT);
  pinMode(SoundSensor, INPUT);
  digitalWrite(LED, LOW);
}

//
// Toggle the LED when sound is detected by the sensor
//
void loop () 
{
  if(digitalRead(SoundSensor) == 1)
  {
    digitalWrite(LED, (state) ? HIGH : LOW);
    state = !state;
    delay(500);
  }
}

