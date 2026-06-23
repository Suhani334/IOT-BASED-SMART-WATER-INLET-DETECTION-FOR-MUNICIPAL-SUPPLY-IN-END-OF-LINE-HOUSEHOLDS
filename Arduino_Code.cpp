Arduino code for HX 710B Air Pressure Sensor:

#include "HX711.h"

// HX710B / HX711 wiring
const int LOADCELL_DOUT_PIN = 2;  // OUT pin
const int LOADCELL_SCK_PIN  = 3;  // SCK pin

const int RELAY_PIN = 8;

HX711 scale;

long baseline = 0;
long threshold_high = 14000;  // Pressure must exceed this to turn ON relay
long threshold_low  = 11000;  // Pressure must fall below this to turn OFF relay

bool relayOn = false;

void setup() {
  Serial.begin(115200);

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);  // Relay OFF initially

  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

  while (!scale.is_ready()) {
    Serial.println("Waiting for HX710B...");
    delay(500);
  }

  // Take multiple readings for accurate baseline
  long sum = 0;
  const int samples = 10;
  for (int i = 0; i < samples; i++) {
    sum += scale.read();
    delay(50);
  }
  baseline = sum / samples;

  Serial.print("Baseline pressure: ");
  Serial.println(baseline);
}

void loop() {
  if (scale.is_ready()) {
    long currentPressure = scale.read();
    Serial.print("Current pressure: ");
    Serial.println(currentPressure);

    // Turn ON relay if pressure increased beyond upper threshold
    if (!relayOn && currentPressure > (baseline + threshold_high)) {
      digitalWrite(RELAY_PIN, LOW);  // Relay ON (active LOW)
      relayOn = true;
      Serial.println("Pressure increased. Relay ON.");
    }

    // Turn OFF relay if pressure falls below lower threshold
    else if (relayOn && currentPressure < (baseline + threshold_low)) {
      digitalWrite(RELAY_PIN, HIGH);  // Relay OFF
      relayOn = false;
      Serial.println("Pressure decreased. Relay OFF.");
    }

  } else {
    Serial.println("Sensor not ready.");
  }

  delay(500);
}

Arduino Code for HK3022 Water pressure Sensor:

// Pin configuration
const int pressurePin = A0;   // Analog pin connected to HK3022 output
const int relayPin = 7;       // Digital pin connected to relay module

// Detection parameters
float baselinePressure = 0;   // Will store initial pressure reading
const float threshold = 5.0;  // Threshold change in pressure (in ADC units, adjust as needed)

// Timing
unsigned long calibrationTime = 5000; // Time to measure baseline (ms)

void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH); // Relay off (assuming active LOW)
  
  Serial.println("Calibrating sensor... Please keep the pipe steady.");
  
  // Calculate baseline pressure over a calibration period
  unsigned long startTime = millis();
  long total = 0;
  int count = 0;
  while (millis() - startTime < calibrationTime) {
    int reading = analogRead(pressurePin);
    total += reading;
    count++;
    delay(50);
  }
  baselinePressure = total / (float)count;
  
  Serial.print("Baseline Pressure (ADC): ");
  Serial.println(baselinePressure);
}

void loop() {
  // Read sensor value
  int sensorValue = analogRead(pressurePin);
  float pressureChange = sensorValue - baselinePressure;
  
  Serial.print("Current: ");
  Serial.print(sensorValue);
  Serial.print("  Change: ");
  Serial.println(pressureChange);
  
  // Detect pressure change beyond threshold
  if (abs(pressureChange) >= threshold) {
    Serial.println("Pressure change detected! Relay ON");
    digitalWrite(relayPin, LOW); // Turn relay on
  } else {
    digitalWrite(relayPin, HIGH); // Turn relay off
  }
  
  delay(200);
} 





ESP 32 Code for HK3022 Water pressure Sensor:

// Pin configuration
const int pressurePin = 34;    // GPIO34 connected to HK3022 output (ADC pin, input only)
const int relayPin = 26;       // GPIO26 connected to relay module

// Detection parameters
float baselinePressure = 0;    // Stores initial pressure reading
const float threshold = 50.0;  // Threshold change (in ADC units for 0–4095 scale)

// Timing
unsigned long calibrationTime = 5000; // Time to measure baseline (ms)

void setup() {
  Serial.begin(115200);  // Faster baud rate for ESP32
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Relay off (assuming active LOW)

  Serial.println("Calibrating sensor... Please keep the pipe steady.");

  // Calculate baseline pressure
  unsigned long startTime = millis();
  long total = 0;
  int count = 0;
  while (millis() - startTime < calibrationTime) {
    int reading = analogRead(pressurePin);
    total += reading;
    count++;
    delay(50);
  }
  baselinePressure = total / (float)count;

  Serial.print("Baseline Pressure (ADC): ");
  Serial.println(baselinePressure);
}

void loop() {
  // Read sensor value
  int sensorValue = analogRead(pressurePin);
  float pressureChange = sensorValue - baselinePressure;

  Serial.print("Current: ");
  Serial.print(sensorValue);
  Serial.print("  Change: ");
  Serial.print(pressureChange);

  // Detect pressure change beyond threshold
  if (abs(pressureChange) >= threshold) {
    Serial.println("  --> Pressure change detected! Relay ON");
    digitalWrite(relayPin, HIGH); // Relay ON
  } else {
    Serial.println("  --> Relay OFF");
    digitalWrite(relayPin, LOW); // Relay OFF
  }

  delay(200);
}

ESP 32 (Arduino Cloud) code for HK3022 Water pressure Sensor:

// Pin configuration
const int pressurePin = 34;    // GPIO34 connected to HK3022 output (ADC pin, input only)
const int relayPin = 26;       // GPIO26 connected to relay module

// Detection parameters
float baselinePressure = 0;    // Stores initial pressure reading
const float threshold = 50.0;  // Threshold change (in ADC units for 0–4095 scale)

// Timing
unsigned long calibrationTime = 5000; // Time to measure baseline (ms)

void setup() {
  Serial.begin(115200);  // Faster baud rate for ESP32
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Relay off (assuming active LOW)

  Serial.println("Calibrating sensor... Please keep the pipe steady.");

  // Calculate baseline pressure
  unsigned long startTime = millis();
  long total = 0;
  int count = 0;
  while (millis() - startTime < calibrationTime) {
    int reading = analogRead(pressurePin);
    total += reading;
    count++;
    delay(50);
  }
  baselinePressure = total / (float)count;

  Serial.print("Baseline Pressure (ADC): ");
  Serial.println(baselinePressure);
}

void loop() {
  // Read sensor value
  int sensorValue = analogRead(pressurePin);
  float pressureChange = sensorValue - baselinePressure;

  Serial.print("Current: ");
  Serial.print(sensorValue);
  Serial.print("  Change: ");
  Serial.print(pressureChange);

  // Detect pressure change beyond threshold
  if (abs(pressureChange) >= threshold) {
    Serial.println("  --> Pressure change detected! Relay ON");
    digitalWrite(relayPin, HIGH); // Relay ON
  } else {
    Serial.println("  --> Relay OFF");
    digitalWrite(relayPin, LOW); // Relay OFF
  }

  delay(200);
}  this is the code give me the all the necessary details that neede to b upload in the github with full cotex