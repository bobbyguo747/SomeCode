#include<stdio.h>
int main(){
	int a,b,c;
	a=3;
	b=4;
	c=5;
	double x,y,z;
	x=1.2;
	y=2.4;
	z=-3.6;
	short u=51274;
	long n=128765;
	char c1,c2;
	c1='a';
	c2='b';
	printf("a=%d b=%d c=%d\n",a,b,c);
	printf("x=%f,y=%f,z=%f\n",x,y,z);
	printf("x+y=%.1f y+z=%.1f z+x=%.1f\n",x+y,y+z,z+x);
	printf("u=%d n=%d\n",u,n);
	printf("c1=%c or %d\n",c1,c1);
	printf("c2=%c or %d",c2,c2);
	return 0;
} 
