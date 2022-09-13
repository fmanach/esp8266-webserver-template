// Handle access to the root URL
void handleRoot() {
  digitalWrite(LED_BUILTIN, HIGH);
  String replyContent = MDNS_NAME;
  replyContent += "\nIP : ";
  replyContent += WiFi.localIP().toString();
  webServer.send(200, "text/plain", replyContent);
  digitalWrite(LED_BUILTIN, LOW);
}

void handleStatus() {
  digitalWrite(LED_BUILTIN, HIGH);
  String replyContent = "{\"name\":\"";
  replyContent += MDNS_NAME;
  replyContent += "\",\"ip\":\"";
  replyContent += WiFi.localIP().toString();
  replyContent += "\"}";
  webServer.send(200, "text/json", replyContent);
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
  webServer.on("/status", handleStatus);
  webServer.onNotFound(handleNotFound);
  webServer.begin();
}
