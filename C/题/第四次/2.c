#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct word
{
	char data;
	int y;
}word;

word stack[3005];
word ans[3005];
word pair[3005];

int main()
{
	FILE *in;
	in=fopen("example.c","r");

	char line[2049]={0};
	int cnt=0;
	int j=0;
	while(fgets(line,2048,in)!=NULL)
	{
		cnt++;
		// if(strcmp(line,"\n")==0) cnt--;
		int len=strlen(line);
		for(int i=0;i<len;i++)
		{
			if(line[i]=='\''||line[i]=='\"'||line[i]=='*'||line[i]=='{'||line[i]=='}'||line[i]=='('||line[i]==')'||line[i]=='/')
			{
				stack[j].data=line[i];
				stack[j].y=cnt;
				j++;
			}
		}
	}

	// 	for(int i=0;i<j;i++)
	// 	{
	// 		printf("%c",stack[i].data);
	// 	}
	// putchar(10);

	int p=0;
	for(int i=0;i<j;i++)
	{
		if(stack[i].data=='/'&&stack[i+1].data=='/')
		{
			int k=0;
			while(stack[i+k].y==stack[i].y) k++;
			i=i+k-1;
		}
		else if(stack[i].data=='/'&&stack[i+1].data=='*')
		{
			int k=1;
			while(stack[i+k].data!='/'||stack[i+k-1].data!='*') k++;
			i=i+k;
		}
		else if(stack[i].data=='\"')
		{
			int k=1;
			while(stack[i+k].data!='\"')
			{
				if(stack[i+k].data=='\\'&&stack[i+k].data=='\"') k++;
				k++;
			}
			i=i+k;
		}
		else if(stack[i].data=='\'')
		{
			int k=1;
			while(stack[i+k].data!='\'')
			{
				if(stack[i+k].data=='\\'&&stack[i+k].data=='\'') k++;
				k++;
			}
			i=i+k;			
		}
		else
		{
			if(stack[i].data!='*') ans[p++]=stack[i];
		}
	}

	// for(int i=0;i<p;i++)
	// {
	// 	printf("%c%d ",ans[i].data,ans[i].y);
	// }
	// printf("\n");

	int t=0;
	for(int i=0;i<p;i++)
	{
		pair[t]=ans[i];
		if(t>0)
		{
			if((pair[t-1].data=='{'&&pair[t].data=='}')||(pair[t-1].data=='('&&pair[t].data==')'))
			{
				t-=2;
			}
			if((pair[t-1].data=='('&&pair[t].data=='{'))
			{
				printf("without maching \'%c\' at line %d",pair[t-1].data,pair[t-1].y);
				return 0;
			}
			if((pair[t-1].data=='{'&&pair[t].data==')')||(pair[t-1].data=='('&&pair[t].data=='}'))
			{
				printf("without maching \'%c\' at line %d",pair[t].data,pair[t].y);
				return 0;
			}
		}
		else
		{
			if(pair[t].data=='}'||pair[t].data==')')
			{
				printf("without maching \'%c\' at line %d",pair[t].data,pair[t].y);
				return 0;
			}
		}
		t++;
	}

	if(t!=0)
	{
		printf("without maching \'%c\' at line %d",pair[0].data,pair[0].y);
	}
	else
	for(int i=0;i<p;i++)
	{
		printf("%c",ans[i].data);
	}
	
	return 0;
}