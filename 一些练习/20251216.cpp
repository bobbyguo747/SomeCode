#include<stdio.h>
int main(){
    long long a,n,num,i,j,zero;
    long long sum=0;
    scanf("%lld %lld",&a,&n);
    for(i=1;i<=n;i++){
        num=0;
        zero=1;
        for(j=1;j<=i;j++){
            num=num+zero*a;
            zero=zero*10;
        }
        sum=sum+num;
    }
    printf("sum=%lld",sum);
    return 0;
}
