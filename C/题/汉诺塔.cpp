#include<stdio.h>
#include<math.h>

int n;
int book[105];
typedef struct line
{
	int x1;
	int y1;
	int x2;
	int y2;
}line;

int cmp(const void* a,const void* b)
{
	line *p,*q;
	p=(line*)a;
	q=(line*)b;
	
	return p->x1-q->x1;
}



int main()
{

	line a[105]={0};
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
	}
	qsort(a,n,sizeof(line),cmp);
	for(int i=0;i<n;i++)
	{
		printf("%d %d %d %d\n",a[i].x1,a[i].y1,a[i].x2,a[i].y2);
	}
	int max=0;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int cnt=0;
		int p=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[p].x2==a[j].x1&&a[p].y2==a[j].y1)
			{
				cnt++;
				p=j;
			}
		}
		if(cnt>max)
		{
			max=cnt;
			ans=i;
		}
	}
	printf("%d %d %d",max+1,a[ans].x1,a[ans].y1);
}
