int k = 0; //陣列資料索引值。
char num; //鍵值。
int led[]={10,11,12,13}; //數位接腳10~13連接四個LED。
//direction 0 for left, 1 for right, 2 for blink, 3 for close
int direction = 3;
void setup()
{
    Serial.begin(9600); //初始化串列埠，設定鮑率為9600bps。
    Serial.println("L for left, R for right, F for flash all, S for close all");
    for(int i=0;i<4;i++) //設定數位接腳10~13為輸出模式。
        pinMode(led[i],OUTPUT);
    for(int i=0;i<4;i++) //設定LED初始狀態為暗。
        digitalWrite(led[i],LOW);
}
void loop()
{
    if(Serial.available()>0) //按任意鍵?
    {
        num = Serial.read(); //讀取按鍵值。
        //num=num-'0'; //按鍵值轉成數值。
        switch(num){
            case('L'):
                direction = 0;
                Serial.print("LED Direction LEFT\n");
                break;
            case('R'):
                direction = 1;
                Serial.print("LED Direction RIGHT\n");
                break;
            case('F'):
                direction = 2;
                Serial.print("LED Blink\n");
                break;
            case('S'):
                direction = 3;
                Serial.print("LED close\n");
                break;
        }
    }

    if(direction==2){
        for(int i=0 ; i<4 ; i++){
            digitalWrite(led[i],HIGH);
        }  
        delay(200);
        for(int i=0 ; i<4 ; i++){
            digitalWrite(led[i],LOW);
        }     
        delay(200);
    }
    else if(direction==3){
        for(int i=0 ; i<4 ; i++){
            digitalWrite(led[i],LOW);
        }  
    }
    else{
        for(int i=0 ; i<4 ; i++){
            digitalWrite(led[i],LOW);
        }
        delay(200);
        digitalWrite(led[k],HIGH);
        delay(200);
        if(direction==0)  k++;
        else if(direction==1)  k--;
        if(k==-1)  k=3;
        if(k==4)  k=0;        
    }
} 
