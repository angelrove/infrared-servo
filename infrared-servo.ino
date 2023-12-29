#include "helpers.h"

#define pTrigger 4
#define pEcho 7
#define MAX_DISTANCE 12

#define pServo 9
#define servoClose 0
#define servoOpen 90
#define servoOpenTime 500

void setup()
{
  Serial.begin(9600);
  Serial.println("Starting...");

  // Init led
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  // Init sensor
  initUltrasonic(pTrigger, pEcho, MAX_DISTANCE);

  // Init servo
  initServo(pServo, servoClose, servoOpen, servoOpenTime);
}

void loop()
{
  long distance = ultrasinicPing();
  servoOpen(distance);
  delay(200);
}
