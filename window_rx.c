#include <LPC21xx.h>   

#include"can.h"   
	

main()   

{   
	char window_level=0;
   	struct CAN_Frame rxFrame;
	IODIR0=255;
	IOSET0=255; 

  	Init_CAN1();   

	while(1)   
	{   
        CAN1_Rx(&rxFrame); 
		if(rxFrame.ID==1 && window_level<8)
		{
			IOCLR0=(1<<(window_level));
     		window_level++;
		}    
	  	else if(rxFrame.ID==2 && window_level>0)
		{
			IOSET0=(1<<(window_level));
			window_level--;
		}    
	}   
 }
