#include <stdio.h>
#include <stdlib.h>
//#include <time.h>
void main(){
int number,ask,times=1;
long t;
srand((unsigned)time(NULL));/*产生一个与时间有关的随机数*/
number = rand() % 100;  /*使随机数在1~100之间*/
printf(" 请输入您猜的数字(1~100):");
scanf(" %d",&ask);
t=time(NULL);/*记时开始*/
while (ask!=number&&times<6)
{
if (ask>number)printf("\n您猜的数字大了,请重输入:");
if (ask<number)printf("\n您猜的数字小了,请重输入:");
scanf("%d",&ask);
times++;
}
t=time(NULL)-t;
if(ask==number)
{
printf("\n恭喜您!回答正确,您猜了%d次,用时%ld秒。\n",times,t);
}else
{
printf("\n很遗憾，您的次数已用尽,答案为%d",number); 
}
}
