#include <stdio.h>
int main(){
	int i,j,sum;
	for(i=1;i<=1000;i++){
		sum=0;
		for(j=1;j<=i/2;j++){
			if(i%j==0){
				sum=sum+j;
			} 
		}
		if(sum==i){
			printf("%d ",i);
		}
	}
    return 0;
}
