#include "DHTesp.h"

const int DHT_PIN = 15; // Pino ligado ao sensor DHT22
DHTesp dhtSensor;

void setup() {
  Serial.begin(115200); // Inicializa comunicação serial
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22); // Configura o tipo de sensor
}

void loop() {
  TempAndHumidity data = dhtSensor.getTempAndHumidity(); // Lê os dados

  Serial.println("Temperatura: " + String(data.temperature, 2) + "°C");
  Serial.println("Umidade: " + String(data.humidity, 1) + "%");
  Serial.println("---");

  delay(2000); // Aguarda 2 segundos para nova leitura
}
