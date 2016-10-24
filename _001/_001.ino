const int ledPin = 13;
char inByte = 0;
char buffer[32];
int pos = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void contralLED(char *str) {
  int num = atoi(str);
  Serial.print("num ");
  Serial.println(num);
  //digitalWrite(ledPin,HIGH);
  analogWrite(ledPin, num);
}

void loop() {
  if (Serial.available() > 0) {
    // read the incoming byte:
    inByte = Serial.read();
    if (inByte == '\r' || inByte == '\n')
    {
      buffer[pos] = '\0';
      Serial.println(buffer);
      pos = 0;
      contralLED(buffer);
    }
    else
    {
      if (pos < 31)
        buffer[pos++] = inByte;
      else
        buffer[pos] = '\0';
    }
    // say what you got:
  }
  delay(5);
  // put your main code here, to run repeatedly:

}
