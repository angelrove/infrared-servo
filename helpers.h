#include <Servo.h>
Servo ioe;

int pTrigger;
int pEcho;
int MAX_DISTANCE;

int servoCloseAngle;
int servoOpenAngle;
int servoOpenTime;

// Init -----------------------------------------
void initUltrasonic(int trigger, int echo, int maxDistance)
{
    pTrigger = trigger;
    pEcho = echo;
    MAX_DISTANCE = maxDistance;

    pinMode(pTrigger, OUTPUT);
    pinMode(pEcho, INPUT);
    digitalWrite(pTrigger, LOW);
}

void initServo(int pServo, int servClose, int servOpen, int servOpenTime)
{
    // Init
    servoCloseAngle = servClose;
    servoOpenAngle = servOpen;
    servoOpenTime = servOpenTime;

    // Attach servo
    ioe.attach(pServo);

    // Test servo
    ioe.write(servoOpenAngle);
    delay(1000);

    // Init
    ioe.write(servoCloseAngle);
    delay(100);
}

// Helpers ---------------------------------------
long ultrasinicPing()
{
    digitalWrite(pTrigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(pTrigger, LOW);
    long duration = pulseIn(pEcho, HIGH);

    // return microsecondsToCentimeters(duration);
    return duration / 29 / 2;
}

void servoOpen(long dist)
{
    if (dist > 1 && dist < MAX_DISTANCE)
    {
        Serial.println(dist);

        digitalWrite(LED_BUILTIN, HIGH);
        ioe.write(servoOpenAngle);
        delay(servoOpenTime);
        ioe.write(servoCloseAngle);
        delay(2000);
        digitalWrite(LED_BUILTIN, LOW);
    }
}

long microsecondsToCentimeters(long microseconds)
{
    // The speed of sound is 340 m/s or 29 microseconds per centimeter.
    // The ping travels out and back, so to find the distance of the object we
    // take half of the distance travelled.
    return microseconds / 29 / 2;
}
