const int motA_pin1=8;
const int motA_pin2=7;
const int motA_EN=5;

const int motB_pin1=12;
const int motB_pin2=13;
const int motB_EN=6;

char speed=220;
char change_speed_add=30;

int command=0;

void setup() {
 motor_init();
 Serial.begin(9600);
}

void loop() {
if(Serial.available()>0){
  command = Serial.read();
  
if(command==70){
  forward();
}

else if(command==76){
  left();
}

else if(command==82){
  right();
}

else if(command==66){
  reverse();
}

else{
  stop();
}

Serial.println(command);
}

else{
  stop();
}

}

void motor_init(){
  pinMode(motA_pin1,OUTPUT);
  pinMode(motA_pin2,OUTPUT);

  pinMode(motB_pin1,OUTPUT);
  pinMode(motB_pin2,OUTPUT);

  pinMode(motA_EN,OUTPUT);
  pinMode(motB_EN,OUTPUT);

  analogWrite(motA_EN,0);
  digitalWrite(motA_pin1,LOW);
  digitalWrite(motA_pin2,LOW);

  analogWrite(motB_EN,0);
  digitalWrite(motB_pin1,LOW);
  digitalWrite(motB_pin2,LOW);
}

void forward(){
  Serial.print("fwd");
  
  analogWrite(motA_EN,speed);
  analogWrite(motB_EN,speed);

  digitalWrite(motA_pin1,HIGH);
  digitalWrite(motA_pin2,LOW);

  digitalWrite(motB_pin1,HIGH);
  digitalWrite(motB_pin2,LOW);
}

void reverse(){
  Serial.print("rev");
  
  analogWrite(motA_EN,speed);
  analogWrite(motB_EN,speed);

  digitalWrite(motA_pin1,LOW);
  digitalWrite(motA_pin2,HIGH);

  digitalWrite(motB_pin1,LOW);
  digitalWrite(motB_pin2,HIGH);
}

void left(){
  Serial.print("left");
  
  analogWrite(motA_EN,speed+10);
  digitalWrite(motA_pin1,LOW);
  digitalWrite(motA_pin2,HIGH);

  analogWrite(motB_EN,speed-10);
  digitalWrite(motB_pin1,HIGH);
  digitalWrite(motB_pin2,LOW);
}

void right(){
  Serial.print("right");
  
  analogWrite(motA_EN,speed-10);
  digitalWrite(motA_pin1,HIGH);
  digitalWrite(motA_pin2,LOW);

  analogWrite(motB_EN,speed+10);
  digitalWrite(motB_pin1,LOW);
  digitalWrite(motB_pin2,HIGH);
}

void stop(){
  Serial.print("stop");
  
  analogWrite(motA_EN,0);
  digitalWrite(motA_pin1,LOW);
  digitalWrite(motA_pin2,LOW);

  analogWrite(motB_EN,0);
  digitalWrite(motB_pin1,LOW);
  digitalWrite(motB_pin2,LOW);
}

