#include "helpers.h"

// Ultrasonic
#define pTrigger 4
#define pEcho 7
#define MAX_DISTANCE 16

// Servo
#define pServo 9
#define servoCloseAngle 180
#define servoOpenAngle 90
#define servoOpenTime 300

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
  initServo(pServo, servoCloseAngle, servoOpenAngle, servoOpenTime);
}

void loop()
{
  long distance = ultrasinicPing();
  servoOpen(distance);
  delay(200);
}
