#include <TinyGPS.h>
#include<avr/io.h>
#include<avr/interrupt.h>
#include<SoftwareSerial.h> 
TinyGPS gps;  //Creates a new instance of the TinyGPS object
bool LED = 0;
SoftwareSerial LEDReceiver(3,4);
void setup() {
  Serial.begin(9600);
  DDRD |= (1<<7);

}

void serialEvent(){ // Event nerima data dari GPS
   bool newData = false;
  unsigned long chars;
  unsigned short sentences, failed;

  // For one second we parse GPS data and report some key values
  for (unsigned long start = millis(); millis() - start < 1000;)
  {
    while (Serial.available())
    {
      char c = Serial.read();
      //Serial.print(c);
      if (gps.encode(c)) 
        newData = true;  
    }
  }

  if (newData)      //If newData is true
  {
    float flat, flon;
    unsigned long age;
    gps.f_get_position(&flat, &flon, &age);   
    Serial.print("Latitude = ");
    Serial.print(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6);
    Serial.print(" Longitude = ");
    Serial.print(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);
  }
  delay(2000);
}

void loop() {
  digitalWrite(7,LED);
  while(LEDReceiver.available()){
  }
  LED = !LED;
 }
 
