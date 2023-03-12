#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
struct edge			//�߽ṹ�� 
{
	int ID;			//·��ID 
	int u,v;		//�������� 
	int w;			//Ȩ�� 
};
struct edge edges[6000];
int i,top=0;
int Father[1000],MinSpanTreeVertex[2000];	
//Father�洢����ÿ�������������֣����ȣ�����,MinSpanTreeVertex�洢����·������ID
int cnt;
long long res;	//��� 
//��С����������Kruskal�㷨�����鼯��  O(elog2e) eΪ����
void initFather(int vertexNum)
{
	int i; 
	for(i=1;i<=vertexNum;++i)
	{
		Father[i]=i;	//��ʼ���������飨һ��ʼ�����Լ�����ı�ţ� 
	}
}
int getFather(int x)
{
	return Father[x]==x?x:(Father[x]=getFather(Father[x]));	//�������� 
}
void kruskal(int vertexNum,int edgeNum)
{
	int p,q;
	cnt=0,res=0;
	for(i=0;i<edgeNum;++i)
	{
		p=getFather(edges[i].u);	//���˵����� 
		q=getFather(edges[i].v);	//���˵����� 
		if(p!=q)		//������Ȳ�ͬ����û�й��ɱջ��� 
		{
			Father[p]=q;	//�������� 
			MinSpanTreeVertex[top++]=edges[i].ID;	//¼��ڵ���Ϣ 
			res+=edges[i].w;	//���ϻ��ѵķ��� 
			cnt++;				//���ڵ�+1 
		}
		if(cnt==vertexNum-1)	//�������� 
		{
			break;
		}
	}
}
int cmp(const void*p1,const void*p2)	//����Ȩ������ 
{
	struct edge *a=(struct edge*)p1;
	struct edge *b=(struct edge*)p2;
	return a->w-b->w;
}
int cmp2(const void* a, const void* b){
    int*p=(int*)a;
    int*q=(int*)b;
	return *p-*q;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	initFather(n);	//��ʼ���������� 
	int i;
	for(i=0;i<m;i++)
		scanf("%d %d %d %d",&edges[i].ID,&edges[i].u,&edges[i].v,&edges[i].w);
	qsort(edges,m,sizeof(struct edge),cmp);
	kruskal(n,m);
	printf("%d\n",res);
	qsort(MinSpanTreeVertex,top,sizeof(int),cmp2);	//���� 
	for(i=0;i<n-1;i++)
		printf("%d ",MinSpanTreeVertex[i]);	//��� 
}