#include<iostream>
using namespace std;
int main(){
	int arr[2][3]=
	{
		{1,2,3},
		{4,5,6}
	};
	cout<<sizeof(arr)<<endl<<sizeof(arr[0])<<endl<<sizeof(arr[0][0])<<endl;
	//    ȫ�ռ��ڴ�           һ���ڴ�              һ��Ԫ���ڴ� 
	cout<<(sizeof(arr)/sizeof(arr[0]))<<endl<<(sizeof(arr[0])/sizeof(arr[0][0]))<<endl;
	//                ����                                  ���� 
	cout<<arr<<endl<<(long long)arr<<endl<<(long long)arr[0]<<endl<<(long long)arr[1]<<endl<<(long long)&arr[0][1]<<endl;
	//                 �����׵�ַ            ��һ���׵�ַ           �ڶ����׵�ַ         ��һ�еڶ���Ԫ�ص�ַ 
	//                                                                                 ��&ΪԪ�ص�ַ,���� ΪԪ��
	
	
	  
 
	system("pause");
	return 0;
} 
