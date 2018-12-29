int num=0; //電腦鍵盤按鍵值。
int flash=-1;
int led=13; //LED 連接至數位接腳13。
void setup()
{
 Serial.begin(9600); //初始化串列埠，設定傳輸速率為9600 baud。
 pinMode(led,OUTPUT); //設定數位接腳13為輸出模式。
}
void loop()
{
 if (Serial.available()>0) //是否接收到可用的字元?
 {
     num = Serial.read(); //讀取按鍵值。
     Serial.write("You pressed: ");
     Serial.write(num);
     Serial.write("\n");
     num=num-'0'; //將鍵值0~9 轉成數值0~9。
     if(num>=0 && num<=9)
     {
        switch(num){
          case 0:
             flash = -1;
            digitalWrite(led,LOW); //設定LED為LOW(暗)。
            Serial.write("led low\n");
            break;
          case 1:
             flash = -1;
            digitalWrite(led,HIGH); //設定LED為LOW(暗)。
            Serial.write("led high\n");
            break;
          case 2:
             flash = 0;
             Serial.write("led flash fast\n");
             break;
          case 3:
             flash = 1;
             Serial.write("led flash slow\n");
             break;
        }

     }
 }
 if(flash==0){
             digitalWrite(led,HIGH); //設定LED為HIGH(亮)。
             delay(100); //延遲時間。
             digitalWrite(led,LOW); //設定LED為LOW(暗)。
             delay(100); //延遲時間。
 }
 else if(flash==1){
             digitalWrite(led,HIGH); //設定LED為HIGH(亮)。
             delay(500); //延遲時間。
             digitalWrite(led,LOW); //設定LED為LOW(暗)。
             delay(500); //延遲時間。
 }

}
