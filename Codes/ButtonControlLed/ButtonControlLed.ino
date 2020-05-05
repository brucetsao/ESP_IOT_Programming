#define LedPin 2
#define ButtonPin 4

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LedPin, OUTPUT);
  digitalWrite(LedPin,LOW) ;
}

// the loop function runs over and over again forever
void loop() {
  if (digitalRead(ButtonPin) == HIGH)
    {
        digitalWrite(LedPin, HIGH);   // turn the LED on (HIGH is the voltage level)
    }
    else
    {
        digitalWrite(LedPin, LOW);   // turn the LED on (HIGH is the voltage level)
    }
}
