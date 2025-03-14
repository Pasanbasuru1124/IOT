#include <SoftwareSerial.h>

SoftwareSerial sim800l(2, 3); // RX, TX

void setup() {
  // Start communication with SIM800L
  sim800l.begin(9600);  
  Serial.begin(9600);

  // Wait for the SIM800L module to respond
  delay(1000);
  Serial.println("Initializing...");
  
  // Send SMS
  sendSMS("+94714855753", "Hello from Arduino!");  // Replace with recipient's number and your message
}

void loop() {
  // Do nothing in loop
}

void sendSMS(String phoneNumber, String message) {
  sim800l.println("AT");  // Check communication
  delay(1000);
  sim800l.println("AT+CMGF=1");  // Set SMS to Text Mode
  delay(1000);
  sim800l.println("AT+CMGS=\"" + phoneNumber + "\"");  // Specify recipient's number
  delay(1000);
  sim800l.println(message);  // Message content
  delay(1000);
  sim800l.write(26);  // Send Ctrl+Z to indicate end of message
  delay(1000);
  Serial.println("SMS sent successfully");
}