/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <Servo.h>
// Servo stuff
Servo servo1;  // create servo object to control a servo
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position


//Motor stuff
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Adafruit_DCMotor *myMotor = AFMS.getMotor(3);
Adafruit_DCMotor *myOtherMotor = AFMS.getMotor(4);



void setup() {
  servo1.attach(9);  // Left arm --> 60 - 140
  servo2.attach(10);  // Left hand
  servo3.attach(11);  // Right hand
  servo4.attach(6);  // Right arm
  servo5.attach(8);  // Head (horizontal) --> 30-110
  servo6.attach(7);  // Head vertical -->90-160


  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  
  // Set the speed to start, from 0 (off) to 255 (max speed)
  myMotor->setSpeed(255);
  myMotor->run(FORWARD);
  myOtherMotor->setSpeed(255);
  myOtherMotor->run(FORWARD);
  // turn on motor
  myMotor->run(RELEASE);
  myOtherMotor->run(RELEASE);
}

void loop() {
  uint8_t i;
  servo4.write(140);
  servo1.write(40);
  delay(5000); 
  for (pos = 140; pos >= 90; pos -= 1) { 
    servo4.write(pos);   
    delay(10);                       
  }
  for (pos = 40; pos <= 90; pos += 1) { 
    servo1.write(pos);   
    delay(10);                       
  }
  // Head up left and right --> look to right arm
  for (pos =90; pos <= 120; pos += 1) { 
    servo6.write(pos);  
    delay(100);                      
  }
  delay(1000);
    for (pos = 90; pos >= 30; pos -= 1) { 
    servo5.write(pos);   
    delay(40);                       
  }
  delay(2000);
   for (pos = 30; pos <= 110; pos += 1) { 
    servo5.write(pos);   
    delay(40);                       
  }
   for (pos = 120; pos >= 90; pos -= 1) { 
    servo6.write(pos);   
    delay(50);                       
  }
  


  //Right arm up and down
   for (pos = 90; pos <= 140; pos += 1) { 
    servo4.write(pos);   
    delay(20);                       
  }
    delay(500);
   for (pos = 140; pos >= 90; pos -= 1) { 
    servo4.write(pos);   
    delay(20);                       
  }



// Head switch sides
 
   for (pos = 110; pos >= 30; pos -= 1) { 
    servo5.write(pos);   
    delay(10);                       
  }



  //Left arm up and down
  for (pos = 90; pos >= 40; pos -= 1) { 
    servo1.write(pos);   
    delay(20);                       
  }
    delay(500);
   for (pos = 40; pos <= 90; pos += 1) { 
    servo1.write(pos);   
    delay(20);                       
  }



  //Head centre
  for (pos = 30; pos <= 80; pos += 1) { 
    servo5.write(pos);   
    delay(10);                       
  }
  for (pos =90; pos >= 75; pos -= 1) { 
    servo6.write(pos);  
    delay(100);                      
  }
  for (pos = 90; pos >= 0; pos -= 1) { 
    servo2.write(pos);
    servo3.write(pos);   
    delay(10);                       
  }
  delay(4000);  // Music starts and suddenly stops
  for (pos =90; pos <= 120; pos += 1) { 
    servo6.write(pos);  
    delay(10); 
  }
  for (pos = 90; pos >= 30; pos -= 1) { 
    servo5.write(pos);   
    delay(5);                       
  }
  delay(1000);
   for (pos = 30; pos <= 110; pos += 1) { 
    servo5.write(pos);   
    delay(5);                       
  }  
  delay(1000);
   for (pos = 110; pos >= 80; pos -= 1) { 
    servo5.write(pos);   
    delay(10);                       
  }
  delay(500);
  for (pos =120; pos >= 75; pos -= 1) { 
    servo6.write(pos);  
    delay(20);                      
  }
delay(5000);// music continues


  // Celebrate name
  for (pos =90; pos <= 120; pos += 1) { 
    servo6.write(pos);  
    delay(10);     
  }
  delay(1000);
  for (pos = 90; pos >= 30; pos -= 1) { 
    servo4.write(pos);
    servo1.write(180-pos);                          
  }


  // THIS IS WHERE THE C MOTOR QUICKLY SHOOTS HIM FORWARD AND HE GETS CONFUSED
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);  
  for (i=0; i<70; i++) {
    myMotor->setSpeed(255);  
    myOtherMotor->setSpeed(255); 
    delay(10);
  }
  myMotor->run(RELEASE);
  myOtherMotor->run(RELEASE); 
  delay(500);

  //Looks at wheels
  for (pos = 30; pos <= 140; pos += 1) { 
    servo4.write(pos);
    servo1.write(180-pos);   
    delay(1);
  }  
    servo2.write(90);
    servo3.write(90);   
   for (pos = 120; pos >= 90; pos -= 1) { 
    servo6.write(pos);   
    delay(10);                       
  }
  delay(2000);


  //Tests wheels
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);  
  for (i=0; i<50; i++) {
    myMotor->setSpeed(255);  
    myOtherMotor->setSpeed(255); 
    delay(10);
  }
  myMotor->run(RELEASE);
  myOtherMotor->run(RELEASE); 
  delay(2000);
  
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);  
  for (i=0; i<70; i++) {
    myMotor->setSpeed(255);  
    myOtherMotor->setSpeed(255); 
    delay(10);
  }
  myMotor->run(RELEASE);
  myOtherMotor->run(RELEASE); 
  delay(1000);

  
  for (pos =90; pos <= 120; pos += 1) { 
    servo6.write(pos);  
    delay(40);  
  }
  delay(2000);
  for (pos = 140; pos >= 90; pos -= 1) { 
    servo4.write(pos);
    servo1.write(180-pos);   
    delay(1);
  }

  //MUSIC STARTS AGAIN AND HE GOES TOWARDS THE TV
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);  
  for (i=0; i<200; i++) {
    myMotor->setSpeed(255);  
    myOtherMotor->setSpeed(255); 
    delay(10);
  }
  myMotor->run(RELEASE);
  myOtherMotor->run(RELEASE);
  
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);  
  for (i=0; i<200; i++) {
    myMotor->setSpeed(125);  
    myOtherMotor->setSpeed(255); 
    delay(10);
  }
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);  
  for (i=0; i<200; i++) {
    myMotor->setSpeed(125);  
    myOtherMotor->setSpeed(255); 
    delay(10);
  }
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);  
  for (i=0; i<200; i++) {
    myMotor->setSpeed(125);  
    myOtherMotor->setSpeed(255); 
    delay(10);
  }
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);  
  for (i=0; i<200; i++) {
    myMotor->setSpeed(125);  
    myOtherMotor->setSpeed(255); 
    delay(10);
  }
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);  
  for (i=0; i<200; i++) {
    myMotor->setSpeed(125);  
    myOtherMotor->setSpeed(255); 
    delay(10);
  }
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);  
  for (i=0; i<200; i++) {
    myMotor->setSpeed(255);  
    myOtherMotor->setSpeed(255); 
    delay(10);
  }
 myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);  
  for (i=0; i<200; i++) {
    myMotor->setSpeed(255);  
    myOtherMotor->setSpeed(255); 
    delay(10);
  }
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);  
  for (i=0; i<200; i++) {
    myMotor->setSpeed(255);  
    myOtherMotor->setSpeed(255); 
    delay(10);
  }
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);  
  for (i=0; i<200; i++) {
    myMotor->setSpeed(255);  
    myOtherMotor->setSpeed(255); 
    delay(10);
  }
  myMotor->run(RELEASE);
  myOtherMotor->run(RELEASE);
  delay(3000);
  
  // handS AND HEAD LOOK AT TV
  for (pos = 90; pos <= 140; pos += 1) { 
    servo4.write(pos);
    servo1.write(180-pos);   
    delay(10);
  }
  for (pos = 120; pos >= 90; pos -= 1) { 
    servo6.write(pos);   
    delay(50);                       
  }

 //BUMP TV TWICE
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);  
  for (i=0; i<80; i++) {
    myMotor->setSpeed(255);  
    myOtherMotor->setSpeed(255); 
    delay(10);
  }
  myMotor->run(RELEASE);
  myOtherMotor->run(RELEASE); 
  myMotor->run(BACKWARD);
  myOtherMotor->run(BACKWARD);  
  for (i=0; i<80; i++) {
    myMotor->setSpeed(255);  
    myOtherMotor->setSpeed(255); 
    delay(10);
  }
  myMotor->run(RELEASE);
  myOtherMotor->run(RELEASE); 
  delay(1000);
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);  
  for (i=0; i<80; i++) {
    myMotor->setSpeed(255);  
    myOtherMotor->setSpeed(255); 
    delay(10);
  }
  myMotor->run(RELEASE);
  myOtherMotor->run(RELEASE); 
  myMotor->run(BACKWARD);
  myOtherMotor->run(BACKWARD);  
  for (i=0; i<80; i++) {
    myMotor->setSpeed(255);  
    myOtherMotor->setSpeed(255); 
    delay(10);
  }
  myMotor->run(RELEASE);
  myOtherMotor->run(RELEASE); 
  delay(1000);


  // HAND SWITCH ON TV
  for (pos = 140; pos >= 90; pos -= 1) { 
    servo4.write(pos); 
    delay(10);
  }
  delay(1000);
  for (pos = 90; pos <= 140; pos += 1) { 
    servo4.write(pos); 
    delay(10);
  }
  for (pos =90; pos <= 120; pos += 1) { 
    servo6.write(pos);  
    delay(10); 
  }
  for (pos = 90; pos >= 30; pos -= 1) { 
    servo5.write(pos);   
    delay(5);                       
  }
  delay(1000);
   for (pos = 30; pos <= 110; pos += 1) { 
    servo5.write(pos);   
    delay(5);                       
  }  
  delay(1000);
   for (pos = 110; pos >= 80; pos -= 1) { 
    servo5.write(pos);   
    delay(10);                       
  }
  delay(500);
  for (pos =120; pos >= 75; pos -= 1) { 
    servo6.write(pos);  
    delay(20);                      
  }

  //RE-CENTRE
  myMotor->run(BACKWARD);
  myOtherMotor->run(BACKWARD);  
  for (i=0; i<200; i++) {
    myMotor->setSpeed(0);  
    myOtherMotor->setSpeed(255); 
    delay(10);
  }
  myMotor->run(BACKWARD);
  myOtherMotor->run(BACKWARD);  
  for (i=0; i<200; i++) {
    myMotor->setSpeed(0);  
    myOtherMotor->setSpeed(255); 
    delay(10);
  }
  myMotor->run(RELEASE);
  myOtherMotor->run(RELEASE);
  servo6.write(120);
  delay(4000);


  // CUTE
  servo2.write(60);
  servo3.write(60);
  delay(4000);
  for (pos = 120; pos >= 90; pos -= 1) { 
    servo6.write(pos);   
    delay(50);                       
  }
  delay(2000);
  for (pos = 90; pos >= 30; pos -= 1) { 
    servo5.write(pos);   
    delay(40);                       
  }
  delay(1000);
   for (pos = 30; pos <= 110; pos += 1) { 
    servo5.write(pos);   
    delay(40);                       
  }
  delay(1000);
  for (pos = 110; pos >= 80; pos -= 1) { 
    servo5.write(pos);   
    delay(40);                       
  }
  for (pos = 140; pos >= 90; pos -= 1) { 
    servo4.write(pos);
    servo1.write(180-pos);   
    delay(50);
  }  
  for (pos = 60; pos <=90; pos += 1) {
    servo2.write(pos);
    servo3.write(pos);
    delay(50);
  }
  delay(2000);
  for (pos =90; pos <= 120; pos += 1) { 
    servo6.write(pos);  
    delay(100);                      
  }
  delay(1000);
  delay(8000);  
}

  
  
