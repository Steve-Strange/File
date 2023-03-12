#include<iostream>
using namespace std;

int main(){
	//二维数组：数据类型  数组名称 [行数][列数] ={数据1，数据2，数据3，数据4};   也可省去一个  
	//或{{数据1，数据2},{数据3，数据4}};
	//或一个个赋值 
	int arr[2][3]; 
	arr[0][0]=1;
	arr[0][1]=2;  //第一行第二列   （0起始）  一个个赋值。 
	arr[0][2]=3;
	arr[1][0]=4;
	arr[1][1]=5;
	arr[1][2]=6;
	//输出，嵌套循环。
	for (int i=0;i<2;i++)
	{
		for (int j=0;j<3;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	 } 
	//第二种。
	int arr2[2][3]=
	{
		{1,2,3},
		{4,5,6}
	};
	
	//第三种
	int arr3[2][3]={1,2,3,4,5,6};
	//从左向右，从上到下 
	
	system("pause");
	return 0; 
} 
