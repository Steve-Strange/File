#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int t=0;
		for(int i=5;i<=n;i+=5)
		{
			int j=i;
			here:
			if(j%5==0)
			{
				t++;
				j/=5;
				goto here;
			}
		}
		printf("%d\n",t);
	}
	return 0;
} 
