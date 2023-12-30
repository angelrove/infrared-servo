int pButton = 0;
bool buttonOn = false;
bool buttonOnPrev = false;

void initButton(int pin)
{
    pButton = pin;
    pinMode(pButton, INPUT_PULLUP);
}

// Is button pressed?
bool isButtonOn()
{
    bool button = digitalRead(pButton);
    if (button == LOW && buttonOnPrev == HIGH)
    {
        buttonOn = !buttonOn; // flip state
    }
    buttonOnPrev = button;

    // Serial.println("Button: " + String(button) + " / " + String(buttonOn));
    return buttonOn;
}
