#include<stdio.h>
int f(int (*a)[110],int *n)
{
	int m=0;
	int i,j,u,d,l,r; 
	for(i=1;i<=n[0];i++)
	    for(j=1;j<=n[0];j++) a[i][j]+=a[i][j-1];
	for(j=1;j<=n[0];j++)
	    for(i=1;i<=n[0];i++) a[i][j]+=a[i-1][j];
	for(u=1;u<=n[0];u++)
	    for(d=u;d<=n[0];d++)
	        for(l=1;l<=n[0];l++)
	            for(r=l;r<=n[0];r++)
	                if(m<a[d][r]+a[u-1][l-1]-a[u-1][r]-a[d][l-1])
	                    m=a[d][r]+a[u-1][l-1]-a[u-1][r]-a[d][l-1],n[1]=u,n[2]=d,n[3]=l,n[4]=r;
	return m;
}
int main()
{
	int i,j;
	int a[110][110]={},b[110][110]={},n[5],m;
	printf("输入二维数组的N值：");
	scanf("%d",&n);
	for(i=1;i<=n[0];i++)
	    for(j=1;j<=n[0];j++) scanf("%d",&a[i][j]),b[i][j]=a[i][j];
	m=f(a,n);
	printf("最大子矩形的元素：\n");
	for(i=n[1];i<=n[2];i++,printf("\n"))
	    for(j=n[3];j<=n[4];j++) printf("%d ",b[i][j]);
	printf("最大子矩形的和是%d\n",m);
	return 0;
}
