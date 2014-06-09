#include "carDriver.h"
car::car(int pinI1,int pinI2,int pinI3,int pinI4,int speedPinA,int speedPinB)
{
    this->pinI1=pinI1;
	this->pinI2=pinI2;
	this->pinI3=pinI3;
	this->pinI4=pinI4;
	this->speedPinA=speedPinA;
	this->speedPinB=speedPinB;
	pinMode(pinI1,OUTPUT);
	pinMode(pinI2,OUTPUT);
	pinMode(pinI3,OUTPUT);
	pinMode(pinI4,OUTPUT);
	pinMode(speedPinA,OUTPUT);
	pinMode(speedPinB,OUTPUT);
	setSpeed(100,100);//Ĭ���ٶ�Ϊ100
}
void car::setSpeed(int speedLeft,int speedRight)
{
	analogWrite(speedPinA,speedLeft);
	analogWrite(speedPinB,speedRight);
}
void car::goAhead(int speed=100)
{
	setSpeed(speed,speed);//ֱ��ʱ�����ٶ�һ�£�����ָ���ٶȣ���Ĭ��ֱ���ٶ�Ϊ100
	digitalWrite(pinI4,LOW);
	digitalWrite(pinI3,HIGH);
	digitalWrite(pinI2,LOW);
	digitalWrite(pinI1,HIGH);
}
void car::goBack(int speed=80)
{
	setSpeed(speed,speed);
	digitalWrite(pinI3,LOW);
	digitalWrite(pinI4,HIGH);
	digitalWrite(pinI1,LOW);
	digitalWrite(pinI2,HIGH);
}
car::car(void){}
void car::setPin(int pinI1,int pinI2,int pinI3,int pinI4,int speedPinA,int speedPinB)
{
	this->pinI1=pinI1;
	this->pinI2=pinI2;
	this->pinI3=pinI3;
	this->pinI4=pinI4;
	this->speedPinA=speedPinA;
	this->speedPinB=speedPinB;
	pinMode(pinI1,OUTPUT);
	pinMode(pinI2,OUTPUT);
	pinMode(pinI3,OUTPUT);
	pinMode(pinI4,OUTPUT);
	pinMode(speedPinA,OUTPUT);
	pinMode(speedPinB,OUTPUT);
	setSpeed(100,100);//Ĭ���ٶ�Ϊ100
}
void car::goOnPatrol()
{
	if(getDistance()<=7)
		turnRight();//��⵽�����ǽʱ,����ת���Ƕȱ���ײǽ
	else
	{
		setSpeed(70,90);//���ֱ������Կ�,С����������б��ʻ,�Ա��ܿ���ǽ
		digitalWrite(pinI4,LOW);
		digitalWrite(pinI3,HIGH);
		digitalWrite(pinI2,LOW);
		digitalWrite(pinI1,HIGH);
	}

}
void car::turnLeft()
{
	setSpeed(1,90);
	digitalWrite(pinI4,LOW);
	digitalWrite(pinI3,HIGH);
	digitalWrite(pinI2,LOW);
	digitalWrite(pinI1,HIGH);
}
void car::turnRight()
{
	setSpeed(90,1);
	digitalWrite(pinI4,LOW);
	digitalWrite(pinI3,HIGH);
	digitalWrite(pinI2,LOW);
	digitalWrite(pinI1,HIGH);
}
