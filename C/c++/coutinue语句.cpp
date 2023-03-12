#include<iostream>
using namespace std;
int main(){
	for (int i=0;i<=100;i++)
	{
		if (i%2==0){
			continue;     //continue 直接跳过后面部分，进行下一次循环。  break是直接终止循环 
		}
		cout<<i<<endl;
	 } 
	system("pause");
	return 0;
} 
