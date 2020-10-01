String voice;
int en1=11;
int en2=12;
int m11=2;
int m12=3;
int m21=4;
int m22=5;
void front(void);
void back(void);
void right(void);
void left(void);
void freeze(void);
void setup()
{
  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  digitalWrite(en1, HIGH);
  digitalWrite(en2, HIGH);
  digitalWrite(m11, LOW);
  digitalWrite(m12, LOW);
  digitalWrite(m21, LOW);
  digitalWrite(m22, LOW);
  Serial.begin(9600);
}
void loop()
{

  while(Serial.available())
  {
    delay(10);
    char c=Serial.read();
    if(c=='#')
    break;
    voice+=c;
  }
  
while(voice.length()>0)
{
  Serial.println(voice);
  if(voice=="*go")
  front();
  else if(voice=="*back")
  {
    Serial.print("BACK");
    
  back();
  }
  else if(voice=="*right")
  {
  right();
  }
  else if(voice=="*left")
  {
  left();
  }
  else
  freeze();
voice="";  
}

}  
  
  
  void front(void)
{
  digitalWrite(m11,HIGH);
  digitalWrite(m12,LOW);
  digitalWrite(m21,HIGH);
  digitalWrite(m22,LOW);
}
void back(void)
{
  digitalWrite(m11,LOW);
  digitalWrite(m12,HIGH);
  digitalWrite(m21,LOW);
  digitalWrite(m22,HIGH);
}
void right(void)
{
  digitalWrite(m11,LOW);
  digitalWrite(m12,HIGH);
  digitalWrite(m21,HIGH);
  digitalWrite(m22,LOW);
}

void left(void)
{
  digitalWrite(m11,HIGH);
  digitalWrite(m12,LOW);
  digitalWrite(m21,LOW);
  digitalWrite(m22,HIGH);
}

void freeze(void)
{
  digitalWrite(m11,LOW);
  digitalWrite(m12,LOW);
  digitalWrite(m21,LOW);
  digitalWrite(m22,LOW);
}
  

