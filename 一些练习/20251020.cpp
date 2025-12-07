#include<stdio.h>
#include<math.h>
int main(){
	double a,b,c,delta;
	scanf("%lf,%lf,%lf",&a,&b,&c);
	delta=b*b-4*a*c;
	if(delta<0){
		printf("ÎÞÊµ¸ù");
	}else{
		printf("x1=%lf\nx2=%lf",(-b+sqrt(delta))/2/a,(-b-sqrt(delta))/2/a); 
	}
	return 0;
}
