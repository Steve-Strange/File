#include<iostream>
using namespace std;

int main(){
	//ʵ����������
	int arr[5]={1,3,2,5,4};
	int a=0,b=sizeof(arr)/sizeof(arr[0])-1,x=0;
	for (a;a<b;a++)
	{
		x=arr[a];  //��һ���յ� �������� 
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
