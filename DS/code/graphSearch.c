#include<stdio.h>
#include<string.h>
int weights[200][200],visited[200]={0},que[200];
// weightsͼ���ڽӾ��� visited�������飬 que BFS�õķ��ʶ��� 
int n,m;	//�������ͱ��� 
void travelDFS(int v)
{
	int i;
	printf("%d ",v);	//��� 
	visited[v]=1;		//����ѷ��� 
	for(i = 0; i < n; i++)
		if (weights[v][i] && !visited[i])	//��������ڽӽڵ���Ԫ�� ��δ���ʹ� 
		{
			travelDFS(i);		//DFS���� 
		}
}
void travelBFS(int v)
{
	int i,head=0,tail=1,tmp;	//��ͷ����β�����е�Ԫ�� 
	que[head]=v;	//��� 
	while(head<=tail)	//�ж϶����Ƿ������� 
	{
		tmp=que[head++];	//���� 
		if(visited[tmp])	continue;	//������ʹ� 
		else
		{
			printf("%d ",tmp);		//��ӡ����Ԫ�� 
			visited[tmp]=1;			//�ѷ��� 
			for(i=0;i<n;i++)
				if (weights[tmp][i] && !visited[i])	//��������ڽӽڵ���Ԫ�� ��δ���ʹ� 
					que[tail++]=i;		//��� 
		}
	}
}

int main()
{	
	int u,v,i,del;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&u,&v); //¼����� 
		weights[u][v]=1;
		weights[v][u]=1;
	}
	travelDFS(0); printf("\n");
	
	memset(visited,0,sizeof(visited));	//��ʼ��visited 
	travelBFS(0); printf("\n");
	
	scanf("%d",&del);
	memset(visited,0,sizeof(visited));	//��ʼ��visited 
	visited[del]=1;		//	Ҫɾ����Ԫ������Ϊ�ѷ��� 
	travelDFS(0); printf("\n");
	
	memset(visited,0,sizeof(visited));//��ʼ��visited 
    memset(que,0,sizeof(que));//��ʼ������
	visited[del]=1;	
	travelBFS(0); printf("\n");
	return 0;
}