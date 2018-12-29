int brightness = 0;
int lighten = 5;
int flag = 0;
int flag2 = 0;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  if(flag2==0){
    analogWrite(10, 0);
    analogWrite(11, brightness);
  }
  else{
    analogWrite(11, 0);
    analogWrite(10, brightness);
  }
  if(flag == 0)
    brightness += lighten;
  else{
    brightness -= lighten;
  }
    
  if(brightness == 250)
    flag = 1;
  else if (brightness == 0){
    flag = 0;
    if(flag2 == 1)
      flag2 = 0;
    else
      flag2 = 1;
  }
  delay(50);
}
