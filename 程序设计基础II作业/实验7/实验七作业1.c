#include<stdio.h>
#include<stdlib.h> 
	struct type{
		char a;
		struct type *p;
	};
int main(){
	struct type *name[6];
	int i;
	for(i=0;i<6;i++){
		name[i]=(struct type *)malloc(sizeof(struct type));
	}
	for(i=0;i<5;i++){
		name[i]->p=name[i+1];
	}
	name[5]->p=NULL;
	struct type *current=name[0];
	while(current!=NULL){
		scanf("%c",&(current->a));
		current=current->p;
	}
	current=name[0];
	while(current!=NULL){
		printf("%c",current->a);
		current=current->p;
	}
	for(i=0;i<6;i++){
		free(name[i]);
	}
	return 0;
}
