#include<stdio.h>
int main(){
	int jumways(int);
	int n,ways;
	scanf("%d",&n);
	ways=jumpways(n); 
	printf("%d",ways); 
	return 0;
}
int jumpways(int a){
	if(a==1){
		return 1; 
	}else{
		if(a==2){
			return 2;
		}else{
			return jumpways(a-1)+jumpways(a-2);
		}
	}
}
