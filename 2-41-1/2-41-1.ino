// use two array to represent the second 1~4 and second 5~8
// reset the timer when it meets 8 sec
const int led[] = {10,11,12,13};
const int led2[] = {13,12,11,10};
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
  if(timer==8){
    timer=0;
  }
  if(timer<4){
      for(int i=0 ; i<4 ; i++){
        digitalWrite(led[i], LOW);
      }
      digitalWrite(led[timer],HIGH);
      delay(100);
      digitalWrite(led[timer],LOW);
      delay(100);
      digitalWrite(led[timer],HIGH);
      delay(100);
      digitalWrite(led[timer],LOW);
      delay(100);  
  }
  else{
      for(int i=0 ; i<4 ; i++){
        digitalWrite(led[i], LOW);
      }
      digitalWrite(led2[timer-4],HIGH);
      delay(100);
      digitalWrite(led2[timer-4],LOW);
      delay(100);
      digitalWrite(led2[timer-4],HIGH);
      delay(100);
      digitalWrite(led2[timer-4],LOW);
      delay(100);  
  }
  timer++;
}
