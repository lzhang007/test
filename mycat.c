//mycat.c cat a file 
#include<stdio.h>

int main(void)
{
    char ch;
    while((ch = getchar()) != EOF)
        putchar(ch);
    return 0;
}
