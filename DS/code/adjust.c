#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct gate{
    int id;
    int data;
}gate;

int tree[500][3];
gate port[100];

int cmp(const void *a,const void *b){
    gate *p,*q;
    p=(gate *)a;
    q=(gate *)b;
    if(p->data != q->data) return q->data-p->data;
    else return p->id-q->id;
}


int main(){
    char x[100]={0};

    int line1[300]={0};
    int line2[300]={0};
    int gatecnt=0;
    int firstroot=0;
    int firstflag=1;
    int head1=0,tail1=0,tail2=0;
    while(gets(x),x[0]!='-')
    {
        int root;
        int flag=0,j=0,temp=0;
        int cnt=0;
        while(x[j]!='-')
        {
            if(x[j]>='0'&&x[j]<='9')
            {
                temp=temp*10+(x[j]-'0');
            }
            else
            {
                if(firstflag)
                {
                    firstroot=temp;
                    firstflag=0;
                }
                if(flag==0) root=temp;
                else
                {
                    if(temp>=1&&temp<=99) gatecnt++;
                    tree[root][cnt++]=temp;
                }
                flag=1;
                temp=0;
            }
            j++;
        }
    }


    // printf("%d",gatecnt);
    for(int i=0;i<gatecnt;i++)
    {
        scanf("%d%d",&port[i].id,&port[i].data);
    }

    qsort(port,gatecnt,sizeof(gate),cmp);
    
    line1[tail1++]=firstroot;
    while(tail1!=head1)
    {
        for(int i=0;i<3;i++)
        {
            if(tree[line1[head1]][i]>=100) line1[tail1++]=tree[line1[head1]][i];
            if(tree[line1[head1]][i]>=1&&tree[line1[head1]][i]<=99) line2[tail2++]=tree[line1[head1]][i];
        }
        head1++;
    }
    // for(;head2<tail2;head2++)
    // {
    //     printf("%d ",line2[head2]);
    // }

    for(int i=0;i<tail2;i++){
        printf("%d->%d\n",port[i].id,line2[i]);
    }
    return 0;
}