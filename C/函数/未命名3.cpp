#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<limits.h>
int main()
{
	int t;
	scanf("%d",&t);
	for(int k=0;k<t;k++)
	{
		int time=0;
		int n;
		int red=0;
		int blue=0;
		scanf("%d",&n);
		int x[1005];
		memset(x,0,sizeof(x));
		int r[1005];
		memset(r,0,sizeof(r));
		int b[1005];
		memset(b,0,sizeof(b));
		for(int j=0;j<n;j++)
		{
			scanf("%d",&x[j]);
		}
		char color[1005];
		memset(color,0,sizeof(color));
			scanf("%s",color);		
		for(int j=0;j<n;j++)
		{
			if(color[j]=='R') r[red++]=x[j];
			if(color[j]=='B') b[blue++]=x[j];
		}
				int max=0;
				int min=1000005;
				for(int i=0;i<red;i++)
				{
					if(r[i]<min) min=r[i];
					if(r[i]>=n)
					{
						printf("NO\n");
						time=1;
					}
				}
				for(int j=0;j<blue;j++)
				{
					if(b[j]>max) max=b[j];
				}
				if(time==0)
				{
					if(max<min) 
					{
						printf("NO\n");
					}
					else printf("YES\n");				
				} 
	}
	return 0;
}
