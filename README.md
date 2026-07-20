# Solar Monitoring System Using Arduino

> A real-time solar energy monitoring system developed using **Arduino Uno** and **Proteus**, capable of measuring solar panel voltage, charging current, battery voltage, battery State of Charge (SOC), output power, and generated energy.

---

## Overview

Renewable energy systems require continuous monitoring to ensure efficient power generation and battery charging. Manual measurement using multimeters is time-consuming and does not provide continuous feedback.

This project presents a **Solar Monitoring System** that automatically measures key electrical parameters of a small photovoltaic system and displays them on a **20×4 LCD** in real time.

The system is designed as a simple, low-cost embedded solution suitable for educational purposes, prototype development, and small-scale solar installations.

---

## Objectives

- Monitor solar panel voltage
- Measure charging current
- Measure battery voltage
- Estimate Battery State of Charge (SOC)
- Calculate generated power
- Calculate generated energy
- Display all parameters in real time
- Indicate charging status

---

# 📷 Project Preview

> <img width="2356" height="1028" alt="image" src="https://github.com/user-attachments/assets/de59ee9b-653f-42a8-bf17-d166b19f5630" />


![Project Preview](images/solar_monitoring_system.png)

---

# System Architecture

```
          Solar Panel
                 │
                 ▼
        ACS712 Current Sensor
                 │
                 ▼
      Voltage Divider Network
                 │
                 ▼
          Arduino UNO
                 │
      ┌──────────┴──────────┐
      ▼                     ▼
20×4 LCD Display      Charging Indicator
```

---

# Hardware Components

| Component | Description |
|------------|-------------|
| Arduino Uno | Main controller |
| Solar Panel (18V) | DC power source |
| Battery (12V) | Energy storage |
| ACS712 (5A) | Current measurement |
| 20×4 LCD | Real-time display |
| Voltage Divider | Voltage measurement |
| 1N4007 Diode | Reverse protection |
| LED | Charging indication |
| Resistors | Voltage scaling |

---

# Software Requirements

- Arduino IDE
- Proteus 8 Professional
- Embedded C

---

# Working Principle

1. Solar panel generates DC voltage.
2. Charging current passes through the ACS712 sensor.
3. Voltage divider scales solar and battery voltages.
4. Arduino reads all analog sensor values.
5. The controller calculates:
   - Solar Voltage
   - Battery Voltage
   - Charging Current
   - Output Power
   - Generated Energy
   - Battery State of Charge (SOC)
6. Results are displayed on the LCD.
7. LED indicates battery charging status.

---

# Parameters Monitored

| Parameter | Unit |
|------------|------|
| Solar Voltage | V |
| Battery Voltage | V |
| Charging Current | A |
| Battery SOC | % |
| Output Power | W |
| Generated Energy | Wh |

---

# Mathematical Calculations

## Solar Voltage

Voltage Divider:

```
Vsolar = Vadc × (R1 + R3) / R3
```

---

## Battery Voltage

```
Vbattery = Vadc × (R2 + R4) / R4
```

---

## Current

ACS712 Sensitivity

```
185 mV/A
```

Current Calculation

```
I = (Vsensor − 2.5) / 0.185
```

---

## Power

```
P = V × I
```

---

## Energy

```
E = P × t
```

---

## Battery State of Charge

Approximate estimation

```
SOC = ((Vbattery − 11) / (13 − 11)) × 100
```

---

# LCD Screens

### Screen 1

```
SOLAR MONITORING

Voltage
Current
```

---

### Screen 2

```
BATTERY STATUS

Battery Voltage
SOC
Charging Status
```

---

### Screen 3

```
ENERGY GENERATED

Power
Energy
```

---

# Simulation Results

| Parameter | Result |
|------------|---------|
| Solar Voltage | 18.0 V |
| Battery Voltage | 12.02 V |
| Charging Current | 1.9 A |
| Output Power | 34.23 W |
| Generated Energy | 0.402 Wh |
| Battery SOC | 31% |

---

# Features

- Real-time monitoring
- Automatic calculations
- Battery SOC estimation
- LCD user interface
- Low-cost implementation
- Simple hardware design
- Modular architecture
- Easy to understand and modify

---

# Applications

- Solar Home Systems
- Renewable Energy Education
- Laboratory Experiments
- Embedded Systems Learning
- Battery Charging Systems
- Solar Street Lighting
- Prototype Development

---

# Advantages

- Low cost
- Easy implementation
- Real-time monitoring
- Expandable design
- User-friendly interface
- Lightweight embedded solution

---

# Limitations

- Simulation-based implementation
- Approximate SOC estimation
- No wireless communication
- No data logging
- No Maximum Power Point Tracking (MPPT)

---

# Future Improvements

- ESP32 Wi-Fi integration
- IoT Dashboard
- Mobile Application
- Cloud Data Logging
- MPPT Charge Controller
- SD Card Storage
- GSM Alerts
- Remote Monitoring
- Historical Data Analysis

---

# Skills Demonstrated

- Embedded C Programming
- Arduino Programming
- Embedded Systems
- Proteus Simulation
- Sensor Interfacing
- Analog Signal Processing
- LCD Interfacing
- Electrical Measurements
- Battery Monitoring
- Renewable Energy Systems
- Power Electronics Fundamentals

---

# Project Structure

```
solar-monitoring-system-arduino/
│
├── Circuit_Diagram/
│   └── Circuit.png
│
├── Code/
│   ├── Solar_Monitoring_Code.ino
│
├── Images/
│   ├── Batter_Status.png
│   ├── Energy_Generated.png
│   ├── SOC_State.png
│
├── Report/
│   └── Final_Report.pdf
│
├── Simulation/
│   └── Solar Monitoring System Using Arduino.pdsprj
│
└── README.md
│
└──LICENSE
│
└──Solar Monitoring Circuit.DSN
│
└──Solar_Monitoring_Code.ino.with_bootloader.hex
```

---

# Learning Outcomes

Through this project, I gained practical experience in:

- Embedded system development
- Sensor interfacing
- Analog data acquisition
- Electrical parameter calculations
- Renewable energy monitoring
- Arduino programming
- Circuit simulation using Proteus
- Real-time embedded application design

---

# References

- Arduino Official Documentation
- ACS712 Current Sensor Datasheet
- Proteus Design Suite
- LiquidCrystal Library Documentation

---


## ⭐ If you found this project helpful, consider giving it a star.
