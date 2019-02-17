#include "ESP8266WiFi.h" 
#include "ESP8266WebServer.h"
#include "WiFiClient.h"
 
const char* ssid = "ESP8266";
const char* password = "Welcome12#";
IPAddress ip(192,168,0,222);
IPAddress gateway(192,168,0,1);
IPAddress subnet(255,255,255,0);

ESP8266WebServer server(80); 

void handleRoot();              // function prototypes for HTTP handlers
void handleLED();
void handleNotFound();

void setup() {
  wifi_connect();
}
  

void loop() {
  // put your main code here, to run repeatedly:
  char a[100],b[100];

  server.handleClient();

 
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
  client.println("HTTP/1.1 200 OK"); 
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<head>");
  client.println("</head>"); 
  client.println("<style>");
  client.println("body {background-color: #8baee8;}"); 
  client.println("</style>");
  client.print("<h1><b>NOTICE BOARD </b></h1>");
  client.println("<br><br><br>");
  client.println("<form action=\"/DIGITAL NOTICE BOARD.php\">");
  client.println("ENTER THE NOTICE HERE:<br>");
  client.println("<input type=\"text\" name=\"NOTICE IS \"><br>");
  client.println("<input type=\"submit\">");
  client.println("<input type=\"reset\">");
  client.println("</form>"); 
  client.println("</html>");
  delay(5000);

}/*-----------------------void loop ends here------------------------------------*/

void wifi_connect(void){
  
  delay(1000);
  Serial.begin(115200);
  delay(10);
  Serial.print();
  Serial.println("Configuring acces point.");
  
  //set-up the custom IP address
  WiFi.mode(WIFI_AP_STA);
  Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet) ? "Ready" : "Failed!");
  delay(1000);
  
  Serial.print("Setting soft-AP ... ");
  Serial.println(WiFi.softAP(ssid,password) ? "Ready" : "Failed!");
  delay(1000);
  
  Serial.print("AP IP address: ");
  Serial.println(WiFi.softAPIP());
  delay(1000);
 
  server.on("/", HTTP_GET, handleRoot); // Call the 'handleRoot' function when a client requests URI "/"
  server.on("/LED", HTTP_POST, handleRespond); // Call the 'handleRespond' function when a POST request is made to URI "/LED"
  server.onNotFound(handleNotFound);        // When a client requests an unknown URI (i.e. something other than "/"), call function "handleNotFound"
  
  server.begin();                           // Actually start the server
  Serial.println("HTTP server started");
}

void handleRoot() {                         // When URI / is requested, send a web page with a button to toggle the LED
  server.send(200, "text/html", "<form action=\"/LED\" method=\"POST\"><input type=\"submit\" value=\"Toggle LED\"></form>");
}

void handleRespond() {                          // If a POST request is made to URI /LED
 
  server.sendHeader("Location","/");        // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                         // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}

void handleNotFound(){
  server.send(404, "text/plain", "404: Not found"); // Send HTTP status 404 (Not Found) when there's no handler for the URI in the request
}
