#include<stdio.h>
int main(){
	int n,k,i,j;
	int light[100];
	printf("输入灯的数量n=");
	scanf("%d",&n);
	printf("输入人的数量k=");
	scanf("%d",&k); 
	if(k>n||k>100||n>100){
		printf("error");
		return 0;
	}
	for(i=0;i<n;i++){
		light[i]=-1;
	}
	for(j=0;j<k;j++){
		for(i=0;i<n;i++){
			if((i+1)%(j+1)==0){
				light[i]=-light[i];
			}
		}
	}
	printf("最终亮灯的编号是");
	for(i=0;i<n;i++){
		if(light[i]>0){
			printf(" %d",i+1);
		}
	}
	return 0;
} 
