#ifndef __SERVO_H_
#define __SERVO_H_

//#define Servo_Ultrasonic_PWM_Pin 						GPIO_PIN_0
//#define Servo_Ultrasonic_PWM_GPIO_Port 			GPIOA
//#define Servo_Pitch_PWM_Pin 								GPIO_PIN_6
//#define Servo_Pitch_PWM_GPIO_Port 					GPIOA
//#define Servo_Pan_PWM_Pin 									GPIO_PIN_1
//#define Servo_Pan_PWM_GPIO_Port 						GPIOB

//端子号为扩展板上的端子号
#define Servo_Ultrasonic 			2								//TIM5 CH1
#define Servo_Pitch						12							//TIM3 CH1
#define Servo_Pan							5								//TIM3 CH4


void SetJointAngle(int ID, float angle);

#endif
