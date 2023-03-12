#include<iostream>
using namespace std;

int main(){

	int a=0; 
	cout<<"请输入一个分数"<<endl;
	cin>>a;  //让用户赋值 给a  ">>"  即“给” 
	
	if (a>600)   //if后面不要加分号   
	{
		if(a>700){
			cout<<"清北"<<endl;
		}
		else if (a>650){
			cout<<"人大"<<endl;
		}
		else {
			cout<<"北航"<<endl;
		}
	 } 
	else if (a>500){
		cout<<"二本"<<endl;
	} 
	else {
		cout<<"没学上"<<endl;
	}
	system("pause");
	return 0;
} 
