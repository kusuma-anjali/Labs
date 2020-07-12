#include<SoftwareSerial.h>
SoftwareSerial cell(2,3);
int redled = 4;
int greenled = 5;
int blueled = 6;

void readfn()
{
    if(cell.available())
    {
      while(cell.available())
      {
        Serial.write(cell.read());
       }
    }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  cell.begin(9600);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  cell.println("AT");
  delay(1000);
  //cell.print("AT+CMGS=\"+918660106432\"r");
  //delay(1000);
  //cell.print("hi");
  //delay(1000);
  readfn();
  cell.print("AT+CNMI = 2,2,0,0,0");
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(cell.available())
  {
     String msg = cell.readString();
     Serial.println(msg);
     if(msg.indexOf("RED")>0)
     {
        digitalWrite(4,HIGH);
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);
     }
     else if(msg.indexOf("GREEN")>0)
     {
        digitalWrite(4,LOW);
        digitalWrite(5,HIGH);
        digitalWrite(6,LOW);
     }
     else if(msg.indexOf("BLUE")>0)
     {
        digitalWrite(4,LOW);
        digitalWrite(5,LOW);
        digitalWrite(6,HIGH);
     }
     else
     {
        Serial.println("nothing to do");
     }
     
  }
}
