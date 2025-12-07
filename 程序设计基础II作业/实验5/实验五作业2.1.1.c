#include<stdio.h>
int main(){
	int factorial(int);
	int n,i,j,num=0,m,k;
	scanf("%d",&n);
	i=n%2;
	j=(n-i)/2;
	m=i;
	for(k=j;k>=0;k--){
		num=num+(factorial(k+m)/factorial(k)/factorial(m));
		m=m+2;
	}
	printf("%d",num);
	return 0;
} 
int factorial(int a){
	int p=1;
	if(a==1||a==0){
		return 1;
	}else{
		return a*factorial(a-1);
	}
} 
