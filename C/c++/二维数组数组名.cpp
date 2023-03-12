#include<iostream>
using namespace std;
int main(){
	int arr[2][3]=
	{
		{1,2,3},
		{4,5,6}
	};
	cout<<sizeof(arr)<<endl<<sizeof(arr[0])<<endl<<sizeof(arr[0][0])<<endl;
	//    全空间内存           一行内存              一个元素内存 
	cout<<(sizeof(arr)/sizeof(arr[0]))<<endl<<(sizeof(arr[0])/sizeof(arr[0][0]))<<endl;
	//                行数                                  列数 
	cout<<arr<<endl<<(long long)arr<<endl<<(long long)arr[0]<<endl<<(long long)arr[1]<<endl<<(long long)&arr[0][1]<<endl;
	//                 数组首地址            第一行首地址           第二行首地址         第一行第二列元素地址 
	//                                                                                 加&为元素地址,不加 为元素
	
	
	  
 
	system("pause");
	return 0;
} 
