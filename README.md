**Project: RFID Door Lock**

Collaborative task: Sketch a 3D print for the door opening mechanism and request fellow tinkers handling 3D to do the needful. LOL! 
Below is a guide



**2.0 Introduction**
In this task, we will create an RFID door lock system using an RFID module (MFRC522) and a servo motor to demonstrate the control of door access based on registered RFID tags.
2.1 Working of the Prototype
The door will unlock when a registered RFID tag is detected and will remain locked when an unregistered tag or no tag is present. The RFID module reads the tag information, and if the tag matches one of the registered tags, the servo motor will turn to unlock the door.
2.2 Objectives
What Will I Learn?
You will learn the basic working principle of how an RFID module works.
You will learn how to use the RFID module with a servo motor.
You will learn how to register and verify RFID tags in an Arduino program.
You will learn how digital input and output work using the RFID module and the servo motor as the output.

**2.3 Hardware Requirements**
Arduino Uno
RFID module (MFRC522)
Servo motor
Jumper cables

**2.4 Connections**

**RFID Module:**
VCC to 3.3V on the Arduino
RST to pin 9 on the Arduino
GND to GND on the Arduino
MISO to pin 12 on the Arduino
MOSI to pin 11 on the Arduino
SCK to pin 13 on the Arduino
SDA to pin 10 on the Arduino

**Servo Motor:**
Red wire to VCC (5V) on the Arduino
Black wire to GND on the Arduino
Yellow wire to pin 6 on the Arduino
