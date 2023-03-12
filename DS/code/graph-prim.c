#include<stdio.h>
#include<stdlib.h>
#define M 101
#define INF 0x3f3f3f3f
int sum,top=0,MinSpanTreeVertex[200],egdesID[200][200];	
// MinSpanTreeVertex存储的是路径顶点ID，egdesID存储的是两个顶点间路径ID 
void MinSpanTree_Prim(int weights[][M],int vertexNum,int FirstVertexID,int *edges);//Prim算法 
int cmp (const void * a, const void * b);
int main()
{	
	int weights[M][M],edges[M];
	int i,j,k,vertexNum,edgeNum,ID;
	int v1,v2,w;
	scanf("%d %d",&vertexNum,&edgeNum);	//顶点个数和边个数 
	for(i=0;i<vertexNum;i++)
		for(j=0;j<vertexNum;j++)
			weights[i][j]=INF;	//初始化 
	for(i=0;i<edgeNum;i++)
	{
		scanf("%d %d %d %d",&ID,&v1,&v2,&w);	//录入信息 
		egdesID[v1][v2]=ID;
		egdesID[v2][v1]=ID;
		weights[v1][v2]=w;
		weights[v2][v1]=w;
	}
	MinSpanTree_Prim(weights,vertexNum,0,edges);	//最小生成树 
	qsort(MinSpanTreeVertex,top,sizeof(int),cmp);	//按要求排序 
	printf("%d\n",sum);
	for(i=0;i<vertexNum-1;i++)
		printf("%d ",MinSpanTreeVertex[i]);	//输出 
	return 0;
}
//最小生成树——Prim算法（从0开始）   O(n^2)
void MinSpanTree_Prim(int weights[][M],int vertexNum,int FirstVertexID,int *edges)
{// weights为权重数组， vertexNum为顶点个数， FirstVertexID为最小数第一个个节点，edges为最小生成树边
	int min,minweight[M];
	int i,j,k;
	for(i=0;i<vertexNum;i++)	//初始化相关数组 
	{
		minweight[i]=weights[FirstVertexID][i];		//将传入的第一个顶点与之有边的权值存入数组 
		edges[i]=FirstVertexID;		//初始化第一个顶点 
	}
	minweight[FirstVertexID] = 0;	//将第一个顶点加入生成树，0 表示为相应下表的顶点已经加入树 
	for(i=1;i<vertexNum;i++)
	{
		min=INF;
		for(j=0,k=0;j<vertexNum;j++)
			if(minweight[j]!=0 && minweight[j]<min)
			{
				min = minweight[j];
				k=j;				//在数组中找到最小值，其下标为 k 
			}
		sum+=minweight[k];
		minweight[k] = 0;//找到最小生成树的一个新顶点
		//printf("%d ",egdesID[k][edges[k]]);	
		MinSpanTreeVertex[top]=egdesID[k][edges[k]]; 	//记录顶点信息 
		top++;
		for(j=0;j<vertexNum;j++)	//依次检查新加入的顶点 k 到未加入顶点之间的权值 
			if(minweight[j]!=0 && weights[k][j] < minweight[j])
			{
				minweight[j]=weights[k][j];	//替换操作 
				edges[j]=k;
			}
	}
}
int cmp (const void * a, const void * b)
{
    return *(int*)a - *(int*)b;
}