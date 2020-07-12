#include<Servo.h>
Servo s;
int input = A0;
int output = 9;

void setup()
{
  pinMode(A0,INPUT);
  pinMode(9,OUTPUT);
  s.attach(output);
  Serial.begin(9600);
}

void loop()
{
  int value = analogRead(input);
  Serial.println(value);
  delay(30);
  int threshold = 500;
  for(int i=0;i<180;i++)
  {
    s.write(i);
    delay(30);
  }
  for(int i=180;i>0;i--)
  {
    s.write(i);
    delay(30);
  }
}
