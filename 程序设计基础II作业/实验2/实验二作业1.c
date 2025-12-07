#include<stdio.h>
int main(){
	printf("x=");
    double x;
    scanf("%lf",&x);
    if(x>=1){
    	if(x<10){
    		printf("y=%g",2*x+1);
		}else{
			printf("y=%g",3*x-8);
		}
	}else{
		printf("y=%g",x);
	}
	return 0;
} 
