/*����
1 ����ֵ����
2 ������
3 �����б� ����ʽ������ 
4 ���������
5 return ���ʽ
*/ 

//һ���ӷ����� �����������֣��������֮��
 
#include<iostream>
using namespace std;

	    int          add     (int a,int b)  //a b�����β� 
	// ����ֵ����  ������ �����б�a,b�� 
	{
		int sum=a+b;  //��������� 
		return sum;    //return���ʽ 
	}
int main(){
	// main�����е���֮ǰ����ĺ����� �������� ��ʵ�ʲ����� 
	int x;
	cin>>x;
	int y;
	cin>>y;
	int c=add(x,y);   //x y����ʵ�� �����ݸ��β� 
	cout<<c<<endl; 
	system("pause");
	
	return 0;
} 
