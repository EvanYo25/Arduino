int led[] ={10,11,12,13}; //數位接腳10~13連接至四個LED。
int i=3,j; //LED 編號。
void setup()
{
 Serial.begin(9600); //初始化串列埠，設定鮑率為9600bps。
 for(int i=0;i<4;i++)
 {
 pinMode(led[i],OUTPUT); //設定數位接腳10~13為輸出模式。
 }
}
void loop()
{
 Serial.print("LED="); //顯示。
    for(j=0;j<4;j++)
     {
       if(j==i)
       Serial.print("1"); //LED 亮則顯示1。
       else
       Serial.print("0"); //LED 暗則顯示0。
     }
 Serial.println(); //換下一行。
 digitalWrite(led[i],HIGH); //第i 個LED亮。
 delay(200); //延遲1秒。
 digitalWrite(led[i],LOW); //第i 個LED亮。
 delay(200); //延遲1秒。
 digitalWrite(led[i],HIGH); //第i 個LED亮。
 delay(200); //延遲1秒。
 digitalWrite(led[i],LOW); //關閉第i 個LED。
 i--; //右移。
 if(i<0) //已移位至最右?
 i=3; //重設初值。
}

