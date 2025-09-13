#include <TinyGPS++.h>

#define GPS_BAUDRATE 9600  // The default baudrate of NEO-6M is 9600

TinyGPSPlus gps;  // the TinyGPS++ object

void setup() {
  Serial.begin(9600);
  Serial2.begin(GPS_BAUDRATE);//serial2 for GPS UART

  Serial.println(F("ESP32 - GPS module_Simulation"));
}

void loop() {
  if (Serial2.available() > 0) {
    if (gps.encode(Serial2.read())) {
      if (gps.location.isValid()) {
        Serial.print(F("Latitude: "));
        Serial.println(gps.location.lat(),6);

        Serial.print(F("Longitude: "));
        Serial.println(gps.location.lng(),6);

        Serial.print(F("Altitude: "));
        if (gps.altitude.isValid())
          Serial.println(gps.altitude.meters());
        else
          Serial.println(F("INVALID"));
      } else {
        Serial.println(F("Location: INVALID"));
      }

      Serial.print(F("Speed: "));
      if (gps.speed.isValid()) {
        Serial.print(gps.speed.kmph());
        Serial.println(F(" km/h"));
      } else {
        Serial.println(F("INVALID"));
      }

      Serial.print(F("GPS date&time: "));
      if (gps.date.isValid() && gps.time.isValid()) {
        Serial.print(gps.date.year());
        Serial.print(F("-"));
        Serial.print(gps.date.month());
        Serial.print(F("-"));
        Serial.print(gps.date.day());
        Serial.print(F(" "));
        Serial.print(gps.time.hour());
        Serial.print(F(":"));
        Serial.print(gps.time.minute());
        Serial.print(F(":"));
        Serial.println(gps.time.second());
      } else {
        Serial.println(F("INVALID"));
      }

      Serial.println();
    }
  }

  if (millis() > 5000 && gps.charsProcessed() < 10)
    Serial.println(F("No GPS data received: check wiring"));
}