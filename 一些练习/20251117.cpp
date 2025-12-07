#include<stdio.h>
int main(){
	int a,i;
	scanf("%d",&a);
	for(i=2;i<=a/2;i++){
		if(a%i==0){
			printf("不是素数");
			break;
		}
	}
	if(i>=a/2-1){
		printf("是素数");
	}
	return 0;
}
