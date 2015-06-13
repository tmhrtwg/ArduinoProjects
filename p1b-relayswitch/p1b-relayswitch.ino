/* **********************************************
    Project 1b: relay switch
    tomhartwig.nl/blog/arduino-project-1b-relay-switch

    The idea is to see if I can control the
    relay switch I bought.
********************************************** */
int relay1 = 11;
int relay2 = 10;
int relay3 = 9;
int relay4 = 8;

void setup() {
    // debug
    // Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.

	// Set relay pins to output
	pinMode(relay1, OUTPUT);
	pinMode(relay2, OUTPUT);
	pinMode(relay3, OUTPUT);
	pinMode(relay4, OUTPUT);
}

void loop() {
	// activate the 4 relay switches with a small delay
	digitalWrite(relay1, HIGH);
	delay(200);
	digitalWrite(relay2, HIGH);
	delay(200);
	digitalWrite(relay3, HIGH);
	delay(200);
	digitalWrite(relay4, HIGH);

	// keep them activated
	delay(3000);

	// deactivate them all at once
	digitalWrite(relay1, LOW);
	digitalWrite(relay2, LOW);
	digitalWrite(relay3, LOW);
	digitalWrite(relay4, LOW);
	delay(3000);
}