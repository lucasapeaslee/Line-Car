// Author: Lucas Peaslee
// No AI was used in the making of this code... That wouldn't take much effort now would it?

#define motor 2
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8
#define rLED 11
#define gLED 12
#define bLED 13

int red= 0;
int green = 0;
int blue = 0;


void setup() {
  pinMode(motor,OUTPUT);

  pinMode(S0,OUTPUT);
  pinMode(S1,OUTPUT);
  pinMode(S2,OUTPUT);
  pinMode(S3,OUTPUT);

  pinMode(rLED,OUTPUT);
  pinMode(gLED,OUTPUT);
  pinMode(bLED,OUTPUT);

  pinMode(sensorOut, INPUT);

  digitalWrite(motor,LOW);

  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);

  digitalWrite(rLED,LOW);
  digitalWrite(gLED,LOW);
  digitalWrite(bLED,LOW);

  Serial.begin(9600);
}

void setRGB(String color) {
  digitalWrite(rLED,LOW);
  digitalWrite(gLED,LOW);
  digitalWrite(bLED,LOW);

  if (color == "red"){
    digitalWrite(rLED,HIGH);
    digitalWrite(motor,LOW);
  }
  else if (color == "green"){
    digitalWrite(gLED,HIGH);
    digitalWrite(motor,HIGH);
  }
  else if (color == "blue"){
    digitalWrite(bLED,HIGH);
    digitalWrite(motor,HIGH);
  }
  else{
    digitalWrite(rLED,HIGH);
    digitalWrite(gLED,HIGH);
    digitalWrite(bLED,HIGH);
    digitalWrite(motor,HIGH);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);

  red = pulseIn(sensorOut, LOW);
  delay(100);

  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);

  green = pulseIn(sensorOut, LOW);
  delay(100);

  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);

  blue = pulseIn(sensorOut, LOW);
  delay(100);
  
  if ((red < green) && (red < blue)) {
    Serial.println("Mostly Red!");
    setRGB("red");
  }
  else if ((green < red) && (green < blue)){
    Serial.println("Mostly Green!");
    setRGB("green");
  }
  else if ((blue < red) && (blue < green)){
    Serial.println("Mostly Blue!");
    setRGB("blue");
  }
  else {
    Serial.println("Idk man");
    setRGB("white");
  }
}