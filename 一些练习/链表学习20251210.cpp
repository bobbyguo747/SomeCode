#include<stdio.h>
int st[100010],ed[100010],lst[100010],head[10010];
int main(){
	int a,b,n,i,num=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
	    scanf("%d %d",&a,&b);
	    st[i]=a,ed[i]=b,lst[i]=head[a],head[a]=i;
	}
	scanf("%d",&a);
	i=head[a];
	printf("%d ",i); 
	while(1){
		num++;
		if(lst[i]==0) break;
		printf("%d ",lst[i]);
		i=lst[i];
	}
	printf("\n%d",num);
	return 0;
}
