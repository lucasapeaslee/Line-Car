#include <QTRSensors.h>

QTRSensors qtr;

const uint8_t SensorCount = 8;
uint16_t sensorValues[SensorCount];

void setup() {
  qtr.setTypeRC();
  qtr.setSensorPins((const uint8_t[]){3,4,5,6,7,8,9,10}, SensorCount);

  Serial.begin(9600);
  delay(1000);

  Serial.println("Calibrating, move sensor over and out of line");
  digitalWrite(LED_BUILTIN,HIGH);

  for (uint16_t i = 0; i < 400; i++)
  {
    qtr.calibrate();
  }
  
  digitalWrite(LED_BUILTIN, LOW); // Turn off LED
  Serial.println("Calibration Complete.");
}

void loop() {
  // 3500 is center
  uint16_t position = qtr.readLineBlack(sensorValues);
  Serial.println(position);
  delay(250);
}
