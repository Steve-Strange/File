#include <stdio.h> 
int main() {
 int i;
char *ptr[] = {"Pascal", "Basic", "Fortran", "JavaOK", "C language"};
char **p; 
p=ptr;
for (i = 0; i < 5; i++) 
{
printf("%s\n", *p); p++;
}
printf("%c\n", *(*(--p) + 5)); 
return 0;
}
