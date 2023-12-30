#include "sensUltrasonic.h"
#include "actServo.h"
#include "Button.h"

// Ultrasonic
#define pTrigger 4
#define pEcho 7
#define MAX_DISTANCE 16

// Servo
#define pServo 9
#define servoCloseAngle 180
#define servoOpenAngle 90
#define servoOpenTime 400

// Button
#define pButton 10
#define ledButton 12

void setup()
{
  Serial.begin(9600);
  initButton(pButton);
  initUltrasonic(pTrigger, pEcho, MAX_DISTANCE);
  initServo(pServo, servoCloseAngle, servoOpenAngle, servoOpenTime);
}

void loop()
{
  // Load button
  bool buttonOn = loadButtonOn();
  Serial.println(buttonOn);

  if (buttonOn == true)
  {
    digitalWrite(ledButton, HIGH);
    ultrasonicStart();
  }
  else
  {
    digitalWrite(ledButton, LOW);
    ultrasonicStop();
  }

  // Ultrasonic (ping)
  long distance = ultrasinicPing();

  // Servo (open)
  if (distance > 1 && distance < MAX_DISTANCE)
  {
    servoOpen();
  }

  delay(200);
}
