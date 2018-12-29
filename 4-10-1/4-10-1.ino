const int speaker=2; //數位接腳2連接至喇叭。
void setup()
{}
void loop()
{
 for(int i=0;i<10;i++) //振鈴10次。
 {
 tone(speaker,500+50*i); //輸出1000Hz音調。
 delay(20); //延遲50ms。
 }
 noTone(speaker); //靜音2秒。
 delay(2000);
}

