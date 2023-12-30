#include "sensUltrasonic.h"
#include "actServo.h"

// Ultrasonic
#define pTrigger 4
#define pEcho 7
#define MAX_DISTANCE 16

// Servo
#define pServo 9
#define servoCloseAngle 180
#define servoOpenAngle 90
#define servoOpenTime 400

void setup()
{
  Serial.begin(9600);
  Serial.println("Starting...");

  // Init led
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  // Init sensor
  initUltrasonic(pTrigger, pEcho, MAX_DISTANCE);
  // ultrasonicStart();

  // Init servo
  initServo(pServo, servoCloseAngle, servoOpenAngle, servoOpenTime);
}

void loop()
{
  long distance = ultrasinicPing();
  Serial.println(distance);

  if (distance > 1 && distance < MAX_DISTANCE)
  {
    servoOpen();
  }

  delay(200);
}
