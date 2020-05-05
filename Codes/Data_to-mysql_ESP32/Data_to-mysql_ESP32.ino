#include <WiFi.h>
const char* ssid     = "NCNU";
const char* pass = "12345678";
#include <String.h>

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3f,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display


/**************************************************************/
/* Example how to read DHT sensors from an ESP32 using multi- */
/* tasking.                                                   */
/* This example depends on the ESP32Ticker library to wake up */
/* the task every 20 seconds                                  */
/* Please install Ticker-esp32 library first                  */
/* bertmelis/Ticker-esp32                                     */
/* https://github.com/bertmelis/Ticker-esp32                  */
/**************************************************************/
///////please enter your sensitive data in the Secret tab/arduino_secrets.h
int keyIndex = 0;            // your network key Index number (needed only for WEP)

  IPAddress ip ;
  long rssi ;
  
int status = WL_IDLE_STATUS;
char iotserver[] = "192.168.99.200";    // name address for Google (using DNS)
int iotport = 80 ;
// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):
String strGet="GET /iot/dhtdata/dhtadd.php";
String strHttp=" HTTP/1.1";
String strHost="Host: 192.168.99.200";  //OK
 String connectstr ;
String MacData ;
WiFiClient client;
double hhh,ttt ;  // declare vcariable for  sensor data 




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
  Serial.println("System Start") ;  
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);

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

void ShowLCDR1(String gg)
{
  lcd.setCursor(0,0);
  lcd.print("                    ");  
  lcd.setCursor(0,0);
  lcd.print(gg);  
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



void Show1(String ss)
{
  lcd.setCursor(0,2);
  lcd.print("                    ");  
  lcd.setCursor(0,2);
  lcd.print(ss);  
}

void Show2(String ss)
{
  lcd.setCursor(0,3);
  lcd.print("                    ");  
  lcd.setCursor(0,3);
  lcd.print(ss);  
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

void SendtoNAS()
{
        //http://iot.nhri.org.tw/headtemp/headtempadd.php?mac=aabbccddeeff&usrid=0123456789&temperature=33.65
        //INSERT INTO headtemptbl (mac, userid,datatime,dateorder,headtemp) VALUES ('aabbccddeeff','0123456789','2019/08/14 21:37:48','20190814213748',33.65)
            
       connectstr = "?MAC="+MacData+"&T="+String(ttt)+"&H="+String(hhh);
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
  lcd.print("Temp:");    
  lcd.print(ttt);    
  lcd.setCursor(0,3);
  lcd.print("                    ");  
  lcd.setCursor(0,3);
  lcd.print("Humid:");    
  lcd.print(hhh);    
  lcd.setCursor(0,2);

  Serial.print("Temperature:");    
  Serial.println(ttt);    
   Serial.print("Humidity:");    
  Serial.println(hhh);   
}
//--------------------
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

}

void loop() 
{

      ShowData() ;  // please get sxensor data here
    SendtoNAS() ;   // send sensor data to mysql
    
 
  delay(30000) ;
}
