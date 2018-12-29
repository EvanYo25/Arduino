const int speaker=4; //數位接腳2連接至喇叭。
const int toneTable[8]={262,494,440,392,349,330,294,523};//音符。
void setup()
{}
void loop()
{ for(int i=0;i<8;i++) //輸出C、D、E、…等8 個音符。
 {
 tone(speaker,toneTable[i]); //輸出音符。
 delay(500); //延遲0.5秒。
 }
 noTone(speaker); //關閉聲音。
}
