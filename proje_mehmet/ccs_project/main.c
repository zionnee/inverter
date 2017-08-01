#include<18F4431.h> 
#fuses INTRC_IO, NOWDT, NOPROTECT, NOBROWNOUT, PUT, NOLVP 
#use delay(clock=8000000) 

#define POWER_PWM_PERIOD 1999  // 1 KHz pwm freq with 8 MHz osc. 

//======================================= 
void main() 
{ 

// Setup the 4 Power PWM channels as ordinary pwm channels. 
setup_power_pwm_pins(PWM_ODD, PWM_NONE, PWM_COMPLEMENTARY, PWM_COMPLEMENTARY); 

// Mode = Free Run  
// Postscale = 1   (1-16) Timebase output postscaler 
// TimeBase = 0   (0-65355) Initial value of PWM Timebase 
// Period = 2000  (0-4095) Max value of PWM TimeBase 
// Compare = 0     (Timebase value for special event trigger) 
// Compare Postscale = 1 (Postscaler for Compare value) 
// Dead Time 

setup_power_pwm(PWM_FREE_RUN, 1, 0, POWER_PWM_PERIOD, 0, 1,15);  

//set_power_pwm0_duty((int16)((POWER_PWM_PERIOD *4) * .5)); // 10% 
//set_power_pwm2_duty((int16)((POWER_PWM_PERIOD *4) * .4)); // 40% 
set_power_pwm4_duty((int16)((POWER_PWM_PERIOD *4) * .6)); // 60% 
set_power_pwm6_duty((int16)((POWER_PWM_PERIOD *4) * .75)); // 75%    

while(false); 
}
