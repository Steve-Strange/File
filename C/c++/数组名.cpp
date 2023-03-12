#include<iostream>
using namespace std;
int main()
{ 
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	cout<<sizeof(arr)<<endl<<sizeof(arr[5])<<endl<<(sizeof(arr)/sizeof(arr[0]))<<endl;   
	//查数组内存，每个元素内存，可以计算元素个数 
	cout<<arr<<endl<<(long long)arr<<endl;   //直接cout arr可以查看数组内存首地址   默认输出16进制， 用(long long)可转成10进制 
	cout<<(long long)&arr[0]<<endl<<(long long)&arr[1]<<endl;    // 元素前面加一个&  则代表该元素内存地址。 
	
	system("pause");
	return 0;
}
