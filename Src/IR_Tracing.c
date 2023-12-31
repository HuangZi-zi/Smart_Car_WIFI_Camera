#include "IR_Tracing.h"
#include "main.h"
#include "motor.h"

char ctrl_comm = COMM_BRAKE;			//控制指令
char ctrl_comm_last = COMM_BRAKE;	//上一次的指令

//两侧黑胶带，三个传感器均位于白色部分
//当某一侧超出黑色部分，说明方向偏离，应当转向

char TracingRun(void)
{
  //两侧双线
	//白白白 直行
	if(READ_TRACING_L==WHITE_AREA && READ_TRACING_M==WHITE_AREA && READ_TRACING_R==WHITE_AREA)
		ctrl_comm = COMM_FORWARD;
	//黑白白 右转
	else if (READ_TRACING_L == BLACK_AREA && READ_TRACING_M == WHITE_AREA && READ_TRACING_R == WHITE_AREA)
		ctrl_comm = COMM_RIGHT;
	//白白黑 左转
	else if (READ_TRACING_L == WHITE_AREA && READ_TRACING_M == WHITE_AREA && READ_TRACING_R == BLACK_AREA)
		ctrl_comm = COMM_LEFT;
	//白黑白 后退
	else if (READ_TRACING_L == WHITE_AREA && READ_TRACING_M == BLACK_AREA && READ_TRACING_R == WHITE_AREA)
		ctrl_comm = COMM_BACK;
	else ctrl_comm = COMM_BRAKE;
	
////中间单线
//	//白黑白 直行
//	if(READ_TRACING_L==WHITE_AREA && READ_TRACING_M==BLACK_AREA && READ_TRACING_R==WHITE_AREA)
//		ctrl_comm = COMM_FORWARD;
//	//黑白白 左转
//	else if (READ_TRACING_L == BLACK_AREA && READ_TRACING_M == WHITE_AREA && READ_TRACING_R == WHITE_AREA)
//		ctrl_comm = COMM_LEFT;
//	//白白黑 右转
//	else if (READ_TRACING_L == WHITE_AREA && READ_TRACING_M == WHITE_AREA & READ_TRACING_L == BLACK_AREA)
//		ctrl_comm = COMM_RIGHT;
//	//白白白 后退
//	else if (READ_TRACING_L == WHITE_AREA && READ_TRACING_M == WHITE_AREA & READ_TRACING_L == WHITE_AREA)
//		ctrl_comm = COMM_BACK;
//	//白黑黑 右转
//	else if (READ_TRACING_L == WHITE_AREA && READ_TRACING_M == BLACK_AREA & READ_TRACING_L == BLACK_AREA)
//		ctrl_comm = COMM_RIGHT;
//	//黑黑白 左转
//	else if (READ_TRACING_L == BLACK_AREA && READ_TRACING_M == BLACK_AREA & READ_TRACING_L == WHITE_AREA)
//		ctrl_comm = COMM_LEFT;
//	else ctrl_comm = COMM_BRAKE;
	if(ctrl_comm_last != ctrl_comm)
	{
			ctrl_comm_last = ctrl_comm;
	}
	return ctrl_comm;
}
