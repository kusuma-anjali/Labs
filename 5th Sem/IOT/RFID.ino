#include<SoftwareSerial.h>
SoftwareSerial mySerial(2,3);
int green = 10;
int red = 9;
int count=0;
char input[12];
char check[12]={'3', 'C','0','0','8','9','B','9','D','3','D','F'};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(green,OUTPUT);
  pinMode(red,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  boolean flag=0;
  if(mySerial.available())
  {
    count=0;
    while(mySerial.available() && count<12)
 
    {
        input[count]=mySerial.read();
        count++;
        delay(5);
    }
    Serial.println(input);

    for(int i=0;i<12;i++)
    {
      if(input[i]!=check[i])
      {
        flag=1;
        break;        
      }
    }
    if(flag==1)
    {
      digitalWrite(red,HIGH);
      Serial.println("Access Denied");
      digitalWrite(green,LOW);
    }
    else
    {
      digitalWrite(green,HIGH);
      Serial.println("Access Granted");
      digitalWrite(red,LOW);
    }
    delay(1000);
  }
    
  

}
