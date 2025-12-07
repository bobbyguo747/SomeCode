#include<stdio.h>
int main(){
	int factorial(int);
	int x,y=0,i;
	scanf("%d",&x);
	for(i=x;i>0;i--){
		if(i%2==0){
			y=y+factorial(i);
		}
	}
	printf("%d",y); 
	return 0;
}
int factorial(int a){
	int j=1;
	if(a==1){
		return j;
	}else{
		j=factorial(a-1)*a;
		a--;
	}
}
