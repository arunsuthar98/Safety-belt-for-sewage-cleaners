Problem summary
The sewage workers working in the sewage for cleaning and sanitation of sewer lines need more safety due to hazardous conditions present inside the sewage. Due to the absence of facilities and the release of harmful gases like methane, Carbon Monoxide, and hydrogen sulfide, while cleaning the sewer lines, many sewage workers lose their lives and also face many diseases like cardiovascular diseases, asthma, and other life-threatening diseases.
Hardware
starting with the project we have schematics for the project and using all component we make a prototype Universal PCB and also get bet so we can were it on our hand
20210426_183650.jpg
caption (optional)
Design Methodology
first, start with the sensor we take 2 sensors one is MAX30102 pulse oximeter and the second is MQ-9 gas sensor
MQ 9 gas sensor gives us a value of RS or resistance of the coil in the sensor the rato]on of RS/Ro is the coil ratio of the resistance of thecoil in any gases by resistance in pure air so the ratio is also given a value of voltage and we change the sensitivity of a sensor using in built potentiometer. The carbon monoxide is detected in 10 to 1000 ppm and we checking the graph shown fig.
Screenshot (67).png
caption (optional)
MAX30102 is a pulse oximeter and heart rate monitor module. It integrates an infrared LED, optical components, and photodetector, and low-noise electronic circuitry. The MAX30102 features a 1.9V power supply and a separate 5.O V and 3.3V power supply for internal LEDs. It is used in many devices for heart rate and blood oxygen acquisition, and is worn on earlobes, fingers, and wrists.
we use Arduino IDE for programming and get from the sensor and if our heartbeat goes above 100 or below 60 buzzers and led will ON, also MQ9 gas sensor PPM value goes above 200 LED and buzzer will ON and that Dager also notified server and get help. we can use a local server on Amazon web server or blynk server for that.
Screenshot (65).png
caption (optional)
PCB desines
Screenshot (58).png
caption (optional)
