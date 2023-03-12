#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MaxV    256
#define MAXVER  512
#define INFINITY   32767

typedef struct  edge{ 
       int  adj;
       int  wei;
       struct edge *next;     //邻接节点构成的链表
}ELink;     //邻接节点

typedef struct ver{
       ELink *link;
}VLink;
VLink  G[MaxV];     //顶点节点，后伸出链表存储边的信息和指向的节点

//在链表尾插入一个节点
ELink  *insertEdge(ELink *head, int avex)
{
    ELink *e,*p;
    e =(ELink *)malloc(sizeof(ELink));
    e->adj= avex; e->wei=1; e->next = NULL;
    if(head == NULL)  { head=e; return head; }
    for(p=head; p->next != NULL; p=p->next);
    p->next = e;
    return head;
}
//创建图
void createGraph(VLink graph[]){ 
    
  int i,n,v1,v2;
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d %d",&v1,&v2);
    while(v2 != -1){
      graph[v1].link=insertEdge(graph[v1].link, v2);
      graph[v2].link=insertEdge(graph[v2].link, v1);    //无向图 两个对称，互为邻接节点
      //邻接矩阵的话  graph[v1][v2]=graph[v2][v1]=1;
      scanf("%d",&v2);
    }
  }
}

//简单图遍历， 两点之间只有一条线
int  Visited[MaxV]={0}; //标识顶点是否被访问过，N为顶点数
void  travelDFS(VLink  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    for(i=0; i<n; i++)
        if( !Visited[i] ) DFS(G, i);
}

void DFS(VLink  G[ ], int v)        //DFS广度优先
{
    ELink  *p;
    Visited[v] = 1; //标识某顶点被访问过
    VISIT(G, v); //访问某顶点
    for(p = G[v].link; p !=NULL;  p=p->next)
         if(!Visited[p->adj] )
             DFS(G, p->adj);
}


int  Visited[MaxV]={0}; //标识顶点是否被访问过，N为顶点数
void  travelBFS(VLink  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    for(i=0; i<n; i++)
        if( !Visited[i] ) BFS(G, i);
}

void BFS(VLink  G[ ], int v)        //BFS广度优先
{
    ELink  *p;
    VISIT(G, v); //访问当前顶点
    Visited[v] = 1; //标识某顶点被访问过
    enQueue(Q, v);
    while( !emptyQ(Q)){
         v = deQueue(Q);  //取出队头元素
         p = G[v].link;  //获取该顶点第一个邻接顶点
         for(; p != NULL ; p = p->next ) //访问该顶点下的每个邻接顶点
             if( !Visited[p->adj] ) {
                    VISIT(G, p->adj); //访问当前顶点
                    Visited[p->adj] = 1; //标识某顶点被访问过
                    enQueue(G, p->adj);
           }
     }
}


/*最小生成树算法：
1.普里姆算法（Prim）：对顶点操作，在最小生成树的顶点集U和待处理顶点集V-U中，
不断地寻找最短边(代价最小变)，找到后将对应顶点加入集合U，
直到所有顶点均处理完毕(V-U里没有剩余顶点)
2.克鲁斯卡尔算法（Kruskal）：对边操作，每次选取一条最短边，
如果不会和当前最小生成树构成环（回路），将此最短边加入最小生成树中。
当选取了n-1（顶点数-1）条边，或找出了所有符合条件的不成环边最小生成树生成完毕。
*/

void Prim(int  weights[][MAXVER], int n, int src, int edges[])       //prim最小生成树
{ //weights为权重数组、n为顶点个数、src为最小树的第一个顶点、edge为最小生成树边
    /*int weights[MAXVER][MAXVER]; 当图G中存在边 (i,j) ，则weights[i][j]为其权值，否则为一个INFINITY
    int edges[MAXVER]; 存入生成的最小生成树的边，如 (i,edges[i]) 为最小生成树的一条边，应有n-1条边
    int minweight[MAXVER];存放未确定为生成树的顶点至已确定的生成树上顶点的边权重
    minweight[i]表示顶点i至生成树上顶点的边权重， minweight[i] = 0 表示顶点i已确定为最小生成树顶点*/
    int minweight [MAXVER], min;
    int i, j, k;
    for(i=0; i<n; i++){  //初始化相关数组
        minweight[i] = weights[src][i];  //将src顶点与之有边的权值存入数组
        edges[i]  = src;  //初始化所有顶点的前序顶点为src (src,i)
    }
    minweight[src]  = 0;   //将第一个顶点src顶点加入生成树
    for(i=1; i< n; i++){
        min = INFINITY;
        for(j=0, k=0;  j<n; j++)
            if(minweight[j] !=0 && minweight[j] < min) {  //在数组中找最小值，其下标为k
                min = minweight[j];  k = j;
            }
        minweight[k] = 0;  //找到最小树的一个顶点
        for(j=0;  j<n; j++)
             if(minweight[j] != 0 && weights[k][j] < minweight[j] ) {  
                  minweight[j] = weights[k][j];    //将小于当前权值的边(k,j)权值加入数组中
                  edges[j] = k;   //将边(j,k)信息存入边数组中
             }
    }
}

int main(){ //

} 