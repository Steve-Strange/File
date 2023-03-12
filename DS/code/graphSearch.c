#include<stdio.h>
#include<string.h>
int weights[200][200],visited[200]={0},que[200];
// weights图的邻接矩阵， visited访问数组， que BFS用的访问队列 
int n,m;	//顶点数和边数 
void travelDFS(int v)
{
	int i;
	printf("%d ",v);	//输出 
	visited[v]=1;		//标记已访问 
	for(i = 0; i < n; i++)
		if (weights[v][i] && !visited[i])	//如果这行邻接节点有元素 且未访问过 
		{
			travelDFS(i);		//DFS访问 
		}
}
void travelBFS(int v)
{
	int i,head=0,tail=1,tmp;	//队头，队尾，出列的元素 
	que[head]=v;	//入队 
	while(head<=tail)	//判断队列是否访问完毕 
	{
		tmp=que[head++];	//出队 
		if(visited[tmp])	continue;	//如果访问过 
		else
		{
			printf("%d ",tmp);		//打印出队元素 
			visited[tmp]=1;			//已访问 
			for(i=0;i<n;i++)
				if (weights[tmp][i] && !visited[i])	//如果这行邻接节点有元素 且未访问过 
					que[tail++]=i;		//入队 
		}
	}
}

int main()
{	
	int u,v,i,del;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&u,&v); //录入矩阵 
		weights[u][v]=1;
		weights[v][u]=1;
	}
	travelDFS(0); printf("\n");
	
	memset(visited,0,sizeof(visited));	//初始化visited 
	travelBFS(0); printf("\n");
	
	scanf("%d",&del);
	memset(visited,0,sizeof(visited));	//初始化visited 
	visited[del]=1;		//	要删除的元素设置为已访问 
	travelDFS(0); printf("\n");
	
	memset(visited,0,sizeof(visited));//初始化visited 
    memset(que,0,sizeof(que));//初始化队列
	visited[del]=1;	
	travelBFS(0); printf("\n");
	return 0;
}