#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


int data[100]; 
int top=-1;   

void push(int input)
{
	if(top==99) printf("error ");
	else
	{
		top++;
		data[top]=input;

	}
	return;
}

void pop()
{
	if(top==-1) printf("error ");
	else
	{
		printf("%d ",data[top]);
		top--;
	}
	return;
}

int main()
{
	int oper;
	while(scanf("%d",&oper),oper!=-1)
	{
		if(!oper)
		{
			pop();
			continue;
		}
		else
		{
			int input;
			scanf("%d",&input);
			push(input);
			continue;
		}
	}
//	for(int i=0;i<top;i++)
//	{
//		printf("%d ",data[i]);
//	}
	return 0;
}

