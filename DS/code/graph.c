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
       struct edge *next;     //�ڽӽڵ㹹�ɵ�����
}ELink;     //�ڽӽڵ�

typedef struct ver{
       ELink *link;
}VLink;
VLink  G[MaxV];     //����ڵ㣬���������洢�ߵ���Ϣ��ָ��Ľڵ�

//������β����һ���ڵ�
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
//����ͼ
void createGraph(VLink graph[]){ 
    
  int i,n,v1,v2;
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d %d",&v1,&v2);
    while(v2 != -1){
      graph[v1].link=insertEdge(graph[v1].link, v2);
      graph[v2].link=insertEdge(graph[v2].link, v1);    //����ͼ �����Գƣ���Ϊ�ڽӽڵ�
      //�ڽӾ���Ļ�  graph[v1][v2]=graph[v2][v1]=1;
      scanf("%d",&v2);
    }
  }
}

//��ͼ������ ����֮��ֻ��һ����
int  Visited[MaxV]={0}; //��ʶ�����Ƿ񱻷��ʹ���NΪ������
void  travelDFS(VLink  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    for(i=0; i<n; i++)
        if( !Visited[i] ) DFS(G, i);
}

void DFS(VLink  G[ ], int v)        //DFS�������
{
    ELink  *p;
    Visited[v] = 1; //��ʶĳ���㱻���ʹ�
    VISIT(G, v); //����ĳ����
    for(p = G[v].link; p !=NULL;  p=p->next)
         if(!Visited[p->adj] )
             DFS(G, p->adj);
}


int  Visited[MaxV]={0}; //��ʶ�����Ƿ񱻷��ʹ���NΪ������
void  travelBFS(VLink  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    for(i=0; i<n; i++)
        if( !Visited[i] ) BFS(G, i);
}

void BFS(VLink  G[ ], int v)        //BFS�������
{
    ELink  *p;
    VISIT(G, v); //���ʵ�ǰ����
    Visited[v] = 1; //��ʶĳ���㱻���ʹ�
    enQueue(Q, v);
    while( !emptyQ(Q)){
         v = deQueue(Q);  //ȡ����ͷԪ��
         p = G[v].link;  //��ȡ�ö����һ���ڽӶ���
         for(; p != NULL ; p = p->next ) //���ʸö����µ�ÿ���ڽӶ���
             if( !Visited[p->adj] ) {
                    VISIT(G, p->adj); //���ʵ�ǰ����
                    Visited[p->adj] = 1; //��ʶĳ���㱻���ʹ�
                    enQueue(G, p->adj);
           }
     }
}


/*��С�������㷨��
1.����ķ�㷨��Prim�����Զ������������С�������Ķ��㼯U�ʹ������㼯V-U�У�
���ϵ�Ѱ����̱�(������С��)���ҵ��󽫶�Ӧ������뼯��U��
ֱ�����ж�����������(V-U��û��ʣ�ඥ��)
2.��³˹�����㷨��Kruskal�����Ա߲�����ÿ��ѡȡһ����̱ߣ�
�������͵�ǰ��С���������ɻ�����·����������̱߼�����С�������С�
��ѡȡ��n-1��������-1�����ߣ����ҳ������з��������Ĳ��ɻ�����С������������ϡ�
*/

void Prim(int  weights[][MAXVER], int n, int src, int edges[])       //prim��С������
{ //weightsΪȨ�����顢nΪ���������srcΪ��С���ĵ�һ�����㡢edgeΪ��С��������
    /*int weights[MAXVER][MAXVER]; ��ͼG�д��ڱ� (i,j) ����weights[i][j]Ϊ��Ȩֵ������Ϊһ��INFINITY
    int edges[MAXVER]; �������ɵ���С�������ıߣ��� (i,edges[i]) Ϊ��С��������һ���ߣ�Ӧ��n-1����
    int minweight[MAXVER];���δȷ��Ϊ�������Ķ�������ȷ�����������϶���ı�Ȩ��
    minweight[i]��ʾ����i���������϶���ı�Ȩ�أ� minweight[i] = 0 ��ʾ����i��ȷ��Ϊ��С����������*/
    int minweight [MAXVER], min;
    int i, j, k;
    for(i=0; i<n; i++){  //��ʼ���������
        minweight[i] = weights[src][i];  //��src������֮�бߵ�Ȩֵ��������
        edges[i]  = src;  //��ʼ�����ж����ǰ�򶥵�Ϊsrc (src,i)
    }
    minweight[src]  = 0;   //����һ������src�������������
    for(i=1; i< n; i++){
        min = INFINITY;
        for(j=0, k=0;  j<n; j++)
            if(minweight[j] !=0 && minweight[j] < min) {  //������������Сֵ�����±�Ϊk
                min = minweight[j];  k = j;
            }
        minweight[k] = 0;  //�ҵ���С����һ������
        for(j=0;  j<n; j++)
             if(minweight[j] != 0 && weights[k][j] < minweight[j] ) {  
                  minweight[j] = weights[k][j];    //��С�ڵ�ǰȨֵ�ı�(k,j)Ȩֵ����������
                  edges[j] = k;   //����(j,k)��Ϣ�����������
             }
    }
}

int main(){ //

} 