const int speaker=2; //數位接腳2 連接至喇叭。
const int sw[8]={3,4,5,6,7,8,9,10}; //數位接腳4~11 連接至琴鍵。
const int frequency[8]={523,587,659,694,784,880,988,1046};//音符頻率表。
int i; //迴圈索引。
int val; //琴鍵狀態。
void setup()
{
 for(i=0;i<8;i++) //設定數位接腳4~11 為輸入模式。
 pinMode(sw[i],INPUT_PULLUP);
}
void loop()
{
 for(i=0;i<8;i++)
 {
 val=digitalRead(sw[i]); //讀取琴鍵狀態。
 if(val==0) //按下琴鍵?
 tone(speaker,frequency[i],100); //播放所按下琴鍵的音符。
 }
}
