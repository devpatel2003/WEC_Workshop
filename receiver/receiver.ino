#include <WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "Hello";
const char* password = "test1234";
WiFiUDP udp;
const int localUdpPort = 4210;  // Local port to listen on
char incomingPacket[255];  // Buffer for incoming packets
int ledPin = 15;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  udp.begin(localUdpPort);
  Serial.printf("Now listening at IP %s, UDP port %d\n", WiFi.localIP().toString().c_str(), localUdpPort);
}

void loop() {
  int packetSize = udp.parsePacket(); // if data is available it returns size of the packet, if not it returns 0
  if (packetSize) {
    // receive incoming UDP packets
    udp.read(incomingPacket, 255); // incomingPacket is filled with packet data
    int ledState = atoi(incomingPacket);  // Convert packet content to integer (ascii to int)
    digitalWrite(ledPin, ledState);
    Serial.printf("Received %d bytes from %s, port %d\n", packetSize, udp.remoteIP().toString().c_str(), udp.remotePort());
    Serial.printf("LED state: %s\n", ledState ? "ON" : "OFF");
  }
}
