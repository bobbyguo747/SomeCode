#include<stdio.h>
#include<stdlib.h>
struct Node{
	char data;
	struct Node* next;
}; 
struct Node*createList();
void displayList(struct Node* head);
void freeList(struct Node* head);
int main(){
	printf("输入字符a至f：");
	struct Node* head=createList();
	printf("链表中的字符为：");
	displayList(head);
	freeList(head);
	printf("链表空间已释放");
	return 0; 
} 
struct Node* createList(){
	struct Node* head=NULL;
	struct Node* tail=NULL;
	struct Node* newNode=NULL;
	char input;
	while((input=getchar())!='\n'){
		newNode=(struct Node*)malloc(sizeof(struct Node));
		if(newNode==NULL){
			printf("内存分配失败\n");
			exit(1);
		} 
		newNode->data=input;
		newNode->next=NULL;
		if(head==NULL){
			head=newNode;
			tail=newNode;
		} else{
			tail->next=newNode;
			tail=newNode;
		}
	}
	return head;
} 
void displayList(struct Node* head){
	struct Node* current=head;
	while(current!=NULL){
		printf("%c",current->data);
		current=current->next;
	}
	printf("\n");
} 
void freeList(struct Node* head){
	struct Node* current=head;
	struct Node* nextNode=NULL;
	while(current!=NULL){
		nextNode=current->next;
		free(current);
		current=nextNode;
	}
} 
