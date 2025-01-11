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
  }else {
    client.println("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE html>\n<html lang=\"ko\">\n<head>\n  <meta charset=\"UTF-8\">\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n  <title>RELEASE CONTROL PANEL</title>\n  <style>\n    body {\n      font-size: clamp(0.5rem, 1.5vh, 2rem);\n    }\n    .container {\n      position: absolute;\n      top: 0;\n      left: 0;\n      right: 0;\n      bottom: 0;\n    }\n\n    .menu {\n      max-width: 500px;\n      width: 100%;\n\n      > * {\n        text-align: center;\n        width: 100%;\n      }\n    }\n    .linear_menu {\n      display: flex;\n      flex-direction: column;\n      align-items: center;\n      gap: 50px;\n      height: 100%;\n    }\n    .radial_menu {\n      display: flex;\n      justify-content: space-evenly;\n      align-items: center;\n      height: 100%;\n    }\n\n    h2, h3 {\n      display: inline;\n    }\n    button {\n      background-color: azure;\n      border: 1px solid lightgray;\n      border-radius: 6px;\n      height: 50px;\n      width: 90px;\n    }\n  </style>\n</head>\n<body>\n  <div class=\"container\">\n    <br>\n    <div class=\"menu linear_menu\">\n      <div class=\"mode\">\n        <h2>MODE</h2>\n        <div class=\"radial_menu\">\n          <button onclick=\"fetch(\'/m0\')\">Bulb</button>\n          <button onclick=\"fetch(\'/m1\')\">Interval</button>\n          <button onclick=\"fetch(\'/m2\')\">Both</button>\n        </div>\n      </div>\n      <div class=\"control\">\n        <h2>CONTROL</h2>\n        <div class=\"radial_menu\">\n          <div class=\"linear_menu\">\n            <h3>Bulb</h3>\n            <button onclick=\"fetch(\'/u\')\">+100</button>\n            <button onclick=\"fetch(\'/r\')\">+10</button>\n            <button onclick=\"fetch(\'/q\')\">+1</button>\n            <button onclick=\"fetch(\'/a\')\">-1</button>\n            <button onclick=\"fetch(\'/f\')\">-10</button>\n            <button onclick=\"fetch(\'/j\')\">-100</button>\n        </div>\n          <div class=\"linear_menu\">\n            <h3>Interval</h3>\n            <button onclick=\"fetch(\'/i\')\">+100</button>\n            <button onclick=\"fetch(\'/t\')\">+10</button>\n            <button onclick=\"fetch(\'/w\')\">+1</button>\n            <button onclick=\"fetch(\'/s\')\">-1</button>\n            <button onclick=\"fetch(\'/g\')\">-10</button>\n            <button onclick=\"fetch(\'/k\')\">-100</button>\n          </div>\n          <div class=\"linear_menu\">\n            <h3>Count</h3>\n            <button onclick=\"fetch(\'/o\')\">+100</button>\n            <button onclick=\"fetch(\'/y\')\">+10</button>\n            <button onclick=\"fetch(\'/e\')\">+1</button>\n            <button onclick=\"fetch(\'/d\')\">-1</button>\n            <button onclick=\"fetch(\'/h\')\">-10</button>\n            <button onclick=\"fetch(\'/l\')\">-100</button>\n          </div>\n        </div>\n      </div>\n      <button style=\"width: 100%;\" onclick=\"fetch(\'/enter\')\">ENTER</button>\n    </div>\n  </div>\n</body>\n</html>");
    return;
  }
  client.println("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n"+req);
}