#ifndef _LIST_H_
#define _LIST_H_

#include<stdio.h>
#define ElemType int
#define MAXSIZE 100

typedef struct List
{
	ElemType data[MAXSIZE];
	int length;
}List;


void CreateList(List *L)
{
	scanf("%d",&L->length);
	for(int i=0;i<L->length;i++)
	{
		scanf("%d",&L->data[i]);
	}
}

void PrintList(List *L)
{
	for(int i=0;i<L->length-1;i++)
	{
		printf("%d ",L->data[i]);
	}
	printf("%d\n",L->data[L->length-1]);
}

bool GetElem(List *L,int i,ElemType *e)
{
	if(i<1||i>L->length) return 0;
	else
	{
		*e=L->data[i-1];
	}
	return 1;
}

int LocateElem(List *L,ElemType e)      //Ã¶¾Ù
{
	for(int i=0;i<L->length;i++)
	{
		if(e==L->data[i])
		{
			return i+1;
		}
	}
	return 0;
}

bool InsertElem(List *L,int i,ElemType e)
{
	if(i<1||i>L->length+1)
	{
		return 0;
	}
	else
	{
		for(int j=L->length;j>i-1;j--)
		{
			L->data[j]=L->data[j-1];
		}
		L->length++;
		L->data[i-1]=e;
		return 1;
	}
}

bool DeleteElem(List *L,int i)
{
	if(i<1||i>L->length)
	{
		return 0;
	}
	else
	{
		for(int j=i;j<L->length+1;j++)
		{
			L->data[j-1]=L->data[j];
		}
	}
	L->length--;
	return 1;
}

void DeleteList(List *L)
{
	for(int i=0;i<L->length;i++)
	{
		L->data[i]=0;
	}
	L->length=0;
}

void CopyList(List *source,List *destiny)
{
	destiny->length=source->length;
	for(int i=0;i<source->length;i++)
	{
		destiny->data[i]=source->data[i];
	}
}



#endif
