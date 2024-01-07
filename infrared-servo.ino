#include "sensUltrasonic.h"
#include "actServo.h"
#include "ToggleButton.h"

// Ultrasonic
#define pTrigger 4
#define pEcho 7
#define MAX_DISTANCE 16

// Servo
#define pServo 9
#define servoCloseAngle 180
#define servoOpenAngle 70
#define servoOpenTime 900

// Button
#define pButton 10
#define ledButton 12

void setup()
{
  // Serial.begin(9600);
  // pinMode(ledButton, OUTPUT);

  initButton(pButton);
  initUltrasonic(pTrigger, pEcho, MAX_DISTANCE);
  initServo(pServo, servoCloseAngle, servoOpenAngle, servoOpenTime);
}

void loop()
{
  // Load stop button
  if (isButtonOn() == true)
  {
    digitalWrite(ledButton, HIGH);
  }
  else
  {
    digitalWrite(ledButton, LOW);
    delay(200);
    return;
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
