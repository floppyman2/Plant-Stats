#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "b94fdb7f612f4a95b31e93e221f7981e";
char ssid[] = "iPhone";
char pass[] = "diarra10";

int AnalogPin = A0; // FSR is connected to analog A0
int soilmoistureReading;      // the analog reading from the Soil resistor divider

BlynkTimer timer;


void setup() {
  // initialize serial communication at 9600 bits per second:
   // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);

  // Notify immediately on startup
  Blynk.notify("Developing statistics...");
  // Setup a function to be called every minute
}



// the loop routine runs over and over again forever:
void loop() {
 
  Blynk.run();
  timer.run();
  
  soilmoistureReading = analogRead(AnalogPin);
  Serial.print("Soil Moisture reading = ");
  Serial.println(Reading);

  Blynk.virtualWrite(V1, Analog Reading);

  if (soilMoistureReading < 30){  
  Blynk.notify(Plants require water"));
  }
  
  delay(10);
}
