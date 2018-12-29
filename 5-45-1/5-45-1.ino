#define TRIGPIN 2
#define ECHOPIN 3
#define LED1 12
#define LED2 13

long ping(){
  digitalWrite(TRIGPIN,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN,LOW);
  return pulseIn(ECHOPIN,HIGH)/58;
}
void setup(){
  Serial.begin(9600);
  pinMode(TRIGPIN,OUTPUT);
  pinMode(ECHOPIN,INPUT);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
}
void loop(){
  long cm = ping();
  int a = map(cm,0,3600,0,2000);
  Serial.println(cm);
//  if(cm<=100){
    digitalWrite(LED1,HIGH);
    delay(a);
    digitalWrite(LED1,LOW);
//  }
  delay(100);
}

