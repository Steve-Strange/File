#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define N1 1000
#define N2 100000
#define N3 10000000
#define N4 100000000
const double eps=0.000001;
int TNkd[N1][N2],TNd[N2],DNk[N1],anum,wnum=2;
char id[N2][50];
double IDFk[N1];

typedef struct Node
{
	int v[26];
	unsigned char end;
}node;
node e[N3];
int p,cnt=2;
struct Ap
{
	double Simd;
	int cnt;
}ap[N2];

unsigned char buf[N4];
FILE *fp;
int i,j,k;
int flen,N;

int cmp(const void *a,const void *b)
{
	struct Ap *c=(struct Ap*)a,*d=(struct Ap*)b;
	if(eps<d->Simd-c->Simd)	return 1;
	if(c->Simd-d->Simd>eps)	return -1;
	if(c->cnt>d->cnt)	return 1;
	if(c->cnt<d->cnt)	return -1;
	return 0;
}
int main(int argc,char** argv)
{	
	fp=fopen("dictionary.txt","r");
	flen=fread(buf,1,N4,fp);
	fclose(fp);
	buf[flen++]=0;
	p=1;
	for(i=0,j=0,k;i<flen;i++)
	{
		if((buf[i]<=122&&buf[i]>=97)||(buf[i]<=90&&buf[i]>=65))
		{
			if(!j)	j=1;
			k=buf[i]>96?buf[i]-97:buf[i]-65;
			if(!e[p].v[k])	e[p].v[k]=cnt++;
			p=e[p].v[k];
		}
		else if(j)
		{
			e[p].end=1;
			p=1;
			j=0;
		}
	}
	
	fp=fopen("stopwords.txt","r");
	flen=fread(buf,1,N4,fp);
	fclose(fp);
	buf[flen++]=0;
	p=1;
	for(i=0,j=0,k;i<flen;i++)
	{
		if((buf[i]<=122&&buf[i]>=97)||(buf[i]<=90&&buf[i]>=65))
		{
			if(!j)	j=1;
			k=buf[i]>96?buf[i]-97:buf[i]-65;
			p=e[p].v[k];
		}
		else if(j)
		{
			if(e[p].end)	e[p].end=0;
			p=1;
			j=0;
		}
	}
	
	k=strlen(argv[1]);
	for(i=0;i<k;i++) N=N*10+argv[1][i]-'0';
	for(i=2;i<argc;i++)
	{
		p=1;
		for(j=0,k;argv[i][j];j++)
		{
			k=argv[i][j]>96?argv[i][j]-97:argv[i][j]-65;
			p=e[p].v[k];
		}
		if(e[p].end)	e[p].end=wnum++;
	}
	
	fp=fopen("article.txt","r");
	flen=fread(buf,1,N4,fp);
	fclose(fp);
	buf[flen++]=0;
	p=1;
	
	i=0;j=0; 
	while(i<flen)
	{
		for(;buf[i]<33||buf[i]>126;i++);
		for(k=0;buf[i]!='\r'&&buf[i]!='\n';i++,k++)	id[anum][k]=buf[i];
		//printf("%d:%s\n",anum,id[anum]);
		for(;buf[i]!=12&&i<flen;i++)
		{
			if((buf[i]<=122&&buf[i]>=97)||(buf[i]<=90&&buf[i]>=65))
			{
				if(!j)	j=1;
				k=buf[i]>96?buf[i]-97:buf[i]-65;
				p=e[p].v[k];
			}
			else if(j)
			{
				if(e[p].end)
				{
					TNd[anum]++;
					if(e[p].end>1)	TNkd[e[p].end][anum]++;
				}
				p=1;
				j=0;
			}
		}
		for(k=2;k<wnum;k++)	if(TNkd[k][anum])	DNk[k]++;
		anum++;
		//if(anum==9000)	break;
	}
	double danum=anum;
	for(j=2;j<wnum;j++)	IDFk[j]=DNk[j]?log10(danum/DNk[j]):0;
	//for(j=2;j<wnum;j++)	printf("%d\n",TNkd[j][23]);
	for(i=0;i<anum;i++)
	{
		for(j=2;j<wnum;j++)	ap[i].Simd+=IDFk[j]*TNkd[j][i];
		ap[i].Simd=ap[i].Simd/TNd[i]*100;
		ap[i].cnt=i;
	}
	qsort(ap,anum,sizeof(struct Ap),cmp);
	for(i=0;i<5&&i<anum&&ap[i].Simd>=eps;i++)	printf("%.6lf %d %s\n",ap[i].Simd,ap[i].cnt+1,id[ap[i].cnt]);
	fp=fopen("results.txt","w");
	for(i=0;i<N&&i<anum&&ap[i].Simd>=eps;i++)	fprintf(fp,"%.6lf %d %s\n",ap[i].Simd,ap[i].cnt+1,id[ap[i].cnt]);
	fclose(fp);
	//for(i=0;i<anum;i++)	printf("TNd:%d\n",TNd[i]);
	//for(i=2;i<wnum;i++)	printf("DNk:%d\n",DNk[i]);
	//system("pause");
	return 0;
}



