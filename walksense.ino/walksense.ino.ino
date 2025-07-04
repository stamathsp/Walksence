// HC-SR04
const int trig1 = 2;
const int echo1 = 3;
const int trig2 = 4;
const int echo2 = 5;

// PIR
const int pirPin = 6;

// Buzzer
const int buzzerPin = 7;

void setup() {
  Serial.begin(9600);

  pinMode(trig1, OUTPUT); pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT); pinMode(echo2, INPUT);
  pinMode(pirPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  bool pedestrianDetected = digitalRead(pirPin);

  if (pedestrianDetected) {
    float distance1 = measureDistance(trig1, echo1);
    float distance2 = measureDistance(trig2, echo2);

    Serial.print("Pedestrian detected - Distance 1: ");
    Serial.print(distance1);
    Serial.print(" cm, Distance 2: ");
    Serial.println(distance2);

    if ((distance1 > 0 && distance1 < 150) || (distance2 > 0 && distance2 < 150)) {
      Serial.println("VEHICLE APPROACHING!");
      beepBuzzer();
    }
  } else {
    Serial.println("No pedestrian detected.");
  }

  delay(5000);
}

float measureDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000); // 30ms max
  if (duration == 0) return -1.0;
  float distance = duration * 0.0343 / 2;
  return distance;
}

void beepBuzzer() {
  // Δύο μικρά μπιπ
  for (int i = 0; i < 2; i++) {
    tone(buzzerPin, 4000); // 4kHz
    delay(300);
    noTone(buzzerPin);
    delay(200);
  }
}
