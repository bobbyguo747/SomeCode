#include<stdio.h>
int main(){
	int delta(int x,int y);
	int a,b,c;
	printf("please enter two integer numbers:");
	scanf("%d %d",&a,&b);
	c=delta(a,b);
	printf("delat is %d",c);
	return 0;
} 
int delta(int x,int y){
	int z;
	if(x>y){
		z=x-y;
	} else{
		z=y-x;
	}
	return(z);
}

