#include <DShot.h>

/*

redefine DSHOT_PORT if you want to change the default PORT

Defaults
UNO: PORTD, available pins 0-7 (D0-D7)
Leonardo: PORTB, available pins 4-7 (D8-D11)

e.g.
#define DSHOT_PORT PORTD
*/
#define DSHOT_PORT PORTD

//DShot esc1;
//DShot esc2;
//DShot esc7;
DShot esc8;

uint16_t throttle = 0;
uint16_t target = 0;
uint16_t min_throttle = 2200;
int val = 0;

void setup() {
  Serial.begin(115200);

  // Notice, all pins must be connected to same PORT
  //esc1.attach(0);
  //esc2.attach(1);
  //esc7.attach(6);
  esc8.attach(2);  
  //esc1.setThrottle(throttle);
  //esc2.setThrottle(throttle);
  //esc7.setThrottle(throttle);
  esc8.setThrottle(throttle);
}

void loop() {
  val = analogRead(0);
  target = min_throttle+val;
  if (Serial.available()>0){
    target = Serial.parseInt(SKIP_ALL, '\n');
    Serial.println(target);
    //if (target>2047)
    //  target = 2047;
    //Serial.print(target, HEX);
    //Serial.print("\t");
  }
  if (throttle<2200){
    throttle = 2200;
  }
  if (target<=2200){
    //esc1.setThrottle(target);
    //esc2.setThrottle(target);
    //esc7.setThrottle(target);
    esc8.setThrottle(target);
  }else{
    if (target>throttle){
      throttle ++;
      //esc1.setThrottle(throttle);
      //esc2.setThrottle(throttle);
      //esc7.setThrottle(throttle);
      esc8.setThrottle(throttle);
    }else if (target<throttle){
      throttle --;
      //esc1.setThrottle(throttle);
      //esc2.setThrottle(throttle);
      //esc7.setThrottle(throttle);
      esc8.setThrottle(throttle);
    }
  }
  delay(10);
}
