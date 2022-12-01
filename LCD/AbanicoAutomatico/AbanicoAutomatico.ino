#include <LiquidCrystal.h>

#include "DHT.h"
#define DHTPIN 12 //define what pin the sensor is connected to
#define DHTTYPE DHT11 // DHT 11
#define motorPin 13

//Create LiquidCrystal object
//LiquidCrystal(rs, enable, d4, d5, d6, d7)
#define lcdRS 1
#define lcdEnable 2
LiquidCrystal lcd(lcdRS, lcdEnable, 4, 5, 6, 7, 8, 9, 10, 11);

//Create DHT object
//DHT dht(pinNumber, typeOfDHT);
DHT dht(DHTPIN, DHTTYPE);


//Initialize lcd and set dimensions
void setup(){
  lcd.begin(16,2); //dimensions
  dht.begin();
  pinMode(motorPin, OUTPUT);
}

void loop(){
  lcd.setCursor(0, 0); //columns, rows
  lcd.print("Leyendo temps...");
  lcd.setCursor(0, 1); //columns, rows
  float t = dht.readTemperature(); //read temperature

  //checking if any reads failed, exit early to try again on next loop
  if (isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  lcd.print("Temp C: "); lcd.print(t);
  delay(2000);

  //analogWrite(motorPin, speed);
  if(t>26){
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("Encendiendo...");
    lcd.setCursor(0, 1); //columns, rows
    lcd.print("Temp C: "); lcd.print(t);
    analogWrite(motorPin, 250);
    delay(4000);
    digitalWrite(motorPin, 0)
    lcd.clear();
  }

}