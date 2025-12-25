#include<stdio.h>
#include<stdlib.h>
struct node
	{
		int a,b,c[100];
		struct node *p;
	};
int main(){
	struct node *x;
	x=(struct node *)malloc(100*sizeof(struct node));
	x[99].p=NULL;
    for(int i=0;i<99;i++) x[i].p=&x[i+1];
	struct node * current=x;
	while(current!=NULL){
		current->a=10;
		current=current->p;
	} 
    free(x);
    return 0;
}

