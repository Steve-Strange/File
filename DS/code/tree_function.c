#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	ElemType data;
	struct node* left;
	struct node* right;
}Node;

typedef struct tree{//指向一棵树 
	Node *root;
}Tree;
 

void insert(Tree *tree,int item){//创建一棵树 和插入结点都在同一个函数 
	Node *node=(Node*)malloc(sizeof(Node));
	node->data=item;
	node->left=NULL;
	node->right=NULL;
	if(tree->root==NULL){//创建树的情况 
		tree->root=node;
	}
	else{//插入结点的情况 
		Node *temp = tree->root;//从树根开始遍历
		while(temp!=NULL){
			if(item<temp->data){//小于的情况：左树 
				if(temp->left==NULL){//找到左叶子 
					temp->left=node;
					return;
				}
				else{
					temp = temp->left;
				}
			}
			else{//大于等于：右孩子
			    if(temp->right==NULL){
			    	temp->right=node;
					return; 
				}
				else{
					temp = temp->right;
				}
			}
		} 
	}
	return ;
}


void search_parent(Node *node,Node *address,ElemType item){//递归 时间复杂度看情况在log n到n之间 ，虽然递归不好定位，但是可以指针传参 
	if(node->left->data==item||node->right->data==item){
		address->data = node->data;
		return ;
	}
	else if(item > node->data){//在右子树 
		search_parent(node->right,address,item);
		return ;
	}
	else if(item < node->data){//在左子树 
		search_parent(node->left,address,item);
		return ;
	}
}
/*注意使用的时候：
    int e;
	scanf("%d",&e);
	Node parent;
	search_parent(BSTree->root,&parent,e);
	printf("%d",parent.data);
*/


Node *queue[max_node_num];
void layerorder(Tree *tree){//层次遍历二叉树，并且储存到queue 
	int front=0,rear=0;
	queue[0]=tree->root;
	Node *p;
	while(front<=rear){
		p=queue[front];
		front++;
		if(p->left!=NULL){
			rear++;
			queue[rear]=p->left;
		}
		if(p->right!=NULL){
			rear++;
			queue[rear]=p->right;
		}
	}
}


//前序加中序
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct binarytree//定义节点
{
    char val;
    struct binarytree *left, *right;
} bitree;
 
char pre[100];
char in[100];//存储序列
 
void BAK(bitree *r)//后序遍历（蹩脚英语写的脑瘫名字）
{
    if (r->left != NULL)
        BAK(r->left);
    if (r->right != NULL)
        BAK(r->right);
    printf("%c", r->val);
}

bitree *constructcore(int prel, int prer, int inl, int inr)//创建树，变量分别为先序的起点终点，中序的起点终点
{
    bitree *root = (bitree *)malloc(sizeof(bitree));
    root->val = pre[prel];//先序遍历的第一个为根
    root->left = NULL;
    root->right = NULL;//一定要记得初始化 防止出现野指针
 
    if (inl == inr)
        return root;//如果长度为一 没有子树 直接返回
 
    int rootin;
    for (rootin = inl; rootin <= inr; rootin++)//寻找根在中序遍历中的位置
    {
        if (in[rootin] == root->val)
        {
            break;
        }
    }
 
    int l_len = rootin - inl;
    int r_len = inr - rootin;//分别求左右子树长度：一是判断是否存在，二是给子树遍历的起止定位
 
    if (l_len > 0)//注意上方只判断了有没有子树，并没有分别判断左右子树是否存在，还要用长度判断一下
        root->left = constructcore(prel + 1, prel + l_len, inl, rootin - 1);//递归左子树
    if (r_len > 0)
        root->right = constructcore(prel + l_len + 1, prer, rootin + 1, inr);//递归右子树
 
    return root;
}
 
int main()
{
    int n;
    scanf("%s", in);
    //getchar();
    scanf("%s", pre);
    //puts(in);puts(pre);
    n = strlen(in);
    //printf("%d",n);
    bitree *tree = constructcore(0, n - 1, 0, n - 1);
    BAK(tree);
}

//后序加中序
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct binarytree
{
    char val;
    struct binarytree *left, *right;
} bitree;
 
char post[100];
char in[100];
 
bitree *constructcore(int postl, int postr, int inl, int inr)
{
    bitree *root = (bitree *)malloc(sizeof(bitree));
    root->val = post[postr];
    root->left = NULL;
    root->right = NULL;
 
    if (inl == inr)
        return root;
 
    int rootin;
    for (rootin = inl; rootin <= inr; rootin++)
    {
        if (in[rootin] == root->val)
        {
            break;
        }
    }
 
    int l_len = rootin - inl;
    int r_len = inr - rootin;
 
    if (l_len > 0)
        root->left = constructcore(postl, postl + l_len - 1, inl, rootin - 1);
    if (r_len > 0)
        root->right = constructcore(postl + l_len, postr - 1, rootin + 1, inr);
 
    return root;
}
 
void pre_traverse(bitree *p)
{
    printf("%c", p->val);
    if (p->left)
        pre_traverse(p->left);
    if (p->right)
        pre_traverse(p->right);
}
 
int main()
{
    int n;
    scanf("%s",in);
    //getchar();
    scanf("%s",post);
    //puts(in);puts(pre);
    n = strlen(in);
    //printf("%d",n);
    bitree *tree = constructcore(0, n - 1, 0, n - 1);
    pre_traverse(tree);
}