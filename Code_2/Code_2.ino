const int motA_pin1=8;
const int motA_pin2=7;

const int motB_pin1=12;
const int motB_pin2=13;

void motor_init(){
  pinMode(motA_pin1,OUTPUT);
  pinMode(motA_pin2,OUTPUT);

  pinMode(motB_pin1,OUTPUT);
  pinMode(motB_pin2,OUTPUT);

  digitalWrite(motA_pin1,LOW);
  digitalWrite(motA_pin2,LOW);

  digitalWrite(motB_pin1,LOW);
  digitalWrite(motB_pin2,LOW);
}

void forward(){

  digitalWrite(motA_pin1,HIGH);
  digitalWrite(motA_pin2,LOW);

  digitalWrite(motB_pin1,HIGH);
  digitalWrite(motB_pin2,LOW);
}

void back(){

  digitalWrite(motA_pin1,LOW);
  digitalWrite(motA_pin2,HIGH);

  digitalWrite(motB_pin1,LOW);
  digitalWrite(motB_pin2,HIGH);
}

void left(){
 
  digitalWrite(motA_pin1,LOW);
  digitalWrite(motA_pin2,HIGH);

  digitalWrite(motB_pin1,HIGH);
  digitalWrite(motB_pin2,LOW);
}

void right(){
  
  digitalWrite(motA_pin1,HIGH);
  digitalWrite(motA_pin2,LOW);

  digitalWrite(motB_pin1,LOW);
  digitalWrite(motB_pin2,HIGH);
}

void stop(){
  
  digitalWrite(motA_pin1,LOW);
  digitalWrite(motA_pin2,LOW);

  digitalWrite(motB_pin1,LOW);
  digitalWrite(motB_pin2,LOW);
}


void setup() {
 motor_init();
 Serial.begin(9600);
}

void loop() {
  
while(Serial.available()){
  
 char command;
 command = Serial.read();
  
if(command=='f'){
  forward();
}

else if(command=='L'){
  left();
}

else if(command=='r'){
  right();
}

else if(command=='B'){
  back();
}

else{
  stop();
}

}
}


