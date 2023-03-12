#include<stdio.h>

int book[12]={0};
int ans[12]={0};

void dfs(int step,int n)
{
	
	if(step==n)
	{
		for(int i=0;i<n;i++)
		{
			printf("%d ",ans[i]+1);
		}
		putchar(10);
		
		return;
	}
	
	for(int i=0;i<n;i++)
	{
		if(book[i]==0)
		{
			ans[step]=i;
			book[i]=1;
			dfs(step+1,n);
			book[i]=0;
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	dfs(0,n);
	return 0;
}
