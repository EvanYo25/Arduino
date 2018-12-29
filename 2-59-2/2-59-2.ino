const int led[] ={3,9,10,11}; //LED 連接至PWM 信號輸出接腳。
int i; //LED 變化種類。
int j; //LED 亮度種類。
const int brightness[7][4]={ //LED 變化資料。
  {250,0,0,0}, //第1 次LED狀態。
  {100,250,0,0}, //第2 次LED狀態。
  {50,100,250,0}, //第3 次LED狀態。
  {5,50,100,250}, //第4 次LED狀態。
  {0,5,50,100}, //第5 次LED狀態。
  {0,0,5,50}, //第6 次LED狀態。
  {0,0,0,5} }; //第7 次LED狀態。
void setup() {
  // put your setup code here, to run once:

}

void loop(){
  for(i=0 ; i<7 ; i++){
    for(j=0 ; j<4 ; j++){
      analogWrite(led[j],brightness[i][j]);
    }
    delay(100);
  }
  for(i=0 ; i<7 ; i++){
    for(j=0 ; j<4 ; j++){
      analogWrite(led[3-j],brightness[i][j]);
    }
    delay(100);
  }
}
