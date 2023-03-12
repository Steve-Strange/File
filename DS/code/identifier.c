#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


int cmp(const void*a,const void*b)
{
    char *p=(char*)a;
    char *q=(char*)b;
    return strcmp(q,p);
}


int main()
{
    char a[300]={0};
    char pile[300][300]={0};
    gets(a);
	int count=0;
	int len = strlen(a);
    for(int i=0;i<len;i++)
	{
        int length=0;
		if(a[i]=='_'||isalpha(a[i]))
			{
                pile[count][length++]=a[i];
				int k=1;
				while(isalpha(a[i+k])||isdigit(a[i+k])||a[i+k]=='_')
				{
					pile[count][length++]=a[i+k];
					k++;
				}
				i+=k-1;
				count++;
			}
	}
	qsort(pile,count,sizeof(pile[0]),cmp);
	
	for(int i=0;i<count;i++)
    {
        int k=1;
        while(strcmp(pile[i+k],pile[i])==0)
        {
            pile[i+k][0]='\0';
            k++;
        }
        i=i+k-1;
    }

	for(int i=0;i<count;i++)
	{
		if(pile[i][0]) printf("%s ",pile[i]);
	}
	
}

