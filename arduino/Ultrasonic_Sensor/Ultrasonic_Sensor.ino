#define tp 3
#define ep 2
void setup()
{
  Serial.begin(9600);
  pinMode(tp,OUTPUT);
  pinMode(ep, INPUT);
}
void loop()
{
  int time;
  float dist;
  digitalWrite(tp,HIGH);
  delayMicroseconds(1000);
  digitalWrite(tp,LOW);
  time = pulseIn(ep,HIGH);
  dist = (time/2)/29.1;
  
  Serial.print(dist);
  Serial.println("m");
  delay(500);
}
  
