/*函数
1 返回值类型
2 函数名
3 参数列表 （形式参数） 
4 函数体语句
5 return 表达式
*/ 

//一个加法函数 ：输入俩数字，输出数字之和
 
#include<iostream>
using namespace std;

	    int          add     (int a,int b)  //a b叫做形参 
	// 返回值类型  函数名 参数列表（a,b） 
	{
		int sum=a+b;  //函数体语句 
		return sum;    //return表达式 
	}
int main(){
	// main函数中调用之前定义的函数： 函数名称 （实际参数） 
	int x;
	cin>>x;
	int y;
	cin>>y;
	int c=add(x,y);   //x y叫做实参 ，传递给形参 
	cout<<c<<endl; 
	system("pause");
	
	return 0;
} 
