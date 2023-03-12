#include<iostream>
using namespace std;

int main(){

	int a=0; 
	cout<<"请输入一个分数"<<endl;
	cin>>a;  //让用户赋值 给a  ">>"  即“给” 
	
	if (a>600)   //if后面不要加分号   
	{
		cout<<"考上一本"<<endl;
	 } 
	
	else if (500<a)  //上一个不成立的条件下，判断这个是否成立  成立后直接跳出整个if结构  跳到else后面 
	{
		cout<<"考上二本"<<endl;
	}
	
	else if (a>400) {
		cout <<"考上三本"<<endl;
	}
	else {  //前面所有条件都不成立的前提下，输出 
		cout<<"你没学上了"<<endl;
	}
	system("pause");
	return 0;
} 
