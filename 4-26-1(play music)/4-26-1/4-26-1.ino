const int speaker=2; //數位接腳2 連接至喇叭。
unsigned int frequency[7]={523,587,659,694,784,880,988};//音符頻率。
char toneName[]="CDEFGAB"; //音符表。
char beeTone[]="GEEFDDCDEFGGGGEEFDDCEGGEDDDDDEFEEEEEFGGEEFDDCEGGC";
byte beeBeat[]={1,1,2,1,1,2,1,1,1,1,1,1,2,
1,1,2,1,1,2,1,1,1,1,4,
 1,1,1,1,1,1,2,1,1,1,1,1,1,2,
1,1,2,1,1,2,1,1,1,1,4};
const int beeLen=sizeof(beeTone); //小蜜蜂音符總數。
unsigned long tempo=180; //每分鐘180 拍。
int i,j;
void setup()
{} 
void loop()
{
 for(i=0;i<beeLen;i++) //播放小蜜蜂樂曲。
 playTone(beeTone[i],beeBeat[i]);
 delay(3000); //間隔3秒重覆播放。
}
void playTone(char toneNo,byte beatNo) //播放音符函式。
{
 unsigned long duration=beatNo*60000/tempo; //計算每拍時間（毫秒）。
 for(j=0;j<7;j++)
 {
 if(toneNo==toneName[j]) //查音符表。
 {
 tone(speaker,frequency[j]); //播放音符。
 delay(duration); //此音符的節拍。
 noTone(speaker); //關閉聲音。
 }
 }
} 
