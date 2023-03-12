/*����Ŀ¼��

��3�� ���Ա� 
    01���Ա�˳��洢_List

    02���Ա���ʽ�洢_LinkList

    03��̬����_StaticLinkList


��4�� ջ�����
    01˳��ջ_Stack

    02��ջ����ռ�_DoubleStack

    03��ջ_LinkStack

    04쳲���������_Fibonacci

    05˳�����_Queue

    06������_LinkQueue


��5�� ��
    01��_String

    02ģʽƥ��_KMP


��6�� ��
    01������˳��ṹʵ��_BiTreeArray

    02��������ʽ�ṹʵ��_BiTreeLink

    03����������_ThreadBinaryTree


��7�� ͼ
    01�ڽӾ��󴴽�_CreateMGraph

    02�ڽӱ���_CreateALGraph

    03�ڽӾ�����Ⱥ͹�ȱ���DFS_BFS

    04�ڽӱ���Ⱥ͹�ȱ���DFS_BFS

    05��С������_Prim

    06��С������_Kruskal

    07���·��_Dijkstra

    08���·��_Floyd

    09��������_TopologicalSort

    10�ؼ�·��_CriticalPath


��8�� ����
    01��̬����_Search

    02����������_BinarySortTree

    03ƽ�������_AVLTree

    04B��_BTree

    05ɢ�б�_HashTable


��9�� ����
    01����_Sort

ע��1�����ǡ������ݽṹ��һ��ıʼǣ�
2������̫������Ҫ��ɶ�������ɣ�
3��������Ҫ��֪ʶ����������³�����*/

��3�¡����Ա� 
//01���Ա�˳��洢_List
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* �洢�ռ��ʼ������ */
 
typedef int Status;          /* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;        /* ElemType���͸���ʵ������������������Ϊint */


Status visit(ElemType c)
{
    printf("%d ",c);
    return OK;
}
 
typedef struct SqList
{
	ElemType data[MAXSIZE];        /* ���飬�洢����Ԫ�� */
	int length;                                /* ���Ա�ǰ���� */
}SqList;
 
/* ��ʼ��˳�����Ա� */
Status InitList(SqList *L) 
{ 
    L->length=0;
    return OK;
}
 
/* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
Status ListEmpty(SqList L)
{ 
	if(L.length==0)
		return TRUE;
	else
		return FALSE;
}
 
/* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������L����Ϊ�ձ� */
Status ClearList(SqList *L)
{ 
    L->length=0;
    return OK;
}
 
/* ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
int ListLength(SqList L)
{
	return L.length;
}
 
/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* �����������e����L�е�i������Ԫ�ص�ֵ,ע��i��ָλ�ã���1��λ�õ������Ǵ�0��ʼ */
Status GetElem(SqList L,int i,ElemType *e)
{
    if(L.length==0 || i<1 || i>L.length)
            return ERROR;
    *e=L.data[i-1];
 
    return OK;
}
 
/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* �������������L�е�1����e�����ϵ������Ԫ�ص�λ�� */
/* ������������Ԫ�ز����ڣ��򷵻�ֵΪ0 */
int LocateElem(SqList L,ElemType e)
{
    int i;
    if (L.length==0)
            return 0;
    for(i=0;i<L.length;i++)
    {
            if (L.data[i]==e)
                    break;
    }
    if(i>=L.length)
            return 0;
 
    return i+1;
}
 
 
/* ��ʼ������˳�����Ա�L�Ѵ���,1��i��ListLength(L)�� */
/* �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 */
Status ListInsert(SqList *L,int i,ElemType e)
{ 
	int k;
	if (L->length==MAXSIZE)  /* ˳�����Ա��Ѿ��� */
		return ERROR;
	if (i<1 || i>L->length+1)/* ��i�ȵ�һλ��С���߱����һλ�ú�һλ�û�Ҫ��ʱ */
		return ERROR;
 
	if (i<=L->length)        /* ����������λ�ò��ڱ�β */
	{
		for(k=L->length-1;k>=i-1;k--)  /* ��Ҫ����λ��֮�������Ԫ������ƶ�һλ */
			L->data[k+1]=L->data[k];
	}
	L->data[i-1]=e;          /* ����Ԫ�ز��� */
	L->length++;
 
	return OK;
}
 
/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1 */
Status ListDelete(SqList *L,int i,ElemType *e) 
{ 
    int k;
    if (L->length==0)               /* ���Ա�Ϊ�� */
		return ERROR;
    if (i<1 || i>L->length)         /* ɾ��λ�ò���ȷ */
        return ERROR;
    *e=L->data[i-1];
    if (i<L->length)                /* ���ɾ���������λ�� */
    {
        for(k=i;k<L->length;k++)/* ��ɾ��λ�ú��Ԫ��ǰ�� */
			L->data[k-1]=L->data[k];
    }
    L->length--;
    return OK;
}
 
/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* ������������ζ�L��ÿ������Ԫ����� */
Status ListTraverse(SqList L)
{
	int i;
    for(i=0;i<L.length;i++)
            visit(L.data[i]);
    printf("\n");
    return OK;
}

/* ��Lb�ϲ���La */
void unionL(SqList *La,SqList Lb)
{
	int La_len,Lb_len,i;
	ElemType e;
	La_len=ListLength(*La);
	Lb_len=ListLength(Lb);
	for (i=1;i<=Lb_len;i++)
	{
		GetElem(Lb,i,&e);
		if (!LocateElem(*La,e))
			ListInsert(La,++La_len,e);
	}
}
 
int main()
{
        
    SqList L;
	SqList Lb;
    
    ElemType e;
    Status i;
    int j,k;
    i=InitList(&L);
    printf("��ʼ��L��L.length=%d\n",L.length);
    for(j=1;j<=5;j++)
            i=ListInsert(&L,1,j);
    printf("��L�ı�ͷ���β���1��5��L.data=");
    ListTraverse(L); 
 
    printf("L.length=%d \n",L.length);
    i=ListEmpty(L);
    printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n",i);
 
    i=ClearList(&L);
    printf("���L��L.length=%d\n",L.length);
    i=ListEmpty(L);
    printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n",i);
 
    for(j=1;j<=10;j++)
            ListInsert(&L,j,j);
    printf("��L�ı�β���β���1��10��L.data=");
    ListTraverse(L); 
 
    printf("L.length=%d \n",L.length);
 
    ListInsert(&L,1,0);
    printf("��L�ı�ͷ����0��L.data=");
    ListTraverse(L); 
    printf("L.length=%d \n",L.length);
 
    GetElem(L,5,&e);
    printf("��5��Ԫ�ص�ֵΪ��%d\n",e);
    for(j=3;j<=4;j++)
    {
            k=LocateElem(L,j);
            if(k)
                    printf("��%d��Ԫ�ص�ֵΪ%d\n",k,j);
            else
                    printf("û��ֵΪ%d��Ԫ��\n",j);
    }
    
 
    k=ListLength(L); /* kΪ�� */
    for(j=k+1;j>=k;j--)
    {
            i=ListDelete(&L,j,&e); /* ɾ����j������ */
            if(i==ERROR)
                    printf("ɾ����%d������ʧ��\n",j);
            else
                    printf("ɾ����%d����Ԫ��ֵΪ��%d\n",j,e);
    }
    printf("�������L��Ԫ�أ�");
    ListTraverse(L); 
 
    j=5;
    ListDelete(&L,j,&e); /* ɾ����5������ */
    printf("ɾ����%d����Ԫ��ֵΪ��%d\n",j,e);
 
    printf("�������L��Ԫ�أ�");
    ListTraverse(L); 
 
	//����һ����10������Lb
	i=InitList(&Lb);
    for(j=6;j<=15;j++)
            i=ListInsert(&Lb,1,j);
 
	unionL(&L,Lb);
 
	printf("��������ϲ���Lb��L��Ԫ�أ�");
    ListTraverse(L); 
 
    return 0;
}

//02���Ա���ʽ�洢_LinkList
#include "stdio.h"    
#include "string.h"
#include "ctype.h"      
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* �洢�ռ��ʼ������ */
 
typedef int Status;/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;/* ElemType���͸���ʵ������������������Ϊint */
 
 
Status visit(ElemType c)
{
    printf("%d ",c);
    return OK;
}
 
typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *LinkList; /* ����LinkList */
 
/* ��ʼ��˳�����Ա� */
Status InitList(LinkList *L) 
{ 
    *L=(LinkList)malloc(sizeof(Node)); /* ����ͷ���,��ʹLָ���ͷ��� */
    if(!(*L)) /* �洢����ʧ�� */
            return ERROR;
    (*L)->next=NULL; /* ָ����Ϊ�� */
 
    return OK;
}
 
/* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
Status ListEmpty(LinkList L)
{ 
    if(L->next)
            return FALSE;
    else
            return TRUE;
}
 
/* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������L����Ϊ�ձ� */
Status ClearList(LinkList *L)
{ 
	LinkList p,q;
	p=(*L)->next;           /*  pָ���һ����� */
	while(p)                /*  û����β */
	{
		q=p->next;
		free(p);
		p=q;
	}
	(*L)->next=NULL;        /* ͷ���ָ����Ϊ�� */
	return OK;
}
 
/* ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
int ListLength(LinkList L)
{
    int i=0;
    LinkList p=L->next; /* pָ���һ����� */
    while(p)                        
    {
        i++;
        p=p->next;
    }
    return i;
}
 
/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* �����������e����L�е�i������Ԫ�ص�ֵ */
Status GetElem(LinkList L,int i,ElemType *e)
{
	int j;
	LinkList p;		/* ����һ���p */
	p = L->next;		/* ��pָ������L�ĵ�һ����� */
	j = 1;		/*  jΪ������ */
	while (p && j<i)  /* p��Ϊ�ջ��߼�����j��û�е���iʱ��ѭ������ */
	{   
		p = p->next;  /* ��pָ����һ����� */
		++j;
	}
	if ( !p || j>i ) 
		return ERROR;  /*  ��i��Ԫ�ز����� */
	*e = p->data;   /*  ȡ��i��Ԫ�ص����� */
	return OK;
}
 
/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* �������������L�е�1����e�����ϵ������Ԫ�ص�λ�� */
/* ������������Ԫ�ز����ڣ��򷵻�ֵΪ0 */
int LocateElem(LinkList L,ElemType e)
{
    int i=0;
    LinkList p=L->next;
    while(p)
    {
        i++;
        if(p->data==e) /* �ҵ�����������Ԫ�� */
                return i;
        p=p->next;
    }
 
    return 0;
}
 
 
/* ��ʼ������˳�����Ա�L�Ѵ���,1��i��ListLength(L)�� */
/* �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 */
Status ListInsert(LinkList *L,int i,ElemType e)
{ 
	int j;
	LinkList p,s;
	p = *L;   
	j = 1;
	while (p && j < i)     /* Ѱ�ҵ�i����� */
	{
		p = p->next;
		++j;
	} 
	if (!p || j > i) 
		return ERROR;   /* ��i��Ԫ�ز����� */
	s = (LinkList)malloc(sizeof(Node));  /*  �����½��(C���Ա�׼����) */
	s->data = e;  
	s->next = p->next;      /* ��p�ĺ�̽�㸳ֵ��s�ĺ��  */
	p->next = s;          /* ��s��ֵ��p�ĺ�� */
	return OK;
}
 
/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1 */
Status ListDelete(LinkList *L,int i,ElemType *e) 
{ 
	int j;
	LinkList p,q;
	p = *L;
	j = 1;
	while (p->next && j < i)	/* ����Ѱ�ҵ�i��Ԫ�� */
	{
        p = p->next;
        ++j;
	}
	if (!(p->next) || j > i) 
	    return ERROR;           /* ��i��Ԫ�ز����� */
	q = p->next;
	p->next = q->next;			/* ��q�ĺ�̸�ֵ��p�ĺ�� */
	*e = q->data;               /* ��q����е����ݸ�e */
	free(q);                    /* ��ϵͳ���մ˽�㣬�ͷ��ڴ� */
	return OK;
}
 
/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* ������������ζ�L��ÿ������Ԫ����� */
Status ListTraverse(LinkList L)
{
    LinkList p=L->next;
    while(p)
    {
        visit(p->data);
        p=p->next;
    }
    printf("\n");
    return OK;
}
 
/*  �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��ͷ�巨�� */
void CreateListHead(LinkList *L, int n) 
{
	LinkList p;
	int i;
	srand(time(0));                         /* ��ʼ����������� */
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;                      /*  �Ƚ���һ����ͷ���ĵ����� */
	for (i=0; i<n; i++) 
	{
		p = (LinkList)malloc(sizeof(Node)); /*  �����½�� */
		p->data = rand()%100+1;             /*  �������100���ڵ����� */
		p->next = (*L)->next;    
		(*L)->next = p;						/*  ���뵽��ͷ */
	}
}
 
/*  �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��β�巨�� */
void CreateListTail(LinkList *L, int n) 
{
	LinkList p,r;
	int i;
	srand(time(0));                      /* ��ʼ����������� */
	*L = (LinkList)malloc(sizeof(Node)); /* LΪ�������Ա� */
	r=*L;                                /* rΪָ��β���Ľ�� */
	for (i=0; i<n; i++) 
	{
		p = (Node *)malloc(sizeof(Node)); /*  �����½�� */
		p->data = rand()%100+1;           /*  �������100���ڵ����� */
		r->next=p;                        /* ����β�ն˽���ָ��ָ���½�� */
		r = p;                            /* ����ǰ���½�㶨��Ϊ��β�ն˽�� */
	}
	r->next = NULL;                       /* ��ʾ��ǰ������� */
}
 
int main()
{        
    LinkList L;
    ElemType e;
    Status i;
    int j,k;
    i=InitList(&L);
    printf("��ʼ��L��ListLength(L)=%d\n",ListLength(L));
    for(j=1;j<=5;j++)
            i=ListInsert(&L,1,j);
    printf("��L�ı�ͷ���β���1��5��L.data=");
    ListTraverse(L); 
 
    printf("ListLength(L)=%d \n",ListLength(L));
    i=ListEmpty(L);
    printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n",i);
 
    i=ClearList(&L);
    printf("���L��ListLength(L)=%d\n",ListLength(L));
    i=ListEmpty(L);
    printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n",i);
 
    for(j=1;j<=10;j++)
            ListInsert(&L,j,j);
    printf("��L�ı�β���β���1��10��L.data=");
    ListTraverse(L); 
 
    printf("ListLength(L)=%d \n",ListLength(L));
 
    ListInsert(&L,1,0);
    printf("��L�ı�ͷ����0��L.data=");
    ListTraverse(L); 
    printf("ListLength(L)=%d \n",ListLength(L));
 
    GetElem(L,5,&e);
    printf("��5��Ԫ�ص�ֵΪ��%d\n",e);
    for(j=3;j<=4;j++)
    {
            k=LocateElem(L,j);
            if(k)
                    printf("��%d��Ԫ�ص�ֵΪ%d\n",k,j);
            else
                    printf("û��ֵΪ%d��Ԫ��\n",j);
    }
    
 
    k=ListLength(L); /* kΪ�� */
    for(j=k+1;j>=k;j--)
    {
            i=ListDelete(&L,j,&e); /* ɾ����j������ */
            if(i==ERROR)
                    printf("ɾ����%d������ʧ��\n",j);
            else
                    printf("ɾ����%d����Ԫ��ֵΪ��%d\n",j,e);
    }
    printf("�������L��Ԫ�أ�");
    ListTraverse(L); 
 
    j=5;
    ListDelete(&L,j,&e); /* ɾ����5������ */
    printf("ɾ����%d����Ԫ��ֵΪ��%d\n",j,e);
 
    printf("�������L��Ԫ�أ�");
    ListTraverse(L); 
 
    i=ClearList(&L);
    printf("\n���L��ListLength(L)=%d\n",ListLength(L));
    CreateListHead(&L,20);
    printf("���崴��L��Ԫ��(ͷ�巨)��");
    ListTraverse(L); 
    
    i=ClearList(&L);
    printf("\nɾ��L��ListLength(L)=%d\n",ListLength(L));
    CreateListTail(&L,20);
    printf("���崴��L��Ԫ��(β�巨)��");
    ListTraverse(L); 
 
 
    return 0;
}
 
//03��̬����_StaticLinkList
#include "string.h"
#include "ctype.h"      
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"
 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 1000 /* �洢�ռ��ʼ������ */
 
typedef int Status;           /* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef char ElemType;        /* ElemType���͸���ʵ������������������Ϊchar */
 
Status visit(ElemType c)
{
    printf("%c ",c);
    return OK;
}
 
/* ���Ա�ľ�̬����洢�ṹ */
typedef struct 
{
    ElemType data;
    int cur;  /* �α�(Cursor) ��Ϊ0ʱ��ʾ��ָ�� */
} Component,StaticLinkList[MAXSIZE];
 
 
/* ��һά����space�и���������һ����������space[0].curΪͷָ�룬"0"��ʾ��ָ�� */
Status InitList(StaticLinkList space) 
{
	int i;
	for (i=0; i<MAXSIZE-1; i++)  
		space[i].cur = i+1;
	space[MAXSIZE-1].cur = 0; /* Ŀǰ��̬����Ϊ�գ����һ��Ԫ�ص�curΪ0 */
	return OK;
}
 
 
/* �����ÿռ�����ǿգ��򷵻ط���Ľ���±꣬���򷵻�0 */
int Malloc_SSL(StaticLinkList space) 
{ 
	int i = space[0].cur;           		/* ��ǰ�����һ��Ԫ�ص�cur���ֵ */
	                                		/* ����Ҫ���صĵ�һ�����ÿ��е��±� */
	if (space[0]. cur)         
	    space[0]. cur = space[i].cur;       /* ����Ҫ�ó�һ��������ʹ���ˣ� */
	                                        /* �������Ǿ͵ð�������һ�� */
	                                        /* �������������� */
	return i;
}
 
 
/*  ���±�Ϊk�Ŀ��н����յ��������� */
void Free_SSL(StaticLinkList space, int k) 
{  
    space[k].cur = space[0].cur;    /* �ѵ�һ��Ԫ�ص�curֵ����Ҫɾ���ķ���cur */
    space[0].cur = k;               /* ��Ҫɾ���ķ����±긳ֵ����һ��Ԫ�ص�cur */
}
 
/* ��ʼ��������̬����L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
int ListLength(StaticLinkList L)
{
    int j=0;
    int i=L[MAXSIZE-1].cur;
    while(i)
    {
        i=L[i].cur;
        j++;
    }
    return j;
}
 
/*  ��L�е�i��Ԫ��֮ǰ�����µ�����Ԫ��e   */
Status ListInsert(StaticLinkList L, int i, ElemType e)   
{  
    int j, k, l;   
    k = MAXSIZE - 1;   /* ע��k���������һ��Ԫ�ص��±� */
    if (i < 1 || i > ListLength(L) + 1)   
        return ERROR;   
    j = Malloc_SSL(L);   /* ��ÿ��з������±� */
    if (j)   
    {   
		L[j].data = e;   /* �����ݸ�ֵ���˷�����data */
		for(l = 1; l <= i - 1; l++)   /* �ҵ���i��Ԫ��֮ǰ��λ�� */
		   k = L[k].cur;           
		L[j].cur = L[k].cur;    /* �ѵ�i��Ԫ��֮ǰ��cur��ֵ����Ԫ�ص�cur */
		L[k].cur = j;           /* ����Ԫ�ص��±긳ֵ����i��Ԫ��֮ǰԪ�ص�ur */
		return OK;   
    }   
    return ERROR;   
}
 
/*  ɾ����L�е�i������Ԫ��   */
Status ListDelete(StaticLinkList L, int i)   
{ 
    int j, k;   
    if (i < 1 || i > ListLength(L))   
        return ERROR;   
    k = MAXSIZE - 1;   
    for (j = 1; j <= i - 1; j++)   
        k = L[k].cur;   
    j = L[k].cur;   
    L[k].cur = L[j].cur;   
    Free_SSL(L, j);   
    return OK;   
} 
 
Status ListTraverse(StaticLinkList L)
{
    int j=0;
    int i=L[MAXSIZE-1].cur;
    while(i)
    {
            visit(L[i].data);
            i=L[i].cur;
            j++;
    }
    return j;
    printf("\n");
    return OK;
}
 
 
int main()
{
    StaticLinkList L;
    Status i;
    i=InitList(L);
    printf("��ʼ��L��L.length=%d\n",ListLength(L));
 
    i=ListInsert(L,1,'F');
    i=ListInsert(L,1,'E');
    i=ListInsert(L,1,'D');
    i=ListInsert(L,1,'B');
    i=ListInsert(L,1,'A');
 
    printf("\n��L�ı�ͷ���β���FEDBA��\nL.data=");
    ListTraverse(L); 
 
    i=ListInsert(L,3,'C');
    printf("\n��L�ġ�B���롰D��֮����롰C����\nL.data=");
    ListTraverse(L); 
 
    i=ListDelete(L,1);
    printf("\n��L��ɾ����A����\nL.data=");
    ListTraverse(L); 
 
    printf("\n");
 
    return 0;
}
 
��4�¡�ջ�����
//01˳��ջ_Stack
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"
 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* �洢�ռ��ʼ������ */
 
typedef int Status; 
typedef int SElemType; /* SElemType���͸���ʵ������������������Ϊint */
 
/* ˳��ջ�ṹ */
typedef struct
{
        SElemType data[MAXSIZE];
        int top; /* ����ջ��ָ�� */
}SqStack;
 
Status visit(SElemType c)
{
        printf("%d ",c);
        return OK;
}
 
/*  ����һ����ջS */
Status InitStack(SqStack *S)
{ 
        /* S.data=(SElemType *)malloc(MAXSIZE*sizeof(SElemType)); */
        S->top=-1;
        return OK;
}
 
/* ��S��Ϊ��ջ */
Status ClearStack(SqStack *S)
{ 
        S->top=-1;
        return OK;
}
 
/* ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE */
Status StackEmpty(SqStack S)
{ 
        if (S.top==-1)
                return TRUE;
        else
                return FALSE;
}
 
/* ����S��Ԫ�ظ�������ջ�ĳ��� */
int StackLength(SqStack S)
{ 
        return S.top+1;
}
 
/* ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR */
Status GetTop(SqStack S,SElemType *e)
{
        if (S.top==-1)
                return ERROR;
        else
                *e=S.data[S.top];
        return OK;
}
 
/* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
Status Push(SqStack *S,SElemType e)
{
        if(S->top == MAXSIZE -1) /* ջ�� */
        {
                return ERROR;
        }
        S->top++;				/* ջ��ָ������һ */
        S->data[S->top]=e;  /* ���²���Ԫ�ظ�ֵ��ջ���ռ� */
        return OK;
}
 
/* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
Status Pop(SqStack *S,SElemType *e)
{ 
        if(S->top==-1)
                return ERROR;
        *e=S->data[S->top];	/* ��Ҫɾ����ջ��Ԫ�ظ�ֵ��e */
        S->top--;				/* ջ��ָ���һ */
        return OK;
}
 
/* ��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ����ʾ */
Status StackTraverse(SqStack S)
{
        int i;
        i=0;
        while(i<=S.top)
        {
                visit(S.data[i++]);
        }
        printf("\n");
        return OK;
}
 
int main()
{
        int j;
        SqStack s;
        int e;
        if(InitStack(&s)==OK)
                for(j=1;j<=10;j++)
                        Push(&s,j);
        printf("ջ��Ԫ������Ϊ��");
        StackTraverse(s);
        Pop(&s,&e);
        printf("������ջ��Ԫ�� e=%d\n",e);
        printf("ջ�շ�%d(1:�� 0:��)\n",StackEmpty(s));
        GetTop(s,&e);
        printf("ջ��Ԫ�� e=%d ջ�ĳ���Ϊ%d\n",e,StackLength(s));
        ClearStack(&s);
        printf("���ջ��ջ�շ�%d(1:�� 0:��)\n",StackEmpty(s));
        
        return 0;
}
 
//02��ջ����ռ�_DoubleStack
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"
 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* �洢�ռ��ʼ������ */
 
typedef int Status; 
 
typedef int SElemType; /* SElemType���͸���ʵ������������������Ϊint */
 
 
/* ��ջ����ռ�ṹ */
typedef struct 
{
        SElemType data[MAXSIZE];
        int top1;	/* ջ1ջ��ָ�� */
        int top2;	/* ջ2ջ��ָ�� */
}SqDoubleStack;
 
 
Status visit(SElemType c)
{
        printf("%d ",c);
        return OK;
}
 
/*  ����һ����ջS */
Status InitStack(SqDoubleStack *S)
{ 
        S->top1=-1;
        S->top2=MAXSIZE;
        return OK;
}
 
/* ��S��Ϊ��ջ */
Status ClearStack(SqDoubleStack *S)
{ 
        S->top1=-1;
        S->top2=MAXSIZE;
        return OK;
}
 
/* ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE */
Status StackEmpty(SqDoubleStack S)
{ 
        if (S.top1==-1 && S.top2==MAXSIZE)
                return TRUE;
        else
                return FALSE;
}
 
/* ����S��Ԫ�ظ�������ջ�ĳ��� */
int StackLength(SqDoubleStack S)
{ 
        return (S.top1+1)+(MAXSIZE-S.top2);
}
 
/* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
Status Push(SqDoubleStack *S,SElemType e,int stackNumber)
{
        if (S->top1+1==S->top2)	/* ջ������������push��Ԫ���� */
                return ERROR;	
        if (stackNumber==1)			/* ջ1��Ԫ�ؽ�ջ */
                S->data[++S->top1]=e; /* ����ջ1����top1+1�������Ԫ�ظ�ֵ�� */
        else if (stackNumber==2)	/* ջ2��Ԫ�ؽ�ջ */
                S->data[--S->top2]=e; /* ����ջ2����top2-1�������Ԫ�ظ�ֵ�� */
        return OK;
}
 
/* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
Status Pop(SqDoubleStack *S,SElemType *e,int stackNumber)
{ 
        if (stackNumber==1) 
        {
                if (S->top1==-1) 
                        return ERROR; /* ˵��ջ1�Ѿ��ǿ�ջ����� */
                *e=S->data[S->top1--]; /* ��ջ1��ջ��Ԫ�س�ջ */
        }
        else if (stackNumber==2)
        { 
                if (S->top2==MAXSIZE) 
                        return ERROR; /* ˵��ջ2�Ѿ��ǿ�ջ����� */
                *e=S->data[S->top2++]; /* ��ջ2��ջ��Ԫ�س�ջ */
        }
        return OK;
}
 
Status StackTraverse(SqDoubleStack S)
{
        int i;
        i=0;
        while(i<=S.top1)
        {
                visit(S.data[i++]);
        }
        i=S.top2;
        while(i<MAXSIZE)
        {
                visit(S.data[i++]);
        }
        printf("\n");
        return OK;
}
 
int main()
{
        int j;
        SqDoubleStack s;
        int e;
        if(InitStack(&s)==OK)
        {
                for(j=1;j<=5;j++)
                        Push(&s,j,1);
                for(j=MAXSIZE;j>=MAXSIZE-2;j--)
                        Push(&s,j,2);
        }
 
        printf("ջ��Ԫ������Ϊ��");
        StackTraverse(s);
 
        printf("��ǰջ��Ԫ���У�%d \n",StackLength(s));
 
        Pop(&s,&e,2);
        printf("������ջ��Ԫ�� e=%d\n",e);
        printf("ջ�շ�%d(1:�� 0:��)\n",StackEmpty(s));
 
        for(j=6;j<=MAXSIZE-2;j++)
                Push(&s,j,1);
 
        printf("ջ��Ԫ������Ϊ��");
        StackTraverse(s);
 
        printf("ջ����%d(1:�� 0:��)\n",Push(&s,100,1));
 
        
        ClearStack(&s);
        printf("���ջ��ջ�շ�%d(1:�� 0:��)\n",StackEmpty(s));
        
        return 0;
}
//03��ջ_LinkStack
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"
 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* �洢�ռ��ʼ������ */
 
typedef int Status; 
typedef int SElemType; /* SElemType���͸���ʵ������������������Ϊint */
 
 
/* ��ջ�ṹ */
typedef struct StackNode
{
        SElemType data;
        struct StackNode *next;
}StackNode,*LinkStackPtr;
 
 
typedef struct
{
        LinkStackPtr top;
        int count;
}LinkStack;
 
Status visit(SElemType c)
{
        printf("%d ",c);
        return OK;
}
 
/*  ����һ����ջS */
Status InitStack(LinkStack *S)
{ 
        S->top = (LinkStackPtr)malloc(sizeof(StackNode));
        if(!S->top)
                return ERROR;
        S->top=NULL;
        S->count=0;
        return OK;
}
 
/* ��S��Ϊ��ջ */
Status ClearStack(LinkStack *S)
{ 
        LinkStackPtr p,q;
        p=S->top;
        while(p)
        {  
                q=p;
                p=p->next;
                free(q);
        } 
        S->count=0;
        return OK;
}
 
/* ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE */
Status StackEmpty(LinkStack S)
{ 
        if (S.count==0)
                return TRUE;
        else
                return FALSE;
}
 
/* ����S��Ԫ�ظ�������ջ�ĳ��� */
int StackLength(LinkStack S)
{ 
        return S.count;
}
 
/* ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR */
Status GetTop(LinkStack S,SElemType *e)
{
        if (S.top==NULL)
                return ERROR;
        else
                *e=S.top->data;
        return OK;
}
 
/* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
Status Push(LinkStack *S,SElemType e)
{
        LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode)); 
        s->data=e; 
        s->next=S->top;	/* �ѵ�ǰ��ջ��Ԫ�ظ�ֵ���½���ֱ�Ӻ�̣���ͼ�Т� */
        S->top=s;         /* ���µĽ��s��ֵ��ջ��ָ�룬��ͼ�Т� */
        S->count++;
        return OK;
}
 
/* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
Status Pop(LinkStack *S,SElemType *e)
{ 
        LinkStackPtr p;
        if(StackEmpty(*S))
                return ERROR;
        *e=S->top->data;
        p=S->top;					/* ��ջ����㸳ֵ��p����ͼ�Т� */
        S->top=S->top->next;    /* ʹ��ջ��ָ������һλ��ָ���һ��㣬��ͼ�Т� */
        free(p);                    /* �ͷŽ��p */        
        S->count--;
        return OK;
}
 
Status StackTraverse(LinkStack S)
{
        LinkStackPtr p;
        p=S.top;
        while(p)
        {
                 visit(p->data);
                 p=p->next;
        }
        printf("\n");
        return OK;
}
 
int main()
{
        int j;
        LinkStack s;
        int e;
        if(InitStack(&s)==OK)
                for(j=1;j<=10;j++)
                        Push(&s,j);
        printf("ջ��Ԫ������Ϊ��");
        StackTraverse(s);
        Pop(&s,&e);
        printf("������ջ��Ԫ�� e=%d\n",e);
        printf("ջ�շ�%d(1:�� 0:��)\n",StackEmpty(s));
        GetTop(s,&e);
        printf("ջ��Ԫ�� e=%d ջ�ĳ���Ϊ%d\n",e,StackLength(s));
        ClearStack(&s);
        printf("���ջ��ջ�շ�%d(1:�� 0:��)\n",StackEmpty(s));
        return 0;
}
//04쳲���������_Fibonacci
#include "stdio.h"
 
int Fbi(int i)  /* 쳲������ĵݹ麯�� */
{
	if( i < 2 )
		return i == 0 ? 0 : 1;  
    return Fbi(i - 1) + Fbi(i - 2);  /* ����Fbi���Ǻ����Լ��������ڵ����Լ� */
}  
 
int main()
{
	int i;
	int a[40];  
	printf("������ʾ쳲��������У�\n");
	a[0]=0;
	a[1]=1;
	printf("%d ",a[0]);  
	printf("%d ",a[1]);  
	for(i = 2;i < 40;i++)  
	{ 
		a[i] = a[i-1] + a[i-2];  
		printf("%d ",a[i]);  
	} 
	printf("\n");
	
	printf("�ݹ���ʾ쳲��������У�\n");
	for(i = 0;i < 40;i++)  
		printf("%d ", Fbi(i));  
    return 0;
}
 
//05˳�����_Queue
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"
 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* �洢�ռ��ʼ������ */
 
typedef int Status; 
typedef int QElemType; /* QElemType���͸���ʵ������������������Ϊint */
 
/* ѭ�����е�˳��洢�ṹ */
typedef struct
{
	QElemType data[MAXSIZE];
	int front;    	/* ͷָ�� */
	int rear;		/* βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ�� */
}SqQueue;
 
Status visit(QElemType c)
{
	printf("%d ",c);
	return OK;
}
 
/* ��ʼ��һ���ն���Q */
Status InitQueue(SqQueue *Q)
{
	Q->front=0;
	Q->rear=0;
	return  OK;
}
 
/* ��Q��Ϊ�ն��� */
Status ClearQueue(SqQueue *Q)
{
	Q->front=Q->rear=0;
	return OK;
}
 
/* ������QΪ�ն���,�򷵻�TRUE,���򷵻�FALSE */
Status QueueEmpty(SqQueue Q)
{ 
	if(Q.front==Q.rear) /* ���пյı�־ */
		return TRUE;
	else
		return FALSE;
}
 
/* ����Q��Ԫ�ظ�����Ҳ���Ƕ��еĵ�ǰ���� */
int QueueLength(SqQueue Q)
{
	return  (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}
 
/* �����в���,����e����Q�Ķ�ͷԪ��,������OK,���򷵻�ERROR */
Status GetHead(SqQueue Q,QElemType *e)
{
	if(Q.front==Q.rear) /* ���п� */
		return ERROR;
	*e=Q.data[Q.front];
	return OK;
}
 
/* ������δ���������Ԫ��eΪQ�µĶ�βԪ�� */
Status EnQueue(SqQueue *Q,QElemType e)
{
	if ((Q->rear+1)%MAXSIZE == Q->front)	/* ���������ж� */
		return ERROR;
	Q->data[Q->rear]=e;			/* ��Ԫ��e��ֵ����β */
	Q->rear=(Q->rear+1)%MAXSIZE;/* rearָ�������һλ�ã� */
								/* ���������ת������ͷ�� */
	return  OK;
}
 
/* �����в��գ���ɾ��Q�ж�ͷԪ�أ���e������ֵ */
Status DeQueue(SqQueue *Q,QElemType *e)
{
	if (Q->front == Q->rear)			/* ���пյ��ж� */
		return ERROR;
	*e=Q->data[Q->front];				/* ����ͷԪ�ظ�ֵ��e */
	Q->front=(Q->front+1)%MAXSIZE;	/* frontָ�������һλ�ã� */
									/* ���������ת������ͷ�� */
	return  OK;
}
 
/* �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ����� */
Status QueueTraverse(SqQueue Q)
{ 
	int i;
	i=Q.front;
	while((i+Q.front)!=Q.rear)
	{
		visit(Q.data[i]);
		i=(i+1)%MAXSIZE;
	}
	printf("\n");
	return OK;
}
 
int main()
{
	Status j;
	int i=0,l;
	QElemType d;
	SqQueue Q;
	InitQueue(&Q);
	printf("��ʼ�����к󣬶��пշ�%u(1:�� 0:��)\n",QueueEmpty(Q));
 
	printf("���������Ͷ���Ԫ��(������%d��),-1Ϊ��ǰ������: ",MAXSIZE-1);
	do
	{
		/* scanf("%d",&d); */
		d=i+100;
		if(d==-1)
			break;
		i++;
		EnQueue(&Q,d);
	}while(i<MAXSIZE-1);
 
	printf("���г���Ϊ: %d\n",QueueLength(Q));
	printf("���ڶ��пշ�%u(1:�� 0:��)\n",QueueEmpty(Q));
	printf("����%d���ɶ�ͷɾ��Ԫ��,��β����Ԫ��:\n",MAXSIZE);
	for(l=1;l<=MAXSIZE;l++)
	{
		DeQueue(&Q,&d);
		printf("ɾ����Ԫ����%d,�����Ԫ��:%d \n",d,l+1000);
		/* scanf("%d",&d); */
		d=l+1000;
		EnQueue(&Q,d);
	}
	l=QueueLength(Q);
 
	printf("���ڶ����е�Ԫ��Ϊ: \n");
	QueueTraverse(Q);
	printf("�����β������%d��Ԫ��\n",i+MAXSIZE);
	if(l-2>0)
		printf("�����ɶ�ͷɾ��%d��Ԫ��:\n",l-2);
	while(QueueLength(Q)>2)
	{
		DeQueue(&Q,&d);
		printf("ɾ����Ԫ��ֵΪ%d\n",d);
	}
 
	j=GetHead(Q,&d);
	if(j)
		printf("���ڶ�ͷԪ��Ϊ: %d\n",d);
	ClearQueue(&Q);
	printf("��ն��к�, ���пշ�%u(1:�� 0:��)\n",QueueEmpty(Q));
	return 0;
}
 
//06������_LinkQueue
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"
 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* �洢�ռ��ʼ������ */
 
typedef int Status; 
 
typedef int QElemType; /* QElemType���͸���ʵ������������������Ϊint */
 
typedef struct QNode	/* ���ṹ */
{
   QElemType data;
   struct QNode *next;
}QNode,*QueuePtr;
 
typedef struct			/* ���е�����ṹ */
{
   QueuePtr front,rear; /* ��ͷ����βָ�� */
}LinkQueue;
 
Status visit(QElemType c)
{
	printf("%d ",c);
	return OK;
}
 
/* ����һ���ն���Q */
Status InitQueue(LinkQueue *Q)
{ 
	Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q->front)
		exit(OVERFLOW);
	Q->front->next=NULL;
	return OK;
}
 
/* ���ٶ���Q */
Status DestroyQueue(LinkQueue *Q)
{
	while(Q->front)
	{
		 Q->rear=Q->front->next;
		 free(Q->front);
		 Q->front=Q->rear;
	}
	return OK;
}
 
/* ��Q��Ϊ�ն��� */
Status ClearQueue(LinkQueue *Q)
{
	QueuePtr p,q;
	Q->rear=Q->front;
	p=Q->front->next;
	Q->front->next=NULL;
	while(p)
	{
		 q=p;
		 p=p->next;
		 free(q);
	}
	return OK;
}
 
/* ��QΪ�ն���,�򷵻�TRUE,���򷵻�FALSE */
Status QueueEmpty(LinkQueue Q)
{ 
	if(Q.front==Q.rear)
		return TRUE;
	else
		return FALSE;
}
 
/* ����еĳ��� */
int QueueLength(LinkQueue Q)
{ 
	int i=0;
	QueuePtr p;
	p=Q.front;
	while(Q.rear!=p)
	{
		 i++;
		 p=p->next;
	}
	return i;
}
 
/* �����в���,����e����Q�Ķ�ͷԪ��,������OK,���򷵻�ERROR */
Status GetHead(LinkQueue Q,QElemType *e)
{ 
	QueuePtr p;
	if(Q.front==Q.rear)
		return ERROR;
	p=Q.front->next;
	*e=p->data;
	return OK;
}
 
 
/* ����Ԫ��eΪQ���µĶ�βԪ�� */
Status EnQueue(LinkQueue *Q,QElemType e)
{ 
	QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
	if(!s) /* �洢����ʧ�� */
		exit(OVERFLOW);
	s->data=e;
	s->next=NULL;
	Q->rear->next=s;	/* ��ӵ��Ԫ��e���½��s��ֵ��ԭ��β���ĺ�̣���ͼ�Т� */
	Q->rear=s;		/* �ѵ�ǰ��s����Ϊ��β��㣬rearָ��s����ͼ�Т� */
	return OK;
}
 
/* �����в���,ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������OK,���򷵻�ERROR */
Status DeQueue(LinkQueue *Q,QElemType *e)
{
	QueuePtr p;
	if(Q->front==Q->rear)
		return ERROR;
	p=Q->front->next;		/* ����ɾ���Ķ�ͷ����ݴ��p����ͼ�Т� */
	*e=p->data;				/* ����ɾ���Ķ�ͷ����ֵ��ֵ��e */
	Q->front->next=p->next;/* ��ԭ��ͷ���ĺ��p->next��ֵ��ͷ����̣���ͼ�Т� */
	if(Q->rear==p)		/* ����ͷ���Ƕ�β����ɾ����rearָ��ͷ��㣬��ͼ�Т� */
		Q->rear=Q->front;
	free(p);
	return OK;
}
 
/* �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ����� */
Status QueueTraverse(LinkQueue Q)
{
	QueuePtr p;
	p=Q.front->next;
	while(p)
	{
		 visit(p->data);
		 p=p->next;
	}
	printf("\n");
	return OK;
}
 
int main()
{
	int i;
	QElemType d;
	LinkQueue q;
	i=InitQueue(&q);
	if(i)
		printf("�ɹ��ع�����һ���ն���!\n");
	printf("�Ƿ�ն��У�%d(1:�� 0:��)  ",QueueEmpty(q));
	printf("���еĳ���Ϊ%d\n",QueueLength(q));
	EnQueue(&q,-5);
	EnQueue(&q,5);
	EnQueue(&q,10);
	printf("����3��Ԫ��(-5,5,10)��,���еĳ���Ϊ%d\n",QueueLength(q));
	printf("�Ƿ�ն��У�%d(1:�� 0:��)  ",QueueEmpty(q));
	printf("���е�Ԫ������Ϊ��");
	QueueTraverse(q);
	i=GetHead(q,&d);
	if(i==OK)
	 printf("��ͷԪ���ǣ�%d\n",d);
	DeQueue(&q,&d);
	printf("ɾ���˶�ͷԪ��%d\n",d);
	i=GetHead(q,&d);
	if(i==OK)
		printf("�µĶ�ͷԪ���ǣ�%d\n",d);
	ClearQueue(&q);
	printf("��ն��к�,q.front=%u q.rear=%u q.front->next=%u\n",q.front,q.rear,q.front->next);
	DestroyQueue(&q);
	printf("���ٶ��к�,q.front=%u q.rear=%u\n",q.front, q.rear);
	
	return 0;
}
 
��5�¡���
//01��_String
#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"
 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
 
#define MAXSIZE 40 /* �洢�ռ��ʼ������ */
 
typedef int Status;		/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;	/* ElemType���͸���ʵ������������������Ϊint */
 
typedef char String[MAXSIZE+1]; /*  0�ŵ�Ԫ��Ŵ��ĳ��� */
 
/* ����һ����ֵ����chars�Ĵ�T */
Status StrAssign(String T,char *chars)
{ 
	int i;
	if(strlen(chars)>MAXSIZE)
		return ERROR;
	else
	{
		T[0]=strlen(chars);
		for(i=1;i<=T[0];i++)
			T[i]=*(chars+i-1);
		return OK;
	}
}
 
/* �ɴ�S���Ƶô�T */
Status StrCopy(String T,String S)
{ 
	int i;
	for(i=0;i<=S[0];i++)
		T[i]=S[i];
	return OK;
}
 
/* ��SΪ�մ�,�򷵻�TRUE,���򷵻�FALSE */
Status StrEmpty(String S)
{ 
	if(S[0]==0)
		return TRUE;
	else
		return FALSE;
}
 
/*  ��ʼ����: ��S��T���� */
/*  �������: ��S>T,�򷵻�ֵ>0;��S=T,�򷵻�ֵ=0;��S<T,�򷵻�ֵ<0 */
int StrCompare(String S,String T)
{ 
	int i;
	for(i=1;i<=S[0]&&i<=T[0];++i)
		if(S[i]!=T[i])
			return S[i]-T[i];
	return S[0]-T[0];
}
 
/* ���ش���Ԫ�ظ��� */
int StrLength(String S)
{ 
	return S[0];
}
 
/* ��ʼ����:��S���ڡ��������:��S��Ϊ�մ� */
Status ClearString(String S)
{ 
	S[0]=0;/*  ���Ϊ�� */
	return OK;
}
 
/* ��T����S1��S2���Ӷ��ɵ��´�����δ�ضϣ��򷵻�TRUE������FALSE */
Status Concat(String T,String S1,String S2)
{
	int i;
	if(S1[0]+S2[0]<=MAXSIZE)
	{ /*  δ�ض� */
		for(i=1;i<=S1[0];i++)
			T[i]=S1[i];
		for(i=1;i<=S2[0];i++)
			T[S1[0]+i]=S2[i];
		T[0]=S1[0]+S2[0];
		return TRUE;
	}
	else
	{ /*  �ض�S2 */
		for(i=1;i<=S1[0];i++)
			T[i]=S1[i];
		for(i=1;i<=MAXSIZE-S1[0];i++)
			T[S1[0]+i]=S2[i];
		T[0]=MAXSIZE;
		return FALSE;
	}
}
 
/* ��Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ��� */
Status SubString(String Sub,String S,int pos,int len)
{
	int i;
	if(pos<1||pos>S[0]||len<0||len>S[0]-pos+1)
		return ERROR;
	for(i=1;i<=len;i++)
		Sub[i]=S[pos+i-1];
	Sub[0]=len;
	return OK;
}
 
/* �����Ӵ�T������S�е�pos���ַ�֮���λ�á���������,��������ֵΪ0�� */
/* ����,T�ǿ�,1��pos��StrLength(S)�� */
int Index(String S, String T, int pos) 
{
	int i = pos;	/* i��������S�е�ǰλ���±�ֵ����pos��Ϊ1�����posλ�ÿ�ʼƥ�� */
	int j = 1;				/* j�����Ӵ�T�е�ǰλ���±�ֵ */
	while (i <= S[0] && j <= T[0]) /* ��iС��S�ĳ��Ȳ���jС��T�ĳ���ʱ��ѭ������ */
	{
		if (S[i] == T[j]) 	/* ����ĸ�������� */
      	{
			++i;
         	++j; 
      	} 
      	else 				/* ָ��������¿�ʼƥ�� */
      	{  
         	i = i-j+2;		/* i�˻ص��ϴ�ƥ����λ����һλ */
         	j = 1; 			/* j�˻ص��Ӵ�T����λ */
      	}      
	}
	if (j > T[0]) 
		return i-T[0];
	else 
		return 0;
}
 
 
/*  TΪ�ǿմ���������S�е�pos���ַ�֮�������T��ȵ��Ӵ��� */
/*  �򷵻ص�һ���������Ӵ���S�е�λ�ã����򷵻�0 */
int Index2(String S, String T, int pos) 
{
	int n,m,i;
	String sub;
	if (pos > 0) 
	{
		n = StrLength(S);	/* �õ�����S�ĳ��� */
		m = StrLength(T);	/* �õ��Ӵ�T�ĳ��� */
		i = pos;
		while (i <= n-m+1) 
		{
			SubString (sub, S, i, m);	/* ȡ�����е�i��λ�ó�����T��ȵ��Ӵ���sub */
			if (StrCompare(sub,T) != 0)    /* ������������ */
				++i;
			else 				/* ���������� */
				return i;		/* �򷵻�iֵ */
		}
	}
	return 0;	/* �����Ӵ���T��ȣ�����0 */
}
 
 
/*  ��ʼ����: ��S��T����,1��pos��StrLength(S)+1 */
/*  �������: �ڴ�S�ĵ�pos���ַ�֮ǰ���봮T����ȫ���뷵��TRUE,���ֲ��뷵��FALSE */
Status StrInsert(String S,int pos,String T)
{ 
	int i;
	if(pos<1||pos>S[0]+1)
		return ERROR;
	if(S[0]+T[0]<=MAXSIZE)
	{ /*  ��ȫ���� */
		for(i=S[0];i>=pos;i--)
			S[i+T[0]]=S[i];
		for(i=pos;i<pos+T[0];i++)
			S[i]=T[i-pos+1];
		S[0]=S[0]+T[0];
		return TRUE;
	}
	else
	{ /*  ���ֲ��� */
		for(i=MAXSIZE;i<=pos;i--)
			S[i]=S[i-T[0]];
		for(i=pos;i<pos+T[0];i++)
			S[i]=T[i-pos+1];
		S[0]=MAXSIZE;
		return FALSE;
	}
}
 
/*  ��ʼ����: ��S����,1��pos��StrLength(S)-len+1 */
/*  �������: �Ӵ�S��ɾ����pos���ַ��𳤶�Ϊlen���Ӵ� */
Status StrDelete(String S,int pos,int len)
{ 
	int i;
	if(pos<1||pos>S[0]-len+1||len<0)
		return ERROR;
	for(i=pos+len;i<=S[0];i++)
		S[i-len]=S[i];
	S[0]-=len;
	return OK;
}
 
/*  ��ʼ����: ��S,T��V����,T�Ƿǿմ����˺����봮�Ĵ洢�ṹ�޹أ� */
/*  �������: ��V�滻����S�г��ֵ�������T��ȵĲ��ص����Ӵ� */
Status Replace(String S,String T,String V)
{ 
	int i=1; /*  �Ӵ�S�ĵ�һ���ַ�����Ҵ�T */
	if(StrEmpty(T)) /*  T�ǿմ� */
		return ERROR;
	do
	{
		i=Index(S,T,i); /*  ���iΪ����һ��i֮���ҵ����Ӵ�T��λ�� */
		if(i) /*  ��S�д��ڴ�T */
		{
			StrDelete(S,i,StrLength(T)); /*  ɾ���ô�T */
			StrInsert(S,i,V); /*  ��ԭ��T��λ�ò��봮V */
			i+=StrLength(V); /*  �ڲ���Ĵ�V����������Ҵ�T */
		}
	}while(i);
	return OK;
}
 
/*  ����ַ���T */
void StrPrint(String T)
{ 
	int i;
	for(i=1;i<=T[0];i++)
		printf("%c",T[i]);
	printf("\n");
}
 
 
int main()
{
	
	int i,j;
	Status k;
	char s;
	String t,s1,s2;
	printf("�����봮s1: ");
	
	k=StrAssign(s1,"abcd");
	if(!k)
	{
		printf("��������MAXSIZE(=%d)\n",MAXSIZE);
		exit(0);
	}
	printf("����Ϊ%d ���շ�%d(1:�� 0:��)\n",StrLength(s1),StrEmpty(s1));
	StrCopy(s2,s1);
	printf("����s1���ɵĴ�Ϊ: ");
	StrPrint(s2);
	printf("�����봮s2: ");
	
	k=StrAssign(s2,"efghijk");
	if(!k)
	{
		printf("��������MAXSIZE(%d)\n",MAXSIZE);
		exit(0);
	}
	i=StrCompare(s1,s2);
	if(i<0)
		s='<';
	else if(i==0)
		s='=';
	else
		s='>';
	printf("��s1%c��s2\n",s);
	k=Concat(t,s1,s2);
	printf("��s1���Ӵ�s2�õ��Ĵ�tΪ: ");
	StrPrint(t);
	if(k==FALSE)
		printf("��t�нض�\n");
	ClearString(s1);
	printf("��Ϊ�մ���,��s1Ϊ: ");
	StrPrint(s1);
	printf("����Ϊ%d ���շ�%d(1:�� 0:��)\n",StrLength(s1),StrEmpty(s1));
	printf("��t���Ӵ�,�������Ӵ�����ʼλ��,�Ӵ�����: ");
 
	i=2;
	j=3;
	printf("%d,%d \n",i,j);
 
	k=SubString(s2,t,i,j);
	if(k)
	{
		printf("�Ӵ�s2Ϊ: ");
		StrPrint(s2);
	}
	printf("�Ӵ�t�ĵ�pos���ַ���,ɾ��len���ַ���������pos,len: ");
	
	i=4;
	j=2;
	printf("%d,%d \n",i,j);
 
 
	StrDelete(t,i,j);
	printf("ɾ����Ĵ�tΪ: ");
	StrPrint(t);
	i=StrLength(s2)/2;
	StrInsert(s2,i,t);
	printf("�ڴ�s2�ĵ�%d���ַ�֮ǰ���봮t��,��s2Ϊ:\n",i);
	StrPrint(s2);
	i=Index(s2,t,1);
	printf("s2�ĵ�%d����ĸ���t��һ��ƥ��\n",i);
	SubString(t,s2,1,1);
	printf("��tΪ��");
	StrPrint(t);
	Concat(s1,t,t);
	printf("��s1Ϊ��");
	StrPrint(s1);
	Replace(s2,t,s1);
	printf("�ô�s1ȡ����s2�кʹ�t��ͬ�Ĳ��ص��Ĵ���,��s2Ϊ: ");
	StrPrint(s2);
 
 
	return 0;
}
 
//02ģʽƥ��_KMP
#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"
 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* �洢�ռ��ʼ������ */
 
typedef int Status;		/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;	/* ElemType���͸���ʵ������������������Ϊint */
 
typedef char String[MAXSIZE+1]; /*  0�ŵ�Ԫ��Ŵ��ĳ��� */
 
/* ����һ����ֵ����chars�Ĵ�T */
Status StrAssign(String T,char *chars)
{ 
	int i;
	if(strlen(chars)>MAXSIZE)
		return ERROR;
	else
	{
		T[0]=strlen(chars);
		for(i=1;i<=T[0];i++)
			T[i]=*(chars+i-1);
		return OK;
	}
}
 
Status ClearString(String S)
{ 
	S[0]=0;/*  ���Ϊ�� */
	return OK;
}
 
/*  ����ַ���T�� */
void StrPrint(String T)
{ 
	int i;
	for(i=1;i<=T[0];i++)
		printf("%c",T[i]);
	printf("\n");
}
 
/*  ���Next����ֵ�� */
void NextPrint(int next[],int length)
{ 
	int i;
	for(i=1;i<=length;i++)
		printf("%d",next[i]);
	printf("\n");
}
 
/* ���ش���Ԫ�ظ��� */
int StrLength(String S)
{ 
	return S[0];
}
 
/* ���ص�ģʽƥ�䷨ */
int Index(String S, String T, int pos) 
{
	int i = pos;	/* i��������S�е�ǰλ���±�ֵ����pos��Ϊ1�����posλ�ÿ�ʼƥ�� */
	int j = 1;				/* j�����Ӵ�T�е�ǰλ���±�ֵ */
	while (i <= S[0] && j <= T[0]) /* ��iС��S�ĳ��Ȳ���jС��T�ĳ���ʱ��ѭ������ */
	{
		if (S[i] == T[j]) 	/* ����ĸ�������� */
      	{
			++i;
         	++j; 
      	} 
      	else 				/* ָ��������¿�ʼƥ�� */
      	{  
         	i = i-j+2;		/* i�˻ص��ϴ�ƥ����λ����һλ */
         	j = 1; 			/* j�˻ص��Ӵ�T����λ */
      	}      
	}
	if (j > T[0]) 
		return i-T[0];
	else 
		return 0;
}
 
/* ͨ�����㷵���Ӵ�T��next���顣 */
void get_next(String T, int *next) 
{
	int i,j;
  	i=1;
  	j=0;
  	next[1]=0;
  	while (i<T[0])  /* �˴�T[0]��ʾ��T�ĳ��� */
 	{
    	if(j==0 || T[i]== T[j]) 	/* T[i]��ʾ��׺�ĵ����ַ���T[j]��ʾǰ׺�ĵ����ַ� */
		{
      		++i;  
			++j;  
			next[i] = j;
    	} 
		else 
			j= next[j];	/* ���ַ�����ͬ����jֵ���� */
  	}
}
 
/* �����Ӵ�T������S�е�pos���ַ�֮���λ�á��������ڣ���������ֵΪ0�� */
/*  T�ǿգ�1��pos��StrLength(S)�� */
int Index_KMP(String S, String T, int pos) 
{
	int i = pos;		/* i��������S�е�ǰλ���±�ֵ����pos��Ϊ1�����posλ�ÿ�ʼƥ�� */
	int j = 1;			/* j�����Ӵ�T�е�ǰλ���±�ֵ */
	int next[255];		/* ����һnext���� */
	get_next(T, next);	/* �Դ�T���������õ�next���� */
	while (i <= S[0] && j <= T[0]) /* ��iС��S�ĳ��Ȳ���jС��T�ĳ���ʱ��ѭ������ */
	{
		if (j==0 || S[i] == T[j]) 	/* ����ĸ�����������������㷨������j=0�ж� */
      	{
         	++i;
         	++j; 
      	} 
      	else 			/* ָ��������¿�ʼƥ�� */
      	 	j = next[j];/* j�˻غ��ʵ�λ�ã�iֵ���� */
	}
	if (j > T[0]) 
		return i-T[0];
	else 
		return 0;
}
 
/* ��ģʽ��T��next��������ֵ����������nextval */
void get_nextval(String T, int *nextval) 
{
  	int i,j;
  	i=1;
  	j=0;
  	nextval[1]=0;
  	while (i<T[0])  /* �˴�T[0]��ʾ��T�ĳ��� */
 	{
    	if(j==0 || T[i]== T[j]) 	/* T[i]��ʾ��׺�ĵ����ַ���T[j]��ʾǰ׺�ĵ����ַ� */
		{
      		++i;  
			++j;  
			if (T[i]!=T[j])      /* ����ǰ�ַ���ǰ׺�ַ���ͬ */
				nextval[i] = j;	/* ��ǰ��jΪnextval��iλ�õ�ֵ */
      		else 
				nextval[i] = nextval[j];	/* �����ǰ׺�ַ���ͬ����ǰ׺�ַ��� */
											/* nextvalֵ��ֵ��nextval��iλ�õ�ֵ */
    	} 
		else 
			j= nextval[j];			/* ���ַ�����ͬ����jֵ���� */
  	}
}
 
int Index_KMP1(String S, String T, int pos) 
{
	int i = pos;		/* i��������S�е�ǰλ���±�ֵ����pos��Ϊ1�����posλ�ÿ�ʼƥ�� */
	int j = 1;			/* j�����Ӵ�T�е�ǰλ���±�ֵ */
	int next[255];		/* ����һnext���� */
	get_nextval(T, next);	/* �Դ�T���������õ�next���� */
	while (i <= S[0] && j <= T[0]) /* ��iС��S�ĳ��Ȳ���jС��T�ĳ���ʱ��ѭ������ */
	{
		if (j==0 || S[i] == T[j]) 	/* ����ĸ�����������������㷨������j=0�ж� */
      	{
         	++i;
         	++j; 
      	} 
      	else 			/* ָ��������¿�ʼƥ�� */
      	 	j = next[j];/* j�˻غ��ʵ�λ�ã�iֵ���� */
	}
	if (j > T[0]) 
		return i-T[0];
	else 
		return 0;
}
 
int main()
{
	int i,*p;
	String s1,s2;
	
	StrAssign(s1,"abcdex");
	printf("�Ӵ�Ϊ: ");
	StrPrint(s1);
	i=StrLength(s1);
	p=(int*)malloc((i+1)*sizeof(int));
	get_next(s1,p); 
	printf("NextΪ: ");
	NextPrint(p,StrLength(s1));
	printf("\n");
 
	StrAssign(s1,"abcabx");
	printf("�Ӵ�Ϊ: ");
	StrPrint(s1);
	i=StrLength(s1);
	p=(int*)malloc((i+1)*sizeof(int));
	get_next(s1,p); 
	printf("NextΪ: ");
	NextPrint(p,StrLength(s1));
	printf("\n");
 
	StrAssign(s1,"ababaaaba");
	printf("�Ӵ�Ϊ: ");
	StrPrint(s1);
	i=StrLength(s1);
	p=(int*)malloc((i+1)*sizeof(int));
	get_next(s1,p); 
	printf("NextΪ: ");
	NextPrint(p,StrLength(s1));
	printf("\n");
 
	StrAssign(s1,"aaaaaaaab");
	printf("�Ӵ�Ϊ: ");
	StrPrint(s1);
	i=StrLength(s1);
	p=(int*)malloc((i+1)*sizeof(int));
	get_next(s1,p); 
	printf("NextΪ: ");
	NextPrint(p,StrLength(s1));
	printf("\n");
 
	StrAssign(s1,"ababaaaba");
	printf("   �Ӵ�Ϊ: ");
	StrPrint(s1);
	i=StrLength(s1);
	p=(int*)malloc((i+1)*sizeof(int));
	get_next(s1,p); 
	printf("   NextΪ: ");
	NextPrint(p,StrLength(s1));
	get_nextval(s1,p); 
	printf("NextValΪ: ");
	NextPrint(p,StrLength(s1));
	printf("\n");
 
	StrAssign(s1,"aaaaaaaab");
	printf("   �Ӵ�Ϊ: ");
	StrPrint(s1);
	i=StrLength(s1);
	p=(int*)malloc((i+1)*sizeof(int));
	get_next(s1,p); 
	printf("   NextΪ: ");
	NextPrint(p,StrLength(s1));
	get_nextval(s1,p); 
	printf("NextValΪ: ");
	NextPrint(p,StrLength(s1));
 
	printf("\n");
 
	StrAssign(s1,"00000000000000000000000000000000000000000000000001");
	printf("����Ϊ: ");
	StrPrint(s1);
	StrAssign(s2,"0000000001");
	printf("�Ӵ�Ϊ: ");
	StrPrint(s2);
	printf("\n");
	printf("�������Ӵ��ڵ�%d���ַ����״�ƥ�䣨����ģʽƥ���㷨��\n",Index(s1,s2,1));
	printf("�������Ӵ��ڵ�%d���ַ����״�ƥ�䣨KMP�㷨�� \n",Index_KMP(s1,s2,1));
	printf("�������Ӵ��ڵ�%d���ַ����״�ƥ�䣨KMP�����㷨�� \n",Index_KMP1(s1,s2,1));
 
	return 0;
}
 
��6�¡���
//01������˳��ṹʵ��_BiTreeArray
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"
 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
 
#define MAXSIZE 100 /* �洢�ռ��ʼ������ */
#define MAX_TREE_SIZE 100 /* ��������������� */
 
typedef int Status;		/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int TElemType;  /* �������������ͣ�Ŀǰ�ݶ�Ϊ���� */
typedef TElemType SqBiTree[MAX_TREE_SIZE]; /* 0�ŵ�Ԫ�洢�����  */
 
typedef struct
{
	int level,order; /* ���Ĳ�,�������(��������������) */
}Position;
 
TElemType Nil=0; /*  ��������0Ϊ�� */
 
Status visit(TElemType c)
{
	printf("%d ",c);
	return OK;
}
 
/* ����ն�����T����ΪT�ǹ̶����飬����ı䣬�ʲ���Ҫ& */
Status InitBiTree(SqBiTree T)
{
	int i;
	for(i=0;i<MAX_TREE_SIZE;i++)
		T[i]=Nil; /* ��ֵΪ�� */
	return OK;
}
 
/* �������������������н���ֵ(�ַ��ͻ�����), ����˳��洢�Ķ�����T */
Status CreateBiTree(SqBiTree T)
{ 
	int i=0;
 	printf("�밴�����������ֵ(����)��0��ʾ�ս�㣬��999�������������%d:\n",MAX_TREE_SIZE);
	while(i<10)
	{
		T[i]=i+1;
		
		if(i!=0&&T[(i+1)/2-1]==Nil&&T[i]!=Nil) /* �˽��(����)��˫���Ҳ��Ǹ� */
		{
			printf("������˫�׵ķǸ����%d\n",T[i]);
			exit(ERROR);
		}
		i++;
	}
	while(i<MAX_TREE_SIZE)
	{
		T[i]=Nil; /* ���ո�ֵ��T�ĺ���Ľ�� */
		i++;
	}
 
	return OK;
}
 
#define ClearBiTree InitBiTree /* ��˳��洢�ṹ�У���������ȫһ�� */
 
/* ��ʼ����: ������T���� */
/* �������: ��TΪ�ն�����,�򷵻�TRUE,����FALSE */
Status BiTreeEmpty(SqBiTree T)
{ 
	if(T[0]==Nil) /* �����Ϊ��,������ */
		return TRUE;
	else
		return FALSE;
}
 
/* ��ʼ����: ������T���ڡ��������: ����T����� */
int BiTreeDepth(SqBiTree T)
{ 
   int i,j=-1;
   for(i=MAX_TREE_SIZE-1;i>=0;i--) /* �ҵ����һ����� */
     if(T[i]!=Nil)
       break;
   i++; 
   do
     j++;
   while(i>=powl(2,j));/* ����2��j���ݡ� */
   return j;
}
 
/* ��ʼ����: ������T���� */
/* �������:  ��T����,��e����T�ĸ�,����OK;���򷵻�ERROR,e�޶��� */
Status Root(SqBiTree T,TElemType *e)
{ 
	if(BiTreeEmpty(T)) /* T�� */
		return ERROR;
	else
	{	
		*e=T[0];
		return OK;
	}
}
 
/* ��ʼ����: ������T����,e��T��ĳ�����(��λ��) */
/* �������: ���ش���λ��e(��,�������)�Ľ���ֵ */
TElemType Value(SqBiTree T,Position e)
{ 
	 return T[(int)powl(2,e.level-1)+e.order-2];
}
 
/* ��ʼ����: ������T����,e��T��ĳ�����(��λ��) */
/* �������: ������λ��e(��,�������)�Ľ�㸳��ֵvalue */
Status Assign(SqBiTree T,Position e,TElemType value)
{ 
	int i=(int)powl(2,e.level-1)+e.order-2; /* ���㡢�������תΪ�������� */
	if(value!=Nil&&T[(i+1)/2-1]==Nil) /* ��Ҷ�Ӹ��ǿ�ֵ��˫��Ϊ�� */
		return ERROR;
	else if(value==Nil&&(T[i*2+1]!=Nil||T[i*2+2]!=Nil)) /*  ��˫�׸���ֵ����Ҷ�ӣ����գ� */
		return ERROR;
	T[i]=value;
	return OK;
}
 
/* ��ʼ����: ������T����,e��T��ĳ����� */
/* �������: ��e��T�ķǸ����,�򷵻�����˫��,���򷵻أ��գ� */
TElemType Parent(SqBiTree T,TElemType e)
{ 
	int i;
	if(T[0]==Nil) /* ���� */
		return Nil;
	for(i=1;i<=MAX_TREE_SIZE-1;i++)
		if(T[i]==e) /* �ҵ�e */
			return T[(i+1)/2-1];
	return Nil; /* û�ҵ�e */
}
 
 
/* ��ʼ����: ������T����,e��T��ĳ����� */
/* �������: ����e�����ӡ���e������,�򷵻أ��գ� */
TElemType LeftChild(SqBiTree T,TElemType e)
{ 
	int i;
	if(T[0]==Nil) /* ���� */
		return Nil;
	for(i=0;i<=MAX_TREE_SIZE-1;i++)
		if(T[i]==e) /* �ҵ�e */
			return T[i*2+1];
	return Nil; /* û�ҵ�e */
}
 
/* ��ʼ����: ������T����,e��T��ĳ����� */
/* �������: ����e���Һ��ӡ���e���Һ���,�򷵻أ��գ� */
TElemType RightChild(SqBiTree T,TElemType e)
{ 
	int i;
	if(T[0]==Nil) /* ���� */
		return Nil;
	for(i=0;i<=MAX_TREE_SIZE-1;i++)
		if(T[i]==e) /* �ҵ�e */
			return T[i*2+2];
	return Nil; /* û�ҵ�e */
}
 
/* ��ʼ����: ������T����,e��T��ĳ����� */
/* �������: ����e�����ֵܡ���e��T�����ӻ������ֵ�,�򷵻أ��գ� */
TElemType LeftSibling(SqBiTree T,TElemType e)
{ 
	int i;
	if(T[0]==Nil) /* ���� */
		return Nil;
	for(i=1;i<=MAX_TREE_SIZE-1;i++)
		if(T[i]==e&&i%2==0) /* �ҵ�e�������Ϊż��(���Һ���) */
			return T[i-1];
	return Nil; /* û�ҵ�e */
}
 
/* ��ʼ����: ������T����,e��T��ĳ����� */
/* �������: ����e�����ֵܡ���e��T���Һ��ӻ������ֵ�,�򷵻أ��գ� */
TElemType RightSibling(SqBiTree T,TElemType e)
{ 
	int i;
	if(T[0]==Nil) /* ���� */
		return Nil;
	for(i=1;i<=MAX_TREE_SIZE-1;i++)
		if(T[i]==e&&i%2) /* �ҵ�e�������Ϊ����(������) */
			return T[i+1];
	return Nil; /* û�ҵ�e */
}
 
/* PreOrderTraverse()���� */
void PreTraverse(SqBiTree T,int e)
{ 
	visit(T[e]);
	if(T[2*e+1]!=Nil) /* ���������� */
		PreTraverse(T,2*e+1);
	if(T[2*e+2]!=Nil) /* ���������� */
		PreTraverse(T,2*e+2);
}
 
/* ��ʼ����: ���������� */
/* �������: �������T�� */
Status PreOrderTraverse(SqBiTree T)
{ 
	if(!BiTreeEmpty(T)) /* ������ */
	 PreTraverse(T,0);
	printf("\n");
	return OK;
}
 
/* InOrderTraverse()���� */
void InTraverse(SqBiTree T,int e)
{ 
	if(T[2*e+1]!=Nil) /* ���������� */
		InTraverse(T,2*e+1);
	visit(T[e]);
	if(T[2*e+2]!=Nil) /* ���������� */
		InTraverse(T,2*e+2);
}
 
/* ��ʼ����: ���������� */
/* �������: �������T�� */
Status InOrderTraverse(SqBiTree T)
{ 
	if(!BiTreeEmpty(T)) /* ������ */
		InTraverse(T,0);
	printf("\n");
	return OK;
}
 
/* PostOrderTraverse()���� */
void PostTraverse(SqBiTree T,int e)
{ 
	if(T[2*e+1]!=Nil) /* ���������� */
		PostTraverse(T,2*e+1);
	if(T[2*e+2]!=Nil) /* ���������� */
		PostTraverse(T,2*e+2);
	visit(T[e]);
}
 
/* ��ʼ����: ������T���� */
/* �������: �������T�� */
Status PostOrderTraverse(SqBiTree T)
{ 
	if(!BiTreeEmpty(T)) /* ������ */
		PostTraverse(T,0);
	printf("\n");
	return OK;
}
 
/* ������������� */
void LevelOrderTraverse(SqBiTree T)
{ 
	int i=MAX_TREE_SIZE-1,j;
	while(T[i]==Nil)
		i--; /* �ҵ����һ���ǿս������ */
	for(j=0;j<=i;j++)  /* �Ӹ������,��������������� */
		if(T[j]!=Nil)
			visit(T[j]); /* ֻ�����ǿյĽ�� */
	printf("\n");
}
 
/* ��㡢������������������ */
void Print(SqBiTree T)
{ 
	int j,k;
	Position p;
	TElemType e;
	for(j=1;j<=BiTreeDepth(T);j++)
	{
		printf("��%d��: ",j);
		for(k=1;k<=powl(2,j-1);k++)
		{
			p.level=j;
			p.order=k;
			e=Value(T,p);
			if(e!=Nil)
				printf("%d:%d ",k,e);
		}
		printf("\n");
	}
}
 
 
int main()
{
	Status i;
	Position p;
	TElemType e;
	SqBiTree T;
	InitBiTree(T);
	CreateBiTree(T);
	printf("������������,���շ�%d(1:�� 0:��) �������=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	i=Root(T,&e);
	if(i)
		printf("�������ĸ�Ϊ��%d\n",e);
	else
		printf("���գ��޸�\n");
	printf("�������������:\n");
	LevelOrderTraverse(T);
	printf("ǰ�����������:\n");
	PreOrderTraverse(T);
	printf("�������������:\n");
	InOrderTraverse(T);
	printf("�������������:\n");
	PostOrderTraverse(T);
	printf("�޸Ľ��Ĳ��3�������2��");
	p.level=3;
	p.order=2;
	e=Value(T,p);
	printf("���޸Ľ���ԭֵΪ%d��������ֵ:50 ",e);
	e=50;
	Assign(T,p,e);
	printf("ǰ�����������:\n");
	PreOrderTraverse(T);
	printf("���%d��˫��Ϊ%d,���Һ��ӷֱ�Ϊ",e,Parent(T,e));
	printf("%d,%d,�����ֱֵܷ�Ϊ",LeftChild(T,e),RightChild(T,e));
	printf("%d,%d\n",LeftSibling(T,e),RightSibling(T,e));
	ClearBiTree(T);
	printf("�����������,���շ�%d(1:�� 0:��) �������=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	i=Root(T,&e);
	if(i)
		printf("�������ĸ�Ϊ��%d\n",e);
	else
		printf("���գ��޸�\n");
	
	return 0;
}
 
//02��������ʽ�ṹʵ��_BiTreeLink
#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"
 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
 
#define MAXSIZE 100 /* �洢�ռ��ʼ������ */
 
typedef int Status;		/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
 
/* ���ڹ��������********************************** */
int index=1;
typedef char String[24]; /*  0�ŵ�Ԫ��Ŵ��ĳ��� */
String str;
 
Status StrAssign(String T,char *chars)
{ 
	int i;
	if(strlen(chars)>MAXSIZE)
		return ERROR;
	else
	{
		T[0]=strlen(chars);
		for(i=1;i<=T[0];i++)
			T[i]=*(chars+i-1);
		return OK;
	}
}
/* ************************************************ */
 
typedef char TElemType;
TElemType Nil=' '; /* �ַ����Կո��Ϊ�� */
 
Status visit(TElemType e)
{
	printf("%c ",e);
	return OK;
}
 
typedef struct BiTNode  /* ���ṹ */
{
   TElemType data;		/* ������� */
   struct BiTNode *lchild,*rchild; /* ���Һ���ָ�� */
}BiTNode,*BiTree;
 
 
/* ����ն�����T */
Status InitBiTree(BiTree *T)
{ 
	*T=NULL;
	return OK;
}
 
/* ��ʼ����: ������T���ڡ��������: ���ٶ�����T */
void DestroyBiTree(BiTree *T)
{ 
	if(*T) 
	{
		if((*T)->lchild) /* ������ */
			DestroyBiTree(&(*T)->lchild); /* ������������ */
		if((*T)->rchild) /* ���Һ��� */
			DestroyBiTree(&(*T)->rchild); /* �����Һ������� */
		free(*T); /* �ͷŸ���� */
		*T=NULL; /* ��ָ�븳0 */
	}
}
 
/* ��ǰ������������н���ֵ��һ���ַ��� */
/* #��ʾ������������������ʾ������T�� */
void CreateBiTree(BiTree *T)
{ 
	TElemType ch;
	
	/* scanf("%c",&ch); */
	ch=str[index++];
 
	if(ch=='#') 
		*T=NULL;
	else
	{
		*T=(BiTree)malloc(sizeof(BiTNode));
		if(!*T)
			exit(OVERFLOW);
		(*T)->data=ch; /* ���ɸ���� */
		CreateBiTree(&(*T)->lchild); /* ���������� */
		CreateBiTree(&(*T)->rchild); /* ���������� */
	}
 }
 
/* ��ʼ����: ������T���� */
/* �������: ��TΪ�ն�����,�򷵻�TRUE,����FALSE */
Status BiTreeEmpty(BiTree T)
{ 
	if(T)
		return FALSE;
	else
		return TRUE;
}
 
#define ClearBiTree DestroyBiTree
 
/* ��ʼ����: ������T���ڡ��������: ����T����� */
int BiTreeDepth(BiTree T)
{
	int i,j;
	if(!T)
		return 0;
	if(T->lchild)
		i=BiTreeDepth(T->lchild);
	else
		i=0;
	if(T->rchild)
		j=BiTreeDepth(T->rchild);
	else
		j=0;
	return i>j?i+1:j+1;
}
 
/* ��ʼ����: ������T���ڡ��������: ����T�ĸ� */
TElemType Root(BiTree T)
{ 
	if(BiTreeEmpty(T))
		return Nil;
	else
		return T->data;
}
 
/* ��ʼ����: ������T���ڣ�pָ��T��ĳ����� */
/* �������: ����p��ָ����ֵ */
TElemType Value(BiTree p)
{
	return p->data;
}
 
/* ��p��ָ��㸳ֵΪvalue */
void Assign(BiTree p,TElemType value)
{
	p->data=value;
}
 
/* ��ʼ����: ������T���� */
/* �������: ǰ��ݹ����T */
void PreOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return;
	printf("%c",T->data);/* ��ʾ������ݣ����Ը���Ϊ�����Խ����� */
	PreOrderTraverse(T->lchild); /* ��������������� */
	PreOrderTraverse(T->rchild); /* ���������������� */
}
 
/* ��ʼ����: ������T���� */
/* �������: ����ݹ����T */
void InOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return;
	InOrderTraverse(T->lchild); /* ������������� */
	printf("%c",T->data);/* ��ʾ������ݣ����Ը���Ϊ�����Խ����� */
	InOrderTraverse(T->rchild); /* ���������������� */
}
 
/* ��ʼ����: ������T���� */
/* �������: ����ݹ����T */
void PostOrderTraverse(BiTree T)
{
	if(T==NULL)
		return;
	PostOrderTraverse(T->lchild); /* �Ⱥ������������  */
	PostOrderTraverse(T->rchild); /* �ٺ������������  */
	printf("%c",T->data);/* ��ʾ������ݣ����Ը���Ϊ�����Խ����� */
}
 
 
int main()
{
	int i;
	BiTree T;
	TElemType e1;
	InitBiTree(&T);
 
	
	StrAssign(str,"ABDH#K###E##CFI###G#J##");
 
	CreateBiTree(&T);
 
	printf("����ն�������,���շ�%d(1:�� 0:��) �������=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	e1=Root(T);
	printf("�������ĸ�Ϊ: %c\n",e1);
 
	printf("\nǰ�����������:");
	PreOrderTraverse(T);
	printf("\n�������������:");
	InOrderTraverse(T);
	printf("\n�������������:");
	PostOrderTraverse(T);
	ClearBiTree(&T);
	printf("\n�����������,���շ�%d(1:�� 0:��) �������=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	i=Root(T);
	if(!i)
		printf("���գ��޸�\n");
	
	return 0;
}
 
//03����������_ThreadBinaryTree
#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"
 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
 
#define MAXSIZE 100 /* �洢�ռ��ʼ������ */
 
typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬����,��OK�� */
typedef char TElemType;
typedef enum {Link,Thread} PointerTag;	/* Link==0��ʾָ�����Һ���ָ��, */
										/* Thread==1��ʾָ��ǰ�����̵����� */
typedef  struct BiThrNode	/* ���������洢���ṹ */
{
	TElemType data;	/* ������� */
	struct BiThrNode *lchild, *rchild;	/* ���Һ���ָ�� */
	PointerTag LTag;
	PointerTag RTag;		/* ���ұ�־ */
} BiThrNode, *BiThrTree;
 
TElemType Nil='#'; /* �ַ����Կո��Ϊ�� */
 
Status visit(TElemType e)
{
	printf("%c ",e);
	return OK;
}
 
/* ��ǰ����������������н���ֵ,�������������T */
/* 0(����)/�ո�(�ַ���)��ʾ�ս�� */
Status CreateBiThrTree(BiThrTree *T)
{ 
	TElemType h;
	scanf("%c",&h);
 
	if(h==Nil)
		*T=NULL;
	else
	{
		*T=(BiThrTree)malloc(sizeof(BiThrNode));
		if(!*T)
			exit(OVERFLOW);
		(*T)->data=h; /* ���ɸ����(ǰ��) */
		CreateBiThrTree(&(*T)->lchild); /* �ݹ鹹�������� */
		if((*T)->lchild) /* ������ */
			(*T)->LTag=Link;
		CreateBiThrTree(&(*T)->rchild); /* �ݹ鹹�������� */
		if((*T)->rchild) /* ���Һ��� */
			(*T)->RTag=Link;
	}
	return OK;
}
 
BiThrTree pre; /* ȫ�ֱ���,ʼ��ָ��ոշ��ʹ��Ľ�� */
/* ��������������������� */
void InThreading(BiThrTree p)
{ 
	if(p)
	{
		InThreading(p->lchild); /* �ݹ������������� */
		if(!p->lchild) /* û������ */
		{
			p->LTag=Thread; /* ǰ������ */
			p->lchild=pre; /* ����ָ��ָ��ǰ�� */
		}
		if(!pre->rchild) /* ǰ��û���Һ��� */
		{
			pre->RTag=Thread; /* ������� */
			pre->rchild=p; /* ǰ���Һ���ָ��ָ����(��ǰ���p) */
		}
		pre=p; /* ����preָ��p��ǰ�� */
		InThreading(p->rchild); /* �ݹ������������� */
	}
}
 
/* �������������T,����������������,Thrtָ��ͷ��� */
Status InOrderThreading(BiThrTree *Thrt,BiThrTree T)
{ 
	*Thrt=(BiThrTree)malloc(sizeof(BiThrNode));
	if(!*Thrt)
		exit(OVERFLOW);
	(*Thrt)->LTag=Link; /* ��ͷ��� */
	(*Thrt)->RTag=Thread;
	(*Thrt)->rchild=(*Thrt); /* ��ָ���ָ */
	if(!T) /* ����������,����ָ���ָ */
		(*Thrt)->lchild=*Thrt;
	else
	{
		(*Thrt)->lchild=T;
		pre=(*Thrt);
		InThreading(T); /* ��������������������� */
		pre->rchild=*Thrt;
		pre->RTag=Thread; /* ���һ����������� */
		(*Thrt)->rchild=pre;
	}
	return OK;
}
 
/* �����������������T(ͷ���)�ķǵݹ��㷨 */
Status InOrderTraverse_Thr(BiThrTree T)
{ 
	BiThrTree p;
	p=T->lchild; /* pָ������ */
	while(p!=T)
	{ /* �������������ʱ,p==T */
		while(p->LTag==Link)
			p=p->lchild;
		if(!visit(p->data)) /* ������������Ϊ�յĽ�� */
			return ERROR;
		while(p->RTag==Thread&&p->rchild!=T)
		{
			p=p->rchild;
			visit(p->data); /* ���ʺ�̽�� */
		}
		p=p->rchild;
	}
	return OK;
}
 
int main()
{
	BiThrTree H,T;
	printf("�밴ǰ�����������(��:'ABDH##I##EJ###CF##G##')\n");
 	CreateBiThrTree(&T); /* ��ǰ����������� */
	InOrderThreading(&H,T); /* �������,������������������ */
	printf("�������(���)����������:\n");
	InOrderTraverse_Thr(H); /* �������(���)���������� */
	printf("\n");
	
	return 0;
}
 
 
��7�¡�ͼ
//01�ڽӾ��󴴽�_CreateMGraph
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"
 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100 /* ��󶥵�����Ӧ���û����� */
#define INFINITY 65535
 
typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef char VertexType; /* ��������Ӧ���û�����  */
typedef int EdgeType; /* ���ϵ�Ȩֵ����Ӧ���û����� */
typedef struct
{
	VertexType vexs[MAXVEX]; /* ����� */
	EdgeType arc[MAXVEX][MAXVEX];/* �ڽӾ��󣬿ɿ����߱� */
	int numNodes, numEdges; /* ͼ�е�ǰ�Ķ������ͱ���  */
}MGraph;
 
/* ����������ͼ���ڽӾ����ʾ */
void CreateMGraph(MGraph *G)
{
	int i,j,k,w;
	printf("���붥�����ͱ���:\n");
	scanf("%d,%d",&G->numNodes,&G->numEdges); /* ���붥�����ͱ��� */
	for(i = 0;i <G->numNodes;i++) /* ���붥����Ϣ,��������� */
		scanf(&G->vexs[i]);
	for(i = 0;i <G->numNodes;i++)
		for(j = 0;j <G->numNodes;j++)
			G->arc[i][j]=INFINITY;	/* �ڽӾ����ʼ�� */
	for(k = 0;k <G->numEdges;k++) /* ����numEdges���ߣ������ڽӾ��� */
	{
		printf("�����(vi,vj)�ϵ��±�i���±�j��Ȩw:\n");
		scanf("%d,%d,%d",&i,&j,&w); /* �����(vi,vj)�ϵ�Ȩw */
		G->arc[i][j]=w; 
		G->arc[j][i]= G->arc[i][j]; /* ��Ϊ������ͼ������Գ� */
	}
}
 
int main(void)
{    
	MGraph G;    
	CreateMGraph(&G);
	
	return 0;
}
 
//02�ڽӱ���_CreateALGraph
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"
 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100 /* ��󶥵���,Ӧ���û����� */
 
typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬����,��OK�� */
typedef char VertexType; /* ��������Ӧ���û����� */
typedef int EdgeType; /* ���ϵ�Ȩֵ����Ӧ���û����� */
 
typedef struct EdgeNode /* �߱���  */
{
	int adjvex;    /* �ڽӵ���,�洢�ö����Ӧ���±� */
	EdgeType info;		/* ���ڴ洢Ȩֵ,���ڷ���ͼ���Բ���Ҫ */
	struct EdgeNode *next; /* ����,ָ����һ���ڽӵ� */
}EdgeNode;
 
typedef struct VertexNode /* ������� */
{
	VertexType data; /* ������,�洢������Ϣ */
	EdgeNode *firstedge;/* �߱�ͷָ�� */
}VertexNode, AdjList[MAXVEX];
 
typedef struct
{
	AdjList adjList; 
	int numNodes,numEdges; /* ͼ�е�ǰ�������ͱ��� */
}GraphAdjList;
 
/* ����ͼ���ڽӱ�ṹ */
void  CreateALGraph(GraphAdjList *G)
{
	int i,j,k;
	EdgeNode *e;
	printf("���붥�����ͱ���:\n");
	scanf("%d,%d",&G->numNodes,&G->numEdges); /* ���붥�����ͱ��� */
	for(i = 0;i < G->numNodes;i++) /* ���붥����Ϣ,��������� */
	{
		scanf(&G->adjList[i].data); 	/* ���붥����Ϣ */
		G->adjList[i].firstedge=NULL; 	/* ���߱���Ϊ�ձ� */
	}
	
	
	for(k = 0;k < G->numEdges;k++)/* �����߱� */
	{
		printf("�����(vi,vj)�ϵĶ������:\n");
		scanf("%d,%d",&i,&j); /* �����(vi,vj)�ϵĶ������ */
		e=(EdgeNode *)malloc(sizeof(EdgeNode)); /* ���ڴ�����ռ�,���ɱ߱��� */
		e->adjvex=j;					/* �ڽ����Ϊj */                         
		e->next=G->adjList[i].firstedge;	/* ��e��ָ��ָ��ǰ������ָ��Ľ�� */
		G->adjList[i].firstedge=e;		/* ����ǰ�����ָ��ָ��e */               
		
		e=(EdgeNode *)malloc(sizeof(EdgeNode)); /* ���ڴ�����ռ�,���ɱ߱��� */
		e->adjvex=i;					/* �ڽ����Ϊi */                         
		e->next=G->adjList[j].firstedge;	/* ��e��ָ��ָ��ǰ������ָ��Ľ�� */
		G->adjList[j].firstedge=e;		/* ����ǰ�����ָ��ָ��e */               
	}
}
 
int main(void)
{    
	GraphAdjList G;    
	CreateALGraph(&G);
	
	return 0;
}
 
//03�ڽӾ�����Ⱥ͹�ȱ���DFS_BFS
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"
 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
 
typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */  
typedef int Boolean; /* Boolean�ǲ�������,��ֵ��TRUE��FALSE */
 
typedef char VertexType; /* ��������Ӧ���û����� */
typedef int EdgeType; /* ���ϵ�Ȩֵ����Ӧ���û����� */
 
#define MAXSIZE 9 /* �洢�ռ��ʼ������ */
#define MAXEDGE 15
#define MAXVEX 9
#define INFINITY 65535
 
typedef struct
{
	VertexType vexs[MAXVEX]; /* ����� */
	EdgeType arc[MAXVEX][MAXVEX];/* �ڽӾ��󣬿ɿ����߱� */
	int numVertexes, numEdges; /* ͼ�е�ǰ�Ķ������ͱ��� */ 
}MGraph;
 
/* �õ��Ķ��нṹ�뺯��********************************** */
 
/* ѭ�����е�˳��洢�ṹ */
typedef struct
{
	int data[MAXSIZE];
	int front;    	/* ͷָ�� */
	int rear;		/* βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ�� */
}Queue;
 
/* ��ʼ��һ���ն���Q */
Status InitQueue(Queue *Q)
{
	Q->front=0;
	Q->rear=0;
	return  OK;
}
 
/* ������QΪ�ն���,�򷵻�TRUE,���򷵻�FALSE */
Status QueueEmpty(Queue Q)
{ 
	if(Q.front==Q.rear) /* ���пյı�־ */
		return TRUE;
	else
		return FALSE;
}
 
/* ������δ���������Ԫ��eΪQ�µĶ�βԪ�� */
Status EnQueue(Queue *Q,int e)
{
	if ((Q->rear+1)%MAXSIZE == Q->front)	/* ���������ж� */
		return ERROR;
	Q->data[Q->rear]=e;			/* ��Ԫ��e��ֵ����β */
	Q->rear=(Q->rear+1)%MAXSIZE;/* rearָ�������һλ�ã� */
								/* ���������ת������ͷ�� */
	return  OK;
}
 
/* �����в��գ���ɾ��Q�ж�ͷԪ�أ���e������ֵ */
Status DeQueue(Queue *Q,int *e)
{
	if (Q->front == Q->rear)			/* ���пյ��ж� */
		return ERROR;
	*e=Q->data[Q->front];				/* ����ͷԪ�ظ�ֵ��e */
	Q->front=(Q->front+1)%MAXSIZE;	/* frontָ�������һλ�ã� */
									/* ���������ת������ͷ�� */
	return  OK;
}
/* ****************************************************** */
 
 
void CreateMGraph(MGraph *G)
{
	int i, j;
 
	G->numEdges=15;
	G->numVertexes=9;
 
	/* ���붥����Ϣ����������� */
	G->vexs[0]='A';
	G->vexs[1]='B';
	G->vexs[2]='C';
	G->vexs[3]='D';
	G->vexs[4]='E';
	G->vexs[5]='F';
	G->vexs[6]='G';
	G->vexs[7]='H';
	G->vexs[8]='I';
 
 
	for (i = 0; i < G->numVertexes; i++)/* ��ʼ��ͼ */
	{
		for ( j = 0; j < G->numVertexes; j++)
		{
			G->arc[i][j]=0;
		}
	}
 
	G->arc[0][1]=1;
	G->arc[0][5]=1;
 
	G->arc[1][2]=1; 
	G->arc[1][8]=1; 
	G->arc[1][6]=1; 
	
	G->arc[2][3]=1; 
	G->arc[2][8]=1; 
	
	G->arc[3][4]=1;
	G->arc[3][7]=1;
	G->arc[3][6]=1;
	G->arc[3][8]=1;
 
	G->arc[4][5]=1;
	G->arc[4][7]=1;
 
	G->arc[5][6]=1; 
	
	G->arc[6][7]=1; 
 
	
	for(i = 0; i < G->numVertexes; i++)
	{
		for(j = i; j < G->numVertexes; j++)
		{
			G->arc[j][i] =G->arc[i][j];
		}
	}
 
}
 
Boolean visited[MAXVEX]; /* ���ʱ�־������ */
 
/* �ڽӾ����������ȵݹ��㷨 */
void DFS(MGraph G, int i)
{
	int j;
 	visited[i] = TRUE;
 	printf("%c ", G.vexs[i]);/* ��ӡ���㣬Ҳ������������ */
	for(j = 0; j < G.numVertexes; j++)
		if(G.arc[i][j] == 1 && !visited[j])
 			DFS(G, j);/* ��Ϊ���ʵ��ڽӶ���ݹ���� */
}
 
/* �ڽӾ������ȱ������� */
void DFSTraverse(MGraph G)
{
	int i;
 	for(i = 0; i < G.numVertexes; i++)
 		visited[i] = FALSE; /* ��ʼ���ж���״̬����δ���ʹ�״̬ */
	for(i = 0; i < G.numVertexes; i++)
 		if(!visited[i]) /* ��δ���ʹ��Ķ������DFS��������ͨͼ��ֻ��ִ��һ�� */ 
			DFS(G, i);
}
 
/* �ڽӾ���Ĺ�ȱ����㷨 */
void BFSTraverse(MGraph G)
{
	int i, j;
	Queue Q;
	for(i = 0; i < G.numVertexes; i++)
       	visited[i] = FALSE;
    InitQueue(&Q);		/* ��ʼ��һ�����õĶ��� */
    for(i = 0; i < G.numVertexes; i++)  /* ��ÿһ��������ѭ�� */
    {
		if (!visited[i])	/* ����δ���ʹ��ʹ��� */
		{
			visited[i]=TRUE;		/* ���õ�ǰ������ʹ� */
			printf("%c ", G.vexs[i]);/* ��ӡ���㣬Ҳ������������ */
			EnQueue(&Q,i);		/* ���˶�������� */
			while(!QueueEmpty(Q))	/* ����ǰ���в�Ϊ�� */
			{
				DeQueue(&Q,&i);	/* ���Ӷ�Ԫ�س����У���ֵ��i */
				for(j=0;j<G.numVertexes;j++) 
				{ 
					/* �ж������������뵱ǰ������ڱ���δ���ʹ�  */
					if(G.arc[i][j] == 1 && !visited[j]) 
					{ 
 						visited[j]=TRUE;			/* ���ҵ��Ĵ˶�����Ϊ�ѷ��� */
						printf("%c ", G.vexs[j]);	/* ��ӡ���� */
						EnQueue(&Q,j);				/* ���ҵ��Ĵ˶��������  */
					} 
				} 
			}
		}
	}
}
 
 
int main(void)
{    
	MGraph G;
	CreateMGraph(&G);
	printf("\n��ȱ�����");
	DFSTraverse(G);
	printf("\n��ȱ�����");
	BFSTraverse(G);
	return 0;
}
 
//04�ڽӱ���Ⱥ͹�ȱ���DFS_BFS
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"
 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
 
#define MAXSIZE 9 /* �洢�ռ��ʼ������ */
#define MAXEDGE 15
#define MAXVEX 9
#define INFINITY 65535
 
typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬����,��OK�� */
typedef int Boolean; /* Boolean�ǲ�������,��ֵ��TRUE��FALSE */
 
typedef char VertexType; /* ��������Ӧ���û����� */   
typedef int EdgeType; /* ���ϵ�Ȩֵ����Ӧ���û����� */
 
/* �ڽӾ���ṹ */
typedef struct
{
	VertexType vexs[MAXVEX]; /* ����� */
	EdgeType arc[MAXVEX][MAXVEX];/* �ڽӾ���,�ɿ����߱� */
	int numVertexes, numEdges; /* ͼ�е�ǰ�Ķ������ͱ��� */ 
}MGraph;
 
/* �ڽӱ�ṹ****************** */
typedef struct EdgeNode /* �߱��� */ 
{
	int adjvex;    /* �ڽӵ���,�洢�ö����Ӧ���±� */
	int weight;		/* ���ڴ洢Ȩֵ,���ڷ���ͼ���Բ���Ҫ */
	struct EdgeNode *next; /* ����,ָ����һ���ڽӵ� */ 
}EdgeNode;
 
typedef struct VertexNode /* ������� */ 
{
	int in;	/* ������� */
	char data; /* ������,�洢������Ϣ */
	EdgeNode *firstedge;/* �߱�ͷָ�� */   
}VertexNode, AdjList[MAXVEX];
 
typedef struct
{
	AdjList adjList; 
	int numVertexes,numEdges; /* ͼ�е�ǰ�������ͱ��� */
}graphAdjList,*GraphAdjList;
/* **************************** */
 
/* �õ��Ķ��нṹ�뺯��********************************** */
/* ѭ�����е�˳��洢�ṹ */
typedef struct
{
	int data[MAXSIZE];
	int front;    	/* ͷָ�� */
	int rear;		/* βָ��,�����в���,ָ�����βԪ�ص���һ��λ�� */
}Queue;
 
/* ��ʼ��һ���ն���Q */
Status InitQueue(Queue *Q)
{
	Q->front=0;
	Q->rear=0;
	return  OK;
}
 
/* ������QΪ�ն���,�򷵻�TRUE,���򷵻�FALSE */
Status QueueEmpty(Queue Q)
{ 
	if(Q.front==Q.rear) /* ���пյı�־ */
		return TRUE;
	else
		return FALSE;
}
 
/* ������δ��,�����Ԫ��eΪQ�µĶ�βԪ�� */
Status EnQueue(Queue *Q,int e)
{
	if ((Q->rear+1)%MAXSIZE == Q->front)	/* ���������ж� */
		return ERROR;
	Q->data[Q->rear]=e;			/* ��Ԫ��e��ֵ����β */
	Q->rear=(Q->rear+1)%MAXSIZE;/* rearָ�������һλ��, */
								/* ���������ת������ͷ�� */
	return  OK;
}
 
/* �����в���,��ɾ��Q�ж�ͷԪ��,��e������ֵ */
Status DeQueue(Queue *Q,int *e)
{
	if (Q->front == Q->rear)			/* ���пյ��ж� */
		return ERROR;
	*e=Q->data[Q->front];				/* ����ͷԪ�ظ�ֵ��e */
	Q->front=(Q->front+1)%MAXSIZE;	/* frontָ�������һλ��, */
									/* ���������ת������ͷ�� */
	return  OK;
}
/* ****************************************************** */
 
 
 
void CreateMGraph(MGraph *G)
{
	int i, j;
 
	G->numEdges=15;
	G->numVertexes=9;
 
	/* ���붥����Ϣ,��������� */ 
	G->vexs[0]='A';
	G->vexs[1]='B';
	G->vexs[2]='C';
	G->vexs[3]='D';
	G->vexs[4]='E';
	G->vexs[5]='F';
	G->vexs[6]='G';
	G->vexs[7]='H';
	G->vexs[8]='I';
 
 
	for (i = 0; i < G->numVertexes; i++)/* ��ʼ��ͼ */
	{
		for ( j = 0; j < G->numVertexes; j++)
		{
			G->arc[i][j]=0;
		}
	}
 
	G->arc[0][1]=1;
	G->arc[0][5]=1;
 
	G->arc[1][2]=1; 
	G->arc[1][8]=1; 
	G->arc[1][6]=1; 
	
	G->arc[2][3]=1; 
	G->arc[2][8]=1; 
	
	G->arc[3][4]=1;
	G->arc[3][7]=1;
	G->arc[3][6]=1;
	G->arc[3][8]=1;
 
	G->arc[4][5]=1;
	G->arc[4][7]=1;
 
	G->arc[5][6]=1; 
	
	G->arc[6][7]=1; 
 
	
	for(i = 0; i < G->numVertexes; i++)
	{
		for(j = i; j < G->numVertexes; j++)
		{
			G->arc[j][i] =G->arc[i][j];
		}
	}
 
}
 
/* �����ڽӾ��󹹽��ڽӱ� */
void CreateALGraph(MGraph G,GraphAdjList *GL)
{
	int i,j;
	EdgeNode *e;
 
	*GL = (GraphAdjList)malloc(sizeof(graphAdjList));
 
	(*GL)->numVertexes=G.numVertexes;
	(*GL)->numEdges=G.numEdges;
	for(i= 0;i <G.numVertexes;i++) /* ���붥����Ϣ,��������� */   
	{
		(*GL)->adjList[i].in=0;
		(*GL)->adjList[i].data=G.vexs[i];
		(*GL)->adjList[i].firstedge=NULL; 	/* ���߱���Ϊ�ձ� */
	}
	
	for(i=0;i<G.numVertexes;i++) /* �����߱� */
	{ 
		for(j=0;j<G.numVertexes;j++)
		{
			if (G.arc[i][j]==1)
			{
				e=(EdgeNode *)malloc(sizeof(EdgeNode));
				e->adjvex=j;					/* �ڽ����Ϊj */                         
				e->next=(*GL)->adjList[i].firstedge;	/* ����ǰ�����ϵ�ָ��Ľ��ָ�븳ֵ��e */
				(*GL)->adjList[i].firstedge=e;		/* ����ǰ�����ָ��ָ��e */   
				(*GL)->adjList[j].in++;
				
			}
		}
	}
	
}
 
Boolean visited[MAXSIZE]; /* ���ʱ�־������ */
 
/* �ڽӱ��������ȵݹ��㷨 */
void DFS(GraphAdjList GL, int i)
{
	EdgeNode *p;
 	visited[i] = TRUE;
 	printf("%c ",GL->adjList[i].data);/* ��ӡ����,Ҳ������������ */
	p = GL->adjList[i].firstedge;
	while(p)
	{
 		if(!visited[p->adjvex])
 			DFS(GL, p->adjvex);/* ��Ϊ���ʵ��ڽӶ���ݹ���� */
		p = p->next;
 	}
}
 
/* �ڽӱ����ȱ������� */
void DFSTraverse(GraphAdjList GL)
{
	int i;
 	for(i = 0; i < GL->numVertexes; i++)
 		visited[i] = FALSE; /* ��ʼ���ж���״̬����δ���ʹ�״̬ */
	for(i = 0; i < GL->numVertexes; i++)
 		if(!visited[i]) /* ��δ���ʹ��Ķ������DFS,������ͨͼ,ֻ��ִ��һ�� */ 
			DFS(GL, i);
}
 
/* �ڽӱ�Ĺ�ȱ����㷨 */
void BFSTraverse(GraphAdjList GL)
{
	int i;
    EdgeNode *p;
	Queue Q;
	for(i = 0; i < GL->numVertexes; i++)
       	visited[i] = FALSE;
    InitQueue(&Q);
   	for(i = 0; i < GL->numVertexes; i++)
   	{
		if (!visited[i])
		{
			visited[i]=TRUE;
			printf("%c ",GL->adjList[i].data);/* ��ӡ����,Ҳ������������ */
			EnQueue(&Q,i);
			while(!QueueEmpty(Q))
			{
				DeQueue(&Q,&i);
				p = GL->adjList[i].firstedge;	/* �ҵ���ǰ����ı߱�����ͷָ�� */
				while(p)
				{
					if(!visited[p->adjvex])	/* ���˶���δ������ */
 					{
 						visited[p->adjvex]=TRUE;
						printf("%c ",GL->adjList[p->adjvex].data);
						EnQueue(&Q,p->adjvex);	/* ���˶�������� */
					}
					p = p->next;	/* ָ��ָ����һ���ڽӵ� */
				}
			}
		}
	}
}
 
int main(void)
{    
	MGraph G;  
	GraphAdjList GL;    
	CreateMGraph(&G);
	CreateALGraph(G,&GL);
 
	printf("\n��ȱ���:");
	DFSTraverse(GL);
	printf("\n��ȱ���:");
	BFSTraverse(GL);
	return 0;
}
 
//05��С������_Prim
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"
 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
 
#define MAXEDGE 20
#define MAXVEX 20
#define INFINITY 65535
 
typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
 
typedef struct
{
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;
 
void CreateMGraph(MGraph *G)/* ����ͼ */
{
	int i, j;
 
	/* printf("����������Ͷ�����:"); */
	G->numEdges=15;
	G->numVertexes=9;
 
	for (i = 0; i < G->numVertexes; i++)/* ��ʼ��ͼ */
	{
		for ( j = 0; j < G->numVertexes; j++)
		{
			if (i==j)
				G->arc[i][j]=0;
			else
				G->arc[i][j] = G->arc[j][i] = INFINITY;
		}
	}
 
	G->arc[0][1]=10;
	G->arc[0][5]=11; 
	G->arc[1][2]=18; 
	G->arc[1][8]=12; 
	G->arc[1][6]=16; 
	G->arc[2][8]=8; 
	G->arc[2][3]=22; 
	G->arc[3][8]=21; 
	G->arc[3][6]=24; 
	G->arc[3][7]=16;
	G->arc[3][4]=20;
	G->arc[4][7]=7; 
	G->arc[4][5]=26; 
	G->arc[5][6]=17; 
	G->arc[6][7]=19; 
 
	for(i = 0; i < G->numVertexes; i++)
	{
		for(j = i; j < G->numVertexes; j++)
		{
			G->arc[j][i] =G->arc[i][j];
		}
	}
 
}
 
/* Prim�㷨������С������  */
void MiniSpanTree_Prim(MGraph G)
{
	int min, i, j, k;
	int adjvex[MAXVEX];		/* ������ض����±� */
	int lowcost[MAXVEX];	/* ������ض����ߵ�Ȩֵ */
	lowcost[0] = 0;/* ��ʼ����һ��ȨֵΪ0����v0���������� */
			/* lowcost��ֵΪ0����������Ǵ��±�Ķ����Ѿ����������� */
	adjvex[0] = 0;			/* ��ʼ����һ�������±�Ϊ0 */
	for(i = 1; i < G.numVertexes; i++)	/* ѭ�����±�Ϊ0���ȫ������ */
	{
		lowcost[i] = G.arc[0][i];	/* ��v0������֮�бߵ�Ȩֵ�������� */
		adjvex[i] = 0;					/* ��ʼ����Ϊv0���±� */
	}
	for(i = 1; i < G.numVertexes; i++)
	{
		min = INFINITY;	/* ��ʼ����СȨֵΪ�ޣ� */
						/* ͨ������Ϊ�����ܵĴ�������32767��65535�� */
		j = 1;k = 0;
		while(j < G.numVertexes)	/* ѭ��ȫ������ */
		{
			if(lowcost[j]!=0 && lowcost[j] < min)/* ���Ȩֵ��Ϊ0��ȨֵС��min */
			{	
				min = lowcost[j];	/* ���õ�ǰȨֵ��Ϊ��Сֵ */
				k = j;			/* ����ǰ��Сֵ���±����k */
			}
			j++;
		}
		printf("(%d, %d)\n", adjvex[k], k);/* ��ӡ��ǰ�������Ȩֵ��С�ı� */
		lowcost[k] = 0;/* ����ǰ�����Ȩֵ����Ϊ0,��ʾ�˶����Ѿ�������� */
		for(j = 1; j < G.numVertexes; j++)	/* ѭ�����ж��� */
		{
			if(lowcost[j]!=0 && G.arc[k][j] < lowcost[j]) 
			{/* ����±�Ϊk�������ȨֵС�ڴ�ǰ��Щ����δ������������Ȩֵ */
				lowcost[j] = G.arc[k][j];/* ����С��Ȩֵ����lowcost��Ӧλ�� */
				adjvex[j] = k;				/* ���±�Ϊk�Ķ������adjvex */
			}
		}
	}
}
 
int main(void)
{
	MGraph G;
	CreateMGraph(&G);
	MiniSpanTree_Prim(G);
  
	return 0;
 
}
//06��С������_Kruskal
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"
 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
 
typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
 
#define MAXEDGE 20
#define MAXVEX 20
#define INFINITY 65535
 
typedef struct
{
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;
 
typedef struct
{
	int begin;
	int end;
	int weight;
}Edge;   /* �Ա߼�����Edge�ṹ�Ķ��� */
 
/* ����ͼ */
void CreateMGraph(MGraph *G)
{
	int i, j;
 
	/* printf("����������Ͷ�����:"); */
	G->numEdges=15;
	G->numVertexes=9;
 
	for (i = 0; i < G->numVertexes; i++)/* ��ʼ��ͼ */
	{
		for ( j = 0; j < G->numVertexes; j++)
		{
			if (i==j)
				G->arc[i][j]=0;
			else
				G->arc[i][j] = G->arc[j][i] = INFINITY;
		}
	}
 
	G->arc[0][1]=10;
	G->arc[0][5]=11; 
	G->arc[1][2]=18; 
	G->arc[1][8]=12; 
	G->arc[1][6]=16; 
	G->arc[2][8]=8; 
	G->arc[2][3]=22; 
	G->arc[3][8]=21; 
	G->arc[3][6]=24; 
	G->arc[3][7]=16;
	G->arc[3][4]=20;
	G->arc[4][7]=7; 
	G->arc[4][5]=26; 
	G->arc[5][6]=17; 
	G->arc[6][7]=19; 
 
	for(i = 0; i < G->numVertexes; i++)
	{
		for(j = i; j < G->numVertexes; j++)
		{
			G->arc[j][i] =G->arc[i][j];
		}
	}
 
}
 
/* ����Ȩֵ �Լ�ͷ��β */
void Swapn(Edge *edges,int i, int j)
{
	int temp;
	temp = edges[i].begin;
	edges[i].begin = edges[j].begin;
	edges[j].begin = temp;
	temp = edges[i].end;
	edges[i].end = edges[j].end;
	edges[j].end = temp;
	temp = edges[i].weight;
	edges[i].weight = edges[j].weight;
	edges[j].weight = temp;
}
 
/* ��Ȩֵ�������� */
void sort(Edge edges[],MGraph *G)
{
	int i, j;
	for ( i = 0; i < G->numEdges; i++)
	{
		for ( j = i + 1; j < G->numEdges; j++)
		{
			if (edges[i].weight > edges[j].weight)
			{
				Swapn(edges, i, j);
			}
		}
	}
	printf("Ȩ����֮���Ϊ:\n");
	for (i = 0; i < G->numEdges; i++)
	{
		printf("(%d, %d) %d\n", edges[i].begin, edges[i].end, edges[i].weight);
	}
 
}
 
/* �������߶����β���±� */
int Find(int *parent, int f)
{
	while ( parent[f] > 0)
	{
		f = parent[f];
	}
	return f;
}
 
/* ������С������ */
void MiniSpanTree_Kruskal(MGraph G)
{
	int i, j, n, m;
	int k = 0;
	int parent[MAXVEX];/* ����һ���������жϱ�����Ƿ��γɻ�· */
	
	Edge edges[MAXEDGE];/* ����߼�����,edge�ĽṹΪbegin,end,weight,��Ϊ���� */
 
	/* ���������߼����鲢����********************* */
	for ( i = 0; i < G.numVertexes-1; i++)
	{
		for (j = i + 1; j < G.numVertexes; j++)
		{
			if (G.arc[i][j]<INFINITY)
			{
				edges[k].begin = i;
				edges[k].end = j;
				edges[k].weight = G.arc[i][j];
				k++;
			}
		}
	}
	sort(edges, &G);
	/* ******************************************* */
 
 
	for (i = 0; i < G.numVertexes; i++)
		parent[i] = 0;	/* ��ʼ������ֵΪ0 */
 
	printf("��ӡ��С��������\n");
	for (i = 0; i < G.numEdges; i++)	/* ѭ��ÿһ���� */
	{
		n = Find(parent,edges[i].begin);
		m = Find(parent,edges[i].end);
		if (n != m) /* ����n��m���ȣ�˵���˱�û�������е��������γɻ�· */
		{
			parent[n] = m;	/* ���˱ߵĽ�β��������±�Ϊ����parent�С� */
							/* ��ʾ�˶����Ѿ��������������� */
			printf("(%d, %d) %d\n", edges[i].begin, edges[i].end, edges[i].weight);
		}
	}
}
 
int main(void)
{
	MGraph G;
	CreateMGraph(&G);
	MiniSpanTree_Kruskal(G);
	return 0;
}
//07���·��_Dijkstra
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"
 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
 
#define MAXEDGE 20
#define MAXVEX 20
#define INFINITY 65535
 
typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */ 
 
 
typedef struct
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;
 
typedef int Patharc[MAXVEX];    /* ���ڴ洢���·���±������ */
typedef int ShortPathTable[MAXVEX];/* ���ڴ洢���������·����Ȩֵ�� */
 
/* ����ͼ */
void CreateMGraph(MGraph *G)
{
	int i, j;
 
	/* printf("����������Ͷ�����:"); */
	G->numEdges=16;
	G->numVertexes=9;
 
	for (i = 0; i < G->numVertexes; i++)/* ��ʼ��ͼ */
	{
		G->vexs[i]=i;
	}
 
	for (i = 0; i < G->numVertexes; i++)/* ��ʼ��ͼ */
	{
		for ( j = 0; j < G->numVertexes; j++)
		{
			if (i==j)
				G->arc[i][j]=0;
			else
				G->arc[i][j] = G->arc[j][i] = INFINITY;
		}
	}
 
	G->arc[0][1]=1;
	G->arc[0][2]=5; 
	G->arc[1][2]=3; 
	G->arc[1][3]=7; 
	G->arc[1][4]=5; 
 
	G->arc[2][4]=1; 
	G->arc[2][5]=7; 
	G->arc[3][4]=2; 
	G->arc[3][6]=3; 
	G->arc[4][5]=3;
 
	G->arc[4][6]=6;
	G->arc[4][7]=9; 
	G->arc[5][7]=5; 
	G->arc[6][7]=2; 
	G->arc[6][8]=7;
 
	G->arc[7][8]=4;
 
 
	for(i = 0; i < G->numVertexes; i++)
	{
		for(j = i; j < G->numVertexes; j++)
		{
			G->arc[j][i] =G->arc[i][j];
		}
	}
 
}
 
/*  Dijkstra�㷨����������G��v0���㵽���ඥ��v�����·��P[v]����Ȩ����D[v] */    
/*  P[v]��ֵΪǰ�������±�,D[v]��ʾv0��v�����·�����Ⱥ� */  
void ShortestPath_Dijkstra(MGraph G, int v0, Patharc *P, ShortPathTable *D)
{    
	int v,w,k,min;    
	int final[MAXVEX];/* final[w]=1��ʾ��ö���v0��vw�����·�� */
	for(v=0; v<G.numVertexes; v++)    /* ��ʼ������ */
	{        
		final[v] = 0;			/* ȫ�������ʼ��Ϊδ֪���·��״̬ */
		(*D)[v] = G.arc[v0][v];/* ����v0�������ߵĶ������Ȩֵ */
		(*P)[v] = -1;				/* ��ʼ��·������PΪ-1  */       
	}
 
	(*D)[v0] = 0;  /* v0��v0·��Ϊ0 */  
	final[v0] = 1;    /* v0��v0����Ҫ��·�� */        
	/* ��ʼ��ѭ����ÿ�����v0��ĳ��v��������·�� */   
	for(v=1; v<G.numVertexes; v++)   
	{
		min=INFINITY;    /* ��ǰ��֪��v0������������ */        
		for(w=0; w<G.numVertexes; w++) /* Ѱ����v0����Ķ��� */    
		{            
			if(!final[w] && (*D)[w]<min)             
			{                   
				k=w;                    
				min = (*D)[w];    /* w������v0������� */            
			}        
		}        
		final[k] = 1;    /* ��Ŀǰ�ҵ�������Ķ�����Ϊ1 */
		for(w=0; w<G.numVertexes; w++) /* ������ǰ���·�������� */
		{
			/* �������v�����·������������·���ĳ��ȶ̵Ļ� */
			if(!final[w] && (min+G.arc[k][w]<(*D)[w]))   
			{ /*  ˵���ҵ��˸��̵�·�����޸�D[w]��P[w] */
				(*D)[w] = min + G.arc[k][w];  /* �޸ĵ�ǰ·������ */               
				(*P)[w]=k;        
			}       
		}   
	}
}
 
int main(void)
{   
	int i,j,v0;
	MGraph G;    
	Patharc P;    
	ShortPathTable D; /* ��ĳ�㵽�����������·�� */   
	v0=0;
	
	CreateMGraph(&G);
	
	ShortestPath_Dijkstra(G, v0, &P, &D);  
 
	printf("���·����������:\n");    
	for(i=1;i<G.numVertexes;++i)   
	{       
		printf("v%d - v%d : ",v0,i);
		j=i;
		while(P[j]!=-1)
		{
			printf("%d ",P[j]);
			j=P[j];
		}
		printf("\n");
	}    
	printf("\nԴ�㵽����������·������Ϊ:\n");  
	for(i=1;i<G.numVertexes;++i)        
		printf("v%d - v%d : %d \n",G.vexs[0],G.vexs[i],D[i]);     
	return 0;
}
//08���·��_Floyd
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"
 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXEDGE 20
#define MAXVEX 20
#define INFINITY 65535
 
typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
 
typedef struct
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;
 
typedef int Patharc[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX];
 
/* ����ͼ */
void CreateMGraph(MGraph *G)
{
	int i, j;
 
	/* printf("����������Ͷ�����:"); */
	G->numEdges=16;
	G->numVertexes=9;
 
	for (i = 0; i < G->numVertexes; i++)/* ��ʼ��ͼ */
	{
		G->vexs[i]=i;
	}
 
	for (i = 0; i < G->numVertexes; i++)/* ��ʼ��ͼ */
	{
		for ( j = 0; j < G->numVertexes; j++)
		{
			if (i==j)
				G->arc[i][j]=0;
			else
				G->arc[i][j] = G->arc[j][i] = INFINITY;
		}
	}
 
	G->arc[0][1]=1;
	G->arc[0][2]=5; 
	G->arc[1][2]=3; 
	G->arc[1][3]=7; 
	G->arc[1][4]=5; 
 
	G->arc[2][4]=1; 
	G->arc[2][5]=7; 
	G->arc[3][4]=2; 
	G->arc[3][6]=3; 
	G->arc[4][5]=3;
 
	G->arc[4][6]=6;
	G->arc[4][7]=9; 
	G->arc[5][7]=5; 
	G->arc[6][7]=2; 
	G->arc[6][8]=7;
 
	G->arc[7][8]=4;
 
 
	for(i = 0; i < G->numVertexes; i++)
	{
		for(j = i; j < G->numVertexes; j++)
		{
			G->arc[j][i] =G->arc[i][j];
		}
	}
 
}
 
/* Floyd�㷨������ͼG�и�����v�����ඥ��w�����·��P[v][w]����Ȩ����D[v][w]�� */    
void ShortestPath_Floyd(MGraph G, Patharc *P, ShortPathTable *D)
{    
	int v,w,k;    
	for(v=0; v<G.numVertexes; ++v) /* ��ʼ��D��P */  
	{        
		for(w=0; w<G.numVertexes; ++w)  
		{
			(*D)[v][w]=G.arc[v][w];	/* D[v][w]ֵ��Ϊ��Ӧ����Ȩֵ */
			(*P)[v][w]=w;				/* ��ʼ��P */
		}
	}
	for(k=0; k<G.numVertexes; ++k)   
	{
		for(v=0; v<G.numVertexes; ++v)  
		{        
			for(w=0; w<G.numVertexes; ++w)    
			{
				if ((*D)[v][w]>(*D)[v][k]+(*D)[k][w])
				{/* ��������±�Ϊk����·����ԭ�����·������ */
					(*D)[v][w]=(*D)[v][k]+(*D)[k][w];/* ����ǰ�����Ȩֵ��Ϊ��С��һ�� */
					(*P)[v][w]=(*P)[v][k];/* ·������Ϊ�����±�Ϊk�Ķ��� */
				}
			}
		}
	}
}
 
int main(void)
{    
	int v,w,k;  
	MGraph G;    
	
	Patharc P;    
	ShortPathTable D; /* ��ĳ�㵽�����������·�� */   
	
	CreateMGraph(&G);
	
	ShortestPath_Floyd(G,&P,&D);  
 
	printf("����������·������:\n");    
	for(v=0; v<G.numVertexes; ++v)   
	{        
		for(w=v+1; w<G.numVertexes; w++)  
		{
			printf("v%d-v%d weight: %d ",v,w,D[v][w]);
			k=P[v][w];				/* ��õ�һ��·�������±� */
			printf(" path: %d",v);	/* ��ӡԴ�� */
			while(k!=w)				/* ���·�������±겻���յ� */
			{
				printf(" -> %d",k);	/* ��ӡ·������ */
				k=P[k][w];			/* �����һ��·�������±� */
			}
			printf(" -> %d\n",w);	/* ��ӡ�յ� */
		}
		printf("\n");
	}
 
	printf("���·��D\n");
	for(v=0; v<G.numVertexes; ++v)  
	{        
		for(w=0; w<G.numVertexes; ++w)    
		{
			printf("%d\t",D[v][w]);
		}
		printf("\n");
	}
	printf("���·��P\n");
	for(v=0; v<G.numVertexes; ++v)  
	{        
		for(w=0; w<G.numVertexes; ++w)    
		{
			printf("%d ",P[v][w]);
		}
		printf("\n");
	}
 
	return 0;
}
//09��������_TopologicalSort
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"
 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXEDGE 20
#define MAXVEX 14
#define INFINITY 65535
 
typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
 
/* �ڽӾ���ṹ */
typedef struct
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;
 
/* �ڽӱ�ṹ****************** */
typedef struct EdgeNode /* �߱���  */
{
	int adjvex;    /* �ڽӵ��򣬴洢�ö����Ӧ���±� */
	int weight;		/* ���ڴ洢Ȩֵ�����ڷ���ͼ���Բ���Ҫ */
	struct EdgeNode *next; /* ����ָ����һ���ڽӵ� */
}EdgeNode;
 
typedef struct VertexNode /* ������� */
{
	int in;	/* ������� */
	int data; /* �����򣬴洢������Ϣ */
	EdgeNode *firstedge;/* �߱�ͷָ�� */
}VertexNode, AdjList[MAXVEX];
 
typedef struct
{
	AdjList adjList; 
	int numVertexes,numEdges; /* ͼ�е�ǰ�������ͱ��� */
}graphAdjList,*GraphAdjList;
/* **************************** */
 
 
void CreateMGraph(MGraph *G)/* ����ͼ */
{
	int i, j;
	
	/* printf("����������Ͷ�����:"); */
	G->numEdges=MAXEDGE;
	G->numVertexes=MAXVEX;
 
	for (i = 0; i < G->numVertexes; i++)/* ��ʼ��ͼ */
	{
		G->vexs[i]=i;
	}
 
	for (i = 0; i < G->numVertexes; i++)/* ��ʼ��ͼ */
	{
		for ( j = 0; j < G->numVertexes; j++)
		{
			G->arc[i][j]=0;
		}
	}
 
	G->arc[0][4]=1;
	G->arc[0][5]=1; 
	G->arc[0][11]=1; 
	G->arc[1][2]=1; 
	G->arc[1][4]=1; 
	G->arc[1][8]=1; 
	G->arc[2][5]=1; 
	G->arc[2][6]=1;
	G->arc[2][9]=1;
	G->arc[3][2]=1; 
	G->arc[3][13]=1;
	G->arc[4][7]=1;
	G->arc[5][8]=1;
	G->arc[5][12]=1; 
	G->arc[6][5]=1; 
	G->arc[8][7]=1;
	G->arc[9][10]=1;
	G->arc[9][11]=1;
	G->arc[10][13]=1;
	G->arc[12][9]=1;
 
}
 
/* �����ڽӾ��󹹽��ڽӱ� */
void CreateALGraph(MGraph G,GraphAdjList *GL)
{
	int i,j;
	EdgeNode *e;
 
	*GL = (GraphAdjList)malloc(sizeof(graphAdjList));
 
	(*GL)->numVertexes=G.numVertexes;
	(*GL)->numEdges=G.numEdges;
	for(i= 0;i <G.numVertexes;i++) /* ���붥����Ϣ����������� */
	{
		(*GL)->adjList[i].in=0;
		(*GL)->adjList[i].data=G.vexs[i];
		(*GL)->adjList[i].firstedge=NULL; 	/* ���߱���Ϊ�ձ� */
	}
	
	for(i=0;i<G.numVertexes;i++) /* �����߱� */
	{ 
		for(j=0;j<G.numVertexes;j++)
		{
			if (G.arc[i][j]==1)
			{
				e=(EdgeNode *)malloc(sizeof(EdgeNode));
				e->adjvex=j;					/* �ڽ����Ϊj  */                        
				e->next=(*GL)->adjList[i].firstedge;	/* ����ǰ�����ϵ�ָ��Ľ��ָ�븳ֵ��e */
				(*GL)->adjList[i].firstedge=e;		/* ����ǰ�����ָ��ָ��e  */  
				(*GL)->adjList[j].in++;
				
			}
		}
	}
	
}
 
 
/* ����������GL�޻�·������������������в�����1�����л�·����0�� */
Status TopologicalSort(GraphAdjList GL)
{    
	EdgeNode *e;    
	int i,k,gettop;   
	int top=0;  /* ����ջָ���±�  */
	int count=0;/* ����ͳ���������ĸ���  */    
	int *stack;	/* ��ջ�����Ϊ0�Ķ�����ջ  */   
	stack=(int *)malloc(GL->numVertexes * sizeof(int) );    
 
	for(i = 0; i<GL->numVertexes; i++)                
		if(0 == GL->adjList[i].in) /* �����Ϊ0�Ķ�����ջ */         
			stack[++top]=i;    
	while(top!=0)    
	{        
		gettop=stack[top--];        
		printf("%d -> ",GL->adjList[gettop].data);        
		count++;        /* ���i�Ŷ��㣬������ */        
		for(e = GL->adjList[gettop].firstedge; e; e = e->next)        
		{            
			k=e->adjvex;            
			if( !(--GL->adjList[k].in) )  /* ��i�Ŷ�����ڽӵ����ȼ�1�������1��Ϊ0������ջ */                
				stack[++top]=k;        
		}
	}   
	printf("\n");   
	if(count < GL->numVertexes)        
		return ERROR;    
	else       
		return OK;
}
 
 
int main(void)
{    
	MGraph G;  
	GraphAdjList GL; 
	int result;   
	CreateMGraph(&G);
	CreateALGraph(G,&GL);
	result=TopologicalSort(GL);
	printf("result:%d",result);
 
	return 0;
}
//10�ؼ�·��_CriticalPath
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"
 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
 
#define MAXEDGE 30
#define MAXVEX 30
#define INFINITY 65535
 
typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */  
 
int *etv,*ltv; /* �¼����緢��ʱ�����ٷ���ʱ�����飬ȫ�ֱ��� */
int *stack2;   /* ���ڴ洢�������е�ջ */
int top2;	   /* ����stack2��ָ�� */
 
/* �ڽӾ���ṹ */
typedef struct
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;
 
/* �ڽӱ�ṹ****************** */
typedef struct EdgeNode /* �߱���  */
{
	int adjvex;    /* �ڽӵ��򣬴洢�ö����Ӧ���±� */
	int weight;		/* ���ڴ洢Ȩֵ�����ڷ���ͼ���Բ���Ҫ */
	struct EdgeNode *next; /* ����ָ����һ���ڽӵ� */
}EdgeNode;
 
typedef struct VertexNode /* ������� */
{
	int in;	/* ������� */
	int data; /* �����򣬴洢������Ϣ */
	EdgeNode *firstedge;/* �߱�ͷָ�� */
}VertexNode, AdjList[MAXVEX];
 
typedef struct
{
	AdjList adjList; 
	int numVertexes,numEdges; /* ͼ�е�ǰ�������ͱ��� */
}graphAdjList,*GraphAdjList;
/* **************************** */
 
 
void CreateMGraph(MGraph *G)/* ����ͼ */
{
	int i, j;
	/* printf("����������Ͷ�����:"); */
	G->numEdges=13;
	G->numVertexes=10;
 
	for (i = 0; i < G->numVertexes; i++)/* ��ʼ��ͼ */
	{
		G->vexs[i]=i;
	}
 
	for (i = 0; i < G->numVertexes; i++)/* ��ʼ��ͼ */
	{
		for ( j = 0; j < G->numVertexes; j++)
		{
			if (i==j)
				G->arc[i][j]=0;
			else
				G->arc[i][j]=INFINITY;
		}
	}
 
	G->arc[0][1]=3;
	G->arc[0][2]=4; 
	G->arc[1][3]=5; 
	G->arc[1][4]=6; 
	G->arc[2][3]=8; 
	G->arc[2][5]=7; 
	G->arc[3][4]=3;
	G->arc[4][6]=9; 
	G->arc[4][7]=4;
	G->arc[5][7]=6; 
	G->arc[6][9]=2;
	G->arc[7][8]=5;
	G->arc[8][9]=3;
 
}
 
/* �����ڽӾ��󹹽��ڽӱ� */
void CreateALGraph(MGraph G,GraphAdjList *GL)
{
	int i,j;
	EdgeNode *e;
 
	*GL = (GraphAdjList)malloc(sizeof(graphAdjList));
 
	(*GL)->numVertexes=G.numVertexes;
	(*GL)->numEdges=G.numEdges;
	for(i= 0;i <G.numVertexes;i++) /* ���붥����Ϣ����������� */
	{
		(*GL)->adjList[i].in=0;
		(*GL)->adjList[i].data=G.vexs[i];
		(*GL)->adjList[i].firstedge=NULL; 	/* ���߱���Ϊ�ձ� */
	}
	
	for(i=0;i<G.numVertexes;i++) /* �����߱� */
	{ 
		for(j=0;j<G.numVertexes;j++)
		{
			if (G.arc[i][j]!=0 && G.arc[i][j]<INFINITY)
			{
				e=(EdgeNode *)malloc(sizeof(EdgeNode));
				e->adjvex=j;					/* �ڽ����Ϊj */   
				e->weight=G.arc[i][j];
				e->next=(*GL)->adjList[i].firstedge;	/* ����ǰ�����ϵ�ָ��Ľ��ָ�븳ֵ��e */
				(*GL)->adjList[i].firstedge=e;		/* ����ǰ�����ָ��ָ��e  */  
				(*GL)->adjList[j].in++;
				
			}
		}
	}
	
}
 
 
/* �������� */
Status TopologicalSort(GraphAdjList GL)
{    /* ��GL�޻�·������������������в�����1�����л�·����0�� */    
	EdgeNode *e;    
	int i,k,gettop;   
	int top=0;  /* ����ջָ���±�  */
	int count=0;/* ����ͳ���������ĸ��� */   
	int *stack;	/* ��ջ�����Ϊ0�Ķ�����ջ  */   
	stack=(int *)malloc(GL->numVertexes * sizeof(int) );    
	for(i = 0; i<GL->numVertexes; i++)                
		if(0 == GL->adjList[i].in) /* �����Ϊ0�Ķ�����ջ */           
			stack[++top]=i;    
 
	top2=0;    
	etv=(int *)malloc(GL->numVertexes * sizeof(int) ); /* �¼����緢��ʱ������ */    
	for(i=0; i<GL->numVertexes; i++)        
		etv[i]=0;    /* ��ʼ�� */
	stack2=(int *)malloc(GL->numVertexes * sizeof(int) );/* ��ʼ����������ջ */
 
	printf("TopologicalSort:\t");
	while(top!=0)    
	{        
		gettop=stack[top--];        
		printf("%d -> ",GL->adjList[gettop].data);        
		count++;        /* ���i�Ŷ��㣬������ */ 
 
		stack2[++top2]=gettop;        /* �������Ķ������ѹ���������е�ջ */
 
		for(e = GL->adjList[gettop].firstedge; e; e = e->next)        
		{            
			k=e->adjvex;            
			if( !(--GL->adjList[k].in) )        /* ��i�Ŷ�����ڽӵ����ȼ�1�������1��Ϊ0������ջ */                
				stack[++top]=k; 
 
			if((etv[gettop] + e->weight)>etv[k])    /* ��������¼������緢��ʱ��etvֵ */                
				etv[k] = etv[gettop] + e->weight;
		}    
	}    
	printf("\n");   
	if(count < GL->numVertexes)        
		return ERROR;    
	else       
		return OK;
}
 
/* ��ؼ�·��,GLΪ�����������G�ĸ���ؼ�� */
void CriticalPath(GraphAdjList GL) 
{    
	EdgeNode *e;    
	int i,gettop,k,j;    
	int ete,lte;  /* ��������緢��ʱ�����ٷ���ʱ����� */        
	TopologicalSort(GL);   /* ���������У���������etv��stack2��ֵ */ 
	ltv=(int *)malloc(GL->numVertexes*sizeof(int));/* �¼����緢��ʱ������ */   
	for(i=0; i<GL->numVertexes; i++)        
		ltv[i]=etv[GL->numVertexes-1];    /* ��ʼ�� */        
	
	printf("etv:\t");   
	for(i=0; i<GL->numVertexes; i++)        
		printf("%d -> ",etv[i]);    
	printf("\n"); 
 
	while(top2!=0)    /* ��ջ����ltv */    
	{        
		gettop=stack2[top2--];        
		for(e = GL->adjList[gettop].firstedge; e; e = e->next)        /* ��������¼�����ٷ���ʱ��ltvֵ */        
		{            
			k=e->adjvex;            
			if(ltv[k] - e->weight < ltv[gettop])               
				ltv[gettop] = ltv[k] - e->weight;        
		}   
	}    
	
	printf("ltv:\t");   
	for(i=0; i<GL->numVertexes; i++)        
		printf("%d -> ",ltv[i]);    
	printf("\n"); 
 
	for(j=0; j<GL->numVertexes; j++)        /* ��ete,lte�͹ؼ�� */        
	{            
		for(e = GL->adjList[j].firstedge; e; e = e->next)            
		{                
			k=e->adjvex;                
			ete = etv[j];        /* ����緢��ʱ�� */                
			lte = ltv[k] - e->weight; /* ���ٷ���ʱ�� */               
			if(ete == lte)    /* ������ȼ��ڹؼ�·���� */                    
				printf("<v%d - v%d> length: %d \n",GL->adjList[j].data,GL->adjList[k].data,e->weight);
		}        
	}
}
 
 
int main(void)
{    
	MGraph G;    
	GraphAdjList GL;    
	CreateMGraph(&G);
	CreateALGraph(G,&GL);
	CriticalPath(GL);
	return 0;
}
��8�¡�����
//01��̬����_Search
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"
 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* �洢�ռ��ʼ������ */
 
typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */ 
 
int F[100]; /* 쳲��������� */
 
/* ���ڱ�˳����ң�aΪ���飬nΪҪ���ҵ����������keyΪҪ���ҵĹؼ��� */
int Sequential_Search(int *a,int n,int key)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if (a[i]==key)
			return i;
	}
	return 0;
}
/* ���ڱ�˳����� */
int Sequential_Search2(int *a,int n,int key)
{
	int i;
	a[0]=key;
	i=n;
	while(a[i]!=key)
	{
		i--;
	}
	return i;
}
 
/* �۰���� */
int Binary_Search(int *a,int n,int key)
{
	int low,high,mid;
	low=1;	/* ��������±�Ϊ��¼��λ */
	high=n;	/* ��������±�Ϊ��¼ĩλ */
	while(low<=high)
	{
		mid=(low+high)/2;	/* �۰� */
		if (key<a[mid])		/* ������ֵ����ֵС */
			high=mid-1;		/* ����±��������λ�±�Сһλ */
		else if (key>a[mid])/* ������ֵ����ֵ�� */
			low=mid+1;		/* ����±��������λ�±��һλ */
		else
		{
			return mid;		/* �������˵��mid��Ϊ���ҵ���λ�� */
		}
		
	}
	return 0;
}
 
/* ��ֵ���� */
int Interpolation_Search(int *a,int n,int key)
{
	int low,high,mid;
	low=1;	/* ��������±�Ϊ��¼��λ */
	high=n;	/* ��������±�Ϊ��¼ĩλ */
	while(low<=high)
	{
		mid=low+ (high-low)*(key-a[low])/(a[high]-a[low]); /* ��ֵ */
		if (key<a[mid])		/* ������ֵ�Ȳ�ֵС */
			high=mid-1;		/* ����±��������ֵ�±�Сһλ */
		else if (key>a[mid])/* ������ֵ�Ȳ�ֵ�� */
			low=mid+1;		/* ����±��������ֵ�±��һλ */
		else
			return mid;		/* �������˵��mid��Ϊ���ҵ���λ�� */
	}
	return 0;
}
 
/* 쳲��������� */
int Fibonacci_Search(int *a,int n,int key)
{
	int low,high,mid,i,k=0;
	low=1;	/* ��������±�Ϊ��¼��λ */
	high=n;	/* ��������±�Ϊ��¼ĩλ */
	while(n>F[k]-1)
		k++;
	for (i=n;i<F[k]-1;i++)
		a[i]=a[n];
	
	while(low<=high)
	{
		mid=low+F[k-1]-1;
		if (key<a[mid])
		{
			high=mid-1;		
			k=k-1;
		}
		else if (key>a[mid])
		{
			low=mid+1;		
			k=k-2;
		}
		else
		{
			if (mid<=n)
				return mid;		/* �������˵��mid��Ϊ���ҵ���λ�� */
			else 
				return n;
		}
		
	}
	return 0;
}
 
 
 
 
  
 
int main(void)
{    
 
	int a[MAXSIZE+1],i,result;
	int arr[MAXSIZE]={0,1,16,24,35,47,59,62,73,88,99};
		
	for(i=0;i<=MAXSIZE;i++)
	{
		a[i]=i;
	}
	result=Sequential_Search(a,MAXSIZE,MAXSIZE);
	printf("Sequential_Search:%d \n",result);
	result=Sequential_Search2(a,MAXSIZE,1);
	printf("Sequential_Search2:%d \n",result);
 
	result=Binary_Search(arr,10,62);
	printf("Binary_Search:%d \n",result);
 
	
	result=Interpolation_Search(arr,10,62);
	printf("Interpolation_Search:%d \n",result);
 
	
	F[0]=0;
	F[1]=1;
	for(i = 2;i < 100;i++)  
	{ 
		F[i] = F[i-1] + F[i-2];  
	} 
	result=Fibonacci_Search(arr,10,62);
	printf("Fibonacci_Search:%d \n",result);
	
	return 0;
}
//02����������_BinarySortTree
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"
 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* �洢�ռ��ʼ������ */
 
typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */ 
 
/* �������Ķ���������ṹ���� */
typedef  struct BiTNode	/* ���ṹ */
{
	int data;	/* ������� */
	struct BiTNode *lchild, *rchild;	/* ���Һ���ָ�� */
} BiTNode, *BiTree;
 
 
/* �ݹ���Ҷ���������T���Ƿ����key, */
/* ָ��fָ��T��˫�ף����ʼ����ֵΪNULL */
/* �����ҳɹ�����ָ��pָ�������Ԫ�ؽ�㣬������TRUE */
/* ����ָ��pָ�����·���Ϸ��ʵ����һ����㲢����FALSE */
Status SearchBST(BiTree T, int key, BiTree f, BiTree *p) 
{  
	if (!T)	/*  ���Ҳ��ɹ� */
	{ 
		*p = f;  
		return FALSE; 
	}
	else if (key==T->data) /*  ���ҳɹ� */
	{ 
		*p = T;  
		return TRUE; 
	} 
	else if (key<T->data) 
		return SearchBST(T->lchild, key, T, p);  /*  ���������м������� */
	else  
		return SearchBST(T->rchild, key, T, p);  /*  ���������м������� */
}
 
 
/*  ������������T�в����ڹؼ��ֵ���key������Ԫ��ʱ�� */
/*  ����key������TRUE�����򷵻�FALSE */
Status InsertBST(BiTree *T, int key) 
{  
	BiTree p,s;
	if (!SearchBST(*T, key, NULL, &p)) /* ���Ҳ��ɹ� */
	{
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;  
		s->lchild = s->rchild = NULL;  
		if (!p) 
			*T = s;			/*  ����sΪ�µĸ���� */
		else if (key<p->data) 
			p->lchild = s;	/*  ����sΪ���� */
		else 
			p->rchild = s;  /*  ����sΪ�Һ��� */
		return TRUE;
	} 
	else 
		return FALSE;  /*  �������йؼ�����ͬ�Ľ�㣬���ٲ��� */
}
 
/* �Ӷ�����������ɾ�����p�����ؽ���������������� */
Status Delete(BiTree *p)
{
	BiTree q,s;
	if((*p)->rchild==NULL) /* ����������ֻ���ؽ���������������ɾ�����Ҷ��Ҳ�ߴ˷�֧) */
	{
		q=*p; *p=(*p)->lchild; free(q);
	}
	else if((*p)->lchild==NULL) /* ֻ���ؽ����������� */
	{
		q=*p; *p=(*p)->rchild; free(q);
	}
	else /* �������������� */
	{
		q=*p; s=(*p)->lchild;
		while(s->rchild) /* ת��Ȼ�����ҵ���ͷ���Ҵ�ɾ����ǰ���� */
		{
			q=s;
			s=s->rchild;
		}
		(*p)->data=s->data; /*  sָ��ɾ����ֱ��ǰ��������ɾ���ǰ����ֵȡ����ɾ����ֵ�� */
		if(q!=*p)
			q->rchild=s->lchild; /*  �ؽ�q�������� */ 
		else
			q->lchild=s->lchild; /*  �ؽ�q�������� */
		free(s);
	}
	return TRUE;
}
 
/* ������������T�д��ڹؼ��ֵ���key������Ԫ��ʱ����ɾ��������Ԫ�ؽ��, */
/* ������TRUE�����򷵻�FALSE�� */
Status DeleteBST(BiTree *T,int key)
{ 
	if(!*T) /* �����ڹؼ��ֵ���key������Ԫ�� */ 
		return FALSE;
	else
	{
		if (key==(*T)->data) /* �ҵ��ؼ��ֵ���key������Ԫ�� */ 
			return Delete(T);
		else if (key<(*T)->data)
			return DeleteBST(&(*T)->lchild,key);
		else
			return DeleteBST(&(*T)->rchild,key);
		 
	}
}
 
int main(void)
{    
	int i;
	int a[10]={62,88,58,47,35,73,51,99,37,93};
	BiTree T=NULL;
	
	for(i=0;i<10;i++)
	{
		InsertBST(&T, a[i]);
	}
	DeleteBST(&T,93);
	DeleteBST(&T,47);
    printf("����������ϵ���ٲ鿴�����������ṹ");
	return 0;
}
//03ƽ�������_AVLTree
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"
 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* �洢�ռ��ʼ������ */
 
typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */ 
 
 
/* �������Ķ���������ṹ���� */
typedef  struct BiTNode	/* ���ṹ */
{
	int data;	/* ������� */
	int bf; /*  ����ƽ������ */ 
	struct BiTNode *lchild, *rchild;	/* ���Һ���ָ�� */
} BiTNode, *BiTree;
 
 
/* ����pΪ���Ķ������������������� */
/* ����֮��pָ���µ�������㣬����ת����֮ǰ���������ĸ���� */
void R_Rotate(BiTree *P)
{ 
	BiTree L;
	L=(*P)->lchild; /*  Lָ��P������������� */ 
	(*P)->lchild=L->rchild; /*  L���������ҽ�ΪP�������� */ 
	L->rchild=(*P);
	*P=L; /*  Pָ���µĸ���� */ 
}
 
/* ����PΪ���Ķ������������������� */
/* ����֮��Pָ���µ�������㣬����ת����֮ǰ���������ĸ����0  */
void L_Rotate(BiTree *P)
{ 
	BiTree R;
	R=(*P)->rchild; /*  Rָ��P������������� */ 
	(*P)->rchild=R->lchild; /* R���������ҽ�ΪP�������� */ 
	R->lchild=(*P);
	*P=R; /*  Pָ���µĸ���� */ 
}
 
#define LH +1 /*  ��� */ 
#define EH 0  /*  �ȸ� */ 
#define RH -1 /*  �Ҹ� */ 
 
/*  ����ָ��T��ָ���Ϊ���Ķ���������ƽ����ת���� */
/*  ���㷨����ʱ��ָ��Tָ���µĸ���� */
void LeftBalance(BiTree *T)
{ 
	BiTree L,Lr;
	L=(*T)->lchild; /*  Lָ��T������������� */ 
	switch(L->bf)
	{ /*  ���T����������ƽ��ȣ�������Ӧƽ�⴦�� */ 
		 case LH: /*  �½�������T�����ӵ��������ϣ�Ҫ������������ */ 
			(*T)->bf=L->bf=EH;
			R_Rotate(T);
			break;
		 case RH: /*  �½�������T�����ӵ��������ϣ�Ҫ��˫������ */ 
			Lr=L->rchild; /*  Lrָ��T�����ӵ��������� */ 
			switch(Lr->bf)
			{ /*  �޸�T�������ӵ�ƽ������ */ 
				case LH: (*T)->bf=RH;
						 L->bf=EH;
						 break;
				case EH: (*T)->bf=L->bf=EH;
						 break;
				case RH: (*T)->bf=EH;
						 L->bf=LH;
						 break;
			}
			Lr->bf=EH;
			L_Rotate(&(*T)->lchild); /*  ��T��������������ƽ�⴦�� */ 
			R_Rotate(T); /*  ��T������ƽ�⴦�� */ 
	}
}
 
/*  ����ָ��T��ָ���Ϊ���Ķ���������ƽ����ת���� */ 
/*  ���㷨����ʱ��ָ��Tָ���µĸ���� */ 
void RightBalance(BiTree *T)
{ 
	BiTree R,Rl;
	R=(*T)->rchild; /*  Rָ��T������������� */ 
	switch(R->bf)
	{ /*  ���T����������ƽ��ȣ�������Ӧƽ�⴦�� */ 
	 case RH: /*  �½�������T���Һ��ӵ��������ϣ�Ҫ������������ */ 
			  (*T)->bf=R->bf=EH;
			  L_Rotate(T);
			  break;
	 case LH: /*  �½�������T���Һ��ӵ��������ϣ�Ҫ��˫������ */ 
			  Rl=R->lchild; /*  Rlָ��T���Һ��ӵ��������� */ 
			  switch(Rl->bf)
			  { /*  �޸�T�����Һ��ӵ�ƽ������ */ 
				case RH: (*T)->bf=LH;
						 R->bf=EH;
						 break;
				case EH: (*T)->bf=R->bf=EH;
						 break;
				case LH: (*T)->bf=EH;
						 R->bf=RH;
						 break;
			  }
			  Rl->bf=EH;
			  R_Rotate(&(*T)->rchild); /*  ��T��������������ƽ�⴦�� */ 
			  L_Rotate(T); /*  ��T������ƽ�⴦�� */ 
	}
}
 
/*  ����ƽ��Ķ���������T�в����ں�e����ͬ�ؼ��ֵĽ�㣬�����һ�� */ 
/*  ����Ԫ��Ϊe���½�㣬������1�����򷵻�0����������ʹ���������� */ 
/*  ʧȥƽ�⣬����ƽ����ת������������taller��ӳT������� */
Status InsertAVL(BiTree *T,int e,Status *taller)
{  
	if(!*T)
	{ /*  �����½�㣬�������ߡ�����tallerΪTRUE */ 
		 *T=(BiTree)malloc(sizeof(BiTNode));
		 (*T)->data=e; (*T)->lchild=(*T)->rchild=NULL; (*T)->bf=EH;
		 *taller=TRUE;
	}
	else
	{
		if (e==(*T)->data)
		{ /*  �����Ѵ��ں�e����ͬ�ؼ��ֵĽ�����ٲ��� */ 
			*taller=FALSE; return FALSE;
		}
		if (e<(*T)->data)
		{ /*  Ӧ������T���������н������� */ 
			if(!InsertAVL(&(*T)->lchild,e,taller)) /*  δ���� */ 
				return FALSE;
			if(*taller) /*   �Ѳ��뵽T�����������������������ߡ� */ 
				switch((*T)->bf) /*  ���T��ƽ��� */ 
				{
					case LH: /*  ԭ�����������������ߣ���Ҫ����ƽ�⴦�� */ 
							LeftBalance(T);	*taller=FALSE; break;
					case EH: /*  ԭ�����������ȸߣ��������������߶�ʹ������ */ 
							(*T)->bf=LH; *taller=TRUE; break;
					case RH: /*  ԭ�����������������ߣ������������ȸ� */  
							(*T)->bf=EH; *taller=FALSE; break;
				}
		}
		else
		{ /*  Ӧ������T���������н������� */ 
			if(!InsertAVL(&(*T)->rchild,e,taller)) /*  δ���� */ 
				return FALSE;
			if(*taller) /*  �Ѳ��뵽T���������������������ߡ� */ 
				switch((*T)->bf) /*  ���T��ƽ��� */ 
				{
					case LH: /*  ԭ�����������������ߣ������������ȸ� */ 
							(*T)->bf=EH; *taller=FALSE;	break;
					case EH: /*  ԭ�����������ȸߣ��������������߶�ʹ������  */
							(*T)->bf=RH; *taller=TRUE; break;
					case RH: /*  ԭ�����������������ߣ���Ҫ����ƽ�⴦�� */ 
							RightBalance(T); *taller=FALSE; break;
				}
		}
	}
	return TRUE;
}
 
int main(void)
{    
	int i;
	int a[10]={3,2,1,4,5,6,7,10,9,8};
	BiTree T=NULL;
	Status taller;
	for(i=0;i<10;i++)
	{
		InsertAVL(&T,a[i],&taller);
	}
	printf("����������ϵ���ٲ鿴ƽ��������ṹ");
	return 0;
}
//04B��_BTree
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"
 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
 
#define MAXSIZE 100 /* �洢�ռ��ʼ������ */
 
#define m 3 /*  B���Ľף�����Ϊ3 */ 
#define N 17 /*  ����Ԫ�ظ��� */ 
#define MAX 5 /*  �ַ�����󳤶�+1  */
 
typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */ 
 
typedef struct BTNode
{
	int keynum; /*  ����йؼ��ָ����������Ĵ�С */ 
	struct BTNode *parent; /*  ָ��˫�׽�� */ 
	struct Node /*  ����������� */ 
	{
		 int key; /*  �ؼ������� */ 
		 struct BTNode *ptr; /*  ����ָ������ */ 
		 int recptr; /*  ��¼ָ������ */ 
	}node[m+1]; /*  key,recptr��0�ŵ�Ԫδ�� */ 
}BTNode,*BTree; /*  B������B�������� */ 
 
typedef struct
{
	BTNode *pt; /*  ָ���ҵ��Ľ�� */ 
	int i; /*  1..m���ڽ���еĹؼ������ */ 
	int tag; /*  1:���ҳɹ���O:����ʧ�� */ 
}Result; /*  B���Ĳ��ҽ������ */ 
 
/*  ��p->node[1..keynum].key�в���i,ʹ��p->node[i].key��K��p->node[i+1].key */ 
int Search(BTree p, int K)
{ 
	int i=0,j;
	for(j=1;j<=p->keynum;j++)
	 if(p->node[j].key<=K)
	   i=j;
	return i;
}
 
/*  ��m��B��T�ϲ��ҹؼ���K�����ؽ��(pt,i,tag)�������ҳɹ���������ֵ */ 
/*  tag=1��ָ��pt��ָ����е�i���ؼ��ֵ���K����������ֵtag=0������K��  */
/*  �ؼ���Ӧ������ָ��Pt��ָ����е�i�͵�i+1���ؼ���֮�䡣 */
Result SearchBTree(BTree T, int K)
{ 
	BTree p=T,q=NULL; /*  ��ʼ����pָ������㣬qָ��p��˫��  */
	Status found=FALSE;
	int i=0;
	Result r;
	while(p&&!found)
	{
	 i=Search(p,K); /*  p->node[i].key��K<p->node[i+1].key  */
	 if(i>0&&p->node[i].key==K) /*  �ҵ�����ؼ��� */ 
	   found=TRUE;
	 else
	 {
	   q=p;
	   p=p->node[i].ptr;
	 }
	}
	r.i=i;
	if(found) /*  ���ҳɹ�  */
	{
	 r.pt=p;
	 r.tag=1;
	}
	else /*   ���Ҳ��ɹ�������K�Ĳ���λ����Ϣ */ 
	{
	 r.pt=q;
	 r.tag=0;
	}
	return r;
}
 
/* ��r->key��r��ap�ֱ���뵽q->key[i+1]��q->recptr[i+1]��q->ptr[i+1]�� */ 
void Insert(BTree *q,int i,int key,BTree ap)
{ 
	int j;
	for(j=(*q)->keynum;j>i;j--) /*  �ճ�(*q)->node[i+1]  */
		(*q)->node[j+1]=(*q)->node[j];
	(*q)->node[i+1].key=key;
	(*q)->node[i+1].ptr=ap;
	(*q)->node[i+1].recptr=key;
	(*q)->keynum++;
}
 
/* �����q���ѳ�������㣬ǰһ�뱣������һ�������������ap */ 
void split(BTree *q,BTree *ap)
{ 
	int i,s=(m+1)/2;
	*ap=(BTree)malloc(sizeof(BTNode)); /*  �����½��ap */ 
	(*ap)->node[0].ptr=(*q)->node[s].ptr; /*  ��һ������ap */ 
	for(i=s+1;i<=m;i++)
	{
		 (*ap)->node[i-s]=(*q)->node[i];
		 if((*ap)->node[i-s].ptr)
			(*ap)->node[i-s].ptr->parent=*ap;
	}
	(*ap)->keynum=m-s;
	(*ap)->parent=(*q)->parent;
	(*q)->keynum=s-1; /*  q��ǰһ�뱣�����޸�keynum */ 
}
 
/* ���ɺ���Ϣ(T,r,ap)���µĸ����&T��ԭT��apΪ����ָ�� */ 
void NewRoot(BTree *T,int key,BTree ap)
{ 
	BTree p;
	p=(BTree)malloc(sizeof(BTNode));
	p->node[0].ptr=*T;
	*T=p;
	if((*T)->node[0].ptr)
		(*T)->node[0].ptr->parent=*T;
	(*T)->parent=NULL;
	(*T)->keynum=1;
	(*T)->node[1].key=key;
	(*T)->node[1].recptr=key;
	(*T)->node[1].ptr=ap;
	if((*T)->node[1].ptr)
		(*T)->node[1].ptr->parent=*T;
}
 
/*  ��m��B��T�Ͻ��*q��key[i]��key[i+1]֮�����ؼ���K��ָ��r�������� */ 
/*  ������,����˫�������б�Ҫ�Ľ����ѵ���,ʹT����m��B���� */
void InsertBTree(BTree *T,int key,BTree q,int i)
{ 
	BTree ap=NULL;
	Status finished=FALSE;
	int s;
	int rx;
	rx=key;
	while(q&&!finished)
	{
		Insert(&q,i,rx,ap); /*  ��r->key��r��ap�ֱ���뵽q->key[i+1]��q->recptr[i+1]��q->ptr[i+1]��  */
		if(q->keynum<m)
			finished=TRUE; /*  ������� */ 
		else
		{ /*  ���ѽ��*q */ 
			s=(m+1)/2;
			rx=q->node[s].recptr;
			split(&q,&ap); /*  ��q->key[s+1..m],q->ptr[s..m]��q->recptr[s+1..m]�����½��*ap  */
			q=q->parent;
			if(q)
				i=Search(q,key); /*  ��˫�׽��*q�в���rx->key�Ĳ���λ��  */
		}
	}
	if(!finished) /*  T�ǿ���(����q��ֵΪNULL)�������ѷ���Ϊ���*q��*ap */ 
		NewRoot(T,rx,ap); /*  ���ɺ���Ϣ(T,rx,ap)���µĸ����*T��ԭT��apΪ����ָ�� */ 
}
 
 
void print(BTNode c,int i) /*  TraverseDSTable()���õĺ���  */
{
	printf("(%d)",c.node[i].key);
}
 
int main()
{
	int r[N]={22,16,41,58,8,11,12,16,17,22,23,31,41,52,58,59,61};
	BTree T=NULL;
	Result s;
	int i;
	for(i=0;i<N;i++)
	{
		s=SearchBTree(T,r[i]);
		if(!s.tag)
			InsertBTree(&T,r[i],s.pt,s.i);
	}
	printf("\n����������Ҽ�¼�Ĺؼ���: ");
	scanf("%d",&i);
	s=SearchBTree(T,i);
	if(s.tag)
		print(*(s.pt),s.i);
	else
		printf("û�ҵ�");
	printf("\n");
 
	return 0;
}
//05ɢ�б�_HashTable
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"
 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
 
#define MAXSIZE 100 /* �洢�ռ��ʼ������ */
 
#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12 /* ����ɢ�б�Ϊ����ĳ��� */
#define NULLKEY -32768 
 
typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */ 
 
typedef struct
{
   int *elem; /* ����Ԫ�ش洢��ַ����̬�������� */
   int count; /*  ��ǰ����Ԫ�ظ��� */
}HashTable;
 
int m=0; /* ɢ�б����ȫ�ֱ��� */
 
/* ��ʼ��ɢ�б� */
Status InitHashTable(HashTable *H)
{
	int i;
	m=HASHSIZE;
	H->count=m;
	H->elem=(int *)malloc(m*sizeof(int));
	for(i=0;i<m;i++)
		H->elem[i]=NULLKEY; 
	return OK;
}
 
/* ɢ�к��� */
int Hash(int key)
{
	return key % m; /* ���������� */
}
 
/* ����ؼ��ֽ�ɢ�б� */
void InsertHash(HashTable *H,int key)
{
	int addr = Hash(key); /* ��ɢ�е�ַ */
	while (H->elem[addr] != NULLKEY) /* �����Ϊ�գ����ͻ */
	{
		addr = (addr+1) % m; /* ���Ŷ�ַ��������̽�� */
	}
	H->elem[addr] = key; /* ֱ���п�λ�����ؼ��� */
}
 
/* ɢ�б���ҹؼ��� */
Status SearchHash(HashTable H,int key,int *addr)
{
	*addr = Hash(key);  /* ��ɢ�е�ַ */
	while(H.elem[*addr] != key) /* �����Ϊ�գ����ͻ */
	{
		*addr = (*addr+1) % m; /* ���Ŷ�ַ��������̽�� */
		if (H.elem[*addr] == NULLKEY || *addr == Hash(key)) /* ���ѭ���ص�ԭ�� */
			return UNSUCCESS;	/* ��˵���ؼ��ֲ����� */
	}
	return SUCCESS;
}
 
int main()
{
	int arr[HASHSIZE]={12,67,56,16,25,37,22,29,15,47,48,34};
	int i,p,key,result;
	HashTable H;
 
	key=39;
 
	InitHashTable(&H);
	for(i=0;i<m;i++)
		 InsertHash(&H,arr[i]);
	
	result=SearchHash(H,key,&p);
	if (result)
		printf("���� %d �ĵ�ַΪ��%d \n",key,p);
	else
		printf("���� %d ʧ�ܡ�\n",key);
 
	for(i=0;i<m;i++)
	{
		key=arr[i];
		SearchHash(H,key,&p);
		printf("���� %d �ĵ�ַΪ��%d \n",key,p);
	}
 
	return 0;
}
��9�¡�����
//01����_Sort
#include <stdio.h>    
#include <string.h>
#include <ctype.h>      
#include <stdlib.h>   
#include <io.h>  
#include <math.h>  
#include <time.h>
 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
 
#define MAX_LENGTH_INSERT_SORT 7 /* ���ڿ�������ʱ�ж��Ƿ�ѡ�ò���������ֵ */
 
typedef int Status; 
 
 
#define MAXSIZE 10000  /* ����Ҫ��������������ֵ���ɸ�����Ҫ�޸� */
typedef struct
{
	int r[MAXSIZE+1];	/* ���ڴ洢Ҫ�������飬r[0]�����ڱ�����ʱ���� */
	int length;			/* ���ڼ�¼˳���ĳ��� */
}SqList;
 
/* ����L������r���±�Ϊi��j��ֵ */
void swap(SqList *L,int i,int j) 
{ 
	int temp=L->r[i]; 
	L->r[i]=L->r[j]; 
	L->r[j]=temp; 
}
 
void print(SqList L)
{
	int i;
	for(i=1;i<L.length;i++)
		printf("%d,",L.r[i]);
	printf("%d",L.r[i]);
	printf("\n");
}
 
/* ��˳���L����������ð����������棩 */
void BubbleSort0(SqList *L)
{ 
	int i,j;
	for(i=1;i<L->length;i++)
	{
		for(j=i+1;j<=L->length;j++)
		{
			if(L->r[i]>L->r[j])
			{
				 swap(L,i,j);/* ����L->r[i]��L->r[j]��ֵ */
			}
		}
	}
}
 
/* ��˳���L��ð������ */
void BubbleSort(SqList *L)
{ 
	int i,j;
	for(i=1;i<L->length;i++)
	{
		for(j=L->length-1;j>=i;j--)  /* ע��j�ǴӺ���ǰѭ�� */
		{
			if(L->r[j]>L->r[j+1]) /* ��ǰ�ߴ��ں��ߣ�ע����������һ�㷨�Ĳ��죩*/
			{
				 swap(L,j,j+1);/* ����L->r[j]��L->r[j+1]��ֵ */
			}
		}
	}
}
 
/* ��˳���L���Ľ�ð���㷨 */
void BubbleSort2(SqList *L)
{ 
	int i,j;
	Status flag=TRUE;			/* flag������Ϊ��� */
	for(i=1;i<L->length && flag;i++) /* ��flagΪtrue˵���й����ݽ���������ֹͣѭ�� */
	{
		flag=FALSE;				/* ��ʼΪFalse */
		for(j=L->length-1;j>=i;j--)
		{
			if(L->r[j]>L->r[j+1])
			{
				 swap(L,j,j+1);	/* ����L->r[j]��L->r[j+1]��ֵ */
				 flag=TRUE;		/* ��������ݽ�������flagΪtrue */
			}
		}
	}
}
 
 
/* ��˳���L����ѡ������ */
void SelectSort(SqList *L)
{
	int i,j,min;
	for(i=1;i<L->length;i++)
	{ 
		min = i;						/* ����ǰ�±궨��Ϊ��Сֵ�±� */
		for (j = i+1;j<=L->length;j++)/* ѭ��֮������� */
        {
			if (L->r[min]>L->r[j])	/* �����С�ڵ�ǰ��Сֵ�Ĺؼ��� */
                min = j;				/* ���˹ؼ��ֵ��±긳ֵ��min */
        }
		if(i!=min)						/* ��min������i��˵���ҵ���Сֵ������ */
			swap(L,i,min);				/* ����L->r[i]��L->r[min]��ֵ */
	}
}
 
/* ��˳���L��ֱ�Ӳ������� */
void InsertSort(SqList *L)
{ 
	int i,j;
	for(i=2;i<=L->length;i++)
	{
		if (L->r[i]<L->r[i-1]) /* �轫L->r[i]���������ӱ� */
		{
			L->r[0]=L->r[i]; /* �����ڱ� */
			for(j=i-1;L->r[j]>L->r[0];j--)
				L->r[j+1]=L->r[j]; /* ��¼���� */
			L->r[j+1]=L->r[0]; /* ���뵽��ȷλ�� */
		}
	}
}
 
/* ��˳���L��ϣ������ */
void ShellSort(SqList *L)
{
	int i,j,k=0;
	int increment=L->length;
	do
	{
		increment=increment/3+1;/* �������� */
		for(i=increment+1;i<=L->length;i++)
		{
			if (L->r[i]<L->r[i-increment])/*  �轫L->r[i]�������������ӱ� */ 
			{ 
				L->r[0]=L->r[i]; /*  �ݴ���L->r[0] */
				for(j=i-increment;j>0 && L->r[0]<L->r[j];j-=increment)
					L->r[j+increment]=L->r[j]; /*  ��¼���ƣ����Ҳ���λ�� */
				L->r[j+increment]=L->r[0]; /*  ���� */
			}
		}
		printf("	��%d��������: ",++k);
		print(*L);
	}
	while(increment>1);
 
}
 
 
/* ������********************************** */
 
/* ��֪L->r[s..m]�м�¼�Ĺؼ��ֳ�L->r[s]֮�������ѵĶ��壬 */
/* ����������L->r[s]�Ĺؼ���,ʹL->r[s..m]��Ϊһ���󶥶� */
void HeapAdjust(SqList *L,int s,int m)
{ 
	int temp,j;
	temp=L->r[s];
	for(j=2*s;j<=m;j*=2) /* �عؼ��ֽϴ�ĺ��ӽ������ɸѡ */
	{
		if(j<m && L->r[j]<L->r[j+1])
			++j; /* jΪ�ؼ����нϴ�ļ�¼���±� */
		if(temp>=L->r[j])
			break; /* rcӦ������λ��s�� */
		L->r[s]=L->r[j];
		s=j;
	}
	L->r[s]=temp; /* ���� */
}
 
/*  ��˳���L���ж����� */
void HeapSort(SqList *L)
{
	int i;
	for(i=L->length/2;i>0;i--) /*  ��L�е�r������һ������� */
		 HeapAdjust(L,i,L->length);
 
	for(i=L->length;i>1;i--)
	{ 
		 swap(L,1,i); /* ���Ѷ���¼�͵�ǰδ�����������е����һ����¼���� */
		 HeapAdjust(L,1,i-1); /*  ��L->r[1..i-1]���µ���Ϊ����� */
	}
}
 
/* **************************************** */
 
 
/* �鲢����********************************** */
 
/* �������SR[i..m]��SR[m+1..n]�鲢Ϊ�����TR[i..n] */
void Merge(int SR[],int TR[],int i,int m,int n)
{
	int j,k,l;
	for(j=m+1,k=i;i<=m && j<=n;k++)	/* ��SR�м�¼��С����ز���TR */
	{
		if (SR[i]<SR[j])
			TR[k]=SR[i++];
		else
			TR[k]=SR[j++];
	}
	if(i<=m)
	{
		for(l=0;l<=m-i;l++)
			TR[k+l]=SR[i+l];		/* ��ʣ���SR[i..m]���Ƶ�TR */
	}
	if(j<=n)
	{
		for(l=0;l<=n-j;l++)
			TR[k+l]=SR[j+l];		/* ��ʣ���SR[j..n]���Ƶ�TR */
	}
}
 
 
/* �ݹ鷨 */
/* ��SR[s..t]�鲢����ΪTR1[s..t] */
void MSort(int SR[],int TR1[],int s, int t)
{
	int m;
	int TR2[MAXSIZE+1];
	if(s==t)
		TR1[s]=SR[s];
	else
	{
		m=(s+t)/2;				/* ��SR[s..t]ƽ��ΪSR[s..m]��SR[m+1..t] */
		MSort(SR,TR2,s,m);		/* �ݹ�ؽ�SR[s..m]�鲢Ϊ�����TR2[s..m] */
		MSort(SR,TR2,m+1,t);	/* �ݹ�ؽ�SR[m+1..t]�鲢Ϊ�����TR2[m+1..t] */
		Merge(TR2,TR1,s,m,t);	/* ��TR2[s..m]��TR2[m+1..t]�鲢��TR1[s..t] */
	}
}
 
/* ��˳���L���鲢���� */
void MergeSort(SqList *L)
{ 
 	MSort(L->r,L->r,1,L->length);
}
 
/* �ǵݹ鷨 */
/* ��SR[]�����ڳ���Ϊs�������������鲢��TR[] */
void MergePass(int SR[],int TR[],int s,int n)
{
	int i=1;
	int j;
	while(i <= n-2*s+1)
	{/* �����鲢 */
		Merge(SR,TR,i,i+s-1,i+2*s-1);
		i=i+2*s;        
	}
	if(i<n-s+1) /* �鲢����������� */
		Merge(SR,TR,i,i+s-1,n);
	else /* �����ֻʣ�µ��������� */
		for(j =i;j <= n;j++)
			TR[j] = SR[j];
}
 
/* ��˳���L���鲢�ǵݹ����� */
void MergeSort2(SqList *L)
{
	int* TR=(int*)malloc(L->length * sizeof(int));/* �������ռ� */
    int k=1;
	while(k<L->length)
	{
		MergePass(L->r,TR,k,L->length);
		k=2*k;/* �����г��ȼӱ� */
		MergePass(TR,L->r,k,L->length);
		k=2*k;/* �����г��ȼӱ� */       
	}
}
 
/* **************************************** */
 
/* ��������******************************** */
 
/* ����˳���L���ӱ�ļ�¼��ʹ�����¼��λ��������������λ�� */
/* ��ʱ����֮ǰ(��)�ļ�¼������(С)������ */
int Partition(SqList *L,int low,int high)
{ 
	int pivotkey;
 
	pivotkey=L->r[low]; /* ���ӱ�ĵ�һ����¼�������¼ */
	while(low<high) /*  �ӱ�����˽�������м�ɨ�� */
	{ 
		 while(low<high&&L->r[high]>=pivotkey)
			high--;
		 swap(L,low,high);/* ���������¼С�ļ�¼�������Ͷ� */
		 while(low<high&&L->r[low]<=pivotkey)
			low++;
		 swap(L,low,high);/* ���������¼��ļ�¼�������߶� */
	}
	return low; /* ������������λ�� */
}
 
/* ��˳���L�е�������L->r[low..high]���������� */
void QSort(SqList *L,int low,int high)
{ 
	int pivot;
	if(low<high)
	{
			pivot=Partition(L,low,high); /*  ��L->r[low..high]һ��Ϊ�����������ֵpivot */
			QSort(L,low,pivot-1);		/*  �Ե��ӱ�ݹ����� */
			QSort(L,pivot+1,high);		/*  �Ը��ӱ�ݹ����� */
	}
}
 
/* ��˳���L���������� */
void QuickSort(SqList *L)
{ 
	QSort(L,1,L->length);
}
 
/* **************************************** */
 
/* �Ľ����������******************************** */
 
/* ���������Ż��㷨 */
int Partition1(SqList *L,int low,int high)
{ 
	int pivotkey;
 
	int m = low + (high - low) / 2; /* ���������м��Ԫ�ص��±� */  
	if (L->r[low]>L->r[high])			
		swap(L,low,high);	/* ����������Ҷ����ݣ���֤��˽�С */
	if (L->r[m]>L->r[high])
		swap(L,high,m);		/* �����м����Ҷ����ݣ���֤�м��С */
	if (L->r[m]>L->r[low])
		swap(L,m,low);		/* �����м���������ݣ���֤��˽�С */
	
	pivotkey=L->r[low]; /* ���ӱ�ĵ�һ����¼�������¼ */
	L->r[0]=pivotkey;  /* ������ؼ��ֱ��ݵ�L->r[0] */
	while(low<high) /*  �ӱ�����˽�������м�ɨ�� */
	{ 
		 while(low<high&&L->r[high]>=pivotkey)
			high--;
		 L->r[low]=L->r[high];
		 while(low<high&&L->r[low]<=pivotkey)
			low++;
		 L->r[high]=L->r[low];
	}
	L->r[low]=L->r[0];
	return low; /* ������������λ�� */
}
 
void QSort1(SqList *L,int low,int high)
{ 
	int pivot;
	if((high-low)>MAX_LENGTH_INSERT_SORT)
	{
		while(low<high)
		{
			pivot=Partition1(L,low,high); /*  ��L->r[low..high]һ��Ϊ�����������ֵpivot */
			QSort1(L,low,pivot-1);		/*  �Ե��ӱ�ݹ����� */
			/* QSort(L,pivot+1,high);		/*  �Ը��ӱ�ݹ����� */
			low=pivot+1;	/* β�ݹ� */
		}
	}
	else
		InsertSort(L);
}
 
/* ��˳���L���������� */
void QuickSort1(SqList *L)
{ 
	QSort1(L,1,L->length);
}
 
/* **************************************** */
#define N 9
int main()
{
   int i;
   
   /* int d[N]={9,1,5,8,3,7,4,6,2}; */
   int d[N]={50,10,90,30,70,40,80,60,20};
   /* int d[N]={9,8,7,6,5,4,3,2,1}; */
 
   SqList l0,l1,l2,l3,l4,l5,l6,l7,l8,l9,l10;
   
   for(i=0;i<N;i++)
     l0.r[i+1]=d[i];
   l0.length=N;
   l1=l2=l3=l4=l5=l6=l7=l8=l9=l10=l0;
   printf("����ǰ:\n");
   print(l0);
 
   printf("����ð������:\n");
   BubbleSort0(&l0);
   print(l0);
   
   printf("ð������:\n");
   BubbleSort(&l1);
   print(l1);
   
   printf("�Ľ�ð������:\n");
   BubbleSort2(&l2);
   print(l2);
   
   printf("ѡ������:\n");
   SelectSort(&l3);
   print(l3);
   
   printf("ֱ�Ӳ�������:\n");
   InsertSort(&l4);
   print(l4);
 
   printf("ϣ������:\n");
   ShellSort(&l5);
   print(l5);
	
   printf("������:\n");
   HeapSort(&l6);
   print(l6);
 
   printf("�鲢���򣨵ݹ飩:\n");
   MergeSort(&l7);
   print(l7);
 
   printf("�鲢���򣨷ǵݹ飩:\n");
   MergeSort2(&l8);
   print(l8);
 
   printf("��������:\n");
   QuickSort(&l9);
   print(l9);
 
   printf("�Ľ���������:\n");
   QuickSort1(&l10);
   print(l10);
 
 
    /*����������*/
	/* 
	srand(time(0));  
	int Max=10000;
	int d[10000];
	int i;
	SqList l0;
	for(i=0;i<Max;i++)
		d[i]=rand()%Max+1;
	for(i=0;i<Max;i++)
		l0.r[i+1]=d[i];
	l0.length=Max;
	MergeSort(l0);
	print(l0);
	*/
	return 0;
}