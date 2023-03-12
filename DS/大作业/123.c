#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

double eps=1e-6;
int word[10000000];
int tree[10000000][26];
double sim[1000][2]={0};
unsigned char readin[10000000];
int readlen=0;
char vocab[100];
int passagefreq[1000][100000]={0};
int articlefreq[1000]={0};

int cnt = 1;

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
    if(word[p]==0) return 0;
    return p;
}

int cmp(const void *a, const void *b)
{
    if((double *)a-(double *)b>eps) return -1;
    else return 1;
}

int main(int argc,char** argv)
{
    FILE* dictionary, *stopwords, *article;

    dictionary=fopen("dictionary.txt","r");
    readlen=fread(readin,1,10000000,dictionary);
    readin[readlen++]=0;
    for(int i=0,flag=0,p=1;i<readlen;i++)
    {
        if(readin[i]>='a'&&readin[i]<='z')
        {
            if(!flag) flag=1;
            if(!tree[p][readin[i]-'a']) tree[p][readin[i]-'a']=++cnt;
            p=tree[p][readin[i]-'a'];
        }
        else if(flag)
        {
            word[p]=1;
            flag=0;
            p=1;
        }
    }
    fclose(dictionary);

    stopwords=fopen("stopwords.txt","r");
    readlen=fread(readin,1,10000000,stopwords);
    readin[readlen++]=0;
    for(int i=0,flag=0,p=1;i<readlen;i++)
    {
        if(readin[i]>='a'&&readin[i]<='z')
        {
            if(!flag) flag=1;
            if(!tree[p][readin[i]-'a']) tree[p][readin[i]-'a']=++cnt;
            p=tree[p][readin[i]-'a'];
        }
        else if(flag)
        {
            word[p]=0;
            flag=0;
            p=1;
        }
    }
    fclose(stopwords);

    article=fopen("article.txt","r");

    char x[1000]={0};
    scanf("%s",x);
    printf("%d\n",findword(x));

    int passage=1;
    int num=0;
    char keywords[10000]={0};
    char word[50][100]={0};
    int wordnum=0;
    int length=0;
    int bit=0;
    int keysum=0;
    int sum=0;

    length=strlen(argv[1]);
	for(int i=0;i<length;i++) num=num*10+argv[1][i]-'0';
	for(int i=2;i<argc;i++)
	{
		
	}
    FILE *out=fopen("results.txt", "w");

    printf("%d",num);
    int keynum[50]={0};

    for(int i=0;i<wordnum;i++)
    {
        keynum[i]=findword(word[i]);
    }

//
//    while(letter=fgetc(article),letter!=EOF)
//    {
//        int cnt=0;
//        memset(vocab,0,sizeof(vocab));
//        if(letter=='\f')
//        {
//            passage++;
//        }
//        if(isalpha(letter))
//        {
//            while(isalpha(letter))
//            {
//                letter=tolower(letter);
//                vocab[cnt++]=letter;
//                letter=fgetc(article);
//            }
//            vocab[cnt]=='\0';
//            int temp=findword(vocab);
//            if(temp!=0)
//            {
//                sum++;
//                for(int i=0;i<wordnum;i++)
//				{
//                    if(temp==keynum[i])
//                    {
//                        passagefreq[i][passage]++;
//                        break;
//                    }
//				}
//            }
//        }
//        if(passagefreq[wordnum][passage])
//        {
//            articlefreq[wordnum]++;
//        }
//    }

    // printf("%d %d\n",sum,passage);
//    for(int i=1; i<=passage;i++)
//    {
//        sim[i][1]=i;
//        for(int j=0;j<wordnum;j++)
//        {
//            sim[i][0]+=passagefreq[j][i]*log10((double)passage/articlefreq[j]);
//        }
//        // sim[i][0]=sim[i][0]*(double)(100/sum);
//    }

    // for(int i=1;i<=5;i++) printf("%.6lf %d\n",sim[i][0],sim[i][1]);

    // qsort(sim,passage,sizeof(double)*2,cmp);

	// for(int i=0;i<5;i++)
	// {
	// 	printf("%.6lf %d 1-%d\n",sim[i][0],sim[i][1],sim[i][1]);
	// }

    return 0;
}