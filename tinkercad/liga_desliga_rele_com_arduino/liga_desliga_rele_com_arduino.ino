const int RELE = 7;

void setup()
{
  pinMode(RELE, OUTPUT);
}

void loop()
{
  digitalWrite(RELE, HIGH);
  delay(1000);
  digitalWrite(RELE, LOW);
  delay(4000);
}