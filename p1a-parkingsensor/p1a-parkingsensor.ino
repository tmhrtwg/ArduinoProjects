/* **********************************************
    Project 1a: parking sensor!
    tomhartwig.nl/blog/arduino-project-1a-parking-sensor

    The idea is to beep when you come close.
    ...and beep faster when you come closer.
    ...and to go berserk when almost touching.
********************************************** */
#include <NewPing.h>

#define TRIGGER_PIN  A11  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     A12 // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

#define BUZZER_PIN 8 // analog port
int ledPin = 2;

void setup() {
    pinMode(A10, OUTPUT);
    pinMode(A13, OUTPUT);
    digitalWrite(A10, HIGH);
    digitalWrite(A13, LOW);

    // debug
    // Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.

    pinMode(ledPin, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
    delay(50);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
    unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).

    // debug
    // Serial.print("Ping: ");
    // Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance in cm and print result (0 = outside set distance range)
    // Serial.println("cm");

    if(uS / US_ROUNDTRIP_CM == 0) {
        // too close
        noBlink();
    } else if(uS / US_ROUNDTRIP_CM > 0 && uS / US_ROUNDTRIP_CM <= 10){
        blinkFast();
        analogWrite(BUZZER_PIN, 250);
    } else if (uS / US_ROUNDTRIP_CM > 10 && uS / US_ROUNDTRIP_CM <= 20){
        blinkMedium();
        beep(60);
    } else if (uS / US_ROUNDTRIP_CM > 20 && uS / US_ROUNDTRIP_CM <= 30){
        blinkSlow();
        beep(120);
    } else if (uS / US_ROUNDTRIP_CM > 30 && uS / US_ROUNDTRIP_CM <= 40){
        blinkSlow();
        beep(180);
    } else if (uS / US_ROUNDTRIP_CM > 40 && uS / US_ROUNDTRIP_CM <= 50){
        blinkSlow();
        beep(240);
    } else {
        // out of range for this demo, no need to beep here
        digitalWrite(ledPin, LOW);
    }
}

// SOUND FUNCTION
void beep(unsigned char delayms){
    analogWrite(BUZZER_PIN, 250); // Almost any value can be used except 0 and 255 experiment to get the best tone
    delay(delayms);               // wait for a delayms ms
    analogWrite(BUZZER_PIN, 0);   // 0 turns it off
    delay(delayms);               // wait for a delayms ms
}

// BLINK FUNCTIONS
void noBlink(){
    digitalWrite(ledPin, HIGH);
}
void blinkFast(){
    digitalWrite(ledPin, HIGH);
    delay(30);
    digitalWrite(ledPin, LOW);
}
void blinkMedium(){
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
}
void blinkSlow(){
    digitalWrite(ledPin, HIGH);
    delay(250);
    digitalWrite(ledPin, LOW);
}