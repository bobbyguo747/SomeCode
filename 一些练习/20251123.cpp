#include<stdio.h>
int main(){
	int arr[100][100];
	int i,j;
	for(i=0;i<10;i++){
		for(j=0;j<=i;j++){
			if(j==0||j==i){
				arr[i][j]=1; 
			}else{
				arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
			}
		}
	}
	for(i=0;i<10;i++){
		for(j=0;j<=i;j++){
			printf("%d  ",arr[i][j]);
		}
		printf("\n");
	} 
return 0;
} 
