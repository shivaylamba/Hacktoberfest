int x[]={1,2,3,4,5,6};

void setup() {
   for (int i =0; i<7; i++){
      pinMode(x[i], OUTPUT);
   }	
}

void loop() {
   for (int i=0; i<7; i++){
      digitalWrite(x[i], HIGH);
      delay(100);
   }
   for (int i=6; i>0; i--){
      digitalWrite(x[i], LOW);
      delay(50);
   }
}
