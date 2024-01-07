int servoCloseAngle;
int servoOpenAngle;
int servoOpenTime;
#define ledPin 13

void initServo(int pServo, int servClose, int servOpen, int servOpenTime)
{
    // Init
    servoCloseAngle = servClose;
    servoOpenAngle = servOpen;
    servoOpenTime = servOpenTime;

    // Init LED
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);

    // Attach servo
    ioe.attach(pServo);

    // Test servo
    // ioe.write(servoOpenAngle);
    // delay(1000);

    // Init
    ioe.write(servoCloseAngle);
    delay(100);
}

void servoOpen()
{
    digitalWrite(ledPin, HIGH);

    ioe.write(servoOpenAngle);
    delay(servoOpenTime);
    ioe.write(servoCloseAngle);
    delay(2000);

    digitalWrite(ledPin, LOW);
}
