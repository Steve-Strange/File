#include<iostream>
using namespace std;
int main(){
	for (int i=0;i<=100;i++)
	{
		if (i%2==0){
			continue;     //continue ֱ���������沿�֣�������һ��ѭ����  break��ֱ����ֹѭ�� 
		}
		cout<<i<<endl;
	 } 
	system("pause");
	return 0;
} 
