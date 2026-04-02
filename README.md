# Fingerprint-Based Door Lock System (IoT)
**A Smart Biometric Security Solution with Cloud-Integrated Intrusion Alerts**

This project demonstrates the design and implementation of a secure access control system using the **ESP32 microcontroller**, an **AS608 optical fingerprint sensor**, and the **Blynk IoT platform**. 

---

## 🚀 Overview
Traditional locks are vulnerable to picking and lack real-time monitoring. This system provides a two-tier security approach:
1. **Biometric Authentication:** Only registered fingerprints can activate the locking mechanism.
2. **Cloud Monitoring:** Unauthorized access attempts (3 consecutive failures) trigger an immediate email/push notification to the owner via Blynk.

---

## 🛠️ System Architecture
The system is built on a modular hardware-software framework:

| Component | Function |
| :--- | :--- |
| **ESP32-WROOM-32** | Central processing unit and Wi-Fi gateway. |
| **AS608 Sensor** | Optical biometric data acquisition and matching. |
| **SG90 Servo** | Actuator for physical door latch simulation. |
| **Blynk Cloud** | Remote monitoring and automated event logging. |

### 📟 Circuit Logic
* **Authentication:** Fingerprint matches stored ID -> Servo rotates 90° -> Relay toggles.
* **Security Loop:** Incorrect finger -> Counter +1. If Counter >= 3 -> Blynk `logEvent` triggers alert.

---

## 📊 Key Features & Findings
* **Real-time Notifications:** Tested and verified email alerts on unauthorized entry attempts.
* **Scalability:** Designed to be compatible with industrial door locks via the integrated relay module.
* **Accuracy:** High-speed biometric matching (57600 baud rate) with minimal latency.

---

## 💻 Software & Libraries
Developed using the **Arduino IDE** with the following dependencies:
* `Adafruit_Fingerprint.h`
* `ESP32Servo.h`
* `BlynkSimpleEsp32.h`
* `WiFi.h`

---


---
*Developed as a Major Project at Islington College (London Metropolitan University).*
