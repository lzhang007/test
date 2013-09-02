#include<stdio.h>

int main(void)
{
    char c = 'a';
    printf("c = %c\n",c);
    c = 'acde';
    printf("c = %c\n",c);
    printf("sizeof('acde') = %d\n",sizeof('acde'));
    printf("sizeof('e') = %d\n",sizeof('e'));
    printf("sizeof(c) = %d\n",sizeof(c));
    return 0;
}
