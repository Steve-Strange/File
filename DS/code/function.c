#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct fun{
    char name[25];
}fun;

fun pile[205];
fun ans[105][11];
int cnt,cntans;
int cntpile[105];

int op=0;

int find(char *name){
    for(int i=0;i<cntans;i++){
        if(strcmp(name,ans[i][0].name)==0) return i;
    }
    return -1;
}


int main(){
    for(int i=0;i<105;i++){
        cntpile[i]++;
    }
    scanf("%d",&op);
    if(op==0) return 0;
    if(op==8){
        scanf("%s",pile[cnt++].name);
        ans[cntans++][0]=pile[0];
    }
    while(cnt){
        scanf("%d",&op);
        if(op==0){
            cnt--;
        }
        if(op==8){
            scanf("%s",pile[cnt++].name);
            if(find(pile[cnt-1].name)==-1){
                ans[cntans++][0]=pile[cnt-1];
            }
            if(cnt>=2)
            {
                int flag=0;
                int tempcnt=find(pile[cnt-2].name);
                for(int k=1;k<cntpile[tempcnt];k++){
                    if(strcmp(ans[tempcnt][k].name,pile[cnt-1].name)==0) flag=1;
                }
                if(!flag) ans[tempcnt][cntpile[tempcnt]++]=pile[cnt-1];
            }
        }
    }

    for(int i=0;i<cntans;i++){
        if(cntpile[i]>1){
            printf("%s:",ans[i][0].name);
            for(int j=1;j<cntpile[i]-1;j++){
                printf("%s,",ans[i][j].name);
            }
            printf("%s\n",ans[i][cntpile[i]-1].name);
        }
    }
    return 0;
}