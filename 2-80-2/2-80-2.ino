const int sw=2; //按鍵開關連接至數位接腳第2腳。
const int led=13; //LED 連接至數位接腳第13腳。
const int debounceDelay=20; //按鍵開關穩定所需的時間。
int ledStatus=LOW; //LED 初始狀態為LOW。
int val; //按鍵開關狀態。
void setup()
{
 pinMode(sw,INPUT); //設定數位第2 腳為輸入模式。
 digitalWrite(sw,HIGH); //開啟數位第2 腳的內部上拉電阻。
 pinMode(led,OUTPUT); //設定數位第13 腳為輸出模式。
}
void loop()
{
 val=digitalRead(sw); //讀取按鍵開關狀態。
 if(val==LOW) //按鍵開關被按下?
 {
   delay(debounceDelay); //消除按鍵開關的不穩定狀態(機械彈跳)。
   while(digitalRead(sw)==LOW) //按鍵開關已放開?
    ; //等待放開按鍵開關。
   ledStatus=!ledStatus; //改變LED狀態。
 }
 if(ledStatus){
    for(int i=0 ; i<3 ; i++){
     digitalWrite(led,HIGH); //設定LED狀態。
     digitalWrite(12,HIGH); //設定LED狀態。
     delay(100);
     digitalWrite(led,LOW); //設定LED狀態。
     digitalWrite(12,LOW); //設定LED狀態。
     delay(100);
   }
   delay(1000);
 }
 else{
    digitalWrite(led,LOW);
    digitalWrite(12,LOW); //設定LED狀態。
 }
}
