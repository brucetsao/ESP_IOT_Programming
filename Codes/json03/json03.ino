
#include "arduino_secrets.h"
#include <ArduinoJson.h>
//-----------------------
#include <WiFi.h>

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



//------
char* root_0_unit ; // "單位"
char* root_0_telephon ; // "電 話"
char* root_0_fax ; // "傳 真"
char* root_0_address ; // "地 址"
char* root_0_website ; // "網址"
char* root_0_TgosTWD_X ; // "TgosTWD_X"
char* root_0_TgosTWD_Y ; // "TgosTWD_Y"

//--------------

void setup() 
{
  //Initialize serial and wait for port to open:
  //  initAll() ;
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
  
  Serial.println("System  Ready");
            
  if (!client.connect("https://od.moi.gov.tw/od/data/api/EA28418E-8956-4790-BAF4-C2D3988266CC?$format=json", 80)) {
    Serial.println(F("Connection failed"));
    return;
  }

  Serial.println(F("Connected!"));

  // Send HTTP request
  client.println(F("GET /od/data/api/EA28418E-8956-4790-BAF4-C2D3988266CC?$format=json"));
  client.println(F("Host: od.moi.gov.tw"));
  client.println(F("Connection: close"));
  if (client.println() == 0) {
    Serial.println(F("Failed to send request"));
    return;
  }

  // Check HTTP status
  char status[32] = {0};
  client.readBytesUntil('\r', status, sizeof(status));
  // It should be "HTTP/1.0 200 OK" or "HTTP/1.1 200 OK"
  if (strcmp(status + 9, "200 OK") != 0) {
    Serial.print(F("Unexpected response: "));
    Serial.println(status);
    return;
  }

  // Skip HTTP headers
  char endOfHeaders[] = "\r\n\r\n";
  if (!client.find(endOfHeaders)) {
    Serial.println(F("Invalid response"));
    return;
  }


const size_t capacity = JSON_ARRAY_SIZE(23) + 23*JSON_OBJECT_SIZE(7) + 4460;
DynamicJsonDocument doc(capacity);
  // Parse JSON object
  const char* json = "[{\"unit\":\"單位\",\"telephon\":\"電 話\",\"fax\":\"傳 真\",\"address\":\"地 址\",\"website\":\"網址\",\"TgosTWD_X\":\"TgosTWD_X\",\"TgosTWD_Y\":\"TgosTWD_Y\"},{\"unit\":\"新北市政府民政局\",\"telephon\":\"02-29603456\",\"fax\":\"02-29693894\",\"address\":\"新北市板橋區中山路1段161號11樓\",\"website\":\"http://www.ca.ntpc.gov.tw/\",\"TgosTWD_X\":\"296995.84\",\"TgosTWD_Y\":\"2767196.5\"},{\"unit\":\"臺北市政府兵役局\",\"telephon\":\"02-23654361；02-23654362；02-23654363；02-23654364\",\"fax\":\"02-23673072\",\"address\":\"臺北市中正區羅斯福路四段92號9樓\",\"website\":\"http://www.tcdms.taipei.gov.tw/\",\"TgosTWD_X\":\"303996.47\",\"TgosTWD_Y\":\"2767406.2\"},{\"unit\":\"臺中市政府民政局\",\"telephon\":\"04-22289111\",\"fax\":\"04-22202480\",\"address\":\"臺中市臺中港路2段89號6樓\",\"website\":\"http://www.civil.taichung.gov.tw/\",\"TgosTWD_X\":\"214160.3\",\"TgosTWD_Y\":\"2673009.2\"},{\"unit\":\"臺南市政府民政局\",\"telephon\":\"06-2991111\",\"fax\":\"06-2982560\",\"address\":\"臺南市安平區永華路2段6號\",\"website\":\"http://www.tainan.gov.tw/agr/default.asp\",\"TgosTWD_X\":\"166419.75\",\"TgosTWD_Y\":\"2543371.8\"},{\"unit\":\"高雄市政府兵役局\",\"telephon\":\"07-3373582\",\"fax\":\"07-3312241\",\"address\":\"高雄市苓雅區四維3路2號4樓\",\"website\":\"http://mildp.kcg.gov.tw/index.php\",\"TgosTWD_X\":\"178329.53\",\"TgosTWD_Y\":\"2502050.8\"},{\"unit\":\"宜蘭縣政府民政處\",\"telephon\":\"03-9251000#1680；03-9251000#1690\",\"fax\":\"03-9332434\",\"address\":\"宜蘭縣宜蘭市縣政北路1號3樓\",\"website\":\"http://civil.e-land.gov.tw/releaseRedirect.do?unitID=102&pageID=9297\",\"TgosTWD_X\":\"327162.16\",\"TgosTWD_Y\":\"2736149.2\"},{\"unit\":\"桃園縣政府民政局\",\"telephon\":\"03-3322101\",\"fax\":\"03-3364817\",\"address\":\"桃園縣桃園市縣府路1號\",\"website\":\"http://cab.tycg.gov.tw/site/ex_bureau_index.aspx?site_id=029\",\"TgosTWD_X\":\"280383.2\",\"TgosTWD_Y\":\"2765042.2\"},{\"unit\":\"新竹縣政府民政處\",\"telephon\":\"03-5518101#268\",\"fax\":\"03-5513672\",\"address\":\"新竹縣竹北市光明六路10號\",\"website\":\"http://web.hsinchu.gov.tw/civil/\",\"TgosTWD_X\":\"251305.73\",\"TgosTWD_Y\":\"2746600.8\"},{\"unit\":\"苗栗縣政府民政處\",\"telephon\":\"037-322150\",\"fax\":\"037-354593\",\"address\":\"苗栗縣苗栗市縣府路100號\",\"website\":\"http://www.miaoli.gov.tw/civil_affairs/index.php\",\"TgosTWD_X\":\"231846.64\",\"TgosTWD_Y\":\"2717592.8\"},{\"unit\":\"彰化縣政府民政處\",\"telephon\":\"04-7222151#0122\",\"fax\":\"04-7293510\",\"address\":\"彰化縣彰化市中山路二段416號7樓\",\"website\":\"http://www.chcg.gov.tw/civil/00home/index1.asp\",\"TgosTWD_X\":\"203707.83\",\"TgosTWD_Y\":\"2663465.2\"},{\"unit\":\"南投縣政府民政處\",\"telephon\":\"049-2222106；049-2222107；049-2222108；049-2222109\",\"fax\":\"049-2238404\",\"address\":\"南投縣南投市中興路660號\",\"website\":\"http://www.nantou.gov.tw/big5/index.asp?dptid=376480000AU100000\",\"TgosTWD_X\":\"218455\",\"TgosTWD_Y\":\"2644256\"},{\"unit\":\"雲林縣政府民政處\",\"telephon\":\"05-5322154\",\"fax\":\"05-5352041\",\"address\":\"雲林縣斗六市雲林路二段515號\",\"website\":\"http://www4.yunlin.gov.tw/civil/\",\"TgosTWD_X\":\"201694.66\",\"TgosTWD_Y\":\"2621765\"},{\"unit\":\"嘉義縣政府民政處\",\"telephon\":\"05-3620123#460；05-3620123#461\",\"fax\":\"05-3620399\",\"address\":\"嘉義縣太保市祥和新村祥和一路東段1號\",\"website\":\"http://www1.cyhg.gov.tw/civil/chinese/\",\"TgosTWD_X\":\"\",\"TgosTWD_Y\":\"\"},{\"unit\":\"屏東縣政府民政處\",\"telephon\":\"08-7324147\",\"fax\":\"08-7331538\",\"address\":\"屏東縣屏東市自由路527號\",\"website\":\"http://www.pthg.gov.tw/plancab/Index.aspx\",\"TgosTWD_X\":\"197386.9\",\"TgosTWD_Y\":\"2509263\"},{\"unit\":\"臺東縣政府民政處\",\"telephon\":\"089-326141\",\"fax\":\"089-340560\",\"address\":\"台東縣台東市中山路276號\",\"website\":\"http://www.taitung.gov.tw/Civil/index.aspx\",\"TgosTWD_X\":\"265435.62\",\"TgosTWD_Y\":\"2517223.5\"},{\"unit\":\"花蓮縣政府民政處\",\"telephon\":\"03-8232047；03-8221894#374；03-8221894#375\",\"fax\":\"03-8230576\",\"address\":\"花蓮縣花蓮市府後路6號\",\"website\":\"http://ca.hl.gov.tw/bin/home.php\",\"TgosTWD_X\":\"312974.72\",\"TgosTWD_Y\":\"2654109\"},{\"unit\":\"澎湖縣政府民政處\",\"telephon\":\"06-9274400\",\"fax\":\"06-9274701\",\"address\":\"澎湖縣馬公市治平路32號\",\"website\":\"http://www.penghu.gov.tw/civil/\",\"TgosTWD_X\":\"103661.375\",\"TgosTWD_Y\":\"2608175\"},{\"unit\":\"基隆市政府民政處\",\"telephon\":\"02-24201122#2304；02-24201122#2305；02-24201122#2306；02-24201122#2307；02-24201122#2308；02-24201122#2309；02-24201122#2310；02-24201122#2311\",\"fax\":\"02-24668739\",\"address\":\"基隆市中正區正信路205號2樓\",\"website\":\"http://www.klcg.gov.tw/civil/\",\"TgosTWD_X\":\"326702.88\",\"TgosTWD_Y\":\"2781832.5\"},{\"unit\":\"新竹市政府民政處\",\"telephon\":\"03-5216121#314；03-5216121#315；03-5216121#316；03-5216121#317；03-5216121#318；03-5216121#319\",\"fax\":\"03-5214703\",\"address\":\"新竹市中正路120號\",\"website\":\"http://dep-civil.hccg.gov.tw/web/Home?FP=1064\",\"TgosTWD_X\":\"246852.16\",\"TgosTWD_Y\":\"2744373.2\"},{\"unit\":\"嘉義市政府民政處\",\"telephon\":\"05-2254321\",\"fax\":\"05-2259885\",\"address\":\"嘉義市中山路199號\",\"website\":\"http://www.chiayi.gov.tw/web/civil/index.asp\",\"TgosTWD_X\":\"194178.02\",\"TgosTWD_Y\":\"2597686.8\"},{\"unit\":\"金門縣政府民政局\",\"telephon\":\"082-325753\",\"fax\":\"082-322613\",\"address\":\"金門縣金城鎮民生路60號\",\"website\":\"http://www.kinmen.gov.tw/Layout/sub_A/index.aspx?frame=3\",\"TgosTWD_X\":\"-21896.012\",\"TgosTWD_Y\":\"2706070\"},{\"unit\":\"連江縣政府民政局\",\"telephon\":\"0836-22485\",\"fax\":\"0836-22209\",\"address\":\"連江縣南竿鄉介壽村76號\",\"website\":\"http://www.matsu.gov.tw/2008web/governor_index.php?id=civilaffairbureau\",\"TgosTWD_X\":\"145745.47\",\"TgosTWD_Y\":\"2894431\"}]";

  DeserializationError error = deserializeJson(doc, client);
  deserializeJson(doc, json);
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.c_str());
    return;
  }

  for(int i=0; i <23;i++)
  {
      JsonObject root_0 = doc[i];
     root_0_unit = root_0["unit"]; // "單位"
     root_0_telephon = root_0["telephon"]; // "電 話"
     root_0_fax = root_0["fax"]; // "傳 真"
     root_0_address = root_0["address"]; // "地 址"
     root_0_website = root_0["website"]; // "網址"
     root_0_TgosTWD_X = root_0["TgosTWD_X"]; // "TgosTWD_X"
     root_0_TgosTWD_Y = root_0["TgosTWD_Y"]; // "TgosTWD_Y"
    Serial.println(root_0_unit);
    Serial.println(root_0_telephon);
    Serial.println(root_0_fax);
    Serial.println(root_0_address);
    Serial.println(root_0_website);
    Serial.println(root_0_TgosTWD_X);
    Serial.println(root_0_TgosTWD_Y);
    Serial.println(root_0_unit);
    
  }
  // Extract values

  // Disconnect
  client.stop();
}
 

void loop()   
{

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
