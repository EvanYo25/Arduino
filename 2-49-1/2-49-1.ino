const int led = 10;
int brightness = 0;
int lighten = 5;
int flag = 0;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(led, brightness);
  if(flag == 0)
    brightness = brightness + lighten;
  else
    brightness -= lighten;
  if(brightness ==250)
    flag = 1;
  else if (brightness == 0)
    flag = 0;
  delay(50);
  
}
