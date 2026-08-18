#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

int releVentilador = 8; 
int releUmidificador = 9;

const float TEMP_LIGA = 25.0;
const float TEMP_DESLIGA = 23.0;

const float UMID_LIGA = 40.0;
const float UMID_DESLIGA = 45.0;

bool ventiladorLigado = false;
bool umidificadorLigado = false;

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

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature, 1);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Umid: ");
  lcd.print(humidity, 1);
  lcd.print("%");

  if (!ventiladorLigado && temperature >= TEMP_LIGA) {
    ventiladorLigado = true;
  } else if (ventiladorLigado && temperature <= TEMP_DESLIGA) {
    ventiladorLigado = false;
  }
  digitalWrite(releVentilador, ventiladorLigado ? HIGH : LOW);
  Serial.println(ventiladorLigado ? "Ventilador ON" : "Ventilador OFF");

  if (!umidificadorLigado && humidity <= UMID_LIGA) {
    umidificadorLigado = true;
  } else if (umidificadorLigado && humidity >= UMID_DESLIGA) {
    umidificadorLigado = false;
  }
  digitalWrite(releUmidificador, umidificadorLigado ? HIGH : LOW);
  Serial.println(umidificadorLigado ? "Umidificador ON" : "Umidificador OFF");
}
