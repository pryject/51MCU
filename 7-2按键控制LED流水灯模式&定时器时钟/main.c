#include <REGX52.H>
#include "Timer0.h" 	
#include "Key.h"
#include <INTRINS.H> 
unsigned char KeyNum,LEDMode;
void main()
{
	P2=0xFE;
	Timer0_Init();
	while(1)
	{
		KeyNum=Key();
		if(KeyNum)
		{
			if(KeyNum==1)//表示按键按下为K1
			{
				LEDMode++;
				if(LEDMode>=2)
					LEDMode=0;//表示系统只有0，1两种模式
			}
		}
	}

}

void Timer0_Routine() interrupt 1//interrupt 1 表示51单片机中定时器0的固定中断号
{ 
	static unsigned int T0Count;//记录中断次数           static在函数运行完之后不销毁，只由此函数引用
	TL0 = 0x18;
	TH0 = 0xFC;
	T0Count++;
	if(T0Count>=500)
	{
		T0Count=0;
		if(LEDMode==0)
		{
			P2=_crol_(P2,1); //_crol_是循环左移函数
		}
		if(LEDMode==1) //按下K1
		{
			P2=_cror_(P2,1);//_cror_是循环右移函数
		}
	}
	 
}



