#define pirPin 3
int calibrationTime = 30;
long unsigned int lowIn;
long unsigned int pause = 5000;
boolean lockLow = true;
boolean takeLowTime;
int PIRValue = 0;
int ledPin=12;

void setup() {
   Serial.begin(9600);
   pinMode(pirPin, INPUT);
   Serial.print("calibrating sensor");
    for(int i=0;i<calibrationTime;i++)
    {
      Serial.print(".");
      delay(1000);
      
    }
     Serial.println("DONE");
     Serial.println("sensor active");
     delay(50);
}

void loop() {
   PIRSensor();
}

void PIRSensor() {
   if(digitalRead(pirPin) == HIGH) {
      if(lockLow) {
         digitalWrite(ledPin,HIGH);
         PIRValue = 1;
         lockLow = false;
         Serial.print("Motion detected at:");
         Serial.print(millis()/1000);
         Serial.println("sec");
         delay(50);
      }
      takeLowTime = true;
   }
   if(digitalRead(pirPin) == LOW) {
    digitalWrite(ledPin,LOW);
      if(takeLowTime){
         lowIn = millis();
         takeLowTime = false;
      }
      if(!lockLow && millis() - lowIn > pause) {
          PIRValue = 0;
         lockLow = true;
         Serial.print("Motion ended at: ");
         Serial.print((millis()-pause)/1000);
         Serial.println("sec");
         
         delay(50);
      }
   }
}
