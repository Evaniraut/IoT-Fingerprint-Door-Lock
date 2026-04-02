// Main logic for the Fingerprint Door Unlock System
#define BLYNK_TEMPLATE_ID "TMPL6Yb2DPYf0"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "gYslny8aO_p6lkP_CF-1h226_qkkxswv"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <Adafruit_Fingerprint.h>
#include <HardwareSerial.h>
#include <ESP32Servo.h>

// Core System Variables
int failedAttempts = 0;
const int maxAttempts = 3; // Alert threshold [cite: 220]

void setup() {
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, "Islington College", "I$LiNGT0N2025");
  myServo.attach(18); // Servo connected to GPIO 18 [cite: 219]
  mySerial.begin(57600, SERIAL_8N1, 16, 17); // AS608 Serial pins [cite: 223]
}

void loop() {
  Blynk.run();
  int fingerprintID = getFingerprintID();
  if (fingerprintID != -1) {
    unlockDoor(); // Authorized [cite: 224]
    delay(5000);
    lockDoor();
  }
}

// Security Alert Logic
int getFingerprintID() {
  if (finger.fingerFastSearch() != FINGERPRINT_OK) {
    failedAttempts++;
    if (failedAttempts >= maxAttempts) {
      Blynk.logEvent("unauthorized_access", "3 unauthorized attempts!"); [cite: 225]
      failedAttempts = 0;
    }
    return -1;
  }
  return finger.fingerID;
}
