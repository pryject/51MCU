#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNum;
unsigned int Password;
unsigned int Count;
void main()
{ LCD_Init();
	LCD_ShowString(1,1,"----");
	while(1)
	{
		KeyNum=MatrixKey();
		if(KeyNum)
		{
			if(KeyNum<=10) //如果s1~s10按键按下，输入密码
			{
				if(Count<4)
				{
				Password*=10;         //密码左移一位
				Password+=KeyNum%10;					//获取一位密码
				Count++;//计次加一
				}
				LCD_ShowNum(1,1,Password,4); //更新显示
			}	
				if(KeyNum==11)  //如果s11按键按下，确认
				{
					if(Password==2580)
					{
						LCD_ShowString(1,13,"PASS ");//显示OK
						Password=0;//密码清零
						Count=0;//密码清零
						LCD_ShowNum(1,1,Password,4);//更新显示
					}
					else//否则
					{
						LCD_ShowString(1,13,"EEEE");//显示ERR
						Password=0;//密码清零
						Count=0;//密码清零
						LCD_ShowNum(1,1,Password,4);//更新显示
					}
				}
				if(KeyNum==12)//如果s12按键按下，取消
				{
					Password=0;//密码清零
					Count=0;//密码清零
					LCD_ShowNum(1,1,Password,4);//更新显示
				}
		}
	}
}