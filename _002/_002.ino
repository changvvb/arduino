int LEDs[] = {4, 5, 6, 7};
char buffer[32];
char inByte;
int pos = 0;
char dir = 1;  //0:1
char i = 0;
char temp_led;
void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 4; i++)
  {
    pinMode(LEDs[i], OUTPUT);
  }
  Serial.begin(9600);
}



void loop() {
  digitalWrite(LEDs[temp_led], LOW);
  if (dir)
  {
    if (4 == i)
      i = 0;
    temp_led = i;
    digitalWrite(LEDs[i++], HIGH);
  }
  else
  {
    if (-1 == i)
      i = 3;
    temp_led = i;
    digitalWrite(LEDs[i--], HIGH);
  }

  if (Serial.available() > 0) {
    // read the incoming byte:
    inByte = Serial.read();

    if (inByte == '\r' || inByte == '\n')
    {
      buffer[pos] = '\0';
      Serial.println(buffer);
      pos = 0;

      int num = atoi(buffer);
      if (0 == num )
        dir = 0;
      else
        dir = 1;
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
  delay(200);

}
