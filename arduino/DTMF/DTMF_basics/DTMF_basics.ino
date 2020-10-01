const int StD=0;
const int Q[4]={8,9,10,11};
int key;
int led=13;
void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  attachInterrupt(StD,dtmf,RISING);
  for(int i=0;i<4;i++)
  pinMode(Q[i],INPUT);

}
void dtmf()
{
  key=0;
  for(int i=0;i<4;i++)
  key+=digitalRead(Q[i])<<i;
  Serial.println(key);
}
void loop()
{
  dtmf();
  if(key==5)
  {
  digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }
}
