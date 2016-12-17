char v='x';
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    v=Serial.read();
    Serial.write(v);
    if(v>=0)
    {
      Serial.print("\t: ");
      Serial.print((int)v);
      Serial.print("\t");
      Serial.print((int)v,HEX);
      Serial.print("\t");
      Serial.print((int)v,BIN);
      Serial.println(" ");
    }
  }
}
