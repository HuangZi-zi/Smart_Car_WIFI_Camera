#include "servo.h"
#include "main.h"
#include "tim.h"

//����ĽǶ���PWM�źŵ�ռ�ձȿ���
//�Ƕ�		0				45		90			135			180
//PWM			0.5ms		1ms		1.5ms		2ms			2.5ms

//���ڿ��ƶ����PWMƵ��50HZ�� ����20ms (Tim5 Chn1)
//��Ӧ�ɵ���ռ�ձ�Ϊ2.5%��12.5%
//��Ӧ�ıȽ�ֵΪ100~500
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

