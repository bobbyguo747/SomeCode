#include<stdio.h>
int main(){
	int num,k,h,t,o;
	scanf("%d",&num);
	k=num/1000;
	h=(num%1000)/100;
	t=(num%100)/10;
	o=num%10; 
	printf("%d%d%d%d",o,t,h,k);
	return 0;
} 
