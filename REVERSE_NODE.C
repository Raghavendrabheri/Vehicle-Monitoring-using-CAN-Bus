//can_tx_test.c
#include "can.h"
#include "delay.h"
#include"lcd.h"
#include <string.h>
#include <stdlib.h>
#include<lpc21xx.h>
#include "defines.h"

void INIT_Ultrasonic(void);
unsigned int dist_cal(void);
CANF txF;
int d;							  						  
int main()
{
	Init_CAN1();
	InitLCD();
	INIT_Ultrasonic();
	T0PR=12000000/1000000-1;  ///timer0 pre scaler

	txF.ID=3;
	txF.BFV.RTR=0;//data frame 
	txF.BFV.DLC=2;
	while(1)
	{
		txF.Data1=dist_cal();
		CmdLCD(0x80);
		U32LCD(txF.Data1);
		if(txF.Data1<20)
			CAN1_Tx(txF);
		delay_ms(200);
     	CmdLCD(0x01);

	} 
}


