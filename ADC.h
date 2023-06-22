#ifndef __ADC_H_
#define __ADC_H_
 
//---头文件---//
#include <stc32g.h>
#include <intrins.h>
 
//---宏定义---//
#define uchar unsigned char							
#define uint unsigned int
 
//---函数声明---//
void InitADC1();
void InitADC2();
float AD_average();
uint GetADCResult();
void DisplayADCResult();
 
//---全局变量声明---//
extern uchar qian,bai,shi,ge;
 
#endif