
#include <String.h>
#include <WiFi.h>

const char* ssid     = "NCNU";
const char* password = "12345678";
String connectstr ="" ;
String commandstr ="" ;
WiFiServer server(80);

void setup()
{
    Serial.begin(9600);
    pinMode(5, OUTPUT);      // set the LED pin mode

    delay(10);

    // We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    
    server.begin();

}



void loop(){
 WiFiClient client = server.available();   // listen for incoming clients

  if (client) 
  {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) 
    {            // loop while the client's connected
      if (client.available()) 
      {             // if there's bytes to read from the client,
        connectstr = client.readStringUntil(0x23) ;
        // char c = client.read();   
        Serial.print("(");                    // print it out the serial monitor
        Serial.print(connectstr);         // read a byte, then
        commandstr = TranString(connectstr) ;
        Serial.print("/");                    // print it out the serial monitor
        Serial.print(commandstr);                    // print it out the serial monitor
        Serial.print(")\n");                    // print it out the serial monitor
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
}

String TranString(String ss)
{
    String tmp = "" ;
    int pos = -1 ;
    pos = ss.indexOf("@") ;
    if (pos == -1)
      {
          return "" ;
      }
    return ss.substring(pos+1) ; 
}
