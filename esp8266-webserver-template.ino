// esp8266-webserver-template
//
// Created : Sept 13th, 2022 by @fmanach
// https://github.com/fmanach/esp8266-webserver-template
// 
//
// This is a simple template to connect an ESP8266 to a WiFi network and serve HTTP requests.
// It provides feedback on the connection status through the on-board LED.
// Once connected the device announces itself through MDS.

#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>

// User has to set the WiFi credentials in wifi.h
#include "wifi.h"

// Activate console loggin (9600 bauds) ?
#define SERIAL_DEBUG false

// Define the mDNS name
// Device will be reachable at MDNS_NAME.local
#define MDNS_NAME "ESP8266"

void setup() {
  if(SERIAL_DEBUG) {
    Serial.begin(9600);
  }
  pinMode(LED_BUILTIN, OUTPUT);
  startWifi(WFSSID, WFPSK);
  startMDNS(MDNS_NAME);
  blinkStatus(100, 10);
}

void loop() {
  MDNS.update();
}
