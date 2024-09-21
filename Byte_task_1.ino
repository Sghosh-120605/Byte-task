const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;
const int buttonPin = 2;

int buttonState = 0;
int lastButtonState = 0;
int lightState = 0;

void setup() {

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);


  pinMode(buttonPin, INPUT);
}

void loop() {

  buttonState = digitalRead(buttonPin);


  if (buttonState == HIGH && lastButtonState == LOW) {
    lightState++;

    if (lightState > 2) {
      lightState = 0;
    }

    if (lightState == 1) {
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, LOW);
    } else if (lightState == 2) {
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, HIGH);
      digitalWrite(bluePin, LOW);
    } else if (lightState == 0) {
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, HIGH);
    }

    delay(50);
  }

  lastButtonState = buttonState;
}