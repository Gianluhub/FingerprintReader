
// Ejemplo de uso de los dos puertos seriales del ESP8266 con el sensor de huella digital

#include <Adafruit_Fingerprint.h>
//#include <HardwareSerial.h>

// Definir el puerto serie para el sensor
//#define mySerial Serial1
/* Used pins:
   D8 - gpio 15 - tx2 ------  D7 - gpio 13 - rx2 
*/

SoftwareSerial mySerial(13, 15);

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

uint8_t id;

void setup()
{
  Serial.begin(9600);
  
  delay(100);
  Serial.println("\n\nAdafruit Fingerprint sensor enrollment");

  // set the data rate for the sensor serial port
  finger.begin(57600);

  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }

  
  Serial.println(F("Reading sensor parameters"));
  finger.getParameters();
  Serial.print(F("Status: 0x")); Serial.println(finger.status_reg, HEX);
  Serial.print(F("Sys ID: 0x")); Serial.println(finger.system_id, HEX);
  Serial.print(F("Capacity: ")); Serial.println(finger.capacity);
  Serial.print(F("Security level: ")); Serial.println(finger.security_level);
  Serial.print(F("Device address: ")); Serial.println(finger.device_addr, HEX);
  Serial.print(F("Packet len: ")); Serial.println(finger.packet_len);
  Serial.print(F("Baud rate: ")); Serial.println(finger.baud_rate);
  
}

void loop() {
  // Aquí puedes poner tu código para usar el sensor de huella
  // Por ejemplo, puedes usar el método finger.fingerFastSearch() para buscar una huella
  // y enviar el resultado por el puerto serie Serial1
}

