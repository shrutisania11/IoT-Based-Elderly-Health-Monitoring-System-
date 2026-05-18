#include <DHT.h>
#include <SoftwareSerial.h>

#define DHTPIN 2
#define DHTTYPE DHT11

#define PULSE_PIN A0
#define BUZZER_PIN 8

#define GSM_RX 10
#define GSM_TX 11

DHT dht(DHTPIN, DHTTYPE);
SoftwareSerial gsm(GSM_RX, GSM_TX);

// Replace with caregiver phone number
String phoneNumber = "+91XXXXXXXXXX";

// Reminder interval in milliseconds
// Example: 60000 = 1 minute
unsigned long reminderInterval = 60000;
unsigned long lastReminderTime = 0;

void setup() {
  Serial.begin(9600);
  gsm.begin(9600);

  dht.begin();

  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  Serial.println("IoT-Based Elderly Health Monitoring System Started");

  delay(2000);
  initializeGSM();
}

void loop() {
  float temperature = dht.readTemperature();
  int pulseValue = analogRead(PULSE_PIN);

  int heartRate = map(pulseValue, 0, 1023, 60, 120);

  if (isnan(temperature)) {
    Serial.println("Failed to read temperature from DHT11 sensor");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Heart Rate: ");
  Serial.print(heartRate);
  Serial.println(" BPM");

  if (millis() - lastReminderTime >= reminderInterval) {
    buzzerReminder();

    String message = "Health Check Alert:\n";
    message += "Temperature: " + String(temperature) + " C\n";
    message += "Heart Rate: " + String(heartRate) + " BPM\n";

    sendSMS(message);

    lastReminderTime = millis();
  }

  delay(2000);
}

void initializeGSM() {
  Serial.println("Initializing GSM Module...");

  gsm.println("AT");
  delay(1000);

  gsm.println("AT+CMGF=1");
  delay(1000);

  gsm.println("AT+CSCS=\"GSM\"");
  delay(1000);

  Serial.println("GSM Module Ready");
}

void sendSMS(String message) {
  Serial.println("Sending SMS...");

  gsm.println("AT+CMGF=1");
  delay(1000);

  gsm.print("AT+CMGS=\"");
  gsm.print(phoneNumber);
  gsm.println("\"");
  delay(1000);

  gsm.print(message);
  delay(1000);

  gsm.write(26);
  delay(5000);

  Serial.println("SMS Sent Successfully");
}

void buzzerReminder() {
  Serial.println("Buzzer Reminder Activated");

  digitalWrite(BUZZER_PIN, HIGH);
  delay(1000);
  digitalWrite(BUZZER_PIN, LOW);
  delay(500);

  digitalWrite(BUZZER_PIN, HIGH);
  delay(1000);
  digitalWrite(BUZZER_PIN, LOW);
}
