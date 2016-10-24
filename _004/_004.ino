const int inputPin = 4;         // input pin for the switch
const int ledPin = 13;
const int ledPin1 = 11;          // output pin for the LED
int dir = 0; // 0: -- ,   1: ++
unsigned int brightness = 120;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin1, OUTPUT);
  pinMode(inputPin, INPUT);
  digitalWrite(inputPin, HIGH);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  int val1 = digitalRead(inputPin);  // read input value
  Serial.println(val1);
  if (val1 == LOW)                  // check if the input is HIGH
  {
    digitalWrite(ledPin1, HIGH);     // turn LED ON
    if (dir)
      if (brightness < 255)
        brightness ++;
      else if (brightness > 0)
        brightness --;
  }
  else
  {
    digitalWrite(ledPin1, LOW);
  }
  analogWrite(ledPin, brightness);
  delay(5);
}

