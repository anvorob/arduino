#define trigPin 8
#define echoPin 10
int FULL = 11;
int EMPTY = 13;
int FILLING = 12;
int PUMP_ON = 7;
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(FULL,OUTPUT);
  pinMode(EMPTY,OUTPUT);
  pinMode(FILLING,OUTPUT);
  pinMode(PUMP_ON,OUTPUT);
}

void loop() {
  float duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0344;
  
  int pinstatus = digitalRead(PUMP_ON);
  Serial.println(pinstatus);
  
  if (distance < 30 && distance > 7 && pinstatus == 1){
    digitalWrite(FULL,HIGH);
    Serial.println("Water leve is good");
    digitalWrite(PUMP_ON,HIGH);
    Serial.println(distance);
  }
  else if(distance>30){
    digitalWrite(PUMP_ON,LOW);
    digitalWrite(FULL,LOW);
    digitalWrite(FILLING,HIGH);
    Serial.println("Pump on");
  }
  else if(distance<8 && pinstatus==0){
    digitalWrite(PUMP_ON,HIGH);
    digitalWrite(FILLING,LOW);
    Serial.println("Pump off");
  }
  
}

