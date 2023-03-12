#include<iostream>
using namespace std;

//函数常见样式：无参无返，有参无返，无参有返，有参有返
 
 //无参无返
 void test1()
 {
 	cout<<"this is test1"<<endl;
 }
 //有参无返
   void test2(int a)
 {
 	cout<<"this is test2"<<endl;
 }
 //无参有返
 int test3()
 {
 	cout<<"this is test3"<<endl;
 	return 1000;
  } 
 //有参有返
 int test4(int b)
 {
 	cout<<"this is test4"<<endl<<b<<endl;
 	return b;
  } 
 
 int main(){
 	
 	test1();
 	
 	test2(100);
 	
 	int x=test3();
 	
 	int y=test4(10000);
 	cout<<x<<endl<<y<<endl;
 	system("pause");
	 return 0; 
 }
