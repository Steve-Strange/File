#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef char Datatype;
struct node{
    char data[100];
    int cnt;
    struct node *lchild, *rchild;
};
typedef struct node BTNode, *BTNodeptr;

//插入   递归！
BTNodeptr  insertBST(BTNodeptr p, char* item)
{
    if(p == NULL)
    {
        p = (BTNodeptr)malloc(sizeof(BTNode));
        strcpy(p->data, item);
        p->lchild = p->rchild = NULL;
        p->cnt=0;
    } 
    else if(strcmp(p->data,item)>0)
        p->lchild = insertBST(p->lchild,item);
    else if(strcmp(p->data,item)<0)
        p->rchild = insertBST(p->rchild,item);
    else p->cnt++;
    return p;
} 

void inorder(BTNodeptr node){
    if (node != NULL)
    {
        inorder(node->lchild);
        printf("%s %d\n",node->data,node->cnt+1);
        inorder(node->rchild);
    }
}

int main()
{
    char x[1000000]={0};
    FILE *in=fopen("article.txt","r");
    fread(x,1,1000000,in);
    int len=strlen(x);
    BTNodeptr root=NULL;
    for(int i=0;i<len;i++)
    {
        char temp[100]={0};
        int p=0;
        while(isalpha(x[i+p]))
        {
            temp[p]=tolower(x[i+p]);
            p++;
        }
        i+=p;
        if(p) root = insertBST(root,temp);
    }
    if(root->data) printf("%s",root->data);
    if(root->rchild->data) printf(" %s",root->rchild->data);
    if(root->rchild->rchild->data) printf(" %s",root->rchild->rchild->data);
    printf("\n");
    inorder(root);

    return 0;
}



// //查找  非递归
// BTNodeptr searchBST(BTNodeptr t,Datatype key)
// {
//       BTNodeptr  p=t;
//       while(p!=NULL){
//              if(key == p->data)  
//                   return p;               /* 查找成功 */
//              if(key > p->data)
//                   p=p->rchild;        /* 将p移到右子树的根结点 */
//              else
//                   p=p->lchild;         /* 将p移到左子树的根结点 */
//        }
//        return NULL;                 /* 查找失败 */
// }


// //查找 递归
// BTNodeptr  searchBST( BTNodeptr t, Datatype key )
// {
//       if(t!=NULL){
//             if(key == t->data) 
//                   return t;                         /* 查找成功  */ 
//             if(key > t->data)                   /* 查找T的右子树  */
//                   return searchBST(t->rchild, key);               
//             else
//                   return searchBST(t->lchild, key); 
//        }                                                  /* 查找T的左子树 */
//        else
//               return NULL;                    /* 查找失败  */
// }