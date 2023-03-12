#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    int path;
 }Tree,*Treep;
struct leafNode{		//��Ҷ�ڵ���Ϣ 
	int path;			//·��ֵ 
	int val;			//����Ҷ�ڵ���� 
}node[200];
Treep root=NULL,t;
int top=0;
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){	//�ָ������� 
    int p=postorderSize-1,i=0;	//p�Ǻ�������ĵ�����һ���� 
    struct TreeNode* newNode;
    if(postorder == NULL || inorder == NULL) return NULL;
    if(postorderSize <= 0 || inorderSize <= 0 )  return NULL;
    newNode=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val=postorder[p];	//���ú�������ĵ�����һ��������ڵ� 
    newNode->left=newNode->right=NULL;
    for(i=0;i<inorderSize;i++)
        if(newNode->val == inorder[i])	//����������ҵ����ڵ� 
        {
            newNode->left=buildTree(inorder,i,postorder,i);	//�ݹ鴦�� 
            newNode->right=buildTree(inorder+i+1,inorderSize-i-1,postorder+i,postorderSize-i-1);	//�ݹ鴦�� 
        }
    return newNode;
}
void CauculatePath(Treep t,int path)
{
    if(t!=NULL){
        t->path=path+t->val;	//��·����ֵ 
        CauculatePath(t->left,t->path);	//��·����ֵ 
        CauculatePath(t->right,t->path);	//��·����ֵ 
    }
}
void SortLeaves(Treep t)
{
    if(t!=NULL){
        if(t->left==NULL && t->right==NULL)
		{
			node[top].path=t->path,node[top].val=t->val;//	��¼Ҷ�ڵ���Ϣ 
			top++;	//����������� 
		}
        SortLeaves(t->left);
        SortLeaves(t->right);
    }
}
int compare(const void*p1,const void*p2)
{
	struct leafNode *a=(struct leafNode*)p1;
	struct leafNode *b=(struct leafNode*)p2;
	if(a->path!=b->path	)return a->path-b->path;	//����·����ֵ���� 
	else return a->val-b->val;
}
int main()
{
	int inorder[200],postorder[200],inorderSize,postorderSize,tmp,i,path=0,a,offset;
	char s1[200],s2[200];
	char ch;
	while(gets(s1)!=NULL){		//�ѵ� 
  		gets(s2);
  		memset(inorder,0,sizeof(inorder));
  		memset(postorder,0,sizeof(postorder));
  		memset(node,0,sizeof(node));
  		root=NULL;
  		offset=top=0;
  		int readlen;
  		while(sscanf(s1+offset,"%d%n",&a,&readlen)==1)	//���һ���� 
		{
   			offset+=readlen;
   			inorder[top]=a;
   			top++;
  		}
 		offset=0,top=0;
  		while(sscanf(s2+offset,"%d%n",&a,&readlen)==1){	//���һ���� 
   			offset+=readlen;
  			postorder[top]=a;
   			top++;
  		}
		inorderSize=postorderSize=top;	//��¼������������� 
		top=0;
		root=buildTree(inorder,  inorderSize,  postorder,  postorderSize);//�ָ������� 
		CauculatePath(root,path);	//����·����ֵ 
		SortLeaves(root);			//����Ҷ��� 
		qsort(node,top,sizeof(struct leafNode),compare);	//���� 
		printf("%d\n",node[0].val);
	}
}