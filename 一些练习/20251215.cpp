#include<stdio.h>
#include<math.h>
int main(){
    double pi,n=0;
    int i;
    for(i=1;fabs(1/i)>=0.000001;i=-(i+2)){
        n=n+1/i;
    }
    pi=n*4;
    printf("pi=%lf",pi);
    return 0;
}
