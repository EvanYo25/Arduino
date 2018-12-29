const int led[] ={3,9,10,11}; //LED 連接至PWM 信號輸出接腳。(3在最左邊)
int brightness=0; //LED 亮度。
int lighten=5; //LED 亮度變化量。
int ledNums=0; //作用中的LED。
int direct=0; //LED 漸亮或漸暗變化方向。
int flag = 0;

void setup() {
  // put your setup code here, to run once:

}
void loop()
{
  while(1) //重覆變化。
  {
    if(direct==0) //LED 由暗逐漸變亮?
    {
      brightness=brightness+lighten; //LED 漸亮。
      if(brightness>=250) //已至最亮?
        direct=1; //改變為由亮逐漸變暗。
    }
    else //LED 由亮逐漸變暗。
    {
      brightness=brightness-lighten; //LED 漸暗。
      if(brightness<=5) //已至最暗?
      {
        analogWrite(led[ledNums],0); //關閉LED。
        direct=0; //改變為由暗逐漸變亮。
        if(flag==0){
          ledNums++; //下一個LED。
          if(ledNums==3) //led 已右移至最右方?
            flag=1; //重新設定第一個LED。          
        }
        else{
          ledNums--; //下一個LED。
          if(ledNums==0)
            flag=0;
        }
      }
    }
    analogWrite(led[ledNums],brightness);//改變LED亮度。
    delay(10); //延遲10ms。
    }
}
