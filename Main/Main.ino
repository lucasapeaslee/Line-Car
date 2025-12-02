// AUTHOR: Lucas Peaslee
// No AI was used in the making of this program. Call me old fasioned.
#include <QTRSensors.h>

#define MOTORA1 2
#define MOTORA2 3
#define MOTORB1 4
#define MOTORB2 5
#define COLORS2 6
#define COLORS3 7
#define COLOROUT 8

QTRSensors qtr;
const uint8_t qtrCount = 4;
uint16_t qtrValue[qtrCount];

void setup() {
  // Here we go...
  pinMode(MOTORA1,OUTPUT);
  pinMode(MOTORA2,OUTPUT);
  pinMode(MOTORB1,OUTPUT);
  pinMode(MOTORB2,OUTPUT);
  pinMode(COLORS2,OUTPUT);
  pinMode(COLORS3,OUTPUT);
  pinMode(COLOROUT,INPUT);

  digitalWrite(MOTORA1,LOW);
  digitalWrite(MOTORA2,LOW);
  digitalWrite(MOTORB1,LOW);
  digitalWrite(MOTORB2,LOW);
  digitalWrite(COLORS2,LOW);
  digitalWrite(COLORS3,LOW);

  qtr.setTypeRC();
  qtr.setSensorPins((const uint8_t[]){9,10,11,12}, qtrCount);

  Serial.begin(9600); // Finally, holy shit.
  delay(500);
  
  // QTR Sensor Calibration
  Serial.println("Calibrating, roll car onto and away from the black line.");
  digitalWrite(LED_BUILTIN,HIGH);

  for (uint16_t i = 0; i < 400; i++)
  {
    qtr.calibrate();
  }
  
  digitalWrite(LED_BUILTIN,LOW);
  Serial.println("Calibration Complete.");
}

void loop() {
  // put your main code here, to run repeatedly:

}
