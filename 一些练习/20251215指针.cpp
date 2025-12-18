#include<stdio.h>
void input(int *a){
	int i;
	for(i=0;i<10;i++){
		scanf("%d",a+i);
	}
}
void output(int *a){
	int i;
	for(i=0;i<10;i++){
		printf("%d ",*(a+i));
	}
}
void change(int *a){
	int n,p,i,j;
	for(i=0;i<10;i++){
		n=0;
		for(j=0;j<10;j++){
			if(a[i]<=a[j]) n++;
		}
		if(n==10){
			p=a[0];
			a[0]=a[i];
			a[i]=p;
			break;
		}
	}
	for(i=0;i<10;i++){
		n=0;
		for(j=0;j<10;j++){
			if(a[i]>=a[j]) n++;
		}
		if(n==10){
			p=a[9];
			a[9]=a[i];
			a[i]=p;
			break;
		}
	}
} 
int main(){
	int a[10];
	input(a);
	change(a);
	output(a);
	return 0;
} 
