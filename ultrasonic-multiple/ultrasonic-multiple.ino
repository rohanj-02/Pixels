const int no_of_ultrasonic = 3;
int trigPin[no_of_ultrasonic] = {6,8,10};
int echoPin[no_of_ultrasonic] = {7,9,11};
int duration[3];
int distance[3];

void setup() {
  for(int i = 0; i < no_of_ultrasonic; i++){
    pinMode(trigPin[i], OUTPUT);
  }
  for(int i = 0; i < no_of_ultrasonic; i++){
    pinMode(echoPin[i], INPUT);
  }
  Serial.begin (9600);
}

void readsensor(int i){ // This function is for first sensor.
  int duration1, distance1;
  digitalWrite (trigPin[i], HIGH);
  delayMicroseconds (10);
  digitalWrite (trigPin[i], LOW);
  duration[i] = pulseIn (echoPin[i], HIGH);
  distance[i] = (duration[i]/2) / 29.1;
  Serial.print(i+" Sensor: ");
  Serial.print(distance[i]); 
  Serial.print("cm    ");
}

void loop() {
Serial.println("\n");
for (int i = 0; i < no_of_ultrasonic; i++){
  readsensor(i);
}
delay(100);
}
