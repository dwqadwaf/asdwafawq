#ifndef __ADC_H_
#define __ADC_H_
 
//---ͷ�ļ�---//
#include <stc32g.h>
#include <intrins.h>
 
//---�궨��---//
#define uchar unsigned char							
#define uint unsigned int
 
//---��������---//
void InitADC1();
void InitADC2();
float AD_average();
uint GetADCResult();
void DisplayADCResult();
 
//---ȫ�ֱ�������---//
extern uchar qian,bai,shi,ge;
 
#endif