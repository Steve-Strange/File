#include<iostream>
using namespace std;
int main()
{ 
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	cout<<sizeof(arr)<<endl<<sizeof(arr[5])<<endl<<(sizeof(arr)/sizeof(arr[0]))<<endl;   
	//�������ڴ棬ÿ��Ԫ���ڴ棬���Լ���Ԫ�ظ��� 
	cout<<arr<<endl<<(long long)arr<<endl;   //ֱ��cout arr���Բ鿴�����ڴ��׵�ַ   Ĭ�����16���ƣ� ��(long long)��ת��10���� 
	cout<<(long long)&arr[0]<<endl<<(long long)&arr[1]<<endl;    // Ԫ��ǰ���һ��&  ������Ԫ���ڴ��ַ�� 
	
	system("pause");
	return 0;
}
