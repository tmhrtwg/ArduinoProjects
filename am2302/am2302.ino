#include <dht.h>
dht DHT;
#define DHT22_PIN 5

void setup(){
    Serial.begin(115200);
    Serial.println("Project: AM2302");
    Serial.println("Goal: The goal is to check temp and humidity.");
    Serial.println("Url: no blogpost available.");

    Serial.print("DHT LIBRARY VERSION: ");
    Serial.println(DHT_LIB_VERSION);

    Serial.println();
    Serial.println("Humidity (%),\tTemperature (C)");
}

void loop(){
    // READ DATA
    uint32_t start = micros();
    int chk = DHT.read22(DHT22_PIN);
    uint32_t stop = micros();

    // DISPLAY DATA
    Serial.print(DHT.humidity, 1);
    Serial.print(",\t\t");
    Serial.print(DHT.temperature, 1);
    Serial.println();

    delay(2000);
}