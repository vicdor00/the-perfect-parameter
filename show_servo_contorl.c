//示例控制动作
void servo_reset(void)
{
	//让舵机1 从当前位置在1.5s内 移动到 0°，阻塞模式
	FSUS_SetServoAngle(&usart2, 1, 1, 1500, 0, 1);
	
	//其余同理
	FSUS_SetServoAngle(&usart2, 2, 0, 1500, 0, 1);
	
	FSUS_SetServoAngle(&usart2, 3, -46, 1500, 0, 1);
	
	FSUS_SetServoAngle(&usart2, 4, 45, 1500, 0, 1);
}

/*flag为顺逆标志位，0为顺时针，1为逆时针*/
void servo_rotate(void)
{
    
    switch(servo_which)
    {
        case 1:
            if(get_key_state(KEY1) == 0)
            {
                if(servo_flag == 0){
                    FSUS_SetServoAngle(&usart2, 1, 120, 1500, 0, 1);
                }   
                else
                {
                    FSUS_SetServoAngle(&usart2, 1, -120, 1500, 0, 1);
                }
            }
        break;
        case 2:
            if(get_key_state(KEY2) == 0)
            {
                if(servo_flag == 0){
                    FSUS_SetServoAngle(&usart2, 2, 40, 1500, 0, 1);
                }
                else
                   FSUS_SetServoAngle(&usart2, 2, -60, 1500, 0, 1); 
            }
        break;
        case 3:
            if(get_key_state(KEY3) == 0)
            {
                if(servo_flag == 0)
                    FSUS_SetServoAngle(&usart2, 3, 30, 1500, 0, 1);
                else
                    FSUS_SetServoAngle(&usart2, 3, -80, 1500, 0, 1);
            }
        break;
        case 4:
            if(get_key_state(KEY2) == 0)
            {
                if(servo_flag == 0)
                    FSUS_SetServoAngle(&usart2, 4, 50, 1500, 0, 1);
                else
                    FSUS_SetServoAngle(&usart2, 4, -3, 1500, 0, 1);
            }
        break;
            default:
                
        break;
        
    }
}
void servo_conversion(void)
{
    if(++servo_which == 5) servo_which = 1;
}


void servo_do(void)
{

            // 开始，第一步抓取
            FSUS_SetServoAngle(&usart2, 1, -85, 1500, 0, 1);
            FSUS_SetServoAngle(&usart2, 2, 60, 1500, 0, 1);
            FSUS_SetServoAngle(&usart2, 3, -130, 1500, 0, 1);
            FSUS_SetServoAngle(&usart2, 4, 2, 1000, 0, 1);
        

            // 第二步，放到指定位置

            FSUS_SetServoAngle(&usart2, 2, 10, 1500, 0, 0);
            mdelay(500);
            FSUS_SetServoAngle(&usart2, 3, -65, 1500, 0, 0);
            
            
            FSUS_SetServoAngle(&usart2, 1, -125, 1500, 0, 1);
            FSUS_SetServoAngle(&usart2, 2, 50, 1500, 0, 1);
            FSUS_SetServoAngle(&usart2, 3, -135, 1500, 0, 1);
            FSUS_SetServoAngle(&usart2, 4, 10, 1000, 0, 1);
          
        
            
            // 第三步，复位
            FSUS_SetServoAngle(&usart2, 3, -60, 1000, 0, 0);
            FSUS_SetServoAngle(&usart2, 1, 1, 1500, 0, 0);
            FSUS_SetServoAngle(&usart2, 2, 0, 1500, 0, 0);
            FSUS_SetServoAngle(&usart2, 3, -46, 1500, 0, 0);
            FSUS_SetServoAngle(&usart2, 4, 25, 1500, 0, 1);

}