#include <ESP8266WiFi.h>

#include <WiFiClient.h>

using namespace std;

const char *ssid = "release";
const char *password = "thisisrelease";

WiFiServer server(80);

void setup() {
  Serial.begin(9600);
  while (!Serial) continue;

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if(!client){
    return;
  }

  String req = client.readStringUntil('\r');
  client.flush();
  if (req.indexOf("/enter") > 0) {
    Serial.print("\n");
  }else if (req.indexOf("/q") > 0) {
    Serial.print('q');
  }else if (req.indexOf("/w") > 0) {
    Serial.print('w');
  }else if (req.indexOf("/e") > 0) {
    Serial.print('e');
  }else if (req.indexOf("/a") > 0) {
    Serial.print('a');
  }else if (req.indexOf("/s") > 0) {
    Serial.print('s');
  }else if (req.indexOf("/d") > 0) {
    Serial.print('d');
  }else if (req.indexOf("/r") > 0) {
    Serial.print('r');
  }else if (req.indexOf("/t") > 0) {
    Serial.print('t');
  }else if (req.indexOf("/y") > 0) {
    Serial.print('y');
  }else if (req.indexOf("/f") > 0 && !(req.indexOf("/favicon") > 0)) {
    Serial.print('f');
  }else if (req.indexOf("/g") > 0) {
    Serial.print('g');
  }else if (req.indexOf("/h") > 0) {
    Serial.print('h');
  }else if (req.indexOf("/u") > 0) {
    Serial.print('u');
  }else if (req.indexOf("/i") > 0) {
    Serial.print('i');
  }else if (req.indexOf("/o") > 0) {
    Serial.print('o');
  }else if (req.indexOf("/j") > 0) {
    Serial.print('j');
  }else if (req.indexOf("/k") > 0) {
    Serial.print('k');
  }else if (req.indexOf("/l") > 0) {
    Serial.print('l');
  }else if (req.indexOf("/m0") > 0) {
    Serial.print('m');
    Serial.print('0');
  }else if (req.indexOf("/m1") > 0) {
    Serial.print('m');
    Serial.print('1');
  }else if (req.indexOf("/m2") > 0) {
    Serial.print('m');
    Serial.print('2');
  }
  client.println("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n"+req);
}