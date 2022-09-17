#include <IRremote.h>
#include<Servo.h>
int red=9;
int green=13;
int blue=10;
int RECV_PIN = 11;
Servo irservo;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  irservo.attach(8);
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(green,OUTPUT);
  irservo.write(90);

  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
   
    if(results.value==0xFD08F7)
    {
      digitalWrite(red,HIGH);
      digitalWrite(green,LOW);
      digitalWrite(blue,LOW);
      irservo.write(15);

    }
       else if(results.value==0xFD48B7)
       {
      digitalWrite(red,LOW);
      digitalWrite(green,LOW);
      digitalWrite(blue,HIGH);
      irservo.write(30);

    }
       else if(results.value==0xFD8877)
       {
      digitalWrite(red,LOW);
      digitalWrite(green,HIGH);
      digitalWrite(blue,LOW);
      irservo.write(45);

    }
    else if(results.value==0xFD28D7)
       {
      digitalWrite(red,HIGH);
      digitalWrite(green,HIGH);
      digitalWrite(blue,LOW);
      irservo.write(60);
    }
    else if(results.value==0xFDA857)
       {
      digitalWrite(red,HIGH);
      digitalWrite(green,LOW);
      digitalWrite(blue,HIGH);
            irservo.write(75);

    }
    else if(results.value==0xFD6897)
       {
      digitalWrite(red,LOW);
      digitalWrite(green,HIGH);
      digitalWrite(blue,HIGH);
            irservo.write(90);

    }
   else if(results.value==0xFD30CF)
       {
      digitalWrite(red,HIGH);
      digitalWrite(green,HIGH);
      digitalWrite(blue,HIGH);
      irservo.write(105);

    }
  }
 
  delay(100);
}