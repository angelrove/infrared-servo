int pButton = 0;
int buttonOn = false;

void initButton(int pin)
{
    pButton = pin;
    pinMode(pButton, INPUT_PULLUP);
}

bool loadButtonOn()
{
    if (digitalRead(pButton) == LOW)
    {
        if (buttonOn == false)
        {
            buttonOn = true;
        }
        else
        {
            buttonOn = false;
        }
    }

    return buttonOn;
}
