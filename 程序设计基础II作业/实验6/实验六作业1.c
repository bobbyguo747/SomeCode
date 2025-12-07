#include<stdio.h>
void transpose(int(*arr)[3]){
	int temp;
	int i,j;
	for(i=0;i<3;i++){
		for(j=i+1;j<3;j++){
			temp=*(*(arr+i)+j);
			*(*(arr+i)+j)=*(*(arr+j)+i);
			*(*(arr+j)+i)=temp;
		} 
	}
}
int main(){
	int arr[3][3];
	int i,j;
	int *p=&arr[0][0]; 
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",*(arr+i)+j);
		}
	}
	transpose(p);
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%d ",*(*(arr+i)+j));
		}
		printf("\n");
	}
	return 0;
}

