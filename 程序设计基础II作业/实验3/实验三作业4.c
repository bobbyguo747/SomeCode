#include<stdio.h>
int main(){
	char ch;
	int i,j,rows;
	scanf("%c",&ch);
	rows=ch-'A'+1;
	for(i=0;i<rows;i++){
		for(j=0;j<=i;j++){
			printf("%c",ch-j);
		}
		printf("\n"); 
	}
	return 0;
}
