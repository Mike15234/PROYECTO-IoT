#include "ThingSpeak.h"
#include "WiFi.h"

#include "DHT.h"
#include "Adafruit_BMP085.h"


#define pin1 15       //Pin del DHT11.

const char* ssid = "RED";                        //SSID de vuestro router.
const char* password = "CONTRASEÑA";                //Contraseña de vuestro router.

unsigned long channelID = ;                //ID de vuestro canal.
const char* WriteAPIKey = "";     //Write API Key de vuestro canal.

WiFiClient cliente;

DHT dht1(pin1, DHT11);    //El azul.

Adafruit_BMP085 bmp;

void setup() {
  Serial.begin(115200);
  Serial.println("Test de sensores:");

  WiFi.begin(ssid,password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Wifi conectado!");

  ThingSpeak.begin(cliente);

  dht1.begin();

  bmp.begin();
}

void loop() {

  delay(20000);
  leerdht1();
  leerbmp();

  ThingSpeak.writeFields(channelID,WriteAPIKey);
  Serial.println("Datos enviados a ThingSpeak!");
  Serial.println("-----------------------");  
}

void leerdht1() {
  
  float t1 = dht1.readTemperature();
  float h1 = dht1.readHumidity();

  while (isnan(t1) || isnan(h1)){
    Serial.println("Lectura fallida en el sensor DHT11, repitiendo lectura...");
    delay(2000);
    t1 = dht1.readTemperature();
    h1 = dht1.readHumidity();
  }

  Serial.print("Temperatura DHT11: ");
  Serial.print(t1);
  Serial.println(" ºC.");

  Serial.print("Humedad DHT11: ");
  Serial.print(h1);
  Serial.println(" %."); 

  ThingSpeak.setField (1,t1);
  ThingSpeak.setField (2,h1);
}

void leerbmp() {

  float presion = bmp.readPressure();
  float altitud = bmp.readAltitude();

  Serial.print("Presión bmp: ");
  Serial.print(presion);
  Serial.println(" Pa.");

  Serial.print("Altitud bmp: ");
  Serial.print(altitud);
  Serial.println(" metros.");

  ThingSpeak.setField (5,presion);
  ThingSpeak.setField (6,altitud);
}
