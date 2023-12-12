#define BLYNK_TEMPLATE_ID "TMPL6AI8vdN6t"
#define BLYNK_TEMPLATE_NAME "Light"
#define BLYNK_AUTH_TOKEN "TCR3QT3SWX5WKP0egXUgxoKXT3B39O1j"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "DUNG-PHAM-2209";
char pass[] = "22092003";

#define digitalPin D0
#define BLYNK_PRINT Serial
#define led2 D2
#define led4 D4
int percent;
int value;
int brightness = 255; 

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(led2, OUTPUT);
  pinMode(led4, OUTPUT);
  Blynk.virtualWrite(V2, brightness); 
}

void loop() {
  Blynk.run();
  value = analogRead(digitalPin);
  percent = map(value, 0, 1023, 1023, 0);

  Blynk.virtualWrite(V1, percent);

  if (percent <= 1) {
    analogWrite(led2, brightness); 
    analogWrite(led4, brightness);
  } else {
    digitalWrite(led2, LOW);
    digitalWrite(led4, LOW);
  }
}

BLYNK_WRITE(V2) { 
  brightness = param.asInt(); 
  analogWrite(led2, brightness); 
  analogWrite(led4, brightness); 
}
