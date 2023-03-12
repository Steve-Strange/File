#define HEAPSIZE     1000  //�������Ԫ�ظ���
#define ElemType int
ElemType  Heap[HEAPSIZE];
int  Hnum;	//��ǰ����Ԫ�ظ���


void  heapInsert(ElemType e, ElemType heap[ ])   //����Ԫ��  �ȷ����֮���ϸ�
{
    int i;
    heap[Hnum++] = e;
    for(i= Hnum-1; i!=0&&(e > heap[(i-1)/2])  ; i=(i-1) / 2)
        heap[i] = heap[(i-1)/2];
    heap[i] = e;
}

ElemType  heapDelete(ElemType heap[ ])     //ɾ���Ѷ�Ԫ��   �����һ��Ԫ�ط��ڶѶ������³� 
{
    int i=0,j;
    ElemType  cur,last;
    cur = heap[0]; last = heap[--Hnum];
    while( i*2+1 < Hnum) {
         j = i*2+1; 
        if(j != Hnum-1 && heap[j]  < heap[j+1])
            j++;
        if( last < heap[j])
             heap[i] = heap[j];
        else 
             break;
        i = j;
    }
    heap[i] = last;
    return cur;
}