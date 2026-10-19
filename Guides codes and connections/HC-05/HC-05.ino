#include <SoftwareSerial.h>

SoftwareSerial bluetooth(10, 11);  // RX, TX




void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);

  Serial.println("HC-05 iniciado");
  Serial.println("Esperando datos...");
}




void loop() {

  // PC a Bluetooth
  if (Serial.available()) {
    char dato = Serial.read();
    bluetooth.write(dato);
  }


  // Bluetooth a PC
  if (bluetooth.available()) {
    char dato = bluetooth.read();
    Serial.write(dato);
  }
}