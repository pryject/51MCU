#include <REGX52.H>
#include "Delay.h" 
#include "UART.h" 

//一个函数不能既在主函数里面出现又在中断函数里面出现，会导致函数的重复会破环原来的函数
void main()
{
  UART_Init();
	
	while(1)
	{
		
	}

}

void UART_Routine() interrupt 4 //当interrupt跟在谁后面谁就充当中断函数
{
	if(RI==1) //为什么需要这个判断因为发送的时候也会触发中断，以此区分发送和接收
	{
		P2=~SBUF;
		UART_SendByte(SBUF);
		RI=0;
	}
}
