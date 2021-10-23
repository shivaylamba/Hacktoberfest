void setup() {
  
    pinMode(9,OUTPUT);
    pinMode(10,OUTPUT);
    pinMode(11,OUTPUT);
    pinMode(13,OUTPUT);
    digitalWrite(13,HIGH);
  
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    char c=Serial.read();
    int value = Serial.parseInt();
    if (c == 'R'){
      analogWrite(9,value);
    }
    else if (c == 'G'){
      analogWrite(10,value);
    }
    else if (c == 'B'){
      analogWrite(11,value);
    }
  }
}
