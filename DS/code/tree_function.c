#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	ElemType data;
	struct node* left;
	struct node* right;
}Node;

typedef struct tree{//ָ��һ���� 
	Node *root;
}Tree;
 

void insert(Tree *tree,int item){//����һ���� �Ͳ����㶼��ͬһ������ 
	Node *node=(Node*)malloc(sizeof(Node));
	node->data=item;
	node->left=NULL;
	node->right=NULL;
	if(tree->root==NULL){//����������� 
		tree->root=node;
	}
	else{//���������� 
		Node *temp = tree->root;//��������ʼ����
		while(temp!=NULL){
			if(item<temp->data){//С�ڵ���������� 
				if(temp->left==NULL){//�ҵ���Ҷ�� 
					temp->left=node;
					return;
				}
				else{
					temp = temp->left;
				}
			}
			else{//���ڵ��ڣ��Һ���
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


void search_parent(Node *node,Node *address,ElemType item){//�ݹ� ʱ�临�Ӷȿ������log n��n֮�� ����Ȼ�ݹ鲻�ö�λ�����ǿ���ָ�봫�� 
	if(node->left->data==item||node->right->data==item){
		address->data = node->data;
		return ;
	}
	else if(item > node->data){//�������� 
		search_parent(node->right,address,item);
		return ;
	}
	else if(item < node->data){//�������� 
		search_parent(node->left,address,item);
		return ;
	}
}
/*ע��ʹ�õ�ʱ��
    int e;
	scanf("%d",&e);
	Node parent;
	search_parent(BSTree->root,&parent,e);
	printf("%d",parent.data);
*/


Node *queue[max_node_num];
void layerorder(Tree *tree){//��α��������������Ҵ��浽queue 
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


//ǰ�������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct binarytree//����ڵ�
{
    char val;
    struct binarytree *left, *right;
} bitree;
 
char pre[100];
char in[100];//�洢����
 
void BAK(bitree *r)//�������������Ӣ��д����̱���֣�
{
    if (r->left != NULL)
        BAK(r->left);
    if (r->right != NULL)
        BAK(r->right);
    printf("%c", r->val);
}

bitree *constructcore(int prel, int prer, int inl, int inr)//�������������ֱ�Ϊ���������յ㣬���������յ�
{
    bitree *root = (bitree *)malloc(sizeof(bitree));
    root->val = pre[prel];//��������ĵ�һ��Ϊ��
    root->left = NULL;
    root->right = NULL;//һ��Ҫ�ǵó�ʼ�� ��ֹ����Ұָ��
 
    if (inl == inr)
        return root;//�������Ϊһ û������ ֱ�ӷ���
 
    int rootin;
    for (rootin = inl; rootin <= inr; rootin++)//Ѱ�Ҹ�����������е�λ��
    {
        if (in[rootin] == root->val)
        {
            break;
        }
    }
 
    int l_len = rootin - inl;
    int r_len = inr - rootin;//�ֱ��������������ȣ�һ���ж��Ƿ���ڣ����Ǹ�������������ֹ��λ
 
    if (l_len > 0)//ע���Ϸ�ֻ�ж�����û����������û�зֱ��ж����������Ƿ���ڣ���Ҫ�ó����ж�һ��
        root->left = constructcore(prel + 1, prel + l_len, inl, rootin - 1);//�ݹ�������
    if (r_len > 0)
        root->right = constructcore(prel + l_len + 1, prer, rootin + 1, inr);//�ݹ�������
 
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

//���������
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