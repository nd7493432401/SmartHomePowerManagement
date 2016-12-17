//Zero Crossing Detection
#define triacPulse 5
#define aconLed 13 

int val=0;
char v=25, set=0,ctr=0;

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
    if(Serial.available()>0){
        
      set=63-(Serial.read()%63);
      
      Serial.write(set);
      if(set>=0){
        // LED indicator on
        digitalWrite(aconLed, HIGH);
        
        Serial.print("\t: ");
        Serial.print((int)set);
        Serial.print("\t");
        Serial.print((int)set,HEX);
        Serial.print("\t");
        Serial.print((int)set,BIN);
        Serial.println(" ");
        ctr=0;
      }
      else{
        // LED indicator off
        digitalWrite(aconLed, LOW);
      }
    }
    if(set == v){
      ctr=0;
    }
    else if(ctr<10 && set!=v){
      if(set>v){
        v++;
        val=10000*((double)v/63);
        Serial.println(val);
      }
      else if(set>v){
        v--;
        val=10000*((double)v/63);
        Serial.println(val);
      }
    }
    attachInterrupt(digitalPinToInterrupt(2), acon, CHANGE); 
  }

void acon()  
   {
    // delay val uSec on output pulse to turn on triac
    digitalWrite(triacPulse, LOW);
    delayMicroseconds(val); // read AD1
    digitalWrite(triacPulse, HIGH);
    ctr = (ctr>=10 &&  set!=v)?0:(ctr+1);
   } 
