#include <MQTT.h>
#include <WiFi.h>

WiFiClient mqclient;
MQTTClient mqttclient;

 void connectMQTT()
 {

  while (!mqttclient.connect("arduino", "try", "try")) {
    Serial.print(".");
    delay(1000);
  }
  mqttclient.subscribe("/nhri/#");
  Serial.println("\n MQTT connected!");


  // client.unsubscribe("/hello");
}

void messageReceived(String &topic, String &payload) {
       Serial.println("Received Message: " +payload);
  
}

/*
          if (cmd == '1' )
                  mqttclient.publish("/nhri/blood",CarNumber) ;
          if (cmd == '2' )
                  mqttclient.publish("/nhri/oxygen",CarNumber) ;
          if (cmd == '3' )
                  mqttclient.publish("/nhri/headtemperature",CarNumber) ;
          if (cmd == '4' )
                  mqttclient.publish("/nhri/bodytemperature",CarNumber) ;
          if (cmd == '5' )
                  mqttclient.publish("/nhri/bodyweight",CarNumber) ;
          if (cmd == '6' )
                  ShowmonitorScreen() ; ;
          if (cmd == '7' )
                  ShowRfidonLCD(CarNumber) ; ;

*/
void bloodwork(String ccn)
{
  mqttclient.publish("/nhri/blood",ccn) ;
 // BLOOD
}
void oxygenwork(String ccn)
{

  mqttclient.publish("/nhri/oxygen",ccn) ;
  //  PPG
}

void headtemperaturework(String ccn)
{
  mqttclient.publish("/nhri/headtemperature",ccn) ;
  //  HEADTEMP
}
void bodytemperaturework(String ccn)
{
  mqttclient.publish("/nhri/bodytemperature",ccn) ;
  //  BODYTEMP
}
void bodyweightwork(String ccn)
{
  mqttclient.publish("/nhri/bodyweight",ccn) ;
  //  WEIGHT
}
