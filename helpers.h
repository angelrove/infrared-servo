#include <Servo.h>
Servo ioe;

int pTrigger;
int pEcho;
int MAX_DISTANCE;

int servoClose;
int servoOpen;

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

void initServo(int pServo, int servClose, int servOpen)
{
    // Init
    servoClose = servClose;
    servoOpen = servOpen;

    // Attach servo
    ioe.attach(pServo);

    // Test servo
    // ioe.write(180);
    // delay(1000);
    ioe.write(90);
    delay(1000);

    // Init
    ioe.write(servoClose);
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

void servoMove(long dist)
{
    if (dist > 1 && dist < MAX_DISTANCE)
    {
        Serial.println(dist);

        digitalWrite(LED_BUILTIN, HIGH);
        ioe.write(servoOpen);
        delay(1000);
        ioe.write(servoClose);
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
