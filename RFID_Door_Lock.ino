#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

// Define pins for RFID
#define SS_PIN 10
#define RST_PIN 9

// Create MFRC522 instance
MFRC522 mfrc522(SS_PIN, RST_PIN);

// Create servo object
Servo doorServo;

// Registered RFID tags (example tags)
byte tag1[4] = {0xDE, 0xAD, 0xBE, 0xEF};
byte tag2[4] = {0xCA, 0xFE, 0xBA, 0xBE};
byte tag3[4] = {0xFE, 0xED, 0xFA, 0xCE};

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize SPI bus
  SPI.begin();

  // Initialize MFRC522
  mfrc522.PCD_Init();

  // Attach servo to the defined pin
  doorServo.attach(6);

  // Initialize servo position (door locked)
  doorServo.write(0);

  Serial.println("Place your RFID tag near the reader...");
}

void loop() {
  // Look for new RFID cards
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the RFID cards
  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Print the UID of the card
  Serial.print("UID tag: ");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.println();

  // Check if the UID matches any of the registered tags
  if (compareTag(mfrc522.uid.uidByte, tag1) ||
      compareTag(mfrc522.uid.uidByte, tag2) ||
      compareTag(mfrc522.uid.uidByte, tag3)) {
    Serial.println("Access Granted");
    doorServo.write(90); // Unlock door
    delay(5000); // Keep door unlocked for 5 seconds
    doorServo.write(0); // Lock door
  } else {
    Serial.println("Access Denied");
  }

  // Halt PICC
  mfrc522.PICC_HaltA();
}

// Function to compare the UID with a registered tag
bool compareTag(byte *uid, byte *tag) {
  for (byte i = 0; i < 4; i++) {
    if (uid[i] != tag[i]) {
      return false;
    }
  }
  return true;
}
