#include "DHT.h"
#define DHTPIN 2 //Номер порта датчика

//Температура для вентилятора
const float minTemFan = 25;  //Температура при которой выключается вентилятор
const float maxTemFan = 27; //Тут ключается вентилятор
//Температура для обогревателя
const float minTem = 24;    //Температура при которой включается обогрев
const float maxTem = 26;    //выключается
//Влажность
const float minHum = 20;    //Тут включается иррегатор
const float maxHum = 60;    //а тут выключается
//Порты
const int Fan = 8;          //Порт вентилятора
const int Heating = 9;      //Порт обогревателя
const int Irrigation = 10;  //Порт ирригатора

DHT dht(DHTPIN, DHT11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin(); 
  pinMode(Fan,OUTPUT);
  pinMode(Heating,OUTPUT);
  pinMode(Irrigation,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  float t = dht.readTemperature();
  float h = dht.readHumidity();
  if (t >= maxTemFan) digitalWrite(Fan,HIGH);
  if (t <= minTemFan) digitalWrite(Fan,LOW);
  if (t <= maxTem) digitalWrite(Heating,HIGH);
  if (t >= minTem) digitalWrite(Heating,LOW);  
  if (h <= minHum) digitalWrite(Irrigation,HIGH);
  if (h >= maxHum) digitalWrite(Irrigation,LOW);
  
  Serial.println(t);
  Serial.println(h);
  Serial.println();

  delay(2000);
}
