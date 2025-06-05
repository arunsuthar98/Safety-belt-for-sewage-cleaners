//Arun Suthar project
//Safety belt for sewage cleaners
#include <Wire.h>
#include "MAX30105.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "heartRate.h"

MAX30105 particleSensor;

const char* ssid = "edmi 4";
const char* password = "12345678";

ESP8266WebServer server(80);

String page = "";
double beatAvg;
double gas_analog;
const byte RATE_SIZE = 6; 
byte rates[RATE_SIZE]; //Array of heart rates
byte rateSpot = 0;
long lastBeat = 0; //Time at which the last beat occurred

float beatsPerMinute;
float sensor_volt;
float RS_gas;
float ratio;
float R0 = 0.24;

void setup()
{
  Serial.begin(115200);
  Serial.println("Initializing...");

  pinMode(A0, INPUT);
  pinMode(D0, OUTPUT);
  pinMode(D5, OUTPUT);

  delay(1000);
  WiFi.begin(ssid, password); //begin WiFi connection
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());


  // Initialize sensor
  if (!particleSensor.begin(Wire, I2C_SPEED_FAST)) //Use default I2C port, 400kHz speed
  {
    Serial.println("MAX30105 was not found. Please check wiring/power. ");
    while (1);
  }
  Serial.println("Place your index finger on the sensor with steady pressure.");

  particleSensor.setup(); //Configure sensor with default settings
  particleSensor.setPulseAmplitudeRed(0x0A); //Turn Red LED to low to indicate sensor is running
  particleSensor.setPulseAmplitudeGreen(0); //Turn off Green LED


  server.on("/", []() {
    page = "<B><h1>Sensor  Web Server</h1></B><h3>heart bits:</h3> <h4>" + String(beatAvg) + "</h4> <h6> ratio of RS/RO:</h6> <h8>" + String(ratio) + "</h8>";
    server.send(200, "text/html", page);
  });

  server.begin();
  Serial.println("Web server started!");
}

void loop()
{
  long irValue = particleSensor.getIR();
  int sensorValue = analogRead(A0);
  sensor_volt = ((float)sensorValue / 1024) * 5.0;
  RS_gas = (5.0 - sensor_volt) / sensor_volt; // Depend on RL on yor module
  ratio = RS_gas / R0; // ratio = RS/R0

  if (checkForBeat(irValue) == true)
  {
    //We sensed a beat!
    long delta = millis() - lastBeat;
    lastBeat = millis();

    beatsPerMinute = 60 / (delta / 1000.0);

    if (beatsPerMinute < 255 && beatsPerMinute > 20)
    {
      rates[rateSpot++] = (byte)beatsPerMinute; //Store this reading in the array
      rateSpot %= RATE_SIZE; //Wrap variable

      //Take average of readings
      beatAvg = 0;
      for (byte x = 0 ; x < RATE_SIZE ; x++)
        beatAvg += rates[x];
      beatAvg /= RATE_SIZE;
    }
  }
  Serial.print(", Avg BPM=");
  Serial.print(beatAvg);
  server.handleClient();
  if (beatAvg < 60 || beatAvg > 100) {
    digitalWrite(D0, 0);
    digitalWrite(D5, 1);
  }
  else if (ratio > 0.7 && ratio < 2) {
    digitalWrite(D0, 0);
    digitalWrite(D5, 1);
  }
  else {
    digitalWrite(D0, 1);
    digitalWrite(D5, 0);
  }
  if (irValue < 50000) {
    Serial.print(" No finger?");
  }
  Serial.println();
}