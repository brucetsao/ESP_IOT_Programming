#include "arduino_secrets.h"
#include "hmi.h"
#include <Wire.h>
//-----------------------
#include <WiFi.h>
#include "MQTTlib.h"

char ssid[20] ;
char password[20] ;
//char ssid[] = SECRET_SSID;        // your network SSID (name)
//char pass[] = SECRET_PASS;    // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;            // your network key Index number (needed only for WEP)
          // your network key Index number (needed only for WEP)

  IPAddress ip ;
  long rssi ;
  
int status = WL_IDLE_STATUS;
// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):
String MacData ;
WiFiClient client;

//  control parameter 
// int trycount = 0 ;
int wifierror = 0 ;
//---------------

String CarNumber = "0476166658" ;


void setup() 
{
  //Initialize serial and wait for port to open:
    initAll() ;
if (WiFi.status() != WL_CONNECTED)
    {
      // try one pass for AP1
     // attempt to connect to WiFi network:
        Serial.print("Attempting to connect to SSID: ");
        Serial.println(AP1);
        // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
       // status = WiFi.begin(ssid, pass);
          WiFi.begin(AP1, PW1);
        // wait 10 seconds for connection:
        wifierror = 0 ;
            while (WiFi.status() != WL_CONNECTED) {
            delay(500);
            Serial.print(".");
            wifierror++ ;
            if (wifierror >100)
              break ;
        }
      
    } 

  if (WiFi.status() == WL_CONNECTED)
    {
              Serial.print("Sucessful to connect to SSID: ");
    }
    else
    {
          Serial.println("Fail to Connect to wifi successful ");
    }

  printWiFiStatus();
  MacData = GetMacAddress() ;
  
   mqttclient.begin("broker.shiftr.io", mqclient);
  mqttclient.onMessage(messageReceived);

  connectMQTT();
  Serial.println("System  Ready");
            
  HMIStartScreen() ;
}

void loop()   
{

   mqttclient.loop();
    if (Serial.available() >0)
      {
          cmd = Serial.read() ;
          if (cmd == '0' )
                  HMILoginIn() ;
          if (cmd == '9' )
                  HMILoginOut() ;
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
      }


        HMTString = "" ;
      
    if (Serial2.available() > 0)
    {
        Serial.print("Check HMT \n");
        
        HMTString = ReadHMIString() ;
    }
     if (HMTString != "" )
     {
        Serial.print("HMI String:(");
        Serial.print(HMTString);
        Serial.print(")\n");
        if (HMTString == "BLOOD") 
          bloodwork(CarNumber) ;

        if (HMTString == "PPG") 
          oxygenwork(CarNumber) ;

        if (HMTString == "HEADTEMP") 
          headtemperaturework(CarNumber) ;

        if (HMTString == "BODYTEMP") 
          bodytemperaturework(CarNumber) ;

        if (HMTString == "WEIGHT") 
          bodyweightwork(CarNumber) ;

        if (HMTString == "MENU") 
          HMIStartScreen() ;

    //
          
    }
   if (!mqttclient.connected()) 
  {
     Serial.println("connectMQTT()"); 
     connectMQTT();
  }
    delay(100) ;
} // END Loop




void printWiFiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}

String GetMacAddress() {
  // the MAC address of your WiFi shield
  String Tmp = "" ;
  byte mac[6];
  
  // print your MAC address:
  WiFi.macAddress(mac);
  for (int i=0; i<6; i++)
    {
        Tmp.concat(print2HEX(mac[i])) ;
    }
    Tmp.toUpperCase() ;
  return Tmp ;
}



String  print2HEX(int number) {
  String ttt ;
  if (number >= 0 && number < 16)
  {
    ttt = String("0") + String(number,HEX);
  }
  else
  {
      ttt = String(number,HEX);
  }
  return ttt ;
}



void initAll()
{
    Serial.begin(9600);
     Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
  Serial.println("System Start") ;  
  
  

 // initialize the lcd 

  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue:
  }
 
}





String SPACE(int sp)
{
    String tmp = "" ;
    for (int i = 0 ; i < sp; i++)
      {
          tmp.concat(' ')  ;
      }
    return tmp ;
}


String strzero(long num, int len, int base)
{
  String retstring = String("");
  int ln = 1 ;
    int i = 0 ; 
    char tmp[10] ;
    long tmpnum = num ;
    int tmpchr = 0 ;
    char hexcode[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'} ;
    while (ln <= len)
    {
        tmpchr = (int)(tmpnum % base) ;
        tmp[ln-1] = hexcode[tmpchr] ;
        ln++ ;
         tmpnum = (long)(tmpnum/base) ;
 
        
    }
    for (i = len-1; i >= 0 ; i --)
      {
          retstring.concat(tmp[i]);
      }
    
  return retstring;
}

unsigned long unstrzero(String hexstr, int base)
{
  String chkstring  ;
  int len = hexstr.length() ;
  
    unsigned int i = 0 ;
    unsigned int tmp = 0 ;
    unsigned int tmp1 = 0 ;
    unsigned long tmpnum = 0 ;
    String hexcode = String("0123456789ABCDEF") ;
    for (i = 0 ; i < (len ) ; i++)
    {
  //     chkstring= hexstr.substring(i,i) ; 
      hexstr.toUpperCase() ;
           tmp = hexstr.charAt(i) ;   // give i th char and return this char
           tmp1 = hexcode.indexOf(tmp) ;
      tmpnum = tmpnum + tmp1* POW(base,(len -i -1) )  ;
 
        
    }
  return tmpnum;
}

long POW(long num, int expo)
{
  long tmp =1 ;
  if (expo > 0)
  { 
        for(int i = 0 ; i< expo ; i++)
          tmp = tmp * num ;
         return tmp ; 
  } 
  else
  {
   return tmp ; 
  }
}

 void listNetworks() 
 {
  // scan for nearby networks:
  Serial.println("** Scan Networks **");
    Serial.println("scan start");

    // WiFi.scanNetworks will return the number of networks found
    int n = WiFi.scanNetworks();
    Serial.println("scan done");
    if (n == 0) 
    {
        Serial.println("no networks found");
    } 
    else 
    {
        Serial.print(n);
        Serial.println(" networks found");
        for (int i = 0; i < n; ++i) 
          {
            // Print SSID and RSSI for each network found
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.print(WiFi.SSID(i));
            Serial.print(" (");
            Serial.print(WiFi.RSSI(i));
            Serial.print(")");
            Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
            delay(10);
        }
    }
    Serial.println("");
}




String chrtoString(char *p)
{
    String tmp ;
    char c ;
    int count = 0 ;
    while (count <100)
    {
        c= *p ;
        if (c != 0x00)
          {
            tmp.concat(String(c)) ;
          }
          else
          {
              return tmp ;
          }
       count++ ;
       p++;
       
    }
}


void CopyString2Char(String ss, char *p)
{
         //  sprintf(p,"%s",ss) ;

  if (ss.length() <=0)
      {
           *p =  0x00 ;
          return ;
      }
    ss.toCharArray(p, ss.length()+1) ;
   // *(p+ss.length()+1) = 0x00 ;
}

boolean CharCompare(char *p, char *q)
  {
      boolean flag = false ;
      int count = 0 ;
      int nomatch = 0 ;
      while (flag <100)
      {
          if (*(p+count) == 0x00 or *(q+count) == 0x00)
            break ;
          if (*(p+count) != *(q+count) )
              {
                 nomatch ++ ; 
              }
             count++ ; 
      }
     if (nomatch >0)
      {
        return false ;
      }
      else
      {
        return true ;
      }
      
        
  }
