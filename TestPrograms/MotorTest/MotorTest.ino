#define motorA1 2
#define motorA2 3
#define motorB1 4
#define motorB2 5

// NOTE, OUT1 & OUT4 go to front motor pins, OUT2 & OUT3 vice versa

void setup() {
  pinMode(motorA1,OUTPUT);
  pinMode(motorA2,OUTPUT);
  pinMode(motorB1,OUTPUT);
  pinMode(motorB2,OUTPUT);

  digitalWrite(motorA1,LOW);
  digitalWrite(motorA2,HIGH);
  digitalWrite(motorB1,HIGH);
  digitalWrite(motorB2,LOW);
}

void loop() {

}
