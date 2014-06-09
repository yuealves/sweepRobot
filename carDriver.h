#ifndef _CARDRIVER_H
#define _CARDRIVER_H
#include <Arduino.h>
#include "ultraSonicDriver.h"
using namespace std;    
class car
{
public:
    int pinI1;
    int pinI2;
    int pinI3;
    int pinI4;
	int speedPinA;
	int speedPinB;
    car(int pinI1,int pinI2,int pinI3,int pinI4,int speedPinA,int speedPinB);
	car(void);
	void setPin(int pinI1,int pinI2,int pinI3,int pinI4,int speedPinA,int speedPinB);
    void goAhead(int speed=200);
    void turnLeft();
    void turnRight();
	void goBack();
    void goOnPatrol();
    void sweep();
    void stopSweep();
    void setSpeed(int speedLeft,int speedRight);
};

#endif // for #ifndef _CARDRIVER_H
