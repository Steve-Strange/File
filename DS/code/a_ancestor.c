#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char name[21];
    int child[2];
    int parent;
    int depth;
    int id;
}node;

node family[5000000];
int cnt;

int findname(char *name) {
    for(int i=0; i<cnt; i++) {
        if(strcmp(name,family[i].name)==0) return i;
    }
    return -1;    
}

int main(){
    FILE *in=fopen("in.txt", "r");
    char find1[21]={0};
    char find2[21]={0};
    scanf("%s %s",find1,find2);

    int n;
    fscanf(in,"%d",&n);
    for(int i=0;i<n;i++){
        char tempstr[21]="NULL";
        char present[21]={0};
        char child1[21]={0};
        char child2[21]={0};
        fscanf(in,"%s %s %s",present,child1,child2);
        if(findname(present)==-1)
        {
            family[cnt].id=cnt;
            strcpy(family[cnt++].name,present);
        }
        if(strcmp(child1,tempstr))
        {
            family[cnt].id=cnt;
            family[findname(present)].child[0]=findname(child1);
            strcpy(family[cnt++].name,child1);
            family[cnt-1].parent=findname(present);
            family[cnt-1].depth=family[findname(present)].depth+1;
        }
        if(strcmp(child2,tempstr))
        {
            family[cnt].id=cnt;
            family[findname(present)].child[1]=findname(child2);
            strcpy(family[cnt++].name,child2);
            family[cnt-1].parent=findname(present);
            family[cnt-1].depth=family[findname(present)].depth+1;
        }
    }

    // for(int i=0;i<cnt;i++)
    // { 
    //     printf("%d %s %d\n",family[i].id,family[i].name,family[i].depth);
    // }

    int findp1=findname(find1);
    int findp2=findname(find2);

    if(family[findp1].depth<family[findp2].depth) 
        printf("%s %s %d",family[findp2].name,family[findp1].name,family[findp2].depth-family[findp1].depth);
    else if(family[findp1].depth>family[findp2].depth) 
        printf("%s %s %d",family[findp1].name,family[findp2].name,family[findp1].depth-family[findp2].depth);
    else{
        int stack1[105]={0};
        int stack2[105]={0};
        int cntstack1=0,cntstack2=0;
        int temp1=findp1;
        int temp2=findp2;
        while(findname(family[temp1].name)){
            stack1[cntstack1++]=family[temp1].parent;
            temp1=family[temp1].parent;
        }
        while(findname(family[temp2].name)){
            stack2[cntstack2++]=family[temp2].parent;
            temp2=family[temp2].parent;
        }

        // for(int i=0;i<cntstack1;i++){
        //     printf("%s\n",family[stack1[i]].name);
        // }
        int ancestor=0;
        for(int i=0;i<cntstack1;i++){
            if(stack1[i]==stack2[i])
            {
                ancestor=i+1;
                break;
            }
        }

        if(family[findp1].id<family[findp2].id){
            printf("%s %s %d\n",family[stack1[ancestor-1]].name,family[findp1].name,ancestor);
            printf("%s %s %d",family[stack1[ancestor-1]].name,family[findp2].name,ancestor);
        }
        else{
            printf("%s %s %d\n",family[stack1[ancestor-1]].name,family[findp2].name,ancestor);
            printf("%s %s %d",family[stack1[ancestor-1]].name,family[findp1].name,ancestor);
        }
            
    }
    return 0;
}