#define RXD2 16
#define TXD2 17

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600) ;
     Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
    Serial.println("Uart Test Start") ;
}

void loop() {
  // put your main code here, to run repeatedly:
      if (Serial.available()>0)
        {
            Serial2.write(Serial.read()) ;
        }
      if (Serial2.available()>0)
        {
            Serial.write(Serial2.read()) ;
        }
        
        
}
