#include <stdio.h>
#include <windows.h>

#define SPACE ' '//空格 
#define CS 3//在此更改密钥 
//解密：复制密文，把上面CS后的数改成其【相反数】
int main() {
	char ch;
	printf("Please type Your Words\nEnter to solve:");
	ch = getchar();
	while (ch != '\n') { //换行结束
		if (ch == SPACE)
			putchar(ch);
		else
			putchar(ch + CS);
		ch = getchar(); //获取下一个字符
	}
	system("pause");
	return 0;
}
