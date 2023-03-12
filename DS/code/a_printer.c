#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int m,n;
int minpath[200];
int minpathcnt;

typedef struct node{
    int id;
    int type;
    int parentid;
    int place;
    int childrenid[8];
}node;

node net[500];

int search(int id){
    for(int i=0;i<n;i++){
        if(net[i].id == id) return i;
    }
    return -1;
}

int printer[500];
int printercnt;

int path(int computerid,int printerid){
    int p1=search(computerid);
    int p2=search(printerid);
    int temp1=p1;
    int temp2=p2;
    int ancestor1[500]={0};
    int ancestor2[500]={0};
    int cnt1=0,cnt2=0;
    while(temp1!=-1){
        ancestor1[cnt1++]=temp1;
        temp1=search(net[temp1].parentid);
    }
    while(temp2!=-1){
        ancestor2[cnt2++]=temp2;
        temp2=search(net[temp2].parentid);
    }

    for(int i=0;i<cnt1;i++){
        for(int j=0;j<cnt2;j++){   
            if(ancestor1[i]==ancestor2[j])
            {
                return i+j;
            }
        }
    }
}

int printpath(int computerid,int printerid){
    int p1=search(computerid);
    int p2=search(printerid);
    int temp1=p1;
    int temp2=p2;
    int ancestor1[500]={0};
    int ancestor2[500]={0};
    int cnt1=0,cnt2=0;
    while(temp1!=-1){
        ancestor1[cnt1++]=temp1;
        temp1=search(net[temp1].parentid);
    }
    while(temp2!=-1){
        ancestor2[cnt2++]=temp2;
        temp2=search(net[temp2].parentid);
    }

    for(int i=0;i<cnt1;i++){
        for(int j=0;j<cnt2;j++){   
            if(ancestor1[i]==ancestor2[j])
            {
                for(int k=1;k<j;k++) minpath[minpathcnt++]=ancestor2[k];
                for(int k=i;k>0;k--) minpath[minpathcnt++]=ancestor1[k];
                return i+j;
            }
        }
    }
}


int bfsarray[500];
int bfscnt;
int dfsarray[500];
int dfscnt;

void bfs(){
    int stack[500]={0};
    int head=0,tail=0;
    stack[head++]=search(net[0].id);
    while(head!=tail&&head<n){
        for(int i=0;i<=7;i++){
            if(net[stack[tail]].childrenid[i]) 
            {
                stack[head++]=search(net[stack[tail]].childrenid[i]);
            }
        }
        bfsarray[bfscnt++]=net[stack[tail]].id;
        tail++;
    }
    for(int i=tail;i<n;i++){
        bfsarray[bfscnt++]=net[stack[i]].id;
    }
}

int visited[500];
void dfs(int n){
    dfsarray[dfscnt++]=net[n].id;
    visited[search(net[n].id)]=1;
    for(int i=0;i<=7;i++){
        if(visited[search(net[n].childrenid[i])]==0&&net[n].childrenid[i]!=0){
            dfs(net[n].childrenid[i]);
        }
    }
    return;
}

int main()
{
    for(int i=0;i<500;i++){
        net[i].id=-1;
        net[i].type=-1;
        net[i].parentid=-1;
        net[i].place=-1;
    }
    FILE *in=fopen("in.txt", "r");
    scanf("%d%d",&n,&m);
    fscanf(in,"%d %d %d %d",&net[0].id,&net[0].type,&net[0].parentid,&net[0].place);
    for(int i=1; i<n; i++){
        fscanf(in,"%d %d %d %d",&net[i].id,&net[i].type,&net[i].parentid,&net[i].place);
        net[search(net[i].parentid)].childrenid[net[i].place]=net[i].id;
        if(net[i].type==2) printer[printercnt++]=net[i].id;
    }

    // for(int i=0;i<n;i++)
    // { 
    //     printf("%d %d %d\n",net[i].id,net[i].type,net[i].parentid);
    // }


    dfs(0);
    // for(int i=0;i<dfscnt;i++){
    //     printf("%d ",dfsarray[i]);
    // }
    // printf("\n");
    bfs();
    // for(int i=0;i<bfscnt;i++){
    //     printf("%d ",bfsarray[i]);
    // }
    int min=99999;
    int minid=0;
    int sum=0;
    for(int i=0;i<printercnt;i++){
        sum+=path(m,printer[i]);
        if(path(m,printer[i])<min){
            min=path(m,printer[i]);
            minid=printer[i];
        }
        if(path(m,printer[i])==min){
            for(int j=0;j<dfscnt;j++){
                if(dfsarray[j]==minid){
                    break;
                }
                if(dfsarray[j]==printer[i]){
                    minid=printer[i];
                    break;
                }               
            }
        }
    }

    int max=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){ 
            if(path(net[i].id,net[j].id)>max){
                max=path(net[i].id,net[j].id);
            }
        }
    }

    printf("%d ",minid);
    printpath(m,minid);
    for(int i=minpathcnt-1;i>=0;i--) printf("%d ",minpath[i]);
    printf("\n%.3lf",(double)sum/(max*printercnt));
}