#include "servo.h"
#include "main.h"
#include "tim.h"

//舵机的角度由PWM信号的占空比控制
//角度		0				45		90			135			180
//PWM			0.5ms		1ms		1.5ms		2ms			2.5ms

//用于控制舵机的PWM频率50HZ， 周期20ms (Tim5 Chn1)
//对应可调的占空比为2.5%～12.5%
//对应的比较值为100~500
void SetJointAngle(int ID,float angle)
{
	angle=(uint16_t)(20.0*angle/9.0+100.0);
	switch (ID)
	{
		case Servo_Ultrasonic:
			__HAL_TIM_SetCompare(&htim5,TIM_CHANNEL_1,angle);
			break;
		case Servo_Pitch:
			__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,angle);
			break;
		case Servo_Pan:
			__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_4,angle);
			break;
		default:
			break;
	}

	
}

