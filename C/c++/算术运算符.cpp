#include<iostream>  
using namespace std;

int main(){

	int a=5,b=9;  // int 即 integer  连续赋值可用, 
	// 四则运算 + - * / 
	cout<<a+b<<endl<<a-b<<endl<<a*b<<endl<<a/b<<endl;  //输入整数 除法只输出整数部分

	float c=1.3 ,d=2.4;
	cout<<c/d<<endl;  //给的数是小数，除法输出也是小数 
	
	//取模运算，输出余数  小数不可进行取模运算 
	cout<<b%a<<endl; 
	
	/*
	前置递增 ++a a=a+1  先进行+1 后参与运算   (直接改变a的值) 
	后置递增 a++ a=a+1  先参与运算 后进行+1 
	*/
	int e=10,f=++e*10;
	cout<<e<<endl<<f<<endl;
	
	int g=10,h=g++*10;
	cout<<g<<endl<<h<<endl;
	
	int x=1;
	++x;   //也可直接作为一条指令 
	cout<<x<<endl;
	
	/*
	前置递减后置递减同理。。。 
	 */
	
	system("pause");
	
	return 0;
} 
