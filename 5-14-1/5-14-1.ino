const int refVolts=5; //使用5V參考電壓的Arduino 板。
int val; //數位值。
float volts; //類比電壓。
void setup()
{
 Serial.begin(9600); //初始化串列埠，傳輸速率為9600 baud。
}
void loop()
{
 val=analogRead(0); //讀取類比值電壓。
 volts=(float)val*refVolts/1024; //將數位值轉成類比值。
 Serial.print("voltage="); //印出"voltage="。
 Serial.print(volts,2); //印出類比電壓值。
 Serial.println("V"); //印出"V" 。
 delay(1000); //延遲1秒。
}

