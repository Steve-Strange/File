#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct list
{
	int cnt;
	char name[23];
	char num[12];

}list;

int comp(const void*a,const void*b)
{
	list *na=(list*)a;
	list *nb=(list*)b;
	int lena=strlen(na->name);
	int lenb=strlen(nb->name);
	int min=lena?lenb:lena<lenb;
	
	for(int i=0;i<min;i++)
	{
		if(na->name[i]<nb->name[i]) return -1;
		else if(na->name[i]>nb->name[i]) return 1;
		else continue;
	}
	return(na->cnt-nb->cnt);
}


int main()
{
	list book[105];
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",book[i].name);
		scanf("%s",book[i].num);
		book[i].cnt=i;
	}
	
	
	qsort(book,n,sizeof(list),comp);
	int cntp=0;	
	
	printf("%s %s\n",book[0].name,book[0].num);	
	for(int i=1;i<n;i++)
	{
		if(strcmp(book[i].name,book[i-1].name)==0)
		{
			if(strcmp(book[i].num,book[i-1].num)==0)
			{
				continue;
			}
			else
			{
				cntp++;
				printf("%s_%d %s\n",book[i].name,cntp,book[i].num);
			}
		}
		else
		{
			cntp=0;
			printf("%s %s\n",book[i].name,book[i].num);
		}
	}
	return 0;
}	

