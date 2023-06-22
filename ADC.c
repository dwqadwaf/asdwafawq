#include <ADC.h>
 
uchar qian=0,bai=0,shi=0,ge=0;
 
void InitADC()        //adc��ʼ��
{
	ADCTIM=0x3f;       //����ADC�ڲ�ʱ��
	ADCCFG=0x2f;       //����ADCʱ��Ϊϵͳʱ��/2/16
	ADC_CONTR=0x06;    //����ADC�˿�ΪP1.6
	ADC_POWER=1;       //��ADC��Դ
	ADC_RES = 0;       //���ADC����
}

uint GetADCResult()		//adc��ʼ����
{
	ADC_START=1;//����ADת��
	_nop_();
	_nop_();
	while (!ADC_FLAG);//��ѯADC��ɱ�־
	ADC_FLAG=0;//����ɱ�־
 
	return (ADC_RES<<8)|ADC_RESL;
}
 
float AD_average()		//ƽ���˲�
{
	int i;
	float value=0;
 
	for(i=0;i<300;i++)
	{
		value+=GetADCResult();   //1000�β���
	}
	value/=300;		   //��ƽ��
	value=value*5.0/4096; //���ݹٷ��ֲ�Ĺ�ʽ��ADC�˿ڵ�ѹ=12λADC���*�ο���ѹ/4096
	return value;
}
 
void DisplayADCResult()		//adc��ʾ
{
	float ADResult;
	uint Result;
 
	ADResult=AD_average()*1000;
	Result=(int)ADResult;
	
	qian=Result/1000;    //���ݷ���
	bai=Result%1000/100; //��λΪС����ǰһλ��ʮλΪС�����һλ����λΪС�������λ
	shi=Result%100/10;      //��λΪ��
	ge=Result%10;
}