#include <stdio.h>
#include <windows.h>

#define SPACE ' '//�ո� 
#define CS 3//�ڴ˸�����Կ 
//���ܣ��������ģ�������CS������ĳ��䡾�෴����
int main() {
	char ch;
	printf("Please type Your Words\nEnter to solve:");
	ch = getchar();
	while (ch != '\n') { //���н���
		if (ch == SPACE)
			putchar(ch);
		else
			putchar(ch + CS);
		ch = getchar(); //��ȡ��һ���ַ�
	}
	system("pause");
	return 0;
}
