#define TRIGPIN 2
#define ECHOPIN 3
#define LED1 12
#define LED2 13
const int speaker=4; //數位接腳2連接至喇叭。
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
  int a = map(cm,0,50,100,1000);
  Serial.println(cm);
  Serial.println(a);
  if(cm<=50){
    
    
     
     tone(speaker,500); //輸出1000Hz音調。
     digitalWrite(LED1,HIGH);
     delay(a); //延遲50ms。
     noTone(speaker); //靜音2秒。
     digitalWrite(LED1,LOW);
     delay(a);
  }
  delay(100);
}

