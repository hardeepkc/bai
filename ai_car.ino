//create by aryan 
int a = 8; // both right working in forward
int b = 9; // both right worin in backword
int c = 10;// both left working in forard
int d = 11;//both left run in backword
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(a,OUTPUT);
pinMode(b,OUTPUT);
pinMode(c,OUTPUT);
pinMode(d,OUTPUT);
}
void run_for()
{
 // for forward runing
for(int n = 0;n<100;n++){
  forw_a();
}
stop_all();
}
void forw(){
  stop_all();
  digitalWrite(a,HIGH);
  digitalWrite(c,HIGH);
  delay(100);
  stop_all();
  digitalWrite(d,HIGH);
  digitalWrite(b,HIGH);
  delay(100);
}
void forw_a(){
  stop_all();
  digitalWrite(a,HIGH);
  digitalWrite(c,HIGH);
  delay(10);
  stop_all();
  digitalWrite(b,HIGH);
  digitalWrite(d,HIGH);
  delay(10);
}
void stop_all()
{
 digitalWrite(d,LOW);
digitalWrite(c,LOW);
digitalWrite(a,LOW);
digitalWrite(b,LOW); 
}
void left(){
digitalWrite(d,LOW);
digitalWrite(c,LOW);
digitalWrite(a,LOW);
digitalWrite(b,LOW);
delay(50);
digitalWrite(a,HIGH);
digitalWrite(d,HIGH);
delay(1000);
stop_all();

}
void right(){
  stop_all();
  delay(50);
digitalWrite(c,HIGH);
digitalWrite(b,HIGH);
delay(1000);
stop_all();  
}
void loop() {
  // put your main code here, to run repeatedly:
//digitalWrite(a,HIGH);
if(Serial.available()>0){
  char data = Serial.read();
  switch(data){
    case 'w':
      run_for();
      break;
    case 'a':
      left();
      break;
    case 'd':
      right();
      break;
    case 's':
      stop_all();
      break;
     
  }
}



}
