#include <stdio.h>
#include <malloc.h>
typedef struct tagNode{
    int Item;
    struct tagNode *pNext;
}Linklist;
void CreateList(Linklist *HeadNode,int *Array,int DataNum);
void PrintLink(Linklist *HeadNode);
void PrintLink2(Linklist *HeadNode);
Linklist * InsertList1(Linklist *HeadNode,int LocateIndex,int InData);
Linklist * InsertList2(Linklist *HeadNode,int LocateIndex,int InData);
Linklist * DeleteList1(Linklist *HeadNode,int Index,int *DataToDelete);
Linklist * DeleteList2(Linklist *HeadNode,int DataToDel);
int GetListLength(Linklist *HeadNode);
Linklist *DestroyList(Linklist *HeadNode);
Linklist *ListRotate1(Linklist *HeadNode);
Linklist *ListRotate2(Linklist *HeadNode);
int main(){
    int a[10]={1,2,3,4,5,6,7,8,9,0};
    
    Linklist *HeadNode=(Linklist *)malloc(sizeof(Linklist));
    HeadNode->Item=0;
    HeadNode->pNext=NULL;
    //HeadNode为头指针，指向头结点。 
    
    CreateList(HeadNode,a,10);
    PrintLink(HeadNode);
    InsertList1(HeadNode,4,10);
    PrintLink(HeadNode);
    InsertList2(HeadNode,4,10);
    PrintLink(HeadNode);
    
    int *pDataToDel=(int *)malloc(sizeof(int));
    DeleteList1(HeadNode,4,pDataToDel);
    PrintLink(HeadNode);
    printf("The deleted data is %d\n",*pDataToDel);
    free(pDataToDel);
    printf("The length of the linked list is %d\n",GetListLength(HeadNode));
    
    DeleteList2(HeadNode,10);
    PrintLink(HeadNode);
    
    Linklist *HeadOfRev=ListRotate1(HeadNode);
    PrintLink2(HeadOfRev);
    Linklist *HeadOfRev2=ListRotate2(HeadOfRev);
    PrintLink2(HeadOfRev2);
    
    printf("DestroyList\n");
    DestroyList(HeadNode);
    PrintLink(HeadNode);
    return 0;
}

void CreateList(Linklist *HeadNode,int *Array,int DataNum){
    int i=0;
    HeadNode->pNext=(Linklist *)malloc(sizeof(Linklist));
    Linklist *CurrentNode=(Linklist *)HeadNode->pNext;
    for(i=0;i<DataNum;i++){
        CurrentNode->Item=Array[i];
        if(i<DataNum-1){
            CurrentNode->pNext=(Linklist *)malloc(sizeof(Linklist));
            CurrentNode=CurrentNode->pNext;
        }
    }
    CurrentNode->pNext=NULL;
}
void PrintLink(Linklist *HeadNode){//这个HeadNode指向头结点，底下的代码有小改动 
    Linklist *CurrentNode=(Linklist *)HeadNode->pNext;
    if(CurrentNode==NULL){
        printf("NULL");
    }
    while(CurrentNode!=NULL){
        printf("%d ",CurrentNode->Item);
        CurrentNode=CurrentNode->pNext;
    }
    printf("\n");
}
void PrintLink2(Linklist *HeadNode){
    Linklist *CurrentNode=(Linklist *)HeadNode;
    if(CurrentNode==NULL){
        printf("NULL");
    }
    while(CurrentNode!=NULL){
        printf("%d ",CurrentNode->Item);
        CurrentNode=CurrentNode->pNext;
    }
    printf("\n");
}
Linklist * InsertList1(Linklist *HeadNode,int LocateIndex,int InData){//头指针，待插入位置，待插入数据。
    //此处的待插入位置指的是插在第LocateIndex个结点之后。
    int i=0;
    Linklist *CurrentNode=(Linklist *)HeadNode;
    while(i<LocateIndex){
        if(CurrentNode==NULL){
            printf("Invalid insertion position\n");
            return HeadNode;//插入位置无效。
        }
        CurrentNode=CurrentNode->pNext;
        i++;
    }//此时CurrentNode指向第LocateIndex个结点。
    Linklist *NodeToInsert=(Linklist *)malloc(sizeof(Linklist));
    if(NodeToInsert==NULL){
        printf("Insufficient space cache\n");
        return HeadNode;//空间缓存不足。
    }
    NodeToInsert->Item=InData;//插入的数值。
    NodeToInsert->pNext=CurrentNode->pNext;//NodeToInsert中的pNext指向下一个结点。
    CurrentNode->pNext=NodeToInsert;//上一个结点中的pNext指向NodeToInsert。
    return HeadNode;//插入成功。
}
Linklist * InsertList2(Linklist *HeadNode,int LocateIndex,int InData){//头指针，待插入位置，待插入数据。
    //此处的待插入位置指的是插在第LocateIndex个结点之前，即插入后的新结点是第LocateIndex个。
    int i=0;
    Linklist *CurrentNode=(Linklist *)HeadNode;
    while(i<LocateIndex-1){
        if(CurrentNode==NULL){
            printf("Invalid insertion position");
            return HeadNode;//插入位置无效。
        }
        CurrentNode=CurrentNode->pNext;
        i++;
    }//此时CurrentNode指向第LocateIndex-1个结点。
    Linklist *NodeToInsert=(Linklist *)malloc(sizeof(Linklist));
    if(NodeToInsert==NULL){
        printf("Insufficient space cache");
        return HeadNode;//空间缓存不足。
    }
    NodeToInsert->Item=InData;//插入的数值。
    NodeToInsert->pNext=CurrentNode->pNext;//NodeToInsert中的pNext指向第LocateIndex个结点。
    CurrentNode->pNext=NodeToInsert;//第LocateIndex-1个结点中的pNext指向NodeToInsert。
    return HeadNode;//插入成功。
}
Linklist * DeleteList1(Linklist *HeadNode,int Index,int *DataToDelete){//头指针，待删除位置，传出删除的数据。
    int i=0;
    Linklist *CurrentNode=HeadNode;
    while(i<Index-1){
        if(CurrentNode==NULL){
            printf("Invalid delete location\n");
            return HeadNode;//删除位置无效。
        }
        CurrentNode=CurrentNode->pNext;
        i++;
    }//此时CurrentNode指向待删除位置的前一个结点。
    Linklist *NodeToDelete=CurrentNode->pNext;//记录待删除结点的指针，便于释放。
    *DataToDelete=NodeToDelete->Item;//可以记录被删除的数据。
    CurrentNode->pNext=NodeToDelete->pNext;//前置结点的pNext指向后置结点。
    free(NodeToDelete);
    return HeadNode;
}
Linklist * DeleteList2(Linklist *HeadNode,int DataToDel){//头指针，指定的删除元素。
    Linklist *PreNode=HeadNode;
    Linklist *CurrentNode=HeadNode->pNext;
    while(CurrentNode!=NULL){//判断到结束为止，若是指定元素则删除，不是则判断下一个。
        if(CurrentNode->Item==DataToDel){
            Linklist *DelNode=CurrentNode;
            PreNode->pNext=CurrentNode->pNext;
            CurrentNode=CurrentNode->pNext;
            free(DelNode);
        }
        else{
            PreNode=PreNode->pNext;
            CurrentNode=CurrentNode->pNext;
        }
    }
    return HeadNode;
}
int GetListLength(Linklist *HeadNode){//此处HeadNode指向头结点。
    int ListLength=0;
    Linklist *CurrentNode=HeadNode->pNext;
    while(CurrentNode!=NULL){
        ListLength++;
        CurrentNode=CurrentNode->pNext;
    }
    return ListLength;
}
Linklist *DestroyList(Linklist *HeadNode){
    Linklist *CurrentNode=HeadNode->pNext;
    while(CurrentNode!=NULL){
        Linklist *NextNode=CurrentNode->pNext;
        free(CurrentNode);
        CurrentNode=NextNode;
    }
    HeadNode->pNext=NULL;
    return HeadNode;
}
Linklist *ListRotate1(Linklist *HeadNode){
    //此处HeadNode指向头结点。
    Linklist *Pre=(Linklist*)malloc(sizeof(Linklist));
    Pre->pNext=HeadNode->pNext;//即为以上说明中的Head。
    Linklist *CurrentNode=HeadNode->pNext;//即为以上说明中的A1，在逆序过程中A1后面的每个结点依次移动到首元结点的位置。
    while(CurrentNode->pNext!=NULL){//CurrentNode->pNext==NULL时，说明A1已经到了最后一个，逆序完成。
        Linklist *Next=CurrentNode->pNext;
        CurrentNode->pNext=Next->pNext;
        Next->pNext=Pre->pNext;
        Pre->pNext=Next;
    }
    return Pre->pNext;
}
Linklist *ListRotate2(Linklist *HeadNode){
    //此处HeadNode指向首元结点。
    Linklist *CurrentNode=HeadNode;
    if((CurrentNode==NULL)||(CurrentNode->pNext==NULL)){
        return CurrentNode;
    }
    Linklist *HeadOfReverse=ListRotate2(CurrentNode->pNext);
    Linklist *LastNode=CurrentNode->pNext;
    LastNode->pNext=CurrentNode;
 
    CurrentNode->pNext=NULL;
    return HeadOfReverse;
}