#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int Datatype;
struct node {
    Datatype data;
    struct node *lchild, *rchild;
};
typedef struct node BTNode, *BTNodeptr;
  
//������--��������  �ǵݹ�
void insert(BTNodeptr tree, int value)
{
    //����һ���ڵ㣬������ָ��ȫ��ָ��գ�����Ϊvalue
    BTNodeptr node=(BTNodeptr)malloc(sizeof(node));
    node->data = value;
    node->lchild = NULL;
    node->rchild = NULL;
  
    //�ж����ǲ��ǿ���������ǣ�ֱ��������ָ����һ����㼴��
    if (tree == NULL){
        tree = node;
        printf("xx");
    }
    else {//���ǿ���
        BTNodeptr temp = tree;//��������ʼ
        while (temp != NULL){
            if (value < temp->data){ //С�ھͽ������
                if (temp->lchild == NULL){
                    temp->lchild = node;
                    return;
                }
                else {//����������Ѱ
                    temp = temp->lchild;
                }
            } 
            else { //������Ҷ���
                if (temp->rchild == NULL){
                    temp->rchild = node;
                    return;
                }
                else {//����������Ѱ
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
            printf("%d",t->data);       /* ����tָ����  */
             preorder(t->lchild);
             preorder(t->rchild);
       }
}

void  inorder(BTNodeptr t)
{
      if(t!=NULL){
             inorder(t->lchild);
             printf("%d",t->data);       /* ����Tָ���  */
             inorder(t->rchild);
       }
       printf("11");
}

void  postorder(BTNodeptr t)
{
      if(t!=NULL){
             postorder(t->lchild);
             postorder(t->rchild);
             printf("%d",t->data);      /* ����Tָ���  */
      }
}


// //���������������
// void  preorder(BTNodeptr t, Datatype item)
// {
//     if(t!=NULL){
//             push(t);      
//             if(item == t->data) 
//                 // ����ջ������Ԫ�أ� 
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
 }     //�������ĸ߶�



int main(){
    BTNodeptr tree=NULL;
    int n;
    scanf("%d",&n);
  
    //����n���������������
    for (int i = 0; i < n; i++){
        int temp;
        scanf("%d",&temp);
        insert(tree,temp);
    }
    printf("%d",tree->data);
    inorder(tree);//�������
  
    return 0;
}