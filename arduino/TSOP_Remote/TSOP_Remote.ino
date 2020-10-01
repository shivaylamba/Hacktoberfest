#include <IRremote.h>
int a=9;
int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;


void setup()
{
  Serial.begin(9600);
  pinMode(9,OUTPUT);
    pinMode(13,OUTPUT); //Light
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    if(results.value==0xD725717||results.value==0x9FDF580C)
 {
   digitalWrite(a,1);
   delay(2000);
 }   
 else if(results.value==0x6D5D1DB3||results.value==0x6322900E)
 {
   digitalWrite(a,0);
 }
else if(results.value==0xB10C7C8B||results.value==0xC796DFC)
{
digitalWrite(13,HIGH);

 }
 else if(results.value==0x10921B67||results.value==0xDB510F56)
  {
    digitalWrite(13,LOW);
    }  irrecv.resume(); // Receive the next value
  }
}
