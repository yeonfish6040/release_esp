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
  if (req.indexOf("/enter")) {
    Serial.print("\n");
  }else if (req.indexOf("/q")) {
    Serial.print('q');
  }else if (req.indexOf("/w")) {
    Serial.print('w');
  }else if (req.indexOf("/e")) {
    Serial.print('e');
  }else if (req.indexOf("/a")) {
    Serial.print('a');
  }else if (req.indexOf("/s")) {
    Serial.print('s');
  }else if (req.indexOf("/d")) {
    Serial.print('d');
  }else if (req.indexOf("/r")) {
    Serial.print('r');
  }else if (req.indexOf("/t")) {
    Serial.print('t');
  }else if (req.indexOf("/y")) {
    Serial.print('y');
  }else if (req.indexOf("/f")) {
    Serial.print('f');
  }else if (req.indexOf("/g")) {
    Serial.print('g');
  }else if (req.indexOf("/h")) {
    Serial.print('h');
  }else if (req.indexOf("/u")) {
    Serial.print('u');
  }else if (req.indexOf("/i")) {
    Serial.print('i');
  }else if (req.indexOf("/o")) {
    Serial.print('o');
  }else if (req.indexOf("/j")) {
    Serial.print('j');
  }else if (req.indexOf("/k")) {
    Serial.print('k');
  }else if (req.indexOf("/l")) {
    Serial.print('l');
  }else if (req.indexOf("/0")) {
    Serial.print('0');
  }else if (req.indexOf("/1")) {
    Serial.print('1');
  }else if (req.indexOf("/2")) {
    Serial.print('2');
  }else if (req.indexOf("/m")) {
    Serial.print('m');
  }
  client.println("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\nsuccess\r\n<html>\r\n");
}