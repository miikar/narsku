void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  static int minValue = 1024;
  static int maxValue = 0;
  int sensorValue = analogRead(A0);

  // Calibrate
  if(sensorValue > maxValue) {
    maxValue = sensorValue;  
  }
  if(sensorValue < minValue) {
    minValue = sensorValue;  
  }

  int threshold = 0.5*(maxValue - minValue) + minValue;

  Serial.print(sensorValue);
  Serial.print(" ");
  Serial.print(minValue);
  Serial.print(" ");
  Serial.print(maxValue);
  Serial.print(" ");
  Serial.println(threshold);

  if(sensorValue >= threshold) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
  delay(100);
}
