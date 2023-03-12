#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXWORD  32
struct tnode {
    char word[MAXWORD];
    int count;
    struct tnode *left,*right;
} ; //BST,�������ṹ
int getWord(FILE *bfp,char *w);
struct tnode *treeWords(struct tnode *p,char *w);
void treePrint( struct tnode *p);

int main()
{
    char filename[32], word[MAXWORD];
    FILE *bfp;
    struct tnode *root=NULL; //BST�����ڵ�ָ��

    scanf("%s", filename);
    if((bfp = fopen(filename, "r")) == NULL){ //��һ���ļ�
        fprintf(stderr, "%s  can��t open!\n",filename);
        return -1;
     }
     while(getWord(bfp,word) != EOF) //���ļ��ж���һ������
         root = treeWords(root, word);
    treePrint(root);  //�������������
    return 0;
} 

struct tnode *treeWords(struct tnode *p, char *w)  
{
    int cond;
    if( p == NULL ) {	/* a new word has arrived */
        p = (struct tnode *)malloc(sizeof(struct tnode));/* make a new node */
        strcpy(p->word,w);	
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if((cond = strcmp(w, p->word)) == 0)
        p->count ++;		/* repeated word */
    else if ( cond < 0 )		/* lower into left subtree */
        p->left = treeWords(p->left, w);
    else 			                  /* greater into right subtree */
        p->right = treeWords(p->right, w);
    return ( p );
}

void treePrint(struct tnode *p) 
{
    if(p != NULL) {
        treePrint(p->left);
        printf("%s  %4d\n", p->word,p->count);
        treePrint(p->right);
    }
}