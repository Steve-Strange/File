#include<iostream>
using namespace std;
int main(){
	for (int i=0; i<=100; i=i+1)
	{
		if (i/10==7||i%10==7||i%7==0)    //如果个位或十位为1  或是7的倍数，输出敲桌子   
		{
			cout<<"敲桌子"<<endl; 
		}
		else 
		{
			cout<<i<<endl;
		}
	}
	system("pause");
	return 0;
} 
