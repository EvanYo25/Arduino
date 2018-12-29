const int sw=2; //開關連接至數位接腳2。
const int led=3; //LED 連接至數位接腳13。
int val; //開關狀態。
void setup()
{
 pinMode(sw,INPUT); //設定數位接腳2為輸入模式。
 pinMode(led,OUTPUT); //設定數位接腳13為輸出模式。
}
void loop()
{
  val=digitalRead(sw); //讀取開關狀態。
  if(val==HIGH){ //開關接通(ON)?
    digitalWrite(led,HIGH); //開關接通，點亮LED。
    delay(1000);
    digitalWrite(led,LOW); //開關接通，點亮LED。
    delay(1000);
  }
  else //開關斷開(OFF)
    digitalWrite(led,HIGH); //開關接通，點亮LED。
    delay(100);
    digitalWrite(led,LOW); //開關接通，點亮LED。
    delay(100);
}

