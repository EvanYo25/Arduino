const int sw=2; //SW 開關連接至數位接腳2。
const int led[]={10,11,12,13}; //LED 連接至數位接腳10~13。
int i; //索引值，第i 個LED。
int j=0; //索引值，第j 個LED。
int val; //開關狀態。
void setup()
{
  pinMode(sw,INPUT); //設定數位接腳2為輸入模式。
  for(i=0;i<4;i++){
    pinMode(led[i],OUTPUT); //設定數位接腳10~13為輸出模式。
  }
}
void loop(){
  val=digitalRead(sw); //讀取開關狀態。
  for(i=0;i<4;i++) //關閉所有LED。
  {
    digitalWrite(led[i],LOW);
  }
  if(val==LOW) //開關接通(OFF)?
  {
    digitalWrite(led[j],HIGH); //開關接通，執行LED 單燈右移。
    delay(500); //延遲0.5秒。
//    digitalWrite(led[j],LOW); //開關接通，執行LED 單燈右移。
//    delay(100); //延遲0.5秒。
    if(j==3) //LED 已右移至最右方?
      j=0; //重新設定LED位置在最左方。
    else //LED 尚未移至最右方。
      j=j+1; //下一個LED。
  }
  else //開關斷開(ON)，執行LED 單燈左移。
  {
    digitalWrite(led[j],HIGH); //點亮第j 個LED。
    delay(100); //延遲0.5秒。
    digitalWrite(led[j],LOW); //點亮第j 個LED。
    delay(100); //延遲0.5秒。
    if(j==0) //LED 已移至最左方?
      j=3; //重新設定LED位置在最右方。
    else //LED 尚未移至最左方。
      j=j-1; //下一個LED。
  }
}
