#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int cnt=0;
typedef struct node{
    int data;
    struct node *lchild, *rchild;
    int count;
}node;

int max=0;
int maxans=0;
void postorder(node* p)
{
    if(p!=NULL)
    {
        if(p->count>max){
            max=p->count;
            maxans=p->data;
        }
        // printf("%d %d\n",p->data,p->count);
        postorder(p->lchild);
        postorder(p->rchild);
    }
}


node *insertBST(node *root, int data)
{
    if(root==NULL)
    {
        root = (node *)malloc(sizeof(node));
        root->data = data;
        root->lchild = NULL;
        root->rchild = NULL;
        root->count = 1;
    }
    else{
        cnt++;
        if(root->data < data)
        {

            root->rchild=insertBST(root->rchild,data);
        }
        else if(root->data > data)
        {
            root->lchild=insertBST(root->lchild,data);
        }
        else root->count++;
    }
    
    return root;
}

node* searchBST(node* p,int key)
{
    node* t=p;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        if(key==p->data) return NULL;
        if(key>p->data) p=p->rchild;
        else p=p->lchild;
    }
    return NULL;
}


int main()
{
    node *root=NULL;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    { 
        int temp;
        scanf("%d",&temp);
        root=insertBST(root,temp);
    }
    printf("%d\n",cnt);
    postorder(root);
    searchBST(root,maxans);
}
