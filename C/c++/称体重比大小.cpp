#include<iostream>
using namespace std;
int main()
{ 
	//五只小猪称体重，输出最大的
	int a,b,c,d,e;
	cin>>a;
	cin>>b;
	cin>>c;
	cin>>d;
	cin>>e;
	int arr[5]={a,b,c,d,e};
	int max=0;  //先认定一个最大值0
	for (int i=0;i<5;i++)
	{
		if (arr[i]>max)
		{
			max=arr[i];
		}
	 } 
	 cout<<max<<endl;
	system("pause");
	return 0;
}
