# Smart_Car_WIFI_Camera
利用WIFI将摄像头数据回传、利用WIFI接收控制指令

# 0621
完成了云台舵机的相关调试，更新了舵机控制函数

更新了超声波测距的中断服务函数

完成了串口中断服务程序的编写

# 0622
完成了接收信号相关函数的编写，目前调试未通过
 
# 0623
修改了寻迹传感器的接线，解决了之前无法连接中间寻迹的问题

新增了适用于单线寻迹的逻辑，目前未通过测试

完善了串口收发的重定向，完成了串口收发数据的调试

# 0624
修改了指令接收函数

基于有线串口完成了控制指令收发

# 0625
完善了双线红外寻迹的逻辑并完成测试

基于WIFI完成了控制指令收发，但目前仅有一次成功

# 0626
修改了WIFI指令收发的逻辑，完成了基于WIFI模块的指令收发

# 0814
修改了指令接收函数的参数，使采样率降低，运行更快