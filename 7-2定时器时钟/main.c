#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h" 
#include "Timer0.h" 

unsigned char Sec=53,Min=59,Hour=23;

void main()
{
	LCD_Init();
	Timer0_Init();
	LCD_ShowString(1,1,"CLOCK:");
	LCD_ShowString(2,1,"  :  :");
	
	while(1)
	{
		LCD_ShowNum(2,1,Hour,2);
		LCD_ShowNum(2,4,Min,2);
		LCD_ShowNum(2,7,Sec,2);
		
	}

}
void Timer0_Routine() interrupt 1
{ 
	static unsigned int T0Count;//在函数运行完之后不销毁，只由此函数引用
	TL0 = 0x18; //重新赋初值
	TH0 = 0xFC; //重新赋初值
	T0Count++; //每ms加1
	if(T0Count>=1000)//加到1000代码被截断了重置T0Count=0
	{
		T0Count=0;
		Sec++;
		if(Sec>=60)
		{
			Sec=0;
			Min++;
			if(Min>=60)
			{
				Min=0;
				Hour++;
			}
			if(Hour>=24)
			{
				Hour=0;
			}
		}
	}
	 
}