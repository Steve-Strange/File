#include<iostream>
using namespace std;

void swap(int *a,int *b)
{
	cout<<"����ǰ"<<*a<<" "<<*b<<endl;
	int x;
	x=*a;
	*a=*b;
	*b=x;
	cout<<"������" <<*a<<" "<<*b<<endl;
 } 
 
 int main()
 {
 	int x,y;
 	cin>>x;
 	cin>>y;
	swap(&x,&y);
	cout<<x<<endl<<y<<endl; //��ַ���ݻ�Ӱ��ʵ�� 
 }
