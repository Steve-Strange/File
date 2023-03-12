#include<stdio.h> 
#include<string.h>
//设计一个及其简单的数组队列和栈
struct Stack
{
    int _data[100];
    int top;
};
 struct Queue
 {
     int _data[100];
     int head;
     int tail;
 };

 int main()
 {
     struct Queue q1, q2;
     struct Stack s;
     //定义一个扑克数组存放扑克牌样式种类从1，2，3---k13 种，桌子上那种牌有，对应坐标++，闲置0坐标
     //这里是一种优化，提高效率，具体见 哈希表用法
     int puke[14];
     memset(puke, 0, sizeof(int) * 14);
     //初始化队列和链表
     q1.head = q1.tail = 0;
     q2.head = q2.tail = 0;
     s.top = 0;
     //接受两组成员手中的扑克值假设我们现在是6张牌
     for (int i = 0; i < 6; i++)
     {
         scanf("%d", &q1._data[i]);
         q1.tail++;
     }
     for (int i = 0; i < 6; i++)
     {
         scanf("%d", &q2._data[i]);
         q2.tail++;
     }
     //游戏结束条件，每个人手里都有牌、及队列不为空
     while (q1.head < q1.tail && q2.head < q2.tail)
     {
         //假设q1先出牌
         int t = q1._data[q1.head];
         if(puke[t] == 0)
         {
             //桌上没有牌面为t的牌,q1牌-1及队头出值，桌子上多牌，及s+1,puke对应位置+1
             q1.head++;
             s._data[s.top++] = t;
             puke[t] = 1;
         }
         else 
         {
             //有相同的牌，所出牌从对头拿出，放到对尾。
             q1.head++;
             q1._data[q1.tail] = t;
             while (s._data[--s.top - 1] != t)
             {
                 puke[s._data[s.top]] = 0;
                 q1._data[q1.tail++] = s._data[s.top];
             }
         }
         t = q2._data[q2.head];
         if (puke[t] == 0)
         {
             //桌上没有牌面为t的牌,q1牌-1及队头出值，桌子上多牌，及s+1,puke对应位置+1
             q2.head++;
             s._data[s.top++] = t;
             puke[t] = 1;
         }
         else
         {
             //有相同的牌，所出牌从对头拿出，放到对尾。
             q2.head++;
             q2._data[q2.tail] = t;
             while (s._data[--s.top - 1] != t)
             {
                 puke[s._data[s.top]] = 0;
                 q2._data[q2.tail++] = s._data[s.top];
             }
         }
     }
     if (q1.head == q1.tail)
     {
         printf("q2win\n");
     }
     else 
     {
         printf("q1win\n");
     }
     return 0;
}