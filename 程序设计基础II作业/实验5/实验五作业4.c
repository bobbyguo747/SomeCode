#include<stdio.h>
int main(){
	unsigned long long factorial(unsigned long long);
	int m,n;
	unsigned long long answer;
	printf("输入m和n的值：");
	scanf("%d %d",&m,&n);
	if(m<0||n<0||m>n||n>20){
		printf("输入数据不符合条件，输入值应满足0<m<=n<=20");
	}else{
		answer=factorial(n)/factorial(n-m)/factorial(m);
		printf("%llu",answer);
	}
	return 0;
}
unsigned long long factorial(unsigned long long a){
	if(a==0||a==1){
		return 1;
	} else{
		return a*factorial(a-1);
	}
} 
