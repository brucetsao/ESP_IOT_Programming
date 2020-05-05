#include <WiFi.h>

const char* ssid     = "FAMILIA ANGARITA";
const char* password = "T63530193";

IPAddress local_IP(192, 168, 0, 115);
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0);

void setup() {
  Serial.begin(115200);
  if (!WiFi.config(local_IP, gateway, subnet)) {
    Serial.println("Error al configurar");
  }
  Serial.print("Conectandose a: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado!");
  Serial.print("IP asignada: ");
  Serial.println(WiFi.localIP());
  Serial.print("MAC: ");
  Serial.println(WiFi.macAddress());
  Serial.print("Mascara de subred: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("IP de la puerta de enlace: ");
  Serial.println(WiFi.gatewayIP());
  Serial.print("DNS: ");
  Serial.println(WiFi.dnsIP());

}

void loop() {

}
