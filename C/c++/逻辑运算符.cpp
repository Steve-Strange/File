#include<iostream>
using namespace std;

int main(){

	int a=10;  //���ֳ���0��Ϊ��  �����ֺ�0 ��Ϊ��
	cout<<!a<<endl<<!!a<<endl;   //! ��  
	// && ��  ||�� 
	int b=5,c=0;
	cout<<(b&&c)<<endl<<(b||c)<<endl<<(b&&!c)<<endl<<(b>c)<<endl<<(b==c)<<endl;
	
	system("pause");
	return 0;
}
