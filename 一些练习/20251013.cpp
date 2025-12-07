#include<stdio.h>
int main(){
	int sign;
	float a,b,c;
	sign=1;
	a=2.0;
	b=1.0;
	while(a<=10){
		sign=-sign;
		c=sign/a;
		b=b+c;
		a=a+1;
	}
	printf("%f\n",b);
	return 0;
} 
