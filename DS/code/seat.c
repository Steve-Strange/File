#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct info{
    int id;
    char name[20];
    int seat;
}info;

info original[105];
info missing[105];
info duplicate[105];
info final[105];
int duplicate_cnt,missing_cnt,final_cnt;

int cmp(const void *a, const void *b){
    info *p=(info *)a;
    info *q=(info *)b;
    if(p->seat!=q->seat){
        if(p->seat>q->seat) return 1;
        else return -1;
    }
    else return p->id-q->id;
}

int cmp2(const void *a, const void *b){
    info *p=(info *)a;
    info *q=(info *)b;
    return p->id-q->id;
}

int main()
{
    int num = 0;
    int max=0;
    int pile[105]={0};
    scanf("%d",&num);
    FILE *in = fopen("in.txt","r");
    FILE *out = fopen("out.txt","w");
    for(int i = 0; i < num; i++){
        fscanf(in,"%d %s %d",&original[i].id,original[i].name,&original[i].seat);
    }
    qsort(original,num,sizeof(info),cmp);

    for(int i = 0; i < num; i++){
        if(original[i].seat>max) max=original[i].seat;
        if(!pile[original[i].seat]) pile[original[i].seat]=1;
        else
        {
            duplicate[duplicate_cnt++]=original[i];
        }
        // printf("%d %s %d\n",original[i].id,original[i].name,original[i].seat);
    }
    int cnt1=num-1;
    for(int i=1;i<=num&&i<=max;i++){
        if(!pile[i]) original[cnt1--].seat=i;
        max=0;
        for(int i = 0; i < num; i++){
            if(original[i].seat>max) max=original[i].seat;
        }
    }
    max=0;
    for(int i = 0; i < num; i++){
        if(original[i].seat>max) max=original[i].seat;
    }
    for(int i = 0; i < duplicate_cnt; i++){
        // printf("%d %s %d\n",duplicate[i].id,duplicate[i].name,duplicate[i].seat);
        for(int j=0;j<num;j++){
            if(duplicate[i].id==original[j].id) original[j].seat=++max;
        }
    }

    qsort(original,num,sizeof(info),cmp2);
    for(int i = 0; i < num; i++){
        fprintf(out,"%d %s %d\n",original[i].id,original[i].name,original[i].seat);
    }
    fclose(in);
    fclose(out);
    return 0;
}