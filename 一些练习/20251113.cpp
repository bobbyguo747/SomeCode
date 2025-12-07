#include<stdio.h>
#include<math.h>
int main(){
    double x,f;
    scanf("%lf",&x);
    if(0<=x&&1>=x){
        f=2*sqrt(x);
    }else{
        if (x>1){
            f=10*x+1;
        }else{
            printf("error");
        }
    }
    printf("y=f(%.2lf)=%.2lf",x,f);
    return 0;
}
