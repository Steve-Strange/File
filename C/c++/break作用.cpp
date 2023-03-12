#include<iostream>
using namespace std;
int main(){
	//break的作用      switch case default break。   for循环  break退出循环   嵌套循环  退出内层循环 
	cout<<"请选择难度：1、2、3"<< endl;
	int a;
	cin>>a; 
	switch(a)
	{
		case 1:
			cout<<"简单"<<endl;
			break;                 //避免顺序执行下去 
		case 2:
			cout<<"普通"<<endl;
			break;
		case 3:
			cout<<"困难"<<endl;
			break ;
	}
	
	for (int i=0;i<10;i++) 
	{
		if (i==5)
		{
			break;  //用if 加一个条件  满足就退出内层循环 
		}
		cout<<i<<endl;
	}
	
	for  (int x=0; x<10;x++)
	{
		for (int y=0 ; y<10;y++){
			if (y==5)
			{
				break;
			 } 
			 cout<<". ";
		}
		cout<<""<<endl;
	}	
	
	
	
	
	system("pause");
	return 0;
}
