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
	printf("�����������뼸����");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("��������Ϊ��"); 
	print(a,n);
	Insert(a,n,10);
	printf("�������ݺ�����Ϊ"); 
	print(a,n+1);
}
