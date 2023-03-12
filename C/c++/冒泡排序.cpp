#include<iostream>
#include<cstdlib> 
using namespace std;

int main(){
	int a,b,c,d,e,f,y;
	cin>>a;
	cin>>b;
	cin>>c;
	cin>>d;
	cin>>e;
	cin>>f;
	int arr[6]={a,b,c,d,e,f};
	for (int i=0;i<5;i++)
	{
		for (int x=0;x<5-i+1;x++)
		{
			if (arr[x]<arr[x+1])
			{
				y=arr[x];
				arr[x]=arr[x+1];
				arr[x+1]=y;
			}
		}
	}
	for (int z=0;z<6;z++)
	{
		cout<<arr[z]<<",";
	}
	system("pause");
	return 0;
}	
