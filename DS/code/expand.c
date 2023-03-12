#include <stdio.h>
#include <string.h>
int main()
{
	char x[10005]={0};
	scanf("%s",x+1);
	int len=strlen(x+1);
	for(int i=1;i<=len;i++)
	{
		if(x[i]=='-'&&x[i+1]>x[i-1]&&((x[i-1]>='a'&&x[i-1]<='z'&&x[i+1]>='a'&&x[i+1]<='z')||(x[i-1]>='A'&&x[i-1]<='Z'&&x[i+1]>='A'&&x[i+1]<='Z')||(x[i-1]>='0'&&x[i-1]<='9'&&x[i+1]>='0'&&x[i+1]<='9')))
		{
			for(int j=x[i-1]+1;j<x[i+1];j++)
			{
				printf("%c",j);
			}
		}
		else printf("%c",x[i]);
	}
	return 0;
}



