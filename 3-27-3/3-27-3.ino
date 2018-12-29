byte val=97; //定義位元組數值資料val=65。
void setup()
{
 Serial.begin(9600); //初始化串列埠，設定鮑率為9600bps。
}
void loop()
{
 for(int i=0;i<26;i++) //26 個大寫英文字母。
 {
 delay(1000); //延遲1秒後，再輸出下一個字母。
 Serial.print("Arduino ");
 Serial.print(i+1);
 Serial.print(": ");
 Serial.write(val+i); //輸出字母字元至串列埠。
 Serial.print('='); //輸出字元’=’至串列埠。
 Serial.println(val+i,DEC); //輸出ASCII碼至串列埠。
 
 }
} 
