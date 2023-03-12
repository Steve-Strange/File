#include <iostream>
#include<string> 
using namespace std;

//结构体指针 



main(){
struct student
{
	string name;
	int age;
	int score;
}; 
struct student s={"a",18,100};
struct student*p=&s;  //定义一个指针元素，并让它指向s 
cout<<p->name<<"  "<<p->age<<"  " <<p->score<<endl;
//用 -> 来访问元素的成员 


system("pause");
return 0;
}
