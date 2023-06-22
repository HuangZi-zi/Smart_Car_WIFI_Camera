#include "WIFI_Command.h"

//#define COMM_BRAKE  		'I'//ֹͣ
//#define COMM_FORWARD    'A'//ǰ��
//#define COMM_BACK  			'B'//����
//#define COMM_LEFT  			'C'//��ת
//#define COMM_RIGHT 			'D'//��ת

char receive_command()
{
	uint8_t reclen=0;
	if(USART2_RX_STA&0X8000)	//���յ�һ��������
		{
			reclen=USART2_RX_STA&0X7FFF;	//�õ����ݳ���
			USART2_RX[reclen]=0;	 				//���������
		//	printf("USART2_RX_BUF:%s\n",USART2_RX_BUF);
		//	printf("reclen:%d\n",reclen);
			if(reclen==3)
			{	
				//�����ǿ�����̨���
				if(strcmp((const char*)USART2_RX,"ONL")==0)//��
				{
					pan_left();
				}
				else if(strcmp((const char*)USART2_RX,"ONI")==0)//��
				{
          pan_right();
				}
				else if(strcmp((const char*)USART2_RX,"ONJ")==0)//��
				{
          pitch_up();
				}
				else if(strcmp((const char*)USART2_RX,"ONK")==0)//��
				{
          pitch_down();
				}
				//�����ǿ��Ƶ��
				if(strcmp((const char*)USART2_RX,"ONA")==0)
				{
          return COMM_FORWARD;
				}
				else if(strcmp((const char*)USART2_RX,"ONB")==0)
				{
					return COMM_BACK;
				}
				else if(strcmp((const char*)USART2_RX,"ONC")==0)
				{
					return COMM_RIGHT;
				}
			  else if(strcmp((const char*)USART2_RX,"OND")==0)
				{
					return COMM_LEFT;
				}
			  else if(strcmp((const char*)USART2_RX,"ONE")==0)
				{
					return COMM_BRAKE;
				}
				else if(strcmp((const char*)USART2_RX,"ONF")==0)
				{
					return COMM_BRAKE;
				}
			}
			USART2_RX_STA=0;		
		}	
}
