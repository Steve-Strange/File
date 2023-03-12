#include<stdio.h>
#include<string.h>

void double(double a[], int n)
{
	int i,j,hold,flag;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				hold=a[j];
				a[j]=a[j+1];
				a[j+1]=hold;
				flag=1;
			}
		}
		if(flag==0)
		break;
	}
}
