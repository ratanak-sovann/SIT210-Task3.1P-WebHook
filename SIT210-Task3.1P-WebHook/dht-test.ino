// For this task, we're using DHT11 humidity/temperature sensor.

// Using Adafruit_DHT_Particle library to read from sensor
#include "Adafruit_DHT_Particle.h"

// what pin we're connected to
#define DHTPIN D5     

// defining the DHTTYPE
#define DHTTYPE DHT11		// DHT 11


DHT dht(DHTPIN, DHTTYPE);

void setup() {
	Serial.begin(9600); 
	Particle.publish("Reading starts in 2 seconds.");
	dht.begin();
	delay(2000);
}

void loop() {

    // Read temperature as Celsius
	float temperature = dht.getTempCelcius();

  
    // Check if any reads failed and exit early (to try again).
	if (isnan(temperature)) {
		Serial.println("Failed to read from DHT sensor!");
		return;
	}

    //Publish the event to trigger Webhook.
	Particle.publish("Temperature", String::format("%4.2f",temperature));
	
	//Pause for 15 seconds before running again.
	delay(15000);
}

