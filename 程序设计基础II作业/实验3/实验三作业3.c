#include<stdio.h>
#include<math.h>
double f(double x){
		return x*x*x+2*x-5;
	}
int main(){
	double a,b,c,d;
	a=-1;
	b=2;
	d=0.0001;
	if(fabs(f(a))<=d){
		printf("%.4f",a);
		return 0;
	}if(fabs(f(b))<=d){
		printf("%.4f",b);
		return 0;
	}while(fabs(b-a)>d){
		c=(a+b)/2;
		if(fabs(f(c))<=d){
			break;
		}if(f(a)*f(c)<0){
			b=c;
		}else{
			a=c;
		}
	}
	printf("%.4f",c);
	return 0;
} 
