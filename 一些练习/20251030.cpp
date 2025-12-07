#include<stdio.h>
int main(){
    int number,k,h,t,o;
    scanf("%d",&number);
    o=number%10;
    t=(number%100)/10;
    h=(number%1000)/100;
    k=number/1000;
    printf("%d %d %d %d",o,t,h,k);
    return 0;
}
