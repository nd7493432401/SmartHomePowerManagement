//Zero Crossing Detection
#define triacPulse 5
#define aconLed 13 

int val=0,ctr=0,ctrMax=1000;
char v=25, set=0;

    /*START Debug*/
//int timer=0;

    /*END Debug*/

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
      
      Serial.println((int)set);
      if(set>0){
        // LED indicator on
        digitalWrite(aconLed, HIGH);
       
    /*START Debug*/ 
//        Serial.print("\tset : ");
//        Serial.print((int)set);
//        Serial.print("\t");
//        Serial.print((int)set,HEX);
//        Serial.print("\t");
//        Serial.print((int)set,BIN);
//        Serial.print(" ");
//
//        
//        Serial.print("\t\tv: ");
//        Serial.println((int)v);
        
    /*END Debug*/
        ctr=0;
      }
      else{
        // LED indicator off
        digitalWrite(aconLed, LOW);
      }
    }
    if(!(ctr%2) && ctr<ctrMax && set!=v){
      if(set>v){
        
    /*START Debug*/
//        Serial.print((int)set);
//        Serial.print(" set > v ");
//        Serial.println((int)v);
    /*END Debug*/
    
        v++;
        
    /*START Debug*/
//        Serial.println(val);
        
    /*END Debug*/
      }
      else if(set<v){
        
    /*START Debug*/
//        Serial.print((int)set);
//        Serial.print(" set < v ");
//        Serial.println((int)v);
//        
    /*END Debug*/
        v--;
        
    /*START Debug*/
//        Serial.println(val);
    /*END Debug*/
      }
      
      val=10000*((double)v/63);

      if(set==v){
        ctr=0;
        /*START Debug*/
//        Serial.print(" SET ");
//        Serial.println((int)v);
//      }
//      else{
//        Serial.println((int)v);
        /*END Debug*/
      }
      
    /*START Debug*/
//      Serial.println(timer);
    /*END Debug*/
    }
    /*START Debug*/
//    timer++;
//    if(timer>10000){
//      timer=0;
      //Serial.print("\n\t\tAcon\n");
//      acon();
//      }
    /*END Debug*/
    
    attachInterrupt(digitalPinToInterrupt(2), acon, CHANGE); 
  }

void acon()  
   {
    // delay val uSec on output pulse to turn on triac
    digitalWrite(triacPulse, LOW);
    delayMicroseconds(val); // read AD1
    digitalWrite(triacPulse, HIGH);
    ctr = (ctr<ctrMax &&  set!=v)?0:(ctr+1);
    
    /*START Debug*/
    //Serial.println("\t\tInterrupt");
    
    /*END Debug*/
   } 
