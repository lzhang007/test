#include<stdio.h>

void to_binary(unsigned long n)
{
    if(n > 1)
        to_binary(n/2);
    putchar(n%2 ? '1':'0');
    return;
}
