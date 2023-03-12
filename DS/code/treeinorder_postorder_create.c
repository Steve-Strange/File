#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    int path;
 }Tree,*Treep;
struct leafNode{		//树叶节点信息 
	int path;			//路径值 
	int val;			//该树叶节点的名 
}node[200];
Treep root=NULL,t;
int top=0;
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){	//恢复二叉树 
    int p=postorderSize-1,i=0;	//p是后序遍历的倒数第一个数 
    struct TreeNode* newNode;
    if(postorder == NULL || inorder == NULL) return NULL;
    if(postorderSize <= 0 || inorderSize <= 0 )  return NULL;
    newNode=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val=postorder[p];	//利用后序遍历的倒数第一个构造根节点 
    newNode->left=newNode->right=NULL;
    for(i=0;i<inorderSize;i++)
        if(newNode->val == inorder[i])	//在中序遍历找到根节点 
        {
            newNode->left=buildTree(inorder,i,postorder,i);	//递归处理 
            newNode->right=buildTree(inorder+i+1,inorderSize-i-1,postorder+i,postorderSize-i-1);	//递归处理 
        }
    return newNode;
}
void CauculatePath(Treep t,int path)
{
    if(t!=NULL){
        t->path=path+t->val;	//算路径总值 
        CauculatePath(t->left,t->path);	//算路径总值 
        CauculatePath(t->right,t->path);	//算路径总值 
    }
}
void SortLeaves(Treep t)
{
    if(t!=NULL){
        if(t->left==NULL && t->right==NULL)
		{
			node[top].path=t->path,node[top].val=t->val;//	记录叶节点信息 
			top++;	//用数组存下来 
		}
        SortLeaves(t->left);
        SortLeaves(t->right);
    }
}
int compare(const void*p1,const void*p2)
{
	struct leafNode *a=(struct leafNode*)p1;
	struct leafNode *b=(struct leafNode*)p2;
	if(a->path!=b->path	)return a->path-b->path;	//根据路径总值排序 
	else return a->val-b->val;
}
int main()
{
	int inorder[200],postorder[200],inorderSize,postorderSize,tmp,i,path=0,a,offset;
	char s1[200],s2[200];
	char ch;
	while(gets(s1)!=NULL){		//难点 
  		gets(s2);
  		memset(inorder,0,sizeof(inorder));
  		memset(postorder,0,sizeof(postorder));
  		memset(node,0,sizeof(node));
  		root=NULL;
  		offset=top=0;
  		int readlen;
  		while(sscanf(s1+offset,"%d%n",&a,&readlen)==1)	//获得一个数 
		{
   			offset+=readlen;
   			inorder[top]=a;
   			top++;
  		}
 		offset=0,top=0;
  		while(sscanf(s2+offset,"%d%n",&a,&readlen)==1){	//获得一个数 
   			offset+=readlen;
  			postorder[top]=a;
   			top++;
  		}
		inorderSize=postorderSize=top;	//记录遍历数组的总数 
		top=0;
		root=buildTree(inorder,  inorderSize,  postorder,  postorderSize);//恢复二叉树 
		CauculatePath(root,path);	//计算路径总值 
		SortLeaves(root);			//存树叶结点 
		qsort(node,top,sizeof(struct leafNode),compare);	//排序 
		printf("%d\n",node[0].val);
	}
}