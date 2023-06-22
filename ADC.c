#include <ADC.h>
 
uchar qian=0,bai=0,shi=0,ge=0;
 
void InitADC()        //adc初始化
{
	ADCTIM=0x3f;       //设置ADC内部时序
	ADCCFG=0x2f;       //设置ADC时钟为系统时钟/2/16
	ADC_CONTR=0x06;    //设置ADC端口为P1.6
	ADC_POWER=1;       //打开ADC电源
	ADC_RES = 0;       //清空ADC数据
}

uint GetADCResult()		//adc开始采样
{
	ADC_START=1;//启动AD转换
	_nop_();
	_nop_();
	while (!ADC_FLAG);//查询ADC完成标志
	ADC_FLAG=0;//清完成标志
 
	return (ADC_RES<<8)|ADC_RESL;
}
 
float AD_average()		//平均滤波
{
	int i;
	float value=0;
 
	for(i=0;i<300;i++)
	{
		value+=GetADCResult();   //1000次采样
	}
	value/=300;		   //求平均
	value=value*5.0/4096; //根据官方手册的公式，ADC端口电压=12位ADC结果*参考电压/4096
	return value;
}
 
void DisplayADCResult()		//adc显示
{
	float ADResult;
	uint Result;
 
	ADResult=AD_average()*1000;
	Result=(int)ADResult;
	
	qian=Result/1000;    //数据分离
	bai=Result%1000/100; //百位为小数点前一位，十位为小数点后一位，个位为小数点后两位
	shi=Result%100/10;      //单位为伏
	ge=Result%10;
}