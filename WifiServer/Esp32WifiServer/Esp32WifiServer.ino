#include <WiFi.h>

const char* ssid="esp32_dominator";
const char* password="afterlife";

IPAddress ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnetmask(255,255,255,0);

WiFiServer server(80);
WiFiClient client;

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid,password);
  
  WiFi.softAPConfig(ip,gateway,subnetmask);
  delay(100);

  server.begin();  
}

void loop() {
  client = server.available();
  if (!client){
    return;
  }

  while (client.connected()){
    if (client.available()){
      Serial.println(client.readStringUntil('\n'));
    }
  }
  delay(1);
  client.stop();
  
}
