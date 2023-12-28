#include "helpers.h"

#define pTrigger 4
#define pEcho 7
#define pServo 9
#define MAX_DISTANCE 12

void setup()
{
  Serial.begin(9600);
  Serial.println("Starting...");

  // Init led
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  // Init sensors
  initUltrasonic(pTrigger, pEcho, MAX_DISTANCE);
  initServo(pServo);
}

void loop()
{
  long distance = ultrasinicPing();
  servoMove(distance);
  delay(200);
}
