int Col[] = {4, 5, 6, 7};
int Row[] = {8, 9, 10, 11};
char key[4][4] =
{
  {'+', '3', '2', '1'},
  {'-', '6', '5', '4'},
  {'*', '9', '8', '7'},
  {'/', '=', '0', 'C'}
};
void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 4; i++)
  {
    pinMode(Col[i], OUTPUT);
    pinMode(Row[i], INPUT);
    digitalWrite(Col[i], HIGH);
    digitalWrite(Row[i], HIGH);
  }
  Serial.begin(9600);
}

void calculate(char c)
{
  static int count = 0;
  static int pos = 0;
  static int num1;
  static int num2;
  static char num[8];
  static char operate;

  if (c >= '0' && c <= '9')
  {
    num[pos++] = c;
    return;
  }
  switch (c)
  {
    case '+':
    case '-':
    case '*':
    case '/':
      operate = c;
      num[pos] = '\0';
      pos = 0;
      if (count == 0)
        num1 = atoi(num);
      break;
    case '=':
      num[pos] = '\0';
      num2 = atoi(num);

      switch (operate)
      {
        case '+':
          Serial.println(num1 + num2);
          break;
        case '-':
          Serial.println(num1 - num2);
          break;
        case '*':
          Serial.println(num1 * num2);
          break;
        case '/':
          Serial.println((float)num1 / (float)num2);
          break;
      }
      Serial.println();
      pos = 0;
      count = 0;
      break;
    case 'C':
      pos = 0;
      count = 0;
      num1 = 0;
      num2 = 0;
      Serial.println();
      break;
    default: break;
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 4; i++)
  {
    digitalWrite(Col[i], LOW);
    for (int j = 0; j < 4; j++)
    {
      if (digitalRead(Row[j]) == LOW)
      {
        Serial.print(key[j][i]);
        calculate(key[j][i]);
        while (digitalRead(Row[j]) == LOW)
          delay(5);
      }
    }
    digitalWrite(Col[i], HIGH);
  }


}
