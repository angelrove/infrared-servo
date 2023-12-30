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

// Button
#define pButton 10
bool buttonOn = false;
#define ledButton 12

void setup()
{
  Serial.begin(9600);
  Serial.println("Starting...");

  // Button
  pinMode(pButton, INPUT_PULLUP);

  // Init sensor
  initUltrasonic(pTrigger, pEcho, MAX_DISTANCE);

  // Init servo
  initServo(pServo, servoCloseAngle, servoOpenAngle, servoOpenTime);
}

void loop()
{
  // Button
  parseButton();

  // Ultrasonic (ping)
  long distance = ultrasinicPing();
  // Serial.println(distance);

  // Servo (open)
  if (distance > 1 && distance < MAX_DISTANCE)
  {
    servoOpen();
  }

  delay(200);
}

void parseButton()
{
  Serial.println(digitalRead(pButton));
  if (digitalRead(pButton) == LOW)
  {
    if (!buttonOn)
    {
      // Serial.println("Button On");
      buttonOn = true;
      digitalWrite(ledButton, HIGH);
      ultrasonicStart();
    }
    else
    {
      // Serial.println("Button Off");
      buttonOn = false;
      digitalWrite(ledButton, LOW);
      ultrasonicStop();
    }
  }
}