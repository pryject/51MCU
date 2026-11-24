#include <REGX52.H>

/**
  * @brief  定时器0初始化，1毫秒@12.000MHz
  * @param  无
  * @retval 无
  */



	void Timer0_Init(void)		//
{
	TMOD &= 0xF0;		//设置定时器模式  高4位控制定时器1，低4位控制定时器0
	TMOD |= 0x01;		//设置定时器模式  加前面一行代码，保留高4位，并将低4位清零后设为0001，代表定时器0工作在模式1
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	TF0 = 0;		//清除TF0标志  清除定时器0的溢出标志位（防止一开启就触发中断）
	TR0 = 1;		//定时器0开始计时
	//少了中断配置
	ET0=1;  //开启定时器0的中断允许位
	EA=1;//允许总中断
	PT0=0;//中断优先级=0
}

/*定时器中断函数模板
void Timer0_Routine() interrupt 1
{ 
	static unsigned int T0Count;//在函数运行完之后不销毁，只由此函数引用
	TL0 = 0x18; //重新赋初值
	TH0 = 0xFC; //重新赋初值
	T0Count++; //每ms加1
	if(T0Count>=1000)//加到1000代码被截断了重置T0Count=0
	{
		T0Count=0;
		P2_0=~P2_0;
	}
	 
}
*/