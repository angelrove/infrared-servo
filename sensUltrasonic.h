#include <Servo.h>
Servo ioe;

// Ultrasonic
int pTrigger;
int pEcho;
int MAX_DISTANCE;
bool ultrasonicStarted = true;

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

void ultrasonicStart()
{
    ultrasonicStarted = true;
}

void ultrasonicStop()
{
    ultrasonicStarted = false;
}

long ultrasinicPing()
{
    if (!ultrasonicStarted)
    {
        return -1;
    }

    digitalWrite(pTrigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(pTrigger, LOW);
    long duration = pulseIn(pEcho, HIGH);

    // return microsecondsToCentimeters(duration);
    return duration / 29 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
    // The speed of sound is 340 m/s or 29 microseconds per centimeter.
    // The ping travels out and back, so to find the distance of the object we
    // take half of the distance travelled.
    return microseconds / 29 / 2;
}
