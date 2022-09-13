// Handle access to the root URL
void handleRoot() {
  digitalWrite(LED_BUILTIN, HIGH);
  webServer.send(200, "text/plain", MDNS_NAME);
  digitalWrite(LED_BUILTIN, LOW);
}

// Reply 404 to unkown requests
void handleNotFound() {
  digitalWrite(LED_BUILTIN, HIGH);
  webServer.send(404, "text/plain", "404 NOT FOUND");
  digitalWrite(LED_BUILTIN, LOW);
}

// Start web server and map requests to handlers 
void startWebServer()  {
  webServer.on("/", handleRoot);
  webServer.onNotFound(handleNotFound);
  webServer.begin();
}
