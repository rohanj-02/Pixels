const int no_of_ultrasonic = 3;
int trigPin[no_of_ultrasonic] = {A0,A2,A4};
int echoPin[no_of_ultrasonic] = {A1,A3,A5};
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
}

void printsensor(int i){
  Serial.print(i + 1);
  Serial.print(" Sensor: ");
  Serial.print(distance[i]); 
  Serial.print("cm    ");

}

void getPosition(){

if(distance[0] < 50 && distance[1] > 50 && distance[2] > 50){
  Serial.println("1");
}
else if((distance[1] < 50 && distance[2] > 50 && distance[0] > 50) || (distance[0] < 50 && distance[1] < 50 && distance[2] < 50)){
  Serial.println("3");
}
else if(distance[2] < 50 && distance[1] > 50 && distance[0] > 50){
  Serial.println("5");
}
else if(distance[1] < 50 && distance[0] < 50 && distance[2] > 50){
  Serial.println("2");
}
else if(distance[1] < 50 && distance[2] < 50 && distance[0] > 50){
  Serial.println("4");
}

}

void loop() {
//Serial.println("\n");
for (int i = 0; i < no_of_ultrasonic; i++){
  readsensor(i);
//  printsensor(i);
}
getPosition();


delay(100);
}
