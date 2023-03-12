#include <stdio.h> 

void UpperCase(char str[]) // 将str中的小写字母转换成大写字母
 {
int i; printf("Uppercase: %lu\n", sizeof(str)); for( i = 0; str[i] != '\0'; ++i ) if(str[i] >= 'a' && str[i] <= 'z') str[i] -= ('a'-'A' );
}
	
int main()
 {
char str[] = "aBcDe"; printf("the length of str is: %lu\n", sizeof(str)); UpperCase( str ); printf("%s\n", str); return 0;
}
