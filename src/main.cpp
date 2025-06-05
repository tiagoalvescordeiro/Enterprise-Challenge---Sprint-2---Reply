#include <Arduino.h>
#include <DHT.h>

#define DHTPIN 2          // Pino conectado ao sensor DHT22
#define DHTTYPE DHT22     // Tipo de sensor DHT

#define LDRPIN 34         // Pino analógico conectado ao sensor de luminosidade (LDR)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  delay(2000); // Aguarda 2 segundos entre as leituras

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Erro na leitura do DHT22!");
    return;
  }

  int ldrValue = analogRead(LDRPIN);
  float ldrVoltage = ldrValue * (5.0 / 1023.0);

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C   Humidity: ");
  Serial.print(humidity);
  Serial.print(" %   LDR Voltage: ");
  Serial.print(ldrVoltage);
  Serial.println(" V");
}

