#include<stdio.h>
#include<string.h>
int main(){
	int num=0,qwe,n,i;
	char a[100];
	printf("请输入一个十六进制数：");
	scanf("%s",a);
	for(i=0;i<strlen(a);i++){
		qwe=1;
		for(n=1;n<strlen(a)-i;n++){
				qwe=qwe*16;
			}
		if(a[i]>='0'&&a[i]<='9'){
			 num=num+(a[i]-'0')*qwe;
		}else{
			num=num+(a[i]-'A'+10)*qwe;
		}
	}
	printf("转换为十进制数：%d",num);
	return 0;
}
