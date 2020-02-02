/*************************************************************
 *          WEB SERVER TO CONTROL 2 LEDs
 *          ============================
 *                  
 * This is a simple web server program. 2 LEDs are connected to 
 * GPIO ports 23 and 22 of the ESP32 devkitc board. The project
 * controls these LEDs (turns ON or OFF) from a web server
 * application. For example, teh LEDs can be controlled from any
 * device that is on the web, for example, a PC, tablet, mobile
 * phone etc. when activated, a form will appear on the device
 * with buttons and clicking these buttons will control the
 * LEDs. The LEDs are named LED0 and LED1, connected to GPIO
 * ports 23 and 22 respectively.
 *  
 *  
 *  File:   WEBSERVER
 *  Author: Dogan Ibrahim
 *  Date:   August, 2017
 * 
 **************************************************************/
#include <WiFi.h>
#define LED0 23
#define LED1 22

//
// Local Wi-Fi name and password
//
const char* ssid = "NCNU";
const char* password = "12345678";
WiFiServer server(80);

//
// The HTML code. This code will display two buttons on user's
// device which can be clicked to control the LEDs
//
String html ="<!DOCTYPE html> \
<html> \
<body> \
<center><h1>ESP32 Devkitc LED ON/OFF</h1></center> \
<center><h2>Web Server Example with 2 LEDs</h2></center> \
<form> \
<button name=\"LED0\" button style=\"color:green\" value=\"ON\" type=\"submit\">LED0 ON</button> \
<button name=\"LED0\" button style=\"color=red\" value=\"OFF\" type=\"submit\">LED0 OFF</button><br><br> \
<button name=\"LED1\" button style=\"color:green\" value=\"ON\" type=\"submit\">LED1 ON</button> \
<button name=\"LED1\" button style=\"color:red\" value=\"OFF\" type=\"submit\">LED1 OFF</button> \
</form> \
</body> \
</html>";

//
// This function connects the ESP32 Devkitc to the local Wi-Fi
// network. The network name and passwors are as specifed earlier
void Connect_WiFi()
{
      WiFi.begin(ssid, password);
      while(WiFi.status() != WL_CONNECTED)
      {
        delay(1000);
      }
}


//
// Configure LEDs as outputs, turn OFF the LEDs to start with,
// Connect to the local Wi-Fi, start the server
//
void setup()
{   
    Serial.begin(9600) ;
    Serial.println("WEBSERVER Start") ;
    pinMode(LED0, OUTPUT);
    pinMode(LED1, OUTPUT);
    digitalWrite(LED0, LOW);
    digitalWrite(LED1, LOW);
    Connect_WiFi();
    server.begin();
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

//
// This is teh main program loop. Inside the main program we
// check for the client connection and send the HTML file so
// that it is displayed on user's device. The user clicks the
// buttons to control the LEDs.
//
void loop()
{
      Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    WiFiClient client=server.available();
    String request = client.readStringUntil('\r');
    client.flush();
//
// We control the LEDs depending upon the key click. Variable
// request holds the request and we search this string to see
// which LED should be turned ON/OFF. The contents of request
// is of the form (for example, to turn OFF LED0): 
// "/?LED0=OFF", or similarly, to turn LED 1: "/?LED1=ON"
//    
    if(request.indexOf("LED0=ON") != -1)digitalWrite(LED0, HIGH);
    if(request.indexOf("LED0=OFF") != -1)digitalWrite(LED0, LOW);
    if(request.indexOf("LED1=ON") != -1)digitalWrite(LED1, HIGH);
    if(request.indexOf("LED1=OFF") != -1)digitalWrite(LED1, LOW);
//
// The HTML page to be displayed on user's device
//
    client.print(html);
}
