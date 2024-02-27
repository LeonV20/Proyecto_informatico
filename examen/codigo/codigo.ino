#define ld1 2
#define ld2 3
#define bottom 4
#define buzzer 7
#define tmp A0
int temperatura;
void setup()
{
  pinMode(bottom, INPUT_PULLUP);
  pinMode(ld1, OUTPUT);
  pinMode(ld2, OUTPUT);
  pinMode(tmp, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop()
{  
    temperatura = analogRead(tmp)*0.48828125;
  
  if (temperatura >= 30)
{
  digitalWrite(ld1, HIGH);
  digitalWrite(ld2, LOW);
  
}
else if (temperatura <= 15)
{
digitalWrite(ld1, LOW);
digitalWrite(ld2, HIGH);
}  
else 
  {
  digitalWrite(ld1, LOW);
  digitalWrite(ld2, LOW);
  
  }
if (temperatura > 30 && digitalRead(bottom) == LOW) 
{
  tone (buzzer, 1000);
}
else 
{
 noTone(buzzer);
}
  delay(1000);
}
