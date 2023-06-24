#include "WIFI_Command.h"

//#define COMM_BRAKE  		'I'//停止
//#define COMM_FORWARD    'A'//前进
//#define COMM_BACK  			'B'//后退
//#define COMM_LEFT  			'C'//左转
//#define COMM_RIGHT 			'D'//右转

char receive_command()
{
	char comm=COMM_BRAKE;
	uint8_t reclen=0;
	if(USART2_RX_STA!=0)	//接收到一次数据了
		{

			reclen=USART2_RX_STA&0X7FFF;	//得到数据长度
			USART2_RX[reclen]=0;	 				//加入结束符
			printf("%s!\n",USART2_RX);
			printf("%d!\n",reclen);
			if(reclen==3)
			{	
				//以下是控制云台舵机
				if(strcmp((const char*)USART2_RX,"ONL")==0)//左
				{
					comm = 'L';
				}
				else if(strcmp((const char*)USART2_RX,"ONI")==0)//右
				{
          comm = 'R';
				}
				else if(strcmp((const char*)USART2_RX,"ONJ")==0)//上
				{
          comm = 'J';
				}
				else if(strcmp((const char*)USART2_RX,"ONK")==0)//下
				{
          comm = 'K';
				}
				//以下是控制电机
				if(strcmp((const char*)USART2_RX,"ONA")==0)
				{
          comm = COMM_FORWARD;
				}
				else if(strcmp((const char*)USART2_RX,"ONB")==0)
				{
					comm = COMM_BACK;
				}
				else if(strcmp((const char*)USART2_RX,"ONC")==0)
				{
					comm = COMM_RIGHT;
				}
			  else if(strcmp((const char*)USART2_RX,"OND")==0)
				{
					comm = COMM_LEFT;
				}
			  else if(strcmp((const char*)USART2_RX,"ONE")==0)
				{
					comm = COMM_BRAKE;
				}
				else if(strcmp((const char*)USART2_RX,"ONF")==0)
				{
					comm = COMM_BRAKE;
				}
				USART2_RX_STA=0;
			}
					
		}	
	return comm;	
}
