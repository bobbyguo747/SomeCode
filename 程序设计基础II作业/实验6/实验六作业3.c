#include<stdio.h>
#include <string.h>
void Max(char *c,int *len,int *num,int *p){
	if(*len<strlen(c))
	    *len=strlen(c),*p=*num+1;
	*num+=strlen(c)+1;
}
int main(){
	int len,num,p,i; 
    char c[110],a;
	printf("请输入一个英文句子：\n");
	while(a!='\n')
	{
		scanf("%s",c);
		Max(c,&len,&num,&p);
		scanf("%c",&a);
		for(i=0;i<110;i++){
			c[i]='\0';
		}
	}
	printf("最长单词在%d字符处,长度为%d字符",p,len);
	return 0;
}
