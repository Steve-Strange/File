//程序流程结构 ： 顺序结构，选择结构，循环结构
#include<iostream>
using namespace std;

int main(){

	int a=0; 
	cout<<"请输入一个分数"<<endl;
	cin>>a;  //让用户赋值 给a  ">>"  即“给” 
	
	if (a>500)   //if后面不要加分号   
	{
		cout<<"恭喜你考上大学"<<endl;
	 } 
	
	else   //包含不满足这个if的所有情况 
	{
		cout<<"你没考上大学"<<endl;
	}
	system("pause");
	return 0;
} 
