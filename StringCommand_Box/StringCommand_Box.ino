 
#include <String.h>
#include <WiFi.h>
#define relaypin 4
const char* ssid     = "NCNU";
const char* password = "12345678";
String connectstr ="" ;
String commandstr ="" ;
WiFiServer server(80);
int status = WL_IDLE_STATUS;
char iotserver[] = "192.168.99.200";    // name address for Google (using DNS)
int iotport = 80 ;
// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):
String strGet="GET /iot02/work/dataadd.php";
String strHttp=" HTTP/1.1";
String strHost="Host: 192.168.99.200";  //OK

String MacData ;
WiFiClient wwwclient;


void setup()
{
    Serial.begin(9600);
    pinMode(relaypin, OUTPUT);      // set the LED pin mode
    digitalWrite(relaypin,LOW) ;

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
        Serial.print(")\n");  
        // print it out the serial monitor
        if (commandstr =="ON")
            {
                    digitalWrite(relaypin,HIGH) ;
                    SendtoNAS(1) ;
            }
        if (commandstr == "OFF")
            {
                    digitalWrite(relaypin,LOW) ;
                    SendtoNAS(0) ;
            }            
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

void SendtoNAS(int ttt)
{
        //http://iot.nhri.org.tw/headtemp/headtempadd.php?mac=aabbccddeeff&usrid=0123456789&temperature=33.65
        //INSERT INTO headtemptbl (mac, userid,datatime,dateorder,headtemp) VALUES ('aabbccddeeff','0123456789','2019/08/14 21:37:48','20190814213748',33.65)
            
       connectstr = "?MAC="+MacData+"&open="+String(ttt);
         Serial.println(connectstr) ;
         if (wwwclient.connect(iotserver, iotport)) {
                 Serial.println("Make a HTTP request ... ");
                 //### Send to Server
                 String strHttpGet = strGet + connectstr + strHttp;
                 Serial.println(strHttpGet);
     
                 wwwclient.println(strHttpGet);
                 wwwclient.println(strHost);
                 wwwclient.println();
               } 
    
      if (wwwclient.connected()) 
      { 
        wwwclient.stop();  // DISCONNECT FROM THE SERVER
      }

    
}
