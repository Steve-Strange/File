//函数的分文件编写：  
//1.创建以.h为后缀的头文件
//2.添加以.cpp为后缀的源文件
//3.在头文件中写函数的声明
//4.在源文件中写函数的定义 
//即自己单独定义函数，设置在一个函数库中，其他文件如要使用直接 include 

#include<iostream>   
using namespace std; 
#include "swap.h" 

int main(){
	
	int x,y;
	cin>>x;
	cin>>y;
	swap(x,y); 
		
	system("pause");
	
	return 0;
}  
