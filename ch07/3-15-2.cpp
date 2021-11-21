#include <stdio.h>
#include <stdlib.h>
void Insert(int *a,int n,int data)
{
	for(int n;n>0;--n)
	{
		a[n]=a[n-1];
	}
	a[0]=data;
}
print(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
int main()
{
	int a[15],n;
	printf("请问您想输入几个数");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("输入数组为："); 
	print(a,n);
	Insert(a,n,10);
	printf("插入数据后数组为"); 
	print(a,n+1);
}
