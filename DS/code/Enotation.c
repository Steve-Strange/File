#include<stdio.h>
#include<string.h>

int main()
{
	char x[105]={0};
	gets(x);
	int n=strlen(x);
	int dig=0;
	int length=0;
	
	if(x[0]=='-')
	{
		printf("-");
		for(int i=0;i<n;i++)
		{
			x[i]=x[i+1];
		}
		x[n-1]='\0';
		n--;
	}
	for(int i=0;i<n;i++)
	{
		if(x[i]!='.')
		{
			length++;
		}
		else
		{
			break;
		}
	}

	if(length==n)
	{
		for(int i=0;i<n;i++) printf("%c",x[i]);
		return 0;
	}

	else
	{
		if(x[0]=='0')
		{
			int j=0;
			while((x[j]=='.'&&x[j+1]=='0')||(x[j]=='0'&&(x[j+1]=='0'||x[j+1]=='.'))) dig--,j++;
			int dot=0;
			for(int i=0;i<n;i++)
			{
				if(x[i]>'0') dot++;
			}
			if(dot==1)
			{
				for(int i=j+1;i<n;i++)
				{
					printf("%c",x[i]);
				}
				printf("e%d",dig);
				return 0;
			}
			else
			{
				int p=0;
				for(int i=j+1;i<n;i++)
				{
					printf("%c",x[i]);
					if(p==0)
					{
						printf(".");
						p++;
					}
				}
				printf("e%d",dig);				
			}
		}
		
		else
		{
			for(int i=0;i<n;i++)
			{
				if(x[i]!='.')
				{
					dig++;
				}
				else
				{
					break;
				}
			}
			for(int i=0;i<n;i++)
			{
				if(i==0) printf("%c.",x[i]);
				else
				{
					if(x[i]!='.') printf("%c",x[i]);
				}
			}
			printf("e%d",dig-1);
			return 0;
		}
	}
	return 0;
}



