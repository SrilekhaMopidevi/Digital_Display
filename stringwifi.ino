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
  
  Serial.begin(115200);
  delay(10);
  
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.config(ip,gateway,subnet);
  WiFi.begin(ssid, password);
  
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected"); 
  
  server.begin();
  Serial.println("Web Server Started");
  
  Serial.print("Connect to the Server: ");
  Serial.print("http://");
  Serial.print(ip);
  Serial.println();
  Serial.println();
   server.on("/", [](){
    server.send(200, "text/html", );
  });

    server.begin();
   
}
