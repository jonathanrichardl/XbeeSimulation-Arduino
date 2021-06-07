#include<avr/io.h>
#include<SoftwareSerial.h>
#include <SPI.h>        
#include <SD.h>         
String b;
File logger;
bool led = 0;
SoftwareSerial LED(3,4);
void setup () {
  SD.begin();
  logger = SD.open("Logs.txt", FILE_WRITE);
  logger.println("Logged Succesfully!");
  Serial.begin(9600);
  logger.close();
  PORTD |= (1<<2); // jadiin pin 2 input pullup
  EICRA |= (1<<1); //nyalakan EICRA 1 supaya Falling edge
  EIMSK |= (1<<0); //nyalakan EIMSK0 untuk aktifkan interrupt di pin 2 arduino.
  sei();    //nyalakan interrupt
}

ISR(INT0_vect){ // Interrupt Service Routine ketika button dipencet
  logger = SD.open("Logs.txt", FILE_WRITE);
  led = !led;
  LED.print("LED"); // Perintah menyalakan LED ke arduino drone
  if(led){
    logger.println("LED ON");
  }
  if(!led){
    logger.println("LED OFF");
  }
  logger.close();
}

void serialEvent(){
  logger = SD.open("Logs.txt", FILE_WRITE);
  if(Serial.available() > 0) {
    b = Serial.readString();
  }
  Serial.print(b);
  logger.println(b);
  logger.close();
}
void loop () {
}
