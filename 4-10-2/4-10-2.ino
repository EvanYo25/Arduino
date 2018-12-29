const int speaker=4; //數位接腳2連接至喇叭。
void setup()
{}
void loop()
{
 tone(speaker,500); //輸出1000Hz音調。
 delay(200); //延遲50ms。
 noTone(speaker); //靜音2秒。
 delay(200);
}

