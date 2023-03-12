#include<iostream>
using namespace std;

void swap(int *a,int *b)
{
	cout<<"交换前"<<*a<<" "<<*b<<endl;
	int x;
	x=*a;
	*a=*b;
	*b=x;
	cout<<"交换后" <<*a<<" "<<*b<<endl;
 } 
 
 int main()
 {
 	int x,y;
 	cin>>x;
 	cin>>y;
	swap(&x,&y);
	cout<<x<<endl<<y<<endl; //地址传递会影响实参 
 }
