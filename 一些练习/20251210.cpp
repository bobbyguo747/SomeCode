#include<stdio.h>
#include<string.h>
void change(char *a,char *b,int *m,int *n){
	char c[100];
	strcpy(c,a);
	strcpy(a,b);
	strcpy(b,c); 
	int *p=0;
	p=m;
	m=n;
	n=p;
} 
int main(){
	char a[100],b[100];
	char c;
	int i,m=0,n=0;
	for(i=0;c!='\n';i++){
		scanf("%c",&a[i]);
		c=a[i];
		m++;
	}
	a[m-1]='\0';
	c='\0';
	for(i=0;c!='\n';i++){
		scanf("%c",&b[i]);
		c=b[i];
		n++;
	}
	b[n-1]='\0';
	if(strcmp(a,b)<0) change(a,b,&m,&n);
	for(i=0;i<m-1;i++){
		printf("%c",a[i]);
	}
	printf("\n");
	for(i=0;i<n-1;i++){
		printf("%c",b[i]);
	}
	return 0;
}
