#include<Servo.h>
Servo s;
#define A 2
volatile int count=0;
void setup()
{
  
  Serial.begin(9600);
  pinMode(A,INPUT_PULLUP);
  pinMode(8,OUTPUT);
  pinMode(5,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2),fun,RISING);
  s.attach(6);
  s.write(90);
}
volatile int d;
void fun()
{
  count++;
}

void loop()
{
  
  if(Serial.available())
  {
    d=Serial.parseInt();
    count=0; 
     s.write(0);
     delay(1000);  
  }
 // noInterrupts();
  
  if(count>abs(d-20)) 
  {
    s.write(45);   
  }
  if(count<=(d-2))
  {
        digitalWrite(8,LOW);
        analogWrite(5,255);
  }
  else
  { 
 // Serial.println(count);  
        analogWrite(5,0);
  } 
  //interrupts();
}
