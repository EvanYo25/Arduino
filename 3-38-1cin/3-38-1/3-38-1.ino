long num = 0; //自串列埠中讀取可用位元組數目。
char myNum[9];
void setup()
{
 Serial.begin(9600); //初始化串列埠，設定傳輸速率為9600。
}
void loop()
{
if(Serial.available()>0) //是否至少有接收到一個可用的字元?
{
// num=Serial.read(); //讀取字元資料。
 Serial.readBytes(myNum,9);
// Serial.println(atoi(myNum));
 num = atoi(myNum);
 Serial.print("I received:"); //輸出"I received:"字串。
 Serial.print(num); //輸出所讀取到的字元數值。
 Serial.print("\n");
 Serial.println(num,DEC); //輸出所讀取到的字元數值。
 Serial.println(num,HEX); //輸出所讀取到的字元數值。
 
 }
}
