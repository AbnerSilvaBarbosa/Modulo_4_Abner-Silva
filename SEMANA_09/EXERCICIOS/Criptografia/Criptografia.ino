#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include <String>

const char *ssid = "Sou lindo";  //atribuir nome da rede WiFi
const char *password = "vitorteamo";  //atribuir senha da rede



char converter(char ch, int chave) {
  if (!isalpha(ch)) return ch;
  char offset = isupper(ch) ? 'A' : 'a';
  return (char)((((ch + chave) - offset) % 26) + offset);
}


String criptografar(String entrada, int chave) {
  String saida = "";
  size_t len = entrada.length();
  for (size_t i = 0; i < len; i++)
    saida += converter(entrada[i], chave);
  return saida;
}

void postDataToServer() {

  Serial.println("Posting JSON data to server...");
  String cripto = criptografar("Hoje e treino de perna", 12);

  // Block until we are able to connect to the WiFi access point
  HTTPClient http;
    http.begin("https://ur524n-3000.preview.csb.app/teobaldo");
    http.addHeader("Content-Type", "application/json");

    StaticJsonDocument<200> doc;
    // Add values in the document
    //
    doc["nome"] = "Abner Silva Barbosa";
    doc["turma"] = 1;
    doc["grupo"] = 2;
    doc["mensagem_texto"] = "Hoje e treino de perna";
    doc["mensagem_criptografada"] = cripto;
     // Add an array.
    //
    JsonArray data = doc.createNestedArray("data");
    String requestBody;
    serializeJson(doc, requestBody);
    int httpResponseCode = http.POST(requestBody);
    if(httpResponseCode>0){
    String response = http.getString();
    Serial.println(httpResponseCode);
    Serial.println(response);
    }
}

void setup(){
  Serial.begin(115200);
  WiFi.begin(ssid, password); 

  while(WiFi.status() != WL_CONNECTED)   //aguarda conexão (WL_CONNECTED é uma constante que indica sucesso na conexão)
  {
    delay(1000);
    Serial.print(".");                   //vai imprimindo pontos até realizar a conexão...
  }

  postDataToServer();

}


void loop() {
}