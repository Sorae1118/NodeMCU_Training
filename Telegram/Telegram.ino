#include <UniversalTelegramBot.h>
#include <WiFiClientSecure.h>
#include <ESP8266WiFi.h>

const char *ssid = "DIT_CS_703";  
const char *password = "";   

#define BOT_TOKEN "6451399833:AAG2nJ01i2xw5IDC8Sv1a0hnlbxsa-fZTic"
#define CHAT_ID "6858765176"

X509List cert(TELEGRAM_CERTIFICATE_ROOT);

WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);

void setup() {
  Serial.begin(115200);

  configTime(0, 0, "pool.ntp.org");
  secured_client.setTrustAnchors(&cert);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP :");
  Serial.println(WiFi.localIP());

}

void loop() {
  //bot.sendMessage(CHAT_ID, "Hello, World!", "");
  //delay(10000);

}
