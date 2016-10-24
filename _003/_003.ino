const int inputPin1 = 4;         // input pin for the switch
const int inputPin2 = 5;         // input pin for the switch
const int ledPin = 13;
const int ledPin1 = 11;          // output pin for the LED
const int ledPin2 = 12;          // output pin for the LED

unsigned int brightness = 120;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(inputPin1, INPUT);
  pinMode(inputPin2, INPUT);
  digitalWrite(inputPin1, HIGH);
  digitalWrite(inputPin2, HIGH);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  int val1 = digitalRead(inputPin1);  // read input value
  Serial.println(val1);
  if (val1 == LOW)                  // check if the input is HIGH
  {
    digitalWrite(ledPin1, HIGH);     // turn LED ON
    if (brightness < 255)
      brightness ++;
  }
  else
    digitalWrite(ledPin1, LOW);
  int val2 = digitalRead(inputPin2);
  if (val2 == LOW)
  {
    if (brightness > 0)
      brightness --;
    digitalWrite(ledPin2, HIGH);      // turn LED OFF
  }
  else
    digitalWrite(ledPin2, LOW);
  analogWrite(ledPin, brightness);
  delay(5);
}

