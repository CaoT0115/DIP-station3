#include  <IRremote.h>

IRsend irsend; 


void setup()
{
  pinMode(3,OUTPUT);
  pinMode(8,INPUT);
  Serial.begin(9600);
} 

void loop() 
{
  if(digitalRead(8)==0){
     ircodeSEND(); 
     digitalWrite(13,HIGH);
     delay(500);
     digitalWrite(13,LOW);
  }
}

void ircodeSEND()
{
  irsend.sendNEC(0x806F00FF, 32); // channel 0  红外发射码前需要加上“0x”
  delay(1000);
} 
