#include <iostream>
#include<string> 
using namespace std;

//结构体数组  sturct 结构体名 数组名[元素个数]={{},{}} 



main(){
struct student
{
	string name;
	int age;
	int score;
}; 
	struct student arr[3]={
		{"a",18,100},
		{"b",19,90},
		{"c",20,80}};

arr[2].name="d";
arr[2].age=18;
arr[2].score=70;

for (int i=0;i<3;i++)
{
	cout<<arr[i].name<<"  "<<arr[i].age<<"  "<<arr[i].score<<"\n";
}
system("pause");
return 0;
}
