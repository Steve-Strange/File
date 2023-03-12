//数组  放在一个连续的内存空间中的一些具有相同数据类型的元素。
//用下标可以直接提取每一个元素

#include<iostream>
using namespace std;
int main(){

	int x[5];  
	x[0]=1;   // x[0] 下标从0开始，一一对应。 
	x[1]=2;
	x[2]=3;  //给各个位置的元素赋值  ，如果没赋值，默认为0  前提是给出了数组长度  
	x[3]=4;
	x[4]=5;
	cout<<x[3]<<endl;
	
	int y[5]={1,2,3,4,5};     //数组类型  数组名称[元素个数（可以省略）] ={各个元素}  
	for (int i=0;i<5;i++)
	{
		cout<<y[i]<<endl;
		}	
	system("pause");
	return 0;
}  
