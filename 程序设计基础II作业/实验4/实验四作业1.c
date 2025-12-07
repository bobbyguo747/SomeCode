#include<stdio.h>
int main(){
	int a[10][10];
	int i,j;
	a[1][1]=1;
	for(i=1;i<=6;i++){
		for(j=1;j<=i;j++){
			if(j!=1&&j!=i){
				a[i][j]=a[i-1][j-1]+a[i-1][j];
			}else{
				a[i][j]=1;
			}
		}
		for(j=1;j<=i;j++){
				printf("%d ",a[i][j]);
			}
			printf("\n");
	}
	return 0;
}
