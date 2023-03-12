#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
struct edge			//边结构体 
{
	int ID;			//路径ID 
	int u,v;		//两个顶点 
	int w;			//权重 
};
struct edge edges[6000];
int i,top=0;
int Father[1000],MinSpanTreeVertex[2000];	
//Father存储的是每个顶点的最早出现（祖先）顶点,MinSpanTreeVertex存储的是路径顶点ID
int cnt;
long long res;	//结果 
//最小生成树——Kruskal算法（并查集）  O(elog2e) e为边数
void initFather(int vertexNum)
{
	int i; 
	for(i=1;i<=vertexNum;++i)
	{
		Father[i]=i;	//初始话祖先数组（一开始都是自己本身的编号） 
	}
}
int getFather(int x)
{
	return Father[x]==x?x:(Father[x]=getFather(Father[x]));	//回退祖先 
}
void kruskal(int vertexNum,int edgeNum)
{
	int p,q;
	cnt=0,res=0;
	for(i=0;i<edgeNum;++i)
	{
		p=getFather(edges[i].u);	//回退到祖先 
		q=getFather(edges[i].v);	//回退到祖先 
		if(p!=q)		//如果祖先不同（即没有构成闭环） 
		{
			Father[p]=q;	//更新祖先 
			MinSpanTreeVertex[top++]=edges[i].ID;	//录入节点信息 
			res+=edges[i].w;	//加上花费的费用 
			cnt++;				//树节点+1 
		}
		if(cnt==vertexNum-1)	//满足条件 
		{
			break;
		}
	}
}
int cmp(const void*p1,const void*p2)	//按照权重排序 
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
	initFather(n);	//初始化祖先数组 
	int i;
	for(i=0;i<m;i++)
		scanf("%d %d %d %d",&edges[i].ID,&edges[i].u,&edges[i].v,&edges[i].w);
	qsort(edges,m,sizeof(struct edge),cmp);
	kruskal(n,m);
	printf("%d\n",res);
	qsort(MinSpanTreeVertex,top,sizeof(int),cmp2);	//排序 
	for(i=0;i<n-1;i++)
		printf("%d ",MinSpanTreeVertex[i]);	//输出 
}