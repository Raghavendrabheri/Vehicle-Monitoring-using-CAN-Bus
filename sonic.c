#include<lpc21xx.h>

 #include "delay.h"
#define trr_pin 19
#define echo_pin 18

/*
void delay_us(unsigned int us)

{

us*=12;

while(us--);

} */

void INIT_Ultrasonic(void)

{

IODIR0|=(1<<trr_pin);

IODIR0&=~(1<<echo_pin);


}

void send_pulse(void)

{

IOSET0=1<<trr_pin;

delay_us(10);

IOCLR0=1<<trr_pin;

}

unsigned int read_echo(void)

{


unsigned duration=0;

while(((IOPIN0>>echo_pin)&1)==0);

T0TCR=0X02;

T0TCR=0X01;

while((IOPIN0>>echo_pin)&1);

T0TCR=0X00;

duration=T0TC;

return duration;

}

unsigned int dist_cal(void)

{

unsigned pulse;

float dis;

send_pulse();

pulse=read_echo();

dis=pulse/59.0;

return dis;

}

