
//deze code is om een 2wheel robot te besturen met keyboard input en L298n H-bridge met c++ en vscode gebaseerde editor.
#include <iostream> // voor input en output
#include <wiringPi.h> // de gpio library  we gebruiken.
// deze char zijn voor keyboard input.
char s = 's';
char f = 'f';
char b = 'b';
char l = 'l';
char r = 'r';
char key;

//dit zijn de pinnen voor de rechter kant van de motor.
int ena = 17;
int in1 = 23;
int in2 = 24;
//dit zijn de pinnen voor de linker kant van de motor.
int enb = 14;
int in3 = 15;
int in4 = 18;


void setup()  { //setup de pins voor gebruik

    wiringPiSetupGpio(); // setup de pins in  BCM nummers.
     pinMode(ena,OUTPUT);
     pinMode(in1,OUTPUT);
     pinMode(in2,OUTPUT); 

     pinMode(enb,OUTPUT);
     pinMode(in3,OUTPUT);
     pinMode(in4,OUTPUT); 

}
// hier zijn de motor directies.


void stop() {
   
digitalWrite(ena,LOW);
digitalWrite(enb,LOW);

digitalWrite(in1,LOW);
digitalWrite(in2,LOW);

digitalWrite(in3,LOW);
digitalWrite(in4,LOW);
std::cout << " The robot stops";
    }
        void forward() {
       

      
digitalWrite(ena,HIGH);
digitalWrite(enb,HIGH);

digitalWrite(in1,LOW);
digitalWrite(in2,HIGH);

digitalWrite(in3,LOW);
digitalWrite(in4,HIGH);
std::cout << "The robot move forward";
delay(2000);
stop();
 }
            void backward() {
        
digitalWrite(ena,HIGH);
digitalWrite(enb,HIGH);

digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);

digitalWrite(in3,HIGH);
digitalWrite(in4,LOW);


std::cout << "The robot move backward";
delay(2000);
stop(); 

    }

    void left() {

digitalWrite(ena,HIGH);
digitalWrite(enb,HIGH);

digitalWrite(in1,LOW);
digitalWrite(in2,HIGH);

digitalWrite(in3,HIGH);
digitalWrite(in4,LOW);
std::cout << "The robot move left";
delay(2000);
stop(); 
        
    }
    void right()  {
     

digitalWrite(ena,HIGH);
digitalWrite(enb,HIGH);

digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);

digitalWrite(in3,LOW);
digitalWrite(in4,HIGH);
std::cout << "The robot move right";
delay(2000);
stop();
    }
   



int main() {

setup();

while (1)
{ key = std::cin.get(); // leest de keyboard input.
  if (key == s) { // als de s key is gedrukt stopt de motor
    stop();
  }
  if (key == f) { //    als de f key is gedrukt rijdt de motor vooruit
    forward();
  }
  if (key == b) { //  als de b key is gedrukt rijdt  de motor achteruit.
    backward();
  }
  if (key == l) { //  als de s key is gedrukt rijdt  de motor links .
    left();
  }
  if (key == r) //  als de r key is gedrukt rijdt de motor rechts.
  right();
}

return 0;
  
}