#include<stdio.h>
int even_count=0;
inline int caculate_even_sum(int arr[],int n);
int main(){
	int n=0;
	char ch;
	int numbers[100];
	int even_sum;	
	do{
		scanf("%d",&numbers[n]);
		n++;
		ch=getchar();
	}while(ch!='\n'&&n<100);
	even_sum=caculate_even_sum(numbers[],n);
	printf("和为%d 个数%d",even_sum,even_count);
	return 0;
}
int caculate_even_sum(int arr[],int n){
	int sum=0;
	int i;
	even_count=0;
	for(i=0;i<n;i++){
		if(arr[i]%2==0){
			sum+=arr[i];
			even_count++;
		}
	}
	return sum;
}

