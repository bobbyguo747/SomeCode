#include<stdio.h>
int main(){
	int a[10],i,t,n;
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
	} 
	printf("\n");
	for(t=9;t>0;t--){
		for(i=0;i<t;i++){
			if(a[i]>a[i+1]){
				n=a[i+1];
				a[i+1]=a[i];
			    a[i]=n;
			}else{
				continue;
			} 
		} 
	}
	for(i=0;i<=9;i++){
		printf("%d ",a[i]);
	} 
	return 0;
}
