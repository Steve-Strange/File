#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 512

typedef struct Edge
{
    int eno;    //�ߵı��
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
int V0,V1;   //ʼĩ

Edge *insertEdge(Edge *head,int avex,int eno);
void eDFS(int v,int level);
void printPath(int n);

int main(void)
{
    int en,eno,i,v1,v2;
    scanf("%d %d",&Vnum,&en);
    for(i=0;i<en;i++)            //¼��ͼ
    {
        scanf("%d %d %d",&eno,&v1,&v2);
        Graph[v1].link=insertEdge(Graph[v1].link,v2,eno);
        Graph[v2].link=insertEdge(Graph[v2].link,v1,eno);
    }
    V0=0;
    V1=Vnum-1;       //����ʼĩ
    Visited[V0]=1;   //����߹�����1
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

    if(!head)      //������
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

void eDFS(int v,int level)     //��������ж���·�� ���߹���·�����ߣ� 
{
    Edge *p;
    if(v==V1)
    {
        printPath(level);
        return;
    }

    for(p=Graph[v].link;p!=NULL;p=p->next)  //���������ڽӽڵ�
        if(!Visited[p->adjvex])  //û�߹�
        {
            Paths[level]=p->eno;    //����·��
            Visited[p->adjvex]=1;
            eDFS(p->adjvex,level+1);    //��һ��
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