#include<iostream>
using namespace std;

int main(){
	//switch 语句
	//给电影打分  分级出结果
	
	int a=0;
	cout<<"请打分"<<endl;
	cin>>a; 
	switch(a)   //括号中只能放入整数或字符型 
	{
		case 10:  //结果为10的情况下   ，注意用冒号 
			cout<<"好"<<endl;
			break;   //退出switch分支     
		case 9: 
			cout<<"好"<<endl;
			break;   //退出switch分支   
		case 8:
			cout<<"一般"<<endl;
			break;
		case 7:
		cout<<"一般"<<endl;
		break;
		default:   //不满足上述所有条件时执行 
		cout<<"不好"<<endl; 
		break;  	
	}
	system("pause");
	return 0; 
} 
