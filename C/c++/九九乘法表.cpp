#include<iostream>
using namespace std;

int main()
{
	int c;
	for (int a=1;a<=9;a++)
	{
		for (int b=1;b<=a;b++)
		{ 
		c=a*b;
		cout<<b<<"*"<<a<<"="<<c<<"  ";
		}
	cout<<""<<endl;
	}	
	system("pause");
	return 0;
}
