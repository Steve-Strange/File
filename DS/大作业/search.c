#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

double eps=1e-6;
int words[10000000];
int tree[10000000][26];
unsigned char readin[100000000];
char passage[10000000][20];
int passagecnt=1;
int readlen=0;
int TNkd[1000][100000]={0};
int DNk[100000]={0};
int TNd[100000]={0};

struct sim
{
    double data;
    int page;
}sims[100000];
int findword(char *s)
{
    int p=1;
    for (int i=0;s[i];i++)
    {
        if(!tree[p][s[i]-'a'])
        {
            return 0;
        }
        p=tree[p][s[i]-'a'];
    }
    if(words[p]==0) return 0;
    return p;
}
int cmp(const void *a, const void *b)
{
	struct sim *p=(struct sim*)a;
    struct sim *q=(struct sim*)b;
	if(p->data-q->data>eps)	return -1;
	if(q->data-p->data>eps)	return 1;
	if(p->page>q->page)	return 1;
	if(p->page<p->page)	return -1;
	return 0;
}

int main(int argc,char** argv)
{
    int cnt=1;
    FILE* dictionary, *stopwords, *article;
    dictionary=fopen("dictionary.txt","r");
    readlen=fread(readin,1,100000000,dictionary);
    readin[readlen++]=0;
    for(int i=0,flag=0,p=1;i<readlen;i++)
    {
        if(readin[i]>='a'&&readin[i]<='z')
        {
            flag=1; 
            if(!tree[p][readin[i]-'a']) tree[p][readin[i]-'a']=++cnt;
            p=tree[p][readin[i]-'a'];
        }
        else if(flag)
        {
            words[p]=1;
            flag=0;
            p=1;
        }
    }
    fclose(dictionary);

    stopwords=fopen("stopwords.txt","r");
    readlen=fread(readin,1,100000000,stopwords);
    readin[readlen++]=0;
    for(int i=0,flag=0,p=1;i<readlen;i++)
    {
        if(readin[i]>='a'&&readin[i]<='z')
        {
            flag=1;
            if(!tree[p][readin[i]-'a']) tree[p][readin[i]-'a']=++cnt;
            p=tree[p][readin[i]-'a'];
        }
        else if(flag)
        {
            words[p]=0;
            flag=0;
            p=1;
        }
    }
    fclose(stopwords);

    int keynum=2;
    int num=0;
    int length=0;
    length=strlen(argv[1]);
	for(int i=0;i<length;i++) num=num*10+argv[1][i]-'0';
	for(int i=2;i<argc;i++)
	{
		if(words[findword(argv[i])]) words[findword(argv[i])]=keynum++;
	}
    
    article=fopen("article.txt","r");
    readlen=fread(readin,1,100000000,article);
    readin[readlen++]=0;
    fclose(article);

    int i=0;
    int p=1,flag=0;

    int cntchar=0;
    while(readin[i]=='\n'||readin[i]=='\r') i++;
    while(readin[i]!='\n'&&readin[i]!='\r')
    {
        passage[passagecnt][cntchar++]=readin[i++];
    }
    passage[passagecnt][cntchar]='\0';

    while(i<readlen)
    {
        for(;readin[i]!='\f'&&i<readlen;i++)
		{
            if((readin[i]>='a'&&readin[i]<='z')||(readin[i]>='A'&&readin[i]<='Z'))
            {
                if(readin[i]>='A'&&readin[i]<='Z') readin[i]-=('A'-'a');
                flag=1;
                p=tree[p][readin[i]-'a'];
            }
            else if(flag)
            {
                if(words[p])
                {
                    TNd[passagecnt]++; 
                    if(words[p]>1) TNkd[words[p]][passagecnt]++;
                }
                flag=0;
                p=1;
            }
		}
        if(readin[i]=='\f')
        {
            cntchar=0;
            for(int j=2;j<keynum;j++)
            {
                if(TNkd[j][passagecnt]) DNk[j]++;
            }
            passagecnt++;
            i++;
            while(readin[i]=='\n'||readin[i]=='\r') i++;
            while(readin[i]!='\n'&&readin[i]!='\r')
            {
                passage[passagecnt][cntchar++]=readin[i++];
            }
            passage[passagecnt][cntchar]='\0';
        }
    }

    for(int j=2;j<keynum;j++)
    {
        if(TNkd[j][passagecnt]) DNk[j]++;
    }

        // for(int k=2;k<keynum;k++)
        // {
        //     for(int j=2;j<10;j++)
        //     {
        //         printf("%d ",TNkd[k][j+1]);
        //     }
        // }

        // for(int j=1;j<=50;j++)
        // {
        //     printf("%d ",TNd[j]);
        // }
    

    for(int i=1;i<=passagecnt;i++)
    {
        sims[i].page=i;
        for(int j=2;j<keynum;j++)
        {
            if(DNk[j]==0) continue;
            sims[i].data+=((double)TNkd[j][i]/TNd[i])*(log10((double)passagecnt/DNk[j]))*100;
        }
    }
    qsort(sims,passagecnt,sizeof(struct sim),cmp);

    int valid=1;
    for(int i=1;i<=passagecnt;i++)
    {
        if(sims[i].data>eps) valid++;
    }
    // printf("%d",valid);

	for(int i=0;i<5&&i<valid;i++)
	{
		printf("%.6lf %d %s\n",sims[i].data,sims[i].page,passage[sims[i].page]);
	}
    FILE* results=fopen("results.txt","w");
	for(int i=0;i<num&&i<valid;i++)
	{
		fprintf(results,"%.6lf %d %s\n",sims[i].data,sims[i].page,passage[sims[i].page]);
	}
    fclose(results);
    return 0;
}
