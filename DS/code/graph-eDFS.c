#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 512

typedef struct Edge
{
    int eno;    //边的编号
    int adjvex;
    int weight;
    struct Edge *next;
}Edge;
typedef struct Ver
{
    Edge *link;
}Ver;

Ver Graph[MAXSIZE];
char Visited[MAXSIZE]={0};
int Paths[MAXSIZE]={0};
int Vnum;
int V0,V1;   //始末

Edge *insertEdge(Edge *head,int avex,int eno);
void eDFS(int v,int level);
void printPath(int n);

int main(void)
{
    int en,eno,i,v1,v2;
    scanf("%d %d",&Vnum,&en);
    for(i=0;i<en;i++)            //录入图
    {
        scanf("%d %d %d",&eno,&v1,&v2);
        Graph[v1].link=insertEdge(Graph[v1].link,v2,eno);
        Graph[v2].link=insertEdge(Graph[v2].link,v1,eno);
    }
    V0=0;
    V1=Vnum-1;       //设置始末
    Visited[V0]=1;   //起点走过了设1
    eDFS(V0,0);

    return 0;
}

Edge *insertEdge(Edge *head,int avex,int eno)
{
    Edge *e,*p;
    e=(Edge *)malloc(sizeof(Edge));
    e->eno=eno;
    e->adjvex=avex;
    e->weight=1;
    e->next=NULL;

    if(!head)      //拉拉链
    {
        head=e;
        return head;
    }
    else
    {
        p=head;
        while(p->next!=NULL)
            p=p->next;
        p->next=e;
        return head;
    }
}

void eDFS(int v,int level)     //两点间所有独立路径 （走过的路不能走） 
{
    Edge *p;
    if(v==V1)
    {
        printPath(level);
        return;
    }

    for(p=Graph[v].link;p!=NULL;p=p->next)  //遍历所有邻接节点
        if(!Visited[p->adjvex])  //没走过
        {
            Paths[level]=p->eno;    //存入路径
            Visited[p->adjvex]=1;
            eDFS(p->adjvex,level+1);    //下一层
            Visited[p->adjvex]=0;
        }

    return;
}

void printPath(int n)
{
    int i;
    for(i=0;i<n;i++)
         printf("%d ",Paths[i]);
     printf("\n");
     return;
}