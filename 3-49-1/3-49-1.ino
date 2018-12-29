int i; //陣列資料索引值。
int num; //鍵值。
int led[]={10,11,12,13}; //數位接腳10~13連接四個LED。
int status[]={0,0,0,0}; //LED 狀態。
void setup()
{
 Serial.begin(9600); //初始化串列埠，設定鮑率為9600bps。
 Serial.println("press 0~3 toggle LED status");
 for(i=0;i<4;i++) //設定數位接腳10~13為輸出模式。
 pinMode(led[i],OUTPUT);
 for(i=0;i<4;i++) //設定LED初始狀態為暗。
 digitalWrite(led[i],LOW);
}
void loop()
{
 if(Serial.available()>0) //按任意鍵?
 {
     num = Serial.read(); //讀取按鍵值。
     num=num-'0'; //按鍵值轉成數值。
     if(num>=0 && num<=3) //按0~3 鍵?
     {
         status[num]=!status[num]; //改變LED狀態。
//         digitalWrite(led[num],status[num]);
         
         Serial.print("LED status : ");
         for(i=0;i<4;i++) //顯示LED狀態。
         {
           if(status[i]==1)
           Serial.print("1");
           else
           Serial.print("0");
         }
         Serial.println();
     }
 }

for(int i=0 ; i<4 ; i++){
  if(status[i]==1){
    digitalWrite(led[i],HIGH);
  }
}
delay(200);
for(int i=0 ; i<4 ; i++){
  digitalWrite(led[i],LOW);
}
delay(200);
} 
