unsigned int f=100;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  tone(9,f);      
}

void loop() {
  // put your main code here, to run repeatedly:
    while (Serial.available() > 0) {

      f=(unsigned int)Serial.read();
    }
    
      for(int i=0;i<=100;i++){
        noTone(9);
        tone(9,f+i*20);
        delay(100);    
      }
}
