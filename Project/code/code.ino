const int trig = 12;
const int echo = 13;

const int buzzer = 8;
const int LED1 = 2;  // Long distance
const int LED2 = 3;  // Medium distance
const int LED3 = 6;  // Very close distance

int duration = 0;
int distance = 0;

void setup() 
{
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
  
  pinMode(buzzer, OUTPUT);
  pinMode(LED1 , OUTPUT);
  pinMode(LED2 , OUTPUT);
  pinMode(LED3 , OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trig , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig , LOW);

  duration = pulseIn(echo , HIGH);
  distance = (duration / 2) / 28.5;
  Serial.println(distance);

  if (distance <= 10)
  {
    digitalWrite(LED3, HIGH);
    digitalWrite(buzzer, HIGH);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
  }
  else if (distance > 10 && distance <= 15)
  {
    digitalWrite(LED2, HIGH);
    digitalWrite(LED1, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(buzzer, LOW);
  }
  else
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(buzzer, LOW);
  }
}