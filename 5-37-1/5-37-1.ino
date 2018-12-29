const int led=13; //LED 連接至數位腳13。
const int PIRout=2; //PIR 感測器輸出接至數位腳2。
void setup()
{
 pinMode(led,OUTPUT); //設定數位腳13 為輸出模式。
 pinMode(PIRout,INPUT); //設定數位腳2 為輸入模式。
}
void loop()
{
 int val=digitalRead(PIRout); //讀取PIR狀態（PIR 短路夾連接至H）。
 if(val==HIGH) //PIR 輸出狀態為HIGH（有物體移動）?
 {
 digitalWrite(led,HIGH); //閃爍LED。
 delay(50); //點亮LED 50ms。
 }
 else //PIR 輸出狀態為LOW。
 digitalWrite(led,LOW); //關閉LED。
} 
