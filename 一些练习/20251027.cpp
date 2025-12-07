#include<stdio.h>
int main(){
    double a,b,c;
	scanf("%lf %lf",&a,&b);
	if(a>=0&&a<=1e8&&b>=0&&b<=1e8){
	c=a+b;
	printf("%lf",c);
}else{
	printf("error");
}
	return 0;
}
