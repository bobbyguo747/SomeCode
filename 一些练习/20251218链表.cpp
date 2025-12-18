#include<stdio.h>
#include<stdlib.h>
int main(){
	struct node
	{
		int a,b,c[100];
		struct node *p;
	};
	struct node *x[100];
	for()x[i]=(struct node *)malloc(sizeof(struct node));
    for(int i=0;i<99;i++) x[i].p=&x[i+1];
    for(int i=0;i<99;i++){
    	x[i].p=&x[i+1];
	}
	struct node *a=&x[0],*b=a;
    while(b!=&x[30]) 
    free(x);
    return 0;
}

