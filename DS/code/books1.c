#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct book
{
	char title[55];
	char author[25];
	char publisher[35];
	int year;
}book;

int cmp(const void*a,const void*b)
{
	book *na=(book*)a;
	book *nb=(book*)b;

	return strcmp(na->title,nb->title);
}


int main()
{
	FILE *in,*out;
	if((in=fopen("books.txt","r"))==NULL||(out=fopen("ordered.txt","w"))==NULL)
	{
		printf("Error");
		return 0;
	}

	book list[505];
	int p=0;
	while(fscanf(in,"%s %s %s %d\n",list[p].title,list[p].author,list[p].publisher,&list[p].year)!=EOF)
	{
		p++;
	}
	qsort(list,p,sizeof(book),cmp);


	int cmd=0;
	while(scanf("%d",&cmd),cmd!=0)
	{
		if(cmd==1)
		{
			scanf("%s %s %s %d\n",list[p].title,list[p].author,list[p].publisher,&list[p].year);
			p++;
			qsort(list,p,sizeof(book),cmp);
		}

		if(cmd==2)
		{
			char key_find[55]={0};
			scanf("%s",key_find);
			for(int i=0;i<p;i++)
			{
				int k=0;
				for(int j=0;list[i].title[j]!='\0';j++)
				{
					if(key_find[0]==list[i].title[j])
					{
						int bit=1;
						k=1;

						while(key_find[bit]!='\0'&&list[i].title[j+bit]!='\0')
						{
							if(key_find[bit]!=list[i].title[j+bit])
							{
								k=0;
								break;
							}
							else bit++;
						}
						if(key_find[bit]!='\0') k=0;
					}
					if(k)
					{
						printf("%-50s%-20s%-30s%-10d\n",list[i].title,list[i].author,list[i].publisher,list[i].year);
						break;
					}
				}
			}
		}

		if(cmd==3)
		{
			char key_find[55]={0};
			scanf("%s",key_find);
			for(int i=0;i<p;i++)
			{
				int k=0;
				for(int j=0;list[i].title[j]!='\0';j++)
				{
					if(key_find[0]==list[i].title[j])
					{
						int bit=1;
						k=1;

						while(key_find[bit]!='\0'&&list[i].title[j+bit]!='\0')
						{
							if(key_find[bit]!=list[i].title[j+bit])
							{
								k=0;
								break;
							}
							else bit++;
						}
						if(key_find[bit]!='\0') k=0;
					}
					if(k)
					{
						list[i].year=0;
						break;
					}
				}
			}
		}
	}

	for(int i=0;i<p;i++)
	{
		if(list[i].year!=0) fprintf(out,"%-50s%-20s%-30s%-10d\n",list[i].title,list[i].author,list[i].publisher,list[i].year);
	}

	return 0;
}



