#include <WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "Hello";
const char* password = "test1234";
WiFiUDP udp;
const char* remoteIp = "172.20.10.14"; // IP address of ESP2 recieving 
const int remotePort = 4210;
int switchPin = 14;

void setup() {
  Serial.begin(115200);
  pinMode(switchPin, INPUT_PULLUP);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
}

void loop() {
  int switchState = digitalRead(switchPin); // Inverted because of INPUT_PULLUP
  char packetBuffer[2]; // packet to store data to send
  sprintf(packetBuffer, "%d", switchState); //assign integer value of switch state to packet
  udp.beginPacket(remoteIp, remotePort); // connect to ip and port of the other esp
  udp.write((uint8_t*)packetBuffer, sizeof(packetBuffer)); // send packet
  udp.endPacket();
  delay(100); // Debounce delay
}

