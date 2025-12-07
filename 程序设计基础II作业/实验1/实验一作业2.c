#include<stdio.h>
int main(){
	double r,h,room;
	scanf("r=%lf h=%lf",&r,&h);
	room=3.14*r*r*h;
	printf("room=%.2lf",room);
	return 0;
}
