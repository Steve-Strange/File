#include<iostream>
using namespace std;

int main(){
	//实现数组逆置
	int arr[5]={1,3,2,5,4};
	int a=0,b=sizeof(arr)/sizeof(arr[0])-1,x=0;
	for (a;a<b;a++)
	{
		x=arr[a];  //用一个空档 调换数字 
		arr[a]=arr[b];
		arr[b]=x;
		b--;
	} 
	for (int i=0;i<5;i++)
	{
		cout<<arr[i]<<endl;
	 }	 
	system("pause");
	return 0;
}
