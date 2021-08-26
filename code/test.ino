const int motA_pin1=8;
const int motA_pin2=7;

const int motB_pin1=12;
const int motB_pin2=13;

void setup() {
  pinMode(motA_pin1,OUTPUT);
  pinMode(motA_pin2,OUTPUT);

  pinMode(motB_pin1,OUTPUT);
  pinMode(motB_pin2,OUTPUT);
}

void loop() {
  digitalWrite(motA_pin1,HIGH);
  digitalWrite(motA_pin2,LOW);

  digitalWrite(motB_pin1,HIGH);
  digitalWrite(motB_pin2,LOW);

  delay(300);  

  digitalWrite(motA_pin1,LOW);
  digitalWrite(motA_pin2,HIGH);

  digitalWrite(motB_pin1,LOW);
  digitalWrite(motB_pin2,HIGH);

  delay(300);  
}





