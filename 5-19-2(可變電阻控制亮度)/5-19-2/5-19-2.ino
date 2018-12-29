const int led=13; //LED 連接至數位接腳2。
int val; //數位值。
float volts=0;
const int refVolts=5;
void setup()
{
 Serial.begin(9600); //初始化串列埠，傳輸速率為9600 baud。
}
void loop()
{
 val=analogRead(0); //讀取類比輸入電壓並轉換成數位值。
 volts=(float)val*refVolts/1024; //將數位值轉成類比值。
 Serial.print("voltage="); //印出"voltage="。
 Serial.print(volts,2); //印出類比電壓值。
 Serial.println("V"); //印出"V" 。
 
 val=map(val,0,1023,0,255); //重新調整數位值範圍。
 analogWrite(led,val); //關閉LED。
} 
