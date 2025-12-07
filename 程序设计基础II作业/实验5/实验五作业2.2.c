#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	printf("%d",stepways(n));
	return 0;
}
int stepways(int n){
	if(n<=2){
		return n;
	}
	int a=1;
	int b=2;
	int i;
	int result=0;
	for(i=3;i<=n;i++){
		result=a+b;
		a=b;
		b=result;
	}
	return result;
}
