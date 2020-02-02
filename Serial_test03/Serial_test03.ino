#include <HardwareSerial.h>

#define RXD2 16
#define TXD2 17
HardwareSerial Serial9(2);

void setup() {
  // Note the format for setting a serial port is as follows: Serial2.begin(baud-rate, protocol, RX pin, TX pin);
  Serial.begin(9600);
  //Serial1.begin(9600, SERIAL_8N1, RXD2, TXD2);
//  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
  Serial9.begin(9600);
  Serial.println("Serial Txd is on pin: "+String(TX));
  Serial.println("Serial Rxd is on pin: "+String(RX));
}

void loop() { //Choose Serial1 or Serial2 as required
  if(Serial9.available()) {
    Serial.print(char(Serial9.read()));
  }

  if(Serial.available()) {
    Serial9.print(char(Serial.read()));
  }


}
