#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct node
{
	int num;
	struct node* next;
}node;


int main()
{
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	
	node *chain,*ptr,*head;
	chain=(node*)malloc(sizeof(node));
	head=chain;
	chain->num=1;
	for(int i=1;i<n;i++)
	{
		ptr=(node*)malloc(sizeof(node));
		ptr->num=i+1;
		chain->next=ptr;
		chain=ptr;
	}
	ptr->next=head;
	ptr=head;
	int out=0;
	for(int i=1;i<q;i++)
	{
		ptr=ptr->next;
	}
	int cnt=0;
	while(out<n)
	{
		cnt++;
		if(cnt==m-1)
		{
			out++;
			ptr->next=ptr->next->next;
		}
		ptr=ptr->next;
		cnt%=m-1;
	}
	printf("%d",ptr->num);
	return 0;
}