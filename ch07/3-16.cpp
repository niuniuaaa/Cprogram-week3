#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int N=10;
	int a[N]={1,2,4,5,3,2,8,2,5,2};
	for(int i=0;i<N;i++)
	{
		for(int j=i+1;j<N;j++)
		{
			if(a[i]==a[j])
			{
				for(int m=j;m<N;m++)
				{
				a[m]=a[m+1];
			    }
		        j++;
				N--;  
			} 
		}
	}
    for(int i=0;i<N;i++)
    {
    	printf("%d ",a[i]);
	}
	return 0;
}
