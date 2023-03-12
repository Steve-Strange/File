#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    int place;
    int size;
    struct node *next;
    struct node *prev;
}node;


int main()
{
    int n;
    scanf("%d", &n);

    struct node *p,*q,*head;
    p=(node*)malloc(sizeof(node));
    head=p;
    for(int i=0; i<n-1; i++)
    {
        scanf("%d", &p->place);
        scanf("%d", &p->size);
        q=(node*)malloc(sizeof(node));
        p->next=q;
        p=q;
    }
    scanf("%d", &p->place);
    scanf("%d", &p->size);
    q=(node*)malloc(sizeof(node));
    p->next=head;
    p=head;

    for(int i=0; i<n; i++)
    {
        q=p->next;
        q->prev=p;
        p=q;
    }

    int need=0;
    while(scanf("%d",&need),need!=-1)
    {
        int cnt=0;
        while(need>p->size&&cnt<n)
        {
            cnt++;
            p=p->next;
        }

        // printf("%d %d\n",n,cnt);
        if(cnt!=n)
        {
            p->size-=need;
            if(p->size==0)
            {
                p->prev->next=p->next;
                p->next->prev=p->prev;
                q=p;
                p=p->next;
                free(q);
                n--;
            }
        }
    }
    
    
    for(int i=0;i<n;i++)
    {
        printf("%d %d\n", p->size,p->place);
        p=p->next;
    }
}