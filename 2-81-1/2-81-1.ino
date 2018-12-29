const int sw=2; //按鍵開關連接至數位接腳第2腳。
const int led[]={10,11,12,13}; //LED 連接至數位接腳10~13。
const int debounceDelay=20; //按鍵開關穩定所需的時間。
int ledStatus=LOW; //LED 初始狀態為LOW。
int val; //按鍵開關狀態。
int i;
int j=0;
void setup()
{
 pinMode(sw,INPUT); //設定數位第2 腳為輸入模式。
 digitalWrite(sw,HIGH); //開啟數位第2 腳的內部上拉電阻。
  for(i=0;i<4;i++){
    pinMode(led[i],OUTPUT); //設定數位接腳10~13為輸出模式。
  }
}
void loop()
{
          for(i=0;i<4;i++) //關閉所有LED。
        {
          digitalWrite(led[i],LOW);
        }
 val=digitalRead(sw); //讀取按鍵開關狀態。
 if(val==LOW) //按鍵開關被按下?
 {
   delay(debounceDelay); //消除按鍵開關的不穩定狀態(機械彈跳)。
   while(digitalRead(sw)==LOW) //按鍵開關已放開?
    ; //等待放開按鍵開關。
   ledStatus=!ledStatus; //改變LED狀態。
 }
 if(ledStatus){
    digitalWrite(led[j],HIGH); //開關接通，執行LED 單燈右移。
    delay(500); //延遲0.5秒。
    if(j==3) //LED 已右移至最右方?
      j=0; //重新設定LED位置在最左方。
    else //LED 尚未移至最右方。
      j=j+1; //下一個LED。
   }
 else{
    digitalWrite(led[j],HIGH); //點亮第j 個LED。
    delay(500); //延遲0.5秒。
    if(j==0) //LED 已移至最左方?
      j=3; //重新設定LED位置在最右方。
    else //LED 尚未移至最左方。
      j=j-1; //下一個LED。
 }
}
