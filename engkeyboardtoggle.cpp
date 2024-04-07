// this is a code to control a led with a Keyboard using
// in Vscode editor termial  in c++ language.
#include <iostream> // ztakes care of input and output.
#include <wiringPi.h> // is the Gpio library we use. 
// more info about wiringpi is here: https://github.com/WiringPi/WiringPi


char on = 'a'; // led goes on if you press :b  in terminal.
char off = 'b'; // led gaat goeos off if you press : b  in terminal.
char key; //  reads the  keyboard commands.
int led = 21; // says that the led pin is 21 from the BCM pinout.

int main() {

    wiringPiSetupGpio(); // takes care that the BCM pin works.
    pinMode(led,OUTPUT); // says that led pin a  output is.
    while (1) {
    key = std::cin.get(); 
    if (key == on) // if key == on : led is on
    {
        digitalWrite(led,HIGH);
        delay(1000);
        std::cout << "led is on ";
    }
    if (key == off) // if key == off:  led is off
    {
        digitalWrite(led,LOW);
        std::cout << "led is off. ";
        delay(1000);
    }
    
    }
}
