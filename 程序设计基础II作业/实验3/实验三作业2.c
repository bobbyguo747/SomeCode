#include<stdio.h>
int main(){
	int n,s,i;
	n=2;
	do{
		s=0;
		i=1;
		do{
			if(n%i==0){
				s=s+i;
			}
			i++;
		}while(i<n);
		if(s==n){
			printf("%d ",n);
		}
		n++;
	}while(n<=2001);
	return 0;
}
