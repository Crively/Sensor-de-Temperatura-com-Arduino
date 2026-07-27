#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Relés
int releVentilador = 8;   // Ventilador
int releUmidificador = 9; // Umidificador

void setup() {
  Serial.begin(115200);
  dht.begin();
  lcd.begin(16, 2);
  lcd.backlight();

  pinMode(releVentilador, OUTPUT);
  pinMode(releUmidificador, OUTPUT);
}

void loop() {
  delay(1000);

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Erro no sensor!");
    return;
  }

  // Mostra apenas temperatura e umidade no LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature, 1);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Umid: ");
  lcd.print(humidity, 1);
  lcd.print("%");

  // Controle do ventilador
  if (temperature >= 25) {
    digitalWrite(releVentilador, HIGH);
    Serial.println("Ventilador ON");
  } else {
    digitalWrite(releVentilador, LOW);
    Serial.println("Ventilador OFF");
  }

  // Controle do umidificador
  if (humidity <= 40) {
    digitalWrite(releUmidificador, HIGH);
    Serial.println("Umidificador ON");
  } else {
    digitalWrite(releUmidificador, LOW);
    Serial.println("Umidificador OFF");
  }


}
