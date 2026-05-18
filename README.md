# IoT-Based Elderly Health Monitoring System

An Arduino-based embedded healthcare monitoring system designed to help elderly users regularly check their vital health parameters and notify caregivers through SMS alerts without requiring internet connectivity.

## Features

- Real-time body temperature monitoring using DHT11 sensor
- Heart-rate monitoring using Pulse Sensor
- GSM-based SMS alerting using SIM800L module
- Buzzer reminders for regular health checks
- Works without Wi-Fi or internet dependency
- Low-cost and practical elderly healthcare solution

## Technologies Used

- Arduino Uno
- Embedded C / Arduino IDE
- DHT11 Temperature Sensor
- Pulse Heart Rate Sensor
- SIM800L GSM Module
- Buzzer
- GSM SMS Communication

## Components Required

| Component | Purpose |
|---|---|
| Arduino Uno | Main microcontroller |
| DHT11 Sensor | Temperature measurement |
| Pulse Sensor | Heart-rate detection |
| SIM800L GSM Module | SMS alert communication |
| Buzzer | Reminder alert |
| Jumper Wires | Circuit connections |
| External Battery | GSM module power supply |

## Circuit Connections

### DHT11 Sensor

| DHT11 Pin | Arduino Pin |
|---|---|
| VCC | 5V |
| GND | GND |
| Data | D2 |

### Pulse Sensor

| Pulse Sensor Pin | Arduino Pin |
|---|---|
| VCC | 5V |
| GND | GND |
| Signal | A0 |

### SIM800L GSM Module

| SIM800L Pin | Arduino Pin |
|---|---|
| VCC | External 3.7V–4.2V Supply |
| GND | GND |
| TX | D10 |
| RX | D11 |

> Important: Do not connect SIM800L VCC directly to Arduino 5V. Use a proper 3.7V–4.2V external power supply.

### Buzzer

| Buzzer Pin | Arduino Pin |
|---|---|
| Positive | D8 |
| Negative | GND |

## Working Principle

The system continuously reads temperature from the DHT11 sensor and heart-rate data from the pulse sensor. At regular intervals, the buzzer activates to remind the elderly user to check their health. The Arduino processes the sensor readings and sends the temperature and heart-rate values to a caregiver through SMS using the SIM800L GSM module.

## Applications

- Elderly health monitoring
- Remote caregiver support
- Home-based patient monitoring
- Low-cost healthcare alert system
- Emergency health tracking without internet

## Future Enhancements

- Add SpO2 sensor for oxygen monitoring
- Add LCD/OLED display
- Add mobile application support
- Add cloud-based health record storage
- Add emergency fall detection
- Add GPS location tracking

## Project Summary

Built an Arduino-based IoT healthcare device using DHT11, Pulse Sensor, SIM800L GSM Module, and buzzer alerts for real-time temperature and heart-rate monitoring. Implemented GSM SMS alerts, sensor interfacing, and reminder notifications to support elderly health checks without internet dependency.
