#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

typedef struct index
{
	int a;
	int b;
}index;

int cmp(const void*a,const void*b)
{
	index *p=(index*)a;
	index *q=(index*)b;
	return -(p->b-q->b);
}

int main()
{
	index y1[20];
	index y2[20];
	index p[400];
	int a,b;
	int k1=0;
	int k2=0;
	while(scanf("%d %d",&a,&b))
	{
		y1[k1].a=a;
		y1[k1].b=b;
		k1++;
		if(getchar()=='\n') break;
	}
	while(scanf("%d %d",&a,&b))
	{
		y2[k2].a=a;
		y2[k2].b=b;
		k2++;
		if(getchar()=='\n') break;
	}
//		for(int i=0;i<k1;i++)
//		{
//			printf("%d %d\n",y1[i][0],y1[i][1]);
//		}
//		for(int i=0;i<k2;i++)
//		{
//			printf("%d %d\n",y2[i][0],y2[i][1]);
//		}

	int cnt=0;
	for(int i=0;i<k1;i++)
	{
		for(int j=0;j<k2;j++)
		{
			p[cnt].a=y1[i].a*y2[j].a;
			p[cnt].b=y1[i].b+y2[j].b;
			cnt++;
		}
	}

	qsort(p,cnt,sizeof(index),cmp);

//	for(int i=0;i<cnt;i++)
//	{
//		printf("%d %d\n",p[i].a,p[i].b);
//	}

	for(int i=0;i<cnt-1;i++)
	{
		int bit=i+1;
		while(p[i].b==p[bit].b)
		{
			p[i].a+=p[bit].a;
			p[bit].a=0;
			bit++;
		}
		i=bit-1;
	}
	for(int i=0;i<cnt;i++)
	{
		if(p[i].a!=0)	printf("%d %d ",p[i].a,p[i].b);
	}
}


