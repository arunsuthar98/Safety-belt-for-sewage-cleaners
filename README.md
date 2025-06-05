# Sewage Worker Safety Monitoring System

## Problem Summary
The sewage workers working in the sewage for cleaning and sanitation of sewer lines need more safety due to hazardous conditions present inside the sewage. Due to the absence of facilities and the release of harmful gases like methane, Carbon Monoxide, and hydrogen sulfide, while cleaning the sewer lines, many sewage workers lose their lives and also face many diseases like cardiovascular diseases, asthma, and other life-threatening diseases.

## Hardware
Starting with the project, we have schematics for the project and using all components, we made a prototype Universal PCB and also got a belt so we can wear it on our hand.

![Prototype Image](20210426_183650.jpg)  
*caption (optional)*

## Design Methodology
First, start with the sensors. We take 2 sensors: one is MAX30102 pulse oximeter and the second is MQ-9 gas sensor.

MQ-9 gas sensor gives us a value of RS or resistance of the coil in the sensor. The ratio RS/Ro is the coil ratio of the resistance of the coil in any gases by resistance in pure air. This ratio is also converted to a voltage value and we change the sensitivity of the sensor using the inbuilt potentiometer. The carbon monoxide is detected in 10 to 1000 ppm as shown in the graph below.

![MQ-9 Sensor Graph](Screenshot_67.png)  
*caption (optional)*

MAX30102 is a pulse oximeter and heart rate monitor module. It integrates an infrared LED, optical components, photodetector, and low-noise electronic circuitry. The MAX30102 features a 1.9V power supply and separate 5.0V and 3.3V power supplies for internal LEDs. It is used in many devices for heart rate and blood oxygen acquisition, and is worn on earlobes, fingers, and wrists.

We use Arduino IDE for programming and get data from the sensors. If heartbeat goes above 100 or below 60 bpm, buzzer and LED will turn ON. Also, if MQ-9 gas sensor PPM value goes above 200, LED and buzzer will turn ON and the danger is also notified to a server to get help. We can use a local server on Amazon Web Services or Blynk server for that.

![Alert Screenshot](Screenshot_65.png)  
*caption (optional)*

## PCB Designs

![PCB Design](Screenshot_58.png)  
*caption (optional)*

## Components List

| Component                                         | Quantity |
| -------------------------------------------------|----------|
| Espressif Wemos D1 Mini                           | 1        |
| Gravity: Analog CO/Combustible Gas Sensor (MQ9)  | 1        |
| MAX30102 Pulse Oximeter and Heart Rate Sensor    | 1        |
| LED (generic)                                     | 2        |
| Buzzer                                           | 1        |
| Universal PCB                                    | 1        |
| Male Header 36 Position 1 Row - Long (0.1")      | 1        |
| Female Header 8 Position 1 Row (0.1")             | 2        |
| Battery, 3.7 V                                   | 1       |

---
