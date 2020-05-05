#include <WiFi.h>
#include "PMS.h"
PMS pms(Serial2);
PMS::DATA data;

#include <String.h>
#include <Wire.h> 

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3f,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
                          //please enter your sensitive data in the Secret tab/arduino_secrets.h
 const char* ssid     = "NCNU";
const char* pass = "12345678";                           
int keyIndex = 0;            // your network key Index number (needed only for WEP)
  IPAddress ip ;
  long rssi ;  
int status = WL_IDLE_STATUS;
char iotserver[] = "192.168.99.200";    // name address for Google (using DNS)
int iotport = 80 ;
                           // Initialize the Ethernet client library
                          // with the IP address and port of the server
                          // that you want to connect to (port 80 is default for HTTP):
String strGet="GET /iot01/work/dataadd.php";
String strHttp=" HTTP/1.1";
String strHost="Host: 192.168.99.200";  //OK
 String connectstr ;
String MacData ;
WiFiClient client;


double a,b,c;

    // declare vcariable for  sensor data 
void printWiFiStatus() 
{
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
   String a ;
  if (number >= 0 && number < 16)
  {
    a = String("0") + String(number,HEX);
  }
  else
  {
      a= String(number,HEX);
  }
  return a ;
}

void initAll()
{
    Serial.begin(9600);
  Serial.println("System Start") ;  


  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  
  pms.passiveMode();    // Switch to passive mode
 // Serial.println("Waking up, wait 30 seconds for stable readings...");
  pms.wakeUp();
  delay(3000);
  


               // initialize the lcd 
              // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
               // don't continue:
  }
}
void ShowInternet()
{
    Serial.print("MAC:") ;
    Serial.print(MacData) ;
    Serial.print("\n") ;
    ShowMAC() ;
    ShowIP()  ;
}

void ShowLCDR1(String a)
{
  lcd.setCursor(0,0);
  lcd.print("                    ");  
  lcd.setCursor(0,0);
  lcd.print(a);  
}
void ShowMAC()
{
  lcd.setCursor(0,0);
  lcd.print("MAC:");  
  lcd.print(MacData);  

}
void ShowIP()
{
  lcd.setCursor(0,1);
  lcd.print("IP:");  
  lcd.print(ip);  

}

void Show1(String a)
{
  lcd.setCursor(0,2);
  lcd.print("                    ");  
  lcd.setCursor(0,2);
  lcd.print(a);  
}

void Show2(String b)
{
  lcd.setCursor(0,2);
  lcd.print("                    ");  
  lcd.setCursor(0,2);
  lcd.print(b);  
}

void Show3(String c)
{
  lcd.setCursor(0,2);
  lcd.print("                    ");  
  lcd.setCursor(0,2);
  lcd.print(c);  
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
                                       // chkstring= hexstr.substring(i,i) ; 
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
void SendtoNAS()
{
        //http://iot.nhri.org.tw/headtemp/headtempadd.php?mac=aabbccddeeff&usrid=0123456789&temperature=33.65
        //INSERT INTO headtemptbl (mac, userid,datatime,dateorder,headtemp) VALUES ('aabbccddeeff','0123456789','2019/08/14 21:37:48','20190814213748',33.65)
            
       connectstr = "?MAC="+MacData+"&P="+String(a)+"&Q="+String(b)+"&R="+String(c);
         Serial.println(connectstr) ;
         if (client.connect(iotserver, iotport)) {
                 Serial.println("Make a HTTP request ... ");
                 //### Send to Server
                 String strHttpGet = strGet + connectstr + strHttp;
                 Serial.println(strHttpGet);
                 client.println(strHttpGet);
                 client.println(strHost);
                 client.println();
               } 
      if (client.connected()) 
      { 
        client.stop();  // DISCONNECT FROM THE SERVER
      } 
}

void ShowData()
{

  lcd.setCursor(0,2);
  lcd.print("                    ");  
  lcd.setCursor(0,2);
  lcd.print("PM:");    
  lcd.print(a);    
  lcd.print("/");    
  lcd.print(b);    
  lcd.print("/");    
  lcd.print(c);    
   
  Serial.print("PM 1.0 (ug/m3): ");    
  Serial.println(a);    
  Serial.print("PM 2.5 (ug/m3): ");    
  Serial.println(b);   
  Serial.print("PM 10.0 (ug/m3): ");    
  Serial.println(c);   

}


void setup()
{
                       //Initialize serial and wait for port to open:
    initAll() ;
     WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
  Serial.println("Connected to wifi");
  printWiFiStatus();
  MacData = GetMacAddress() ;
  ShowInternet() ;
  Show2("init System,Pls Wait") ;
  

  Serial2.begin(9600);  // GPIO2 (D4 pin on ESP-12E Development Board)
  pms.passiveMode();    // Switch to passive mode
                      // Serial.println("Waking up, wait 3 seconds for stable readings...");
  pms.wakeUp();
  delay(3000);

  
}
void loop() 
{
 // Serial.println("Send read request...");
  pms.requestRead();
 // Serial.println("Wait max. 1 second for read...");
  if (pms.readUntil(data))
  {
    a = data.PM_AE_UG_1_0 ;
    b = data.PM_AE_UG_2_5 ;
    c = data.PM_AE_UG_10_0;
    Serial.print("PM 1.0 (ug/m3): ");
    Serial.println(a);
    Serial.print("PM 2.5 (ug/m3): ");
    Serial.println(b);
    Serial.print("PM 10.0 (ug/m3): ");
    Serial.println(c);
    ShowData() ;  // please get sxensor data here
    SendtoNAS() ;   // send sensor data to mysql
  }
  else
  {
    Serial.println("No data.");
  }
  Serial.println("Going to sleep for 60 seconds.");
  pms.sleep();
  delay(10000);


}
