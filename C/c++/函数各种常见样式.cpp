#include<iostream>
using namespace std;

//����������ʽ���޲��޷����в��޷����޲��з����в��з�
 
 //�޲��޷�
 void test1()
 {
 	cout<<"this is test1"<<endl;
 }
 //�в��޷�
   void test2(int a)
 {
 	cout<<"this is test2"<<endl;
 }
 //�޲��з�
 int test3()
 {
 	cout<<"this is test3"<<endl;
 	return 1000;
  } 
 //�в��з�
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
