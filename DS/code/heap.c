#define HEAPSIZE     1000  //堆中最大元素个数
#define ElemType int
ElemType  Heap[HEAPSIZE];
int  Hnum;	//当前堆中元素个数


void  heapInsert(ElemType e, ElemType heap[ ])   //插入元素  先放最后，之后上浮
{
    int i;
    heap[Hnum++] = e;
    for(i= Hnum-1; i!=0&&(e > heap[(i-1)/2])  ; i=(i-1) / 2)
        heap[i] = heap[(i-1)/2];
    heap[i] = e;
}

ElemType  heapDelete(ElemType heap[ ])     //删除堆顶元素   把最后一个元素放在堆顶，再下沉 
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