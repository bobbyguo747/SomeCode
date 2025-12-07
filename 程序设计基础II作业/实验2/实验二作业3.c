#include<stdio.h>
int main(){
	int n,m,chicken,rabbit;
	printf("«Î ‰»În,m\n");
	scanf("n=%d m=%d",&n,&m);
	if(m%2==0){
		rabbit=m/2-n;
		chicken=2*n-m/2;
		if(chicken>=0&&rabbit>=0){
			printf("º¶ %d Õ√ %d",chicken,rabbit);
		}else{
			printf("No answer");
		}
	}else{
		printf("No answer");
	}
	return 0; 
} 
