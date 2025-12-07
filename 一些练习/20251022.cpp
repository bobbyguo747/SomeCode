#include<stdio.h>
int main(){
    double price,account,cost;
    scanf("lf %lf",&price,&account);
    cost=price*account/10;
    printf("%.2lf",cost);
    return 0;
}
