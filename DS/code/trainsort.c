#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char name[5];
    int distance;
}node;

typedef struct place{
    char name[25];
    int distance;
}place;

place placeinfo[51];
node trunk[51];
int n,m;

int search(char *name){
    for(int i=0;i<n;i++){
        if(strcmp(name,placeinfo[i].name)==0) return placeinfo[i].distance;
    }
}

int max(int k){
    int temp=0;
    int ans=0;
    for(int i=k;i<m;i++){
        if(trunk[i].distance>temp){
            temp=trunk[i].distance;
            ans=i;
        } 
    }
    // printf("%d\n",ans);
    return ans;
}


int main(){
    int cnt=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s %d",placeinfo[i].name,&placeinfo[i].distance);
    }

    scanf("%d",&m);
    for(int i=0;i<m;i++){
        char x[25]={0};
        scanf("%s %s",trunk[i].name,x);
        trunk[i].distance=search(x);
    }

    for(int i=0;i<m;i++){
        int maxplace=max(i);
        if(maxplace==i) cnt++;
        else cnt+=2+maxplace-i;
        node temptrunk=trunk[maxplace];
        for(int j=maxplace-1;j>=i;j--){
           trunk[j+1]=trunk[j];
        }
        trunk[i]=temptrunk;
    }

    for(int i=0;i<m;i++){
        printf("%s ",trunk[i].name);
    }

    printf("\n%d",cnt);
}