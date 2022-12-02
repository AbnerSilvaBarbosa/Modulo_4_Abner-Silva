#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>

const char* ssid = "abnerEsp";
const char* password = "2003abner";


#define lerRed 40
#define lerBlue 39

int score1_1 = 0;
int score2_2 = 0;


WebServer server(80);

void score1() {
  score1_1 += 1;
  digitalWrite(lerRed, HIGH);
  delay(1000);
  digitalWrite(lerRed, LOW);
}


void score2() {
  score2_2 += 1;
  digitalWrite(lerBlue, HIGH);
  delay(1000);
  digitalWrite(lerBlue, LOW);
}


void setup(void) {

  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  pinMode(lerRed, OUTPUT);
  pinMode(lerBlue, OUTPUT);


  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());


  server.on("/score1", score1);
  server.on("/score2",score2);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  if (score1_1 == 5) {
    digitalWrite(lerRed, HIGH);
    delay(100);

    digitalWrite(lerRed, LOW);
    delay(100);

    digitalWrite(lerRed, HIGH);
    delay(100);

    digitalWrite(lerRed, LOW);
    delay(100);
    digitalWrite(lerRed, HIGH);
    delay(100);

    digitalWrite(lerRed, LOW);
    delay(100);
    digitalWrite(lerRed, HIGH);
    delay(100);

    digitalWrite(lerRed, LOW);
    delay(100);
    digitalWrite(lerRed, HIGH);
    delay(100);

    digitalWrite(lerRed, LOW);
    delay(100);
    digitalWrite(lerRed, HIGH);
    delay(100);

    digitalWrite(lerRed, LOW);
    delay(100);
    digitalWrite(lerRed, HIGH);
    delay(100);

    digitalWrite(lerRed, LOW);
    delay(100);
    score1_1 = 0;
    score2_2 = 0;
  }

  delay(100);

  if (score2_2 == 5) {
    digitalWrite(lerBlue, HIGH);
    delay(100);

    digitalWrite(lerBlue, LOW);
    delay(100);

    digitalWrite(lerBlue, HIGH);
    delay(100);

    digitalWrite(lerBlue, LOW);
    delay(100);
    digitalWrite(lerBlue, HIGH);
    delay(100);

    digitalWrite(lerBlue, LOW);
    delay(100);
    digitalWrite(lerBlue, HIGH);
    delay(100);

    digitalWrite(lerBlue, LOW);
    delay(100);
    digitalWrite(lerBlue, HIGH);
    delay(100);

    digitalWrite(lerBlue, LOW);
    delay(100);
    digitalWrite(lerBlue, HIGH);
    delay(100);

    digitalWrite(lerBlue, LOW);
    delay(100);
    digitalWrite(lerBlue, HIGH);
    delay(100);

    digitalWrite(lerBlue, LOW);
    delay(100);
    score2_2 = 0;
    score1_1 = 0;
  }

  server.handleClient();
  delay(2);  //allow the cpu to switch to other tasks
}