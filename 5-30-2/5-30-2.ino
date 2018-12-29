const int cds=0; //CdS 連接至類比接腳0。
const int led=2; //LED 連接至數位接腳2。
int val; //數位值。
float volts; //類比輸入電壓值。
void setup()
{ pinMode(led,OUTPUT); //設定數位接腳2為輸出模式。
 digitalWrite(led,HIGH); //關閉LED。
 pinMode(3,OUTPUT); //設定數位接腳2為輸出模式。
 digitalWrite(3,HIGH); //關閉LED。
 pinMode(4,OUTPUT); //設定數位接腳2為輸出模式。
 digitalWrite(4,HIGH); //關閉LED。
 Serial.begin(9600);
}
void loop()
{ val=analogRead(cds); //讀取類比輸入電壓值。
 Serial.println(val);
 digitalWrite(led,LOW); //光線較亮，則關閉LED。
 digitalWrite(3,LOW); //光線較亮，則關閉LED。
 digitalWrite(4,LOW); //光線較亮，則關閉LED。
 if(val>600){ //光線較亮?
 digitalWrite(led,HIGH); //光線較亮，則關閉LED。
 }
 else if(val<600 && val>100){
  digitalWrite(3,HIGH);
 }
 else{ //光線較暗。
 digitalWrite(4,HIGH); //光線較暗，則點亮LED。
 }
}
