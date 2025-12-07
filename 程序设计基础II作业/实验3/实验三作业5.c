#include<stdio.h>
int main(){
	int months;
    int rabbit_pairs[10];
    rabbit_pairs[1]=1;
    rabbit_pairs[2]=1;
    for(months=3;months<=10;months++){
    	rabbit_pairs[months]=rabbit_pairs[months-1]+rabbit_pairs[months-2];
	}
	printf("%d\n%d",months-1,rabbit_pairs[10]);
	return 0;
} 
