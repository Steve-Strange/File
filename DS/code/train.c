#include<stdio.h> 
#include<string.h>
//���һ������򵥵�������к�ջ
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
     //����һ���˿��������˿�����ʽ�����1��2��3---k13 �֣��������������У���Ӧ����++������0����
     //������һ���Ż������Ч�ʣ������ ��ϣ���÷�
     int puke[14];
     memset(puke, 0, sizeof(int) * 14);
     //��ʼ�����к�����
     q1.head = q1.tail = 0;
     q2.head = q2.tail = 0;
     s.top = 0;
     //���������Ա���е��˿�ֵ��������������6����
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
     //��Ϸ����������ÿ�������ﶼ���ơ������в�Ϊ��
     while (q1.head < q1.tail && q2.head < q2.tail)
     {
         //����q1�ȳ���
         int t = q1._data[q1.head];
         if(puke[t] == 0)
         {
             //����û������Ϊt����,q1��-1����ͷ��ֵ�������϶��ƣ���s+1,puke��Ӧλ��+1
             q1.head++;
             s._data[s.top++] = t;
             puke[t] = 1;
         }
         else 
         {
             //����ͬ���ƣ������ƴӶ�ͷ�ó����ŵ���β��
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
             //����û������Ϊt����,q1��-1����ͷ��ֵ�������϶��ƣ���s+1,puke��Ӧλ��+1
             q2.head++;
             s._data[s.top++] = t;
             puke[t] = 1;
         }
         else
         {
             //����ͬ���ƣ������ƴӶ�ͷ�ó����ŵ���β��
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