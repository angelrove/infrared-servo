int servoCloseAngle;
int servoOpenAngle;
int servoOpenTime;

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

void servoOpen()
{
    digitalWrite(LED_BUILTIN, HIGH);
    ioe.write(servoOpenAngle);
    delay(servoOpenTime);
    ioe.write(servoCloseAngle);
    delay(2000);
    digitalWrite(LED_BUILTIN, LOW);
}
