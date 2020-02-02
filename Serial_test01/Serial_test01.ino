#define RXPpin 9
#define TXPpin 10


void setup() {
  // put your setup code here, to run once:
//  Serial2.begin(9600) ;
  Serial.begin(9600) ;
  Serial1.begin(9600,SERIAL_8N1, RXPpin, TXPpin);;
  Serial.println("System Start");
}

void loop() {
  // put your main code here, to run repeatedly:
    Serial.println(millis()) ;
    Serial1.print("aaaa===") ;
    Serial1.println(millis()) ;
//    Serial2.println(sprintf("bbb===%d",millis())) ;
    
}
