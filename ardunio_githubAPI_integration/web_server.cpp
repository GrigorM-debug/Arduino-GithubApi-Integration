#include "web_server.h";

WiFiServer server(80);

void startServer(){
  server.begin();
  Serial.println("server started");
}

void handleClient(){
  // Check for incoming clients
  WiFiClient client = server.available();
  if (client) {
    Serial.println("New client connected.");
    String request = "";

    unsigned long startTime = millis();

    // Read the incoming HTTP request
    while (client.connected() && (millis() - startTime < 1000)) {
      if (client.available()) {
        char c = client.read();
        request += c;

        // Break or the end of the request
        if (request.endsWith("\r\n\r\n")) break;
      }
    }

    // Log the HTTP request
    Serial.println("Client Request:");
    Serial.println(request);

    // Send an HTML response
    if(request.indexOf("GET /") >= 0){
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("Connection: close");
      client.println();
      client.println("<!DOCTYPE html>");
      client.println("<html>");
      client.println("<head>");
      client.println("<meta name='viewport' content='width=device-width, initial-scale=1.0'>");
      client.println("<title>Arduino R4 Web Server</title>");
      client.println("</head>");
      client.println("<body>");
      client.println("<h2>Welcome to Arduino R4 WiFi Web Server</h2>");
      client.println("<p>This page is served from your Arduino R4!</p>");
      client.println("<img src='https://rukminim2.flixcart.com/image/850/1000/xif0q/poster/s/q/m/medium-hacker-hd-poster-250gsm-asstore-hkr4-ascollabs-original-imahfzfwngcdnxws.jpeg?q=90&crop=false' alt='hacker' width='500' height='600'>");
      client.println("</body>");
      client.println("</html>");
    }

    // give the web browser time to receive the data
    client.stop();  // Close the connection
    Serial.println("Client disconnected.");
  }
}