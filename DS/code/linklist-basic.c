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
    //HeadNodeΪͷָ�룬ָ��ͷ��㡣 
    
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
void PrintLink(Linklist *HeadNode){//���HeadNodeָ��ͷ��㣬���µĴ�����С�Ķ� 
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
Linklist * InsertList1(Linklist *HeadNode,int LocateIndex,int InData){//ͷָ�룬������λ�ã����������ݡ�
    //�˴��Ĵ�����λ��ָ���ǲ��ڵ�LocateIndex�����֮��
    int i=0;
    Linklist *CurrentNode=(Linklist *)HeadNode;
    while(i<LocateIndex){
        if(CurrentNode==NULL){
            printf("Invalid insertion position\n");
            return HeadNode;//����λ����Ч��
        }
        CurrentNode=CurrentNode->pNext;
        i++;
    }//��ʱCurrentNodeָ���LocateIndex����㡣
    Linklist *NodeToInsert=(Linklist *)malloc(sizeof(Linklist));
    if(NodeToInsert==NULL){
        printf("Insufficient space cache\n");
        return HeadNode;//�ռ仺�治�㡣
    }
    NodeToInsert->Item=InData;//�������ֵ��
    NodeToInsert->pNext=CurrentNode->pNext;//NodeToInsert�е�pNextָ����һ����㡣
    CurrentNode->pNext=NodeToInsert;//��һ������е�pNextָ��NodeToInsert��
    return HeadNode;//����ɹ���
}
Linklist * InsertList2(Linklist *HeadNode,int LocateIndex,int InData){//ͷָ�룬������λ�ã����������ݡ�
    //�˴��Ĵ�����λ��ָ���ǲ��ڵ�LocateIndex�����֮ǰ�����������½���ǵ�LocateIndex����
    int i=0;
    Linklist *CurrentNode=(Linklist *)HeadNode;
    while(i<LocateIndex-1){
        if(CurrentNode==NULL){
            printf("Invalid insertion position");
            return HeadNode;//����λ����Ч��
        }
        CurrentNode=CurrentNode->pNext;
        i++;
    }//��ʱCurrentNodeָ���LocateIndex-1����㡣
    Linklist *NodeToInsert=(Linklist *)malloc(sizeof(Linklist));
    if(NodeToInsert==NULL){
        printf("Insufficient space cache");
        return HeadNode;//�ռ仺�治�㡣
    }
    NodeToInsert->Item=InData;//�������ֵ��
    NodeToInsert->pNext=CurrentNode->pNext;//NodeToInsert�е�pNextָ���LocateIndex����㡣
    CurrentNode->pNext=NodeToInsert;//��LocateIndex-1������е�pNextָ��NodeToInsert��
    return HeadNode;//����ɹ���
}
Linklist * DeleteList1(Linklist *HeadNode,int Index,int *DataToDelete){//ͷָ�룬��ɾ��λ�ã�����ɾ�������ݡ�
    int i=0;
    Linklist *CurrentNode=HeadNode;
    while(i<Index-1){
        if(CurrentNode==NULL){
            printf("Invalid delete location\n");
            return HeadNode;//ɾ��λ����Ч��
        }
        CurrentNode=CurrentNode->pNext;
        i++;
    }//��ʱCurrentNodeָ���ɾ��λ�õ�ǰһ����㡣
    Linklist *NodeToDelete=CurrentNode->pNext;//��¼��ɾ������ָ�룬�����ͷš�
    *DataToDelete=NodeToDelete->Item;//���Լ�¼��ɾ�������ݡ�
    CurrentNode->pNext=NodeToDelete->pNext;//ǰ�ý���pNextָ����ý�㡣
    free(NodeToDelete);
    return HeadNode;
}
Linklist * DeleteList2(Linklist *HeadNode,int DataToDel){//ͷָ�룬ָ����ɾ��Ԫ�ء�
    Linklist *PreNode=HeadNode;
    Linklist *CurrentNode=HeadNode->pNext;
    while(CurrentNode!=NULL){//�жϵ�����Ϊֹ������ָ��Ԫ����ɾ�����������ж���һ����
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
int GetListLength(Linklist *HeadNode){//�˴�HeadNodeָ��ͷ��㡣
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
    //�˴�HeadNodeָ��ͷ��㡣
    Linklist *Pre=(Linklist*)malloc(sizeof(Linklist));
    Pre->pNext=HeadNode->pNext;//��Ϊ����˵���е�Head��
    Linklist *CurrentNode=HeadNode->pNext;//��Ϊ����˵���е�A1�������������A1�����ÿ����������ƶ�����Ԫ����λ�á�
    while(CurrentNode->pNext!=NULL){//CurrentNode->pNext==NULLʱ��˵��A1�Ѿ��������һ����������ɡ�
        Linklist *Next=CurrentNode->pNext;
        CurrentNode->pNext=Next->pNext;
        Next->pNext=Pre->pNext;
        Pre->pNext=Next;
    }
    return Pre->pNext;
}
Linklist *ListRotate2(Linklist *HeadNode){
    //�˴�HeadNodeָ����Ԫ��㡣
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