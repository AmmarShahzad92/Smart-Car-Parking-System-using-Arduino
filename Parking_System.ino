int trig = 8;
int echo = 9;
int Red = 5;
int Yellow = 6;
int Green = 7;
int distance;
long duration;

void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(Red, OUTPUT);
  pinMode(Yellow, OUTPUT);
  pinMode(Green, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 /2;

  Serial.print("Distance : ");
  Serial.println(distance);

  if (distance > 50)
  {
    digitalWrite(Red, LOW);
    digitalWrite(Yellow, LOW);
    digitalWrite(Green, HIGH);
  }
  else if (distance > 25 && distance < 50)
  {
    digitalWrite(Red, LOW);
    digitalWrite(Yellow, HIGH);
    digitalWrite(Green, LOW);
  }
  else if (distance < 25)
  {
    digitalWrite(Red, HIGH);
    digitalWrite(Yellow, LOW);
    digitalWrite(Green, LOW);
  }
}
