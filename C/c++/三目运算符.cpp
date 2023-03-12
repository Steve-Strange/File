//三目运算符 
// 表达式1 ？ 表达式2 ：表达式3；
//如果1真，执行2  如果1假，执行3 

//输出最大数

#include<iostream>  
using namespace std;

int main(){
	
	int a,b,c,d;
	cin>>a;
	cin>>b;
	a>b ? c=a : c=b; 
	(a>b ? a : b)=100; //也可直接返回变量，赋值 
	cout<<c<<endl<<a<<endl<<b<<endl; 
		
	system("pause");
	
	return 0;
}  
