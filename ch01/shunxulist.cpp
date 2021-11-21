#include<stdio.h>
#include<stdlib.h>
void PrintList(int a[],int n);
//MakeEmpty
void Insert(int a[],int i,int num,int n);
void Delete(int a[],int num,int n); 
int Find(int a[],int num,int n);
int FindKth(int a[],int i,int n);
int main()
{
	int a[10]={32,12,52,62,12};
	int n=5;
/*	printf("请输入数组数值:"); 
	while(i<10&&getchar()!='\n')
	{
		scanf("%d",&num);
		a[i]=num;
		printf("%d",num);
		n++;
		i++;
	}  */   
	int i=Find(a,52,n);
	printf("%d\n",i);
	int m=FindKth(a,2,n);  
	if(m!=-1)
	printf("%d\n",a[2]);
	else 
	printf("FindKth error");                                                
	PrintList(a,n);
//	Insert(a,3,5,n);
	PrintList(a,n+1);
	Delete(a,12,n);
	return 0;
}
void PrintList(int a[],int n)
{
//	printf("数组中的数据为："); 
    for(int i=0;i<n;i++)
    {
    	//if(a[i]!=NULL)//如果数组小标为i处不为空才输出 
    	printf("%d ",a[i]);
	}
	printf("\n");
	
}

void Insert(int a[],int i,int num,int n)
{
    for(int j=n-1;j>=i;--j)
	{
		a[j+1]=a[j];
	}
	a[i]=num;	
}
void Delete(int a[],int num,int n)
{
	int flag=0;
	for(int i=0;i<n;i++)
	{
		if(num==a[i])
		{
			for(int j=i;j<5;j++)
			{
				a[j]=a[j+1];
			}
			flag++;
		}
	}
    if(flag!=0)
    {
    	for(int i=0;i<5-flag;i++)
    	{
    		printf("%d ",a[i]);
		}
	}
	else
	{
	printf("del error!\n");	
	}
}
int Find(int a[],int num,int n)
{

	for(int i=0;i<n;i++)
	{
	if(a[i]==num)
	return i;	
	} 
	return -1;
}
int FindKth(int a[],int i,int n)
{
	if(i<n)
	{
	
	int m=a[i];
	return m;
    }
	else
	return -1;
//	else
//	printf("FindKth error");
}
