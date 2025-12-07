#include<stdio.h>
#include<math.h>
int main(){
	int n;
	double s,i,term;
	n=1;
	i=1;
	s=0;
	do{
	    term=i*(2*n+1)/(2*n)/(2*n);
		i=-i;
		n++;
		if(fabs(term)<=1e-3){
			break;
		}else{
				s=s+term;
		}
	}
	while(1);
	printf("%lf",s); 
	return 0;
} 
