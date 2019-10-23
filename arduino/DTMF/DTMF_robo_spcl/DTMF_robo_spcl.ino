int idist=4;
int ldist;
const int t=A2;
const int tp=A3;
const int ep=A4;
const int e1=7;
const int e2=8;
const int a1=6;
const int a2=9;
const int b1=10;
const int b2=11;
const int StD=0;
const int Q[4]={2,3,4,5};
int h=255;
int l=0;
int key;
void us();
void lt();
void rt();
void front();
void bt();
void temp();
void st();

void setup()
{
  pinMode(A3,OUTPUT);
  pinMode(A4,INPUT);
  pinMode(a1,OUTPUT);
  pinMode(a2,OUTPUT);
  pinMode(b1,OUTPUT);
  pinMode(b2,OUTPUT);
  pinMode(e1,OUTPUT);
  pinMode(e2,OUTPUT);
digitalWrite(e1,HIGH);
digitalWrite(e2,HIGH);
 Serial.begin(9600);
 attachInterrupt(StD,dtmf,RISING);
  for(int i=0;i<4;i++)
 {
  pinMode(Q[i],INPUT);
 }
}

void dtmf()
{
  key=0;
  for(int i=0;i<4;i++)
  key+=digitalRead(Q[i])<<i;
  
}
void loop()
{
   dtmf();
  
  if(key==2)
  {
//   us();
 
  front();
  }
  
  else if(key==4)
  {
  //  us();
    lt();
  }
  else if(key==6)
 {
  //us();
  rt();
 }
 else if(key==8)
{
//us();
  bt();
}
  else
{
 //us();
  st();
}
  //temp();


}
 void temp()
 {
  
int x=analogRead(t);
if(x>90)
bt();
 }
  void front()
  {
    analogWrite(a1,h);
    analogWrite(a2,l);
    analogWrite(b1,h);
    analogWrite(b2,l);
  
  }
  void lt()
  {
     analogWrite(a1,l);
      analogWrite(a2,h);
      analogWrite(b1,h);
       analogWrite(b2,l);
       delay(500);
       st();
  }
  void rt()
  {
    analogWrite(a1,h);
     analogWrite(a2,l);
  analogWrite(b1,l);
     analogWrite(b2,h); 
     delay(500);
     st();
  }
  void bt()
  {
    analogWrite(a1,l);
     analogWrite(a2,h);
      analogWrite(b1,l);
       analogWrite(b2,h);
  }
  void st()
  
  {
    analogWrite(a1,l);
     analogWrite(a2,l);
      analogWrite(b1,l);
       analogWrite(b2,l);
  }
 void us()
 {
   analogWrite(tp,h);
   delay(10);
   analogWrite(tp,l);
   int distance=pulseIn(ep,HIGH);
 distance=distance/58;
 if(distance<idist)
 {
   while(distance==idist)
   h=250;
 }
  
 else if(distance>idist)
 {
 while(distance==idist)
 h=115;
 }
 else
 h=180;
 }
