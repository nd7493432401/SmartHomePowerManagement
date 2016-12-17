//Zero Crossing Detection
#define triacPulse 5
#define aconLed 13 

int val;

void setup()  {
   pinMode(2, INPUT);
   digitalWrite(2, HIGH); // pull up
   pinMode(triacPulse, OUTPUT);
   pinMode(aconLed, OUTPUT);
   digitalWrite(aconLed, LOW);
   Serial.begin(9600);
  }

 void loop() {
    // enable power
    Serial.println(val);
    attachInterrupt(digitalPinToInterrupt(2), acon, CHANGE); 
    // LED indicator on
    digitalWrite(aconLed, HIGH);
  }

void acon()  
   {
    //Read Firing Angle  
    // delay 200 uSec on output pulse to turn on triac
    digitalWrite(triacPulse, LOW);
    val=10000*((double)analogRead(A0)/1024);
    delayMicroseconds(val); // read AD1
    digitalWrite(triacPulse, HIGH);
   } 
