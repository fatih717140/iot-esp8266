#include <ESP8266WiFi.h>
#include<ESP8266WebServer.h>
const int ledPin=5;
const char* ssid = "TurkTelekom_TP6D7C_2.4GHz";
const char* password = "Tg3wdphbMrM9";

ESP8266WebServer server(80);
void setup(){
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,password);
  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("Wifi connected");
  Serial.println("ESP 8266 IP adress");
  Serial.println(WiFi.localIP());


  server.on("/led/on",HTTP_GET,[](){
  server.sendHeader("Access-Control-Allow-Origin", "*");
Serial.println("LED ONN request received");
    digitalWrite(ledPin, HIGH);
    server.send(200, "application/json", "{\"status\":\"LED ON\"}");
    
   });
   
  server.on("/led/off", HTTP_GET, []() {
    server.sendHeader("Access-Control-Allow-Origin", "*");

    Serial.println("LED OFF request received");
    digitalWrite(ledPin, LOW);
    server.send(200, "application/json", "{\"status\":\"LED OFF\"}");
  });
  server.begin();
}

void loop(){

  server.handleClient();
}
