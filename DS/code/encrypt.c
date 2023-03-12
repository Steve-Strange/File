#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *in,*out;
	if((in=fopen("encrypt.txt","r"))==NULL)
	{
		printf("Error");
		return 0;
	}
	if((out=fopen("output.txt","w"))==NULL)
	{
		printf("Error");
		return 0;
	}

	int book[26]={0};
	char key[55]={0};
	scanf("%s",key);
	char head[55]={0};
	int p=0;
	int len=strlen(key);
	for(int i=0;i<len;i++)
	{
		if(book[key[i]-'a']==0)
		{
			book[key[i]-'a']=1;
			head[p++]=key[i];
		}
	}
	for(int i=25;i>=0;i--)
	{
		if(book[i]==0)
		{
			head[p++]='a'+i;
		}
	}
	char line[1005]={0};
	while(fgets(line,1005,in)!=NULL)
	{
		int n=strlen(line);
		for(int i=0;i<n;i++)
		{
			if(line[i]>='a'&&line[i]<='z')
			{
				fputc(head[line[i]-'a'],out);
			}
			else
			{
				fputc(line[i],out);
			}
		}
	}
	fclose(in);
	fclose(out);
	return 0;
}

