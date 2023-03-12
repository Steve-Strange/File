	#include<stdio.h>
	#include<math.h>
	int main()
	{
		int n;
		int x;
		int gap;
		char c[1005];
		scanf("%d",&n);
		for (int i=0;i<n;i++)
		{
			for(int k=0;k<1005;k++)
			{
				c[k]=0;
			}
			int ans=100000;
			int len=0;
			int t=0;
			scanf("%s",c);
			for(int k=0;k<1005;k++)
			{
				if(c[k]!=0) len++;
				else break;
			}
			for(x=48;x<123;x++)
			{
				gap=0;
				for(int j=0;j<len;j++)
				{
					if(c[j]==x) gap=0;
					if(c[j]!=x) gap++;
					if(gap>2) break;
					if(j==len-1)
					{
						t++;
						if(ans>x) ans=x;
					}
				}
			}
			if(t!=0) printf("%c\n",ans);
			if(t==0) printf("You loser!\n");
		}
	    return 0;
	}
