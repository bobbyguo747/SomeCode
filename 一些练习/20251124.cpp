#include<stdio.h>
int main(){
	int arr[3][3]={1,4,7,2,5,8,3,6,9};
	int b[3][3];
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			b[j][i]=arr[i][j];
		}
	} 
	for(i=0;i<j;i++){
		for(j=0;j<3;j++){
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}
	return 0;
}
