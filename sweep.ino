#include "carDriver.h"
#include "InfraredRemote.h"
#include "ultraSonicDriver.h"
int pinI1=8;//定义I1
int pinI2=9;//定义I2接口
int speedPinA=11;//定义EA(PWM调速)接口
int pinI3=6;//定义I3接口
int pinI4=7;//定义I4接口
int speedPinB=10;//定义EB(PWM调速)接口
car myCar;
int controller=5;
bool sweepController=0;
void setup()
{
	myCar.setPin(pinI1,pinI2,pinI3,pinI4,speedPinA,speedPinB);//设置四驱车马达模块的引脚
	pinMode(IR_IN,INPUT_PULLUP);//设置红外接收引脚为输入,默认引脚IR_IN为4
	pinMode(EchoPin,INPUT);
    pinMode(TrigPin,OUTPUT);//设置超声波模块的引脚,默认TrigPin=2,EchoPin=3
	timer1_init();//定时器初始化
}
void loop()
{
	myCar.goAhead();
}
void remoteController()
{
	switch(controller)
	{
	case 1:myCar.goAhead();break;
	case 2:myCar.turnLeft();break;
	case 3:myCar.turnRight();break;
	case 4:myCar.goBack();break;
	case 5:myCar.goOnPatrol();break;
	}
	if(sweepController) 
		myCar.sweep();
	else
		myCar.stopSweep();
}
void setController()
{
	switch(adrL_code)
	{
	case 0x16:sweepController=1;
	case 0x19:sweepController=0;
	case 0x46:controller=1;break;//up
	case 0x07:controller=2;break;//left
	case 0x09:controller=3;break;//right
	case 0x15:controller=4;break;//back;
	case 0x40:controller=5;break;//patrol
	default:break;
	}

}

