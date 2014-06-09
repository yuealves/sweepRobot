#ifndef _ULTRASONICDRIVER_H
#define _ULTRASONICDRIVER_H
#include <Arduino.h>
#define TrigPin 2
#define EchoPin 3
double getDistance()
{
    digitalWrite(TrigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(TrigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(TrigPin,LOW);
    return double(pulseIn(EchoPin,HIGH)*17)/1000;
}
#endif // for #ifndef _ULTRASONICDRIVER_H
