#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define keytype node
typedef struct node{
    char name[205];
    int type;
    char time[20];
    int child[105];
    int parent;
    int depth;
}node;

node file[50000];
int cntfile[50000];
int cnt;
node ans[105];
int cntans=0;


int findparent(char *parent) {
    for(int i=0; i<cnt; i++) {
        if(strcmp(parent,file[i].name)==0) return i;
    }
    return -1;
}

int cmp(const void *a, const void *b) {
    node*p=(node*)a;
    node*q=(node*)b;

    if(strcmp(p->time,q->time)==0)
    {
        if(p->depth==q->depth)
        {
            return p->parent-q->parent;
        }
        else return p->depth-q->depth;
    }
    else if(strcmp(p->time,q->time)>0) return -1;
    else return 1;
}

int main(){
    FILE *in=fopen("files.txt", "r");
    for(int i=0; i<50000;i++) cntfile[i]=1;
    int n;
    scanf("%d",&n);
    char find[205]={0};
    scanf("%s",find);
    for(int i=0;i<n;i++){
        char tempchar[5]="-";
        char parent[205]={0};
        fscanf(in,"%s %s %d %s",file[cnt].name,parent,&file[cnt].type,file[cnt].time);
        if(strcmp(parent,tempchar)!=0){
            file[findparent(parent)].child[cntfile[findparent(parent)]++]=cnt;
            file[cnt].parent=findparent(parent);
            file[cnt].depth=file[findparent(parent)].depth+1;
        }
        else{
            file[cnt].parent=-1;
        }
        cnt++;
    }

    // for(int i=1;i<cntfile[findfile("2018")];i++){
    //     printf("%d %s ",findfile("2018"),file[file[findfile("2018")].child[i]]);
    // }

    for(int i=0;i<cnt;i++){
        if(strcmp(find,file[i].name)==0)
        {
            ans[cntans++]=file[i];
        }
    }

    qsort(ans, cntans, sizeof(node),cmp);
    // for(int i=0;i<cntans;i++){
    //     printf("%d\n",ans[i].parent);
    // }

    node temp;

    int stack[1000]={0};
    int cntstack=0;
    for(int i=0;i<cntans;i++){
        temp=ans[i];
        while(temp.parent!=-1)
        {
            // printf("%s ",file[temp.parent].name);
            stack[cntstack++]=temp.parent;
            temp=file[temp.parent];
        }
        for(int j=cntstack-1;j>=0;j--){
            if(j==cntstack-1) printf("%s:\\",file[stack[j]].name);
            else printf("%s\\",file[stack[j]].name);  
        }
        printf("%s\n",ans[i].name);
        memset(stack,0,sizeof(stack));
        cntstack=0;
    }
}