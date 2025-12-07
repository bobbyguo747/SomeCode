#include<stdio.h>
int main(){
	int a[15]={1,5,13,19,26,27,56,64,75,80,88,89,105,106,120};
	int num,i;
	printf("请输入您要查找的数字:");
	scanf("%d",&num);
	for(i=0;i<=14;i++){
		if(a[i]==num){
			printf("%d",i+1);
			break;
		}
		if(i==14&&a[i]!=num){
			printf("无此数"); 
		}
	}
	return 0;
}
