#include <WiFi.h>
#include <WiFiClient.h>
#include <String.h>
#define relaypin 4
const char* ssid     = "aaaa";
const char* password = "12345678";
const char* serverIP  = "115.29.109.104";
int serverPort = 6529;


WiFiClient client;
bool bConnected = false;
char buff[512];
int nm = 0;



void setup() {
  delay(100);
    Serial.begin(9600);
    Serial.println("Startup");
  pinMode(relaypin, OUTPUT);
  digitalWrite(relaypin,LOW) ;
  WiFi.mode(WIFI_STA);//STA
    WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {//等待WiFi连接成功
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

}


void loop() {


   ClientToServer();


}

void ClientToServer()
{

  if (bConnected == false)//如果从服务器断开或者连接失败，则重新连接
  {
    if (!client.connect(serverIP, serverPort))//如果连接失败
    {
      Serial.println("connection failed");
      delay(5000);
      return;
    }
    bConnected = true;
    Serial.println("connection ok");
  }
  else if (client.available())//如果有数据到达
  {
    //Serial.println("Data is coming");
    while (client.available())//接收数据
    {
      buff[nm++] = client.read();
      if (nm >= 511) break;
    }
    buff[nm] = 0x00;
    nm=0;
    Serial.print(buff);//打印数据到串口
    if( buff[0]=='O')
    {
      digitalWrite(relaypin,HIGH);//打开

    }
    else 
    {
      digitalWrite(relaypin,LOW);//关闭
    }
    //client.print(buff);
    client.flush();//丢弃已写入客户端但尚未读取的字节
  }
   if (client.connected()==false ) {
    Serial.println();
    Serial.println("disconnecting.");

     bConnected = false;
  }
    //检查UART端口数据
  if(Serial.available()&&bConnected){
    size_t len = Serial.available();
    //Serial.println(len);
    uint8_t sbuf[len];
    Serial.readBytes(sbuf, len);
    //将UART端口数据推送到服务器，实现双向通信
    client.write(sbuf, len);
  }
}
