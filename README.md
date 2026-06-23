# IOT-BASED-SMART-WATER-INLET-DETECTION-FOR-MUNICIPAL-SUPPLY-IN-END-OF-LINE-HOUSEHOLDS
IoT-based smart water inlet detection system using ESP32 and HK3022 pressure sensor for automatic municipal water supply detection and pump control in end-of-line households.
# IoT-Based Smart Water Inlet Detection for Municipal Supply in End-of-Line Households

## Overview

The unequal distribution of municipal water supply is a common problem in both urban and rural communities. Houses located near the municipal supply source receive sufficient water pressure, while households at the end of the distribution line often experience low pressure or no water supply.

This project presents an IoT-Based Smart Water Inlet Detection System (WIDS) that automatically detects the arrival of municipal water and activates a household water pump without human intervention.

The system uses a HK3022 Water Pressure Sensor connected to an ESP32 microcontroller. When water enters the pipeline, the pressure change is detected and a relay module automatically switches ON the motor. The system also supports IoT monitoring, allowing users to monitor water availability remotely.

---

## Problem Statement

Many households miss municipal water supply because:

- Water supply timings are irregular.
- Users must manually monitor water arrival.
- End-of-line houses receive low pressure.
- Delayed motor activation causes water loss.

This project solves these issues through automatic water inlet detection and pump control.

---

## Objectives

- Detect municipal water supply using pressure sensing.
- Automatically activate the household motor.
- Reduce manual monitoring.
- Provide real-time monitoring through IoT.
- Prevent dry-run conditions.
- Improve water accessibility for end-of-line households.

---

## System Architecture

Water Inlet
     ↓
HK3022 Pressure Sensor
     ↓
ESP32-WROOM-32
     ↓
Relay Module
     ↓
Water Pump / Motor
     ↓
Arduino Cloud Dashboard

---

## Hardware Components

| Component | Description |
|------------|-------------|
| ESP32-WROOM-32 | Main Controller |
| HK3022 Pressure Sensor | Water Pressure Detection |
| HX710B Pressure Sensor | Initial Prototype Testing |
| 2 Channel Relay Module | Motor Switching |
| XL4015 Buck-Boost Converter | Stable Power Supply |
| 12V DC Water Pump | Water Pumping |
| Zero PCB | Circuit Assembly |
| Screw Terminal | Secure Wiring |

---

## Hardware Specifications

### ESP32-WROOM-32

- Wi-Fi + Bluetooth
- Operating Voltage: 2.3V – 3.6V
- Flash Memory: 4 MB
- Clock Frequency: 80–240 MHz

### HK3022 Pressure Sensor

- Operating Voltage: 5V
- Pressure Range: 0–1 MPa
- Output Voltage: 0.5V – 4.5V
- Accuracy: ±1% FS
- Stainless Steel Body

### Relay Module

- Operating Voltage: 5V
- Trigger Type: Low Level
- Switching Capacity:
  - 250VAC @ 10A
  - 30VDC @ 10A

---

## Working Principle

### Step 1: Calibration

The system first measures the baseline pressure.

```cpp
baselinePressure = average(sensor readings);
```

### Step 2: Pressure Monitoring

The ESP32 continuously reads pressure values.

```cpp
sensorValue = analogRead(pressurePin);
```

### Step 3: Pressure Change Detection

```cpp
pressureChange = sensorValue - baselinePressure;
```

### Step 4: Relay Activation

```cpp
if(abs(pressureChange) >= threshold)
{
   Relay ON
}
else
{
   Relay OFF
}
```

### Step 5: Motor Operation

When municipal water enters the pipeline:

- Pressure increases
- Relay activates
- Motor starts automatically

When water supply stops:

- Pressure drops
- Relay deactivates
- Motor turns OFF

---

## Detection Logic

### Water Supply Available

Condition:

```text
Px ≥ Pth
```

Action:

```text
Pump ON
```

### No Water Supply

Condition:

```text
Px < Pth
```

Action:

```text
Pump OFF
```

---

## Software Requirements

### Arduino IDE

Version 2.0+

### Libraries

For HX710B:

```cpp
HX711 Library
```

Install from Arduino Library Manager.

---

## Repository Structure

```text
WIDS/
│
├── Arduino_HX710B/
│   └── HX710B_AirPressure.ino
│
├── Arduino_HK3022/
│   └── HK3022_Arduino.ino
│
├── ESP32_HK3022/
│   └── HK3022_ESP32.ino
│
├── ESP32_Arduino_Cloud/
│   └── HK3022_Cloud.ino
│
├── Images/
│   ├── BlockDiagram.png
│   ├── Schematic.png
│   ├── Prototype.jpg
│   ├── FinalSystem.jpg
│   └── Results.png
│
├── README.md
└── LICENSE
```

---

## Experimental Development

### Trial 1

- Arduino Uno Based Prototype
- Successful detection
- No IoT capability

### Trial 2

- HX710B Air Pressure Sensor
- Accurate in air
- Not suitable for direct water exposure

### Trial 3

- LILYGO WiFi Module
- Improved IoT functionality

### Trial 4

- Voltage regulator overheating issue
- Replaced with XL4015 Buck-Boost Converter

### Trial 5

- Final integrated prototype
- Stable operation
- Accurate water detection

---

## Results

- Successful detection of municipal water supply.
- Automatic motor activation achieved.
- Stable relay operation.
- Real-time monitoring through Arduino Cloud.
- Improved accessibility for end-of-line households.

---

## Limitations

- Sensor readings may be affected by electrical noise.
- Performance depends on proper calibration.
- Does not measure water quality.
- Does not calculate flow rate.
- Requires periodic maintenance.

---

## Future Scope

- GSM-based alerts
- Mobile App Integration
- MQTT Support
- Smart Valve Automation
- Solar Powered Operation
- Multi-Source Water Monitoring
- AI-Based Water Supply Prediction
- Flow Rate Monitoring
- Water Quality Monitoring

---

## Applications

- Smart Homes
- Municipal Water Supply Monitoring
- Smart Irrigation Systems
- Residential Water Management
- Industrial Water Monitoring
- Smart City Infrastructure

---

## Internship Details

Developed during Internship at:

CSIR – Central Building Research Institute (CSIR-CBRI), Roorkee

Under the Guidance of:

- Mr. Kanti Lal Solanki (Scientist)
- Mr. Chandrabhan Patel (Scientist)

Department:

Electronics & Communication Engineering

Dr. Harisingh Gour University, Sagar

---

## Author

Suhani Kumari

B.Tech – Electronics & Communication Engineering

Dr. Harisingh Gour University, Sagar

---

## License

This project is intended for academic, research, and educational purposes.
