#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct word
{
	char x[105];
	int cnt;
}word;


int cmp(const void*a,const void*b)
{
	word *p,*q;
	p=(word*)a;
	q=(word*)b;
	return (strcmp(p->x,q->x));
}


int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	
	word a[5005];
	char line[2049]={0};
	int count=0;
	while(fgets(line,2049,in)!=NULL)
	{
		char p;
		int len=strlen(line);
		for(int i=0;i<len;i++)
		{
			if(isalpha(line[i]))
			{
				int k=0;
				while(isalpha(line[i+k]))
				{
					a[count].x[k]=tolower(line[i+k]);
					k++;
				}
				i+=k-1;
				count++;
				continue;
			}
			else continue;
		}
	}
	qsort(a,count,sizeof(word),cmp);
	
	
	for(int i=0;i<count;i++)
	{
		a[i].cnt=1;
	}
	
//	for(int i=0;i<count;i++)
//	{
//		printf("%s ",a[i].x);
//	}
	
	for(int i=1;i<count;i++)
	{
		if(strcmp(a[i-1].x,a[i].x)==0)
		{
			a[i].cnt+=a[i-1].cnt;
			a[i-1].cnt=0;
		}
	}
	for(int i=0;i<count;i++)
	{
		if(a[i].cnt) printf("%s %d\n",a[i].x,a[i].cnt);
	}
}

