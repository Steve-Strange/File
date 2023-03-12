#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int Datatype;
struct node {
    Datatype data;
    struct node *lchild, *rchild;
};
typedef struct node BTNode, *BTNodeptr;
  
//创建树--插入数据  非递归
void insert(BTNodeptr tree, int value)
{
    //创建一个节点，让左右指针全部指向空，数据为value
    BTNodeptr node=(BTNodeptr)malloc(sizeof(node));
    node->data = value;
    node->lchild = NULL;
    node->rchild = NULL;
  
    //判断树是不是空树，如果是，直接让树根指向这一个结点即可
    if (tree == NULL){
        tree = node;
        printf("xx");
    }
    else {//不是空树
        BTNodeptr temp = tree;//从树根开始
        while (temp != NULL){
            if (value < temp->data){ //小于就进左儿子
                if (temp->lchild == NULL){
                    temp->lchild = node;
                    return;
                }
                else {//继续往下搜寻
                    temp = temp->lchild;
                }
            } 
            else { //否则进右儿子
                if (temp->rchild == NULL){
                    temp->rchild = node;
                    return;
                }
                else {//继续往下搜寻
                    temp = temp->rchild;
                }
            }
        }
    }
    return;
}
  


void  preorder(BTNodeptr t)
{
      if(t!=NULL){
            printf("%d",t->data);       /* 访问t指向结点  */
             preorder(t->lchild);
             preorder(t->rchild);
       }
}

void  inorder(BTNodeptr t)
{
      if(t!=NULL){
             inorder(t->lchild);
             printf("%d",t->data);       /* 访问T指结点  */
             inorder(t->rchild);
       }
       printf("11");
}

void  postorder(BTNodeptr t)
{
      if(t!=NULL){
             postorder(t->lchild);
             postorder(t->rchild);
             printf("%d",t->data);      /* 访问T指结点  */
      }
}


// //输出整个祖先序列
// void  preorder(BTNodeptr t, Datatype item)
// {
//     if(t!=NULL){
//             push(t);      
//             if(item == t->data) 
//                 // 弹出栈中所有元素； 
//             preorder(t->lchild,item);
//             preorder(t->rchild,item);
//             pop();
//     }
// }



int max(int x,int y) 
{ if(x >y)  return x; else return y; }

int  heightTree(BTNodeptr  p)
{
    if(p == NULL)
        return 0;
    else
        return 1 + max(heightTree(p->lchild), heightTree(p->rchild));
 }     //计算树的高度



int main(){
    BTNodeptr tree=NULL;
    int n;
    scanf("%d",&n);
  
    //输入n个数并创建这个树
    for (int i = 0; i < n; i++){
        int temp;
        scanf("%d",&temp);
        insert(tree,temp);
    }
    printf("%d",tree->data);
    inorder(tree);//中序遍历
  
    return 0;
}