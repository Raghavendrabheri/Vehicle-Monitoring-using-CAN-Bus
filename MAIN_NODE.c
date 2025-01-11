//can_tx_test.c
#include "can.h"
#include "delay.h"
#include"lcd.h"
#include "can_defines.h"
#include "defines.h"
#include <string.h>
#include <stdlib.h>
#include<lpc21xx.h>

#define  EINT0_CHNO 14
#define  EINT1_CHNO 15
#define LED 24;
void eint0_isr(void)__irq;
void eint1_isr(void)__irq;
int ReadTemp(void);

CANF txF,rxF;
int temp;
int main()
{
	Init_CAN1();
	InitLCD();
  	IODIR0|=1<<LED;
	//interrupts enabling and allocating slots 
	PINSEL0 |= 0x20000000;//p0.14
	PINSEL1 |= 0x15400001;//p0.16 
	VICIntEnable=((1<<EINT0_CHNO) | (1<<EINT1_CHNO));  //interrupts enabled here
	VICVectCntl0=(1<<5) |EINT0_CHNO;
	VICVectAddr0 =(unsigned int)eint0_isr;
	VICVectCntl1=1<<5 |EINT1_CHNO;
	VICVectAddr1= (unsigned int)eint1_isr;
	
	//EXTMODE |=1<<0;
	//EXTMODE |=1<<1;		
	txF.ID=1;	
	txF.BFV.RTR=0;
	txF.BFV.DLC=1;
	while(1)
	{
	   	StrLCD("CAN Project");
		CmdLCD(0xC0);
		StrLCD("Temp :");
		temp= ReadTemp();
		U32LCD(temp>>4);
		
		CmdLCD(0x94);
		 if(READBIT(C1GSR,RBS_BIT)) //checking whether frame is available or not
		 {
				CAN1_Rx(&rxF);
				if(rxF.ID==3)	//checking  rcv frame id here 
				{
					IOCLR0=1<<LED;
					StrLCD("unsafe");
		 		}
		 }
		 else
		 {
		 	IOSET0=1<<LED;
		 	StrLCD("safe");
		 }	  
	    delay_ms(200);

		CmdLCD(0x01);
  }	
}

//--------------------interrupt service routine start here---------------------------------------
void eint0_isr(void)__irq
{	  txF.ID=1;
		txF.Data1=0;
		CAN1_Tx(txF);
		delay_ms(300);
		EXTINT |=1<<0;
		VICVectAddr=0;
}
void eint1_isr(void)__irq
{
	txF.ID=2;
	txF.Data1=1;
	CAN1_Tx(txF);
		delay_ms(300);
	EXTINT |=1<<1;
	VICVectAddr=0;
}

