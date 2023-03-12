#include<iostream>
using namespace std;

//函数的声明:提前告知后面有函数的定义
//声明可以写多次，定义只能一次。 

int max(int a,int b);   //声明完毕 注意用 ; 


int main(){
	int a,b;
	cin>>a;
	cin>>b;
	cout<<max(a,b)<<endl;

	system("pause");
	
	return 0;
} 

int max(int a,int b)     //函数定义在后面，最好提前告知。 
{
	return a>b ? a : b; 
 } 

