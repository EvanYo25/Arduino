//10 at the right side and 13 on the left side

const int led[] = {10,11,12,13};
int timer = 0;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  for(int i=0 ; i<4 ; i++){
    pinMode(led[i],OUTPUT);
  }
}

// the loop function runs over and over again forever
void loop() {
  if(timer==4){
    timer=0;
  }
  for(int i=0 ; i<4 ; i++){
    digitalWrite(led[i], LOW);
  }
  digitalWrite(led[timer],HIGH);
  delay(1000);
  timer++;
}
