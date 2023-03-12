#include <iostream>
#include<string> 
using namespace std;

//结构体嵌套 

main(){
struct student
{
	string name;
	int age;
	int score;
}; 

struct teacher
{
	string name;
	int age;
	struct student st;
 } ;
 
struct teacher t={"a",50,
};
t.st.name="b";
t.st.age=18;
t.st.score=100;  //两个. 

cout<<t.name<<" "<<t.age<<" "<<t.st.name<<"\n";

system("pause");
return 0;
}
