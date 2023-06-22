//              GND    电源地
//              VCC  接5V或3.3v电源
//              D0   P1^0（SCL）
//              D1   P1^1（SDA）
//              RES  接P12
//              DC   接P13
//              CS   接P14               


//			adc转换引脚P0^4;
#include "STC32G.h"
#include "oled.h"
#include "ADC.h"

int value=0;
 int main(void)
 {	
			P0M1 = 0x00;   P0M0 = 0x00; 
	    P1M1 = 0xc0;   P1M0 = 0x00; 
	    P2M1 = 0x00;   P2M0 = 0x00; 
	    P3M1 = 0x00;   P3M0 = 0x00; 
	    P4M1 = 0x00;   P4M0 = 0x00; 
	    P5M1 = 0x00;   P5M0 = 0x00; 
	    P6M1 = 0x00;   P6M0 = 0x00; 
	    P7M1 = 0x00;   P7M0 = 0x00; 
	
			OLED_Init();			//初始化OLED  
			OLED_Clear(); 
	
	while(1) 
	{			

		InitADC();
		GetADCResult();
		AD_average();
		DisplayADCResult();
		value=qian*1000+bai*100+shi*10+ge;
		OLED_ShowNum(12,3,qian,1,16);
		OLED_ShowCHinese(28,3,11);//.
		OLED_ShowNum(44,3,bai,1,16);
		OLED_ShowNum(60,3,shi,1,16);
		OLED_ShowNum(76,3,ge,1,16);
		
	}	  
	
}
	