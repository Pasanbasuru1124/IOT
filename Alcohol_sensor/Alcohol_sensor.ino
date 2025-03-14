const int mq3Pin = 32;  // Analog pin connected to MQ3 sensor

void setup() {
   //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);
  
  //Begin serial communication with Arduino and SIM800L
  mySerial.begin(9600);

  Serial.println("Initializing..."); 
  delay(1000);

  mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();

  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  mySerial.println("AT+CMGS=\"+94773779647\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  updateSerial();
  mySerial.print("hi!"); //text content
  updateSerial();
  mySerial.write(26);
  Serial.begin(9600);  // Initialize serial communication
}

void loop() {
  int sensorValue = analogRead(mq3Pin);  // Read the analog value from the sensor
  
  // Convert the analog value to voltage
  float voltage = sensorValue * (5.0 / 1023.0);
  
  // Print the sensor value and voltage
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print(", Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");
  
  delay(1000);  // Wait for 1 second before the next reading
}