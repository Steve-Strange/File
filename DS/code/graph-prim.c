#include<stdio.h>
#include<stdlib.h>
#define M 101
#define INF 0x3f3f3f3f
int sum,top=0,MinSpanTreeVertex[200],egdesID[200][200];	
// MinSpanTreeVertex�洢����·������ID��egdesID�洢�������������·��ID 
void MinSpanTree_Prim(int weights[][M],int vertexNum,int FirstVertexID,int *edges);//Prim�㷨 
int cmp (const void * a, const void * b);
int main()
{	
	int weights[M][M],edges[M];
	int i,j,k,vertexNum,edgeNum,ID;
	int v1,v2,w;
	scanf("%d %d",&vertexNum,&edgeNum);	//��������ͱ߸��� 
	for(i=0;i<vertexNum;i++)
		for(j=0;j<vertexNum;j++)
			weights[i][j]=INF;	//��ʼ�� 
	for(i=0;i<edgeNum;i++)
	{
		scanf("%d %d %d %d",&ID,&v1,&v2,&w);	//¼����Ϣ 
		egdesID[v1][v2]=ID;
		egdesID[v2][v1]=ID;
		weights[v1][v2]=w;
		weights[v2][v1]=w;
	}
	MinSpanTree_Prim(weights,vertexNum,0,edges);	//��С������ 
	qsort(MinSpanTreeVertex,top,sizeof(int),cmp);	//��Ҫ������ 
	printf("%d\n",sum);
	for(i=0;i<vertexNum-1;i++)
		printf("%d ",MinSpanTreeVertex[i]);	//��� 
	return 0;
}
//��С����������Prim�㷨����0��ʼ��   O(n^2)
void MinSpanTree_Prim(int weights[][M],int vertexNum,int FirstVertexID,int *edges)
{// weightsΪȨ�����飬 vertexNumΪ��������� FirstVertexIDΪ��С����һ�����ڵ㣬edgesΪ��С��������
	int min,minweight[M];
	int i,j,k;
	for(i=0;i<vertexNum;i++)	//��ʼ��������� 
	{
		minweight[i]=weights[FirstVertexID][i];		//������ĵ�һ��������֮�бߵ�Ȩֵ�������� 
		edges[i]=FirstVertexID;		//��ʼ����һ������ 
	}
	minweight[FirstVertexID] = 0;	//����һ�����������������0 ��ʾΪ��Ӧ�±�Ķ����Ѿ������� 
	for(i=1;i<vertexNum;i++)
	{
		min=INF;
		for(j=0,k=0;j<vertexNum;j++)
			if(minweight[j]!=0 && minweight[j]<min)
			{
				min = minweight[j];
				k=j;				//���������ҵ���Сֵ�����±�Ϊ k 
			}
		sum+=minweight[k];
		minweight[k] = 0;//�ҵ���С��������һ���¶���
		//printf("%d ",egdesID[k][edges[k]]);	
		MinSpanTreeVertex[top]=egdesID[k][edges[k]]; 	//��¼������Ϣ 
		top++;
		for(j=0;j<vertexNum;j++)	//���μ���¼���Ķ��� k ��δ���붥��֮���Ȩֵ 
			if(minweight[j]!=0 && weights[k][j] < minweight[j])
			{
				minweight[j]=weights[k][j];	//�滻���� 
				edges[j]=k;
			}
	}
}
int cmp (const void * a, const void * b)
{
    return *(int*)a - *(int*)b;
}