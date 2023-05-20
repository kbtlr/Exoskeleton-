const int index=A0; //pin0
const int middle=A1; //pin1
const int ring=A2; //pin2
const int pinky=A3; //pin3
const int thumb=A4; //pin4


const int reg1=5;//index
const int reg2=6;//middle
const int reg3=9;//ring
const int reg4=10;//pinky
const int reg5=3; //thumb
//pwm pins

void setup() {
  // put your setup code here, to run once:
  pinMode(reg1, OUTPUT);
  pinMode(reg2, OUTPUT);
  pinMode(reg3, OUTPUT);
  pinMode(reg4, OUTPUT);
  pinMode(reg5, OUTPUT);//set them all as output
  Serial.begin(9600);
}

void loop() {

  int val1=map(analogRead(index),870,367,0,250);
  int val2=map(analogRead(middle),1020,691,0,250);
  int val3=map(analogRead(ring),1023,771,0,250);
  int val4=map(analogRead(pinky),1023,794,0,250);
  int val5=map(analogRead(thumb),1023,741,0,250);
  
  //THE CODE ABOVE TAKES IN POTENTIOMETER READINGS AND MAPS THEM TO VALUES BETWEEN 0 AND 250, CALIBRATED FOR OLIVIA'S HAND
  
  
  Serial.print("Thumb: ");
  Serial.print(val5);
  Serial.print(" | Index Finger: ");
  Serial.print(val1);
  Serial.print(" | Middle Finger: ");
  Serial.print(val2);
  Serial.print(" | Ring Finger ");
  Serial.print(val3);
  Serial.print(" | Pinky Finger: ");
  Serial.print(val4);
  //THE SECTION OF CODE ABOVE PRINTS OUT THE CURRENT MAPPED POTENTIOMETER VALUES TO THE SERIAL MONITOR
  
  analogWrite(reg1,52); //thumb
  analogWrite(reg2,95); //index
  analogWrite(reg3,37); //middle
  analogWrite(reg4,25); //ring
  analogWrite(reg5,32); //pinky
/*
  analogWrite(reg1,0);
  analogWrite(reg2,0);
  analogWrite(reg3,0);
  analogWrite(reg4,0);
  analogWrite(reg5,0);
*/
  
  //THE CODE ABOVE IS USED FOR SENDING SPECIFIC VALUES TO THE REGULATORS AND THE CODE BELOW IS USED WITH THE LEADER GLOVE
  //LEADER GLOVE CODE IS COMMENTED OUT BECAUSE WE WERE TESTING
  
/*  
  if (val1<=0){
    digitalWrite(reg1,0);
  }
  else{
    int val11=val1-10;
    analogWrite(reg1, val1);
  }

  if (val2<=0){
    digitalWrite(reg2,0);
  }
  else{
    int val22=val2-15;
    analogWrite(reg2, val2);
  }

  if (val3<=0){
    digitalWrite(reg3,0);
  }
  else{
    analogWrite(reg3, val3);
  }

  if (val4<=0){
    digitalWrite(reg4,0);
  }
  else{
    analogWrite(reg4, val4);
  }

  if (val5<=0){
    digitalWrite(reg5,0);
  }
  else{
    analogWrite(reg5, val5);
  }
*/ 
  
  Serial.print('\n');
  //Serial.print("Regulator output : ");
  //Serial.print(analogRead(Reg_out));
  Serial.print('\n'); 
  delay(2000);
}
