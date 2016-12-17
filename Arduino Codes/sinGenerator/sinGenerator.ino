int ledPin = 9;      // LED connected to digital pin 9
int analogPin = 3;   // potentiometer connected to analog pin 3
double val = 0;         // variable to store the read value
unsigned int T=10;//ms
void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);   // sets the pin as output
}

void loop()
{
  
  for(int i=0;i<360;++i){
    val = 500*(sin(((double)i/180)*3.14) + 1);
    analogWrite(ledPin,val);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255    
    Serial.println(val);
    delayMicroseconds(T/360);
    while (Serial.available() > 0) {
      T=(unsigned int)Serial.read();
      delay(1000);
    }
  }
}
