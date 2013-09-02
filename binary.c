#include <stdio.h>

int main(void)
{
    unsigned long number;
    printf("enter an integer(q to qiut):\n");
    while(scanf("%lu",&number) == 1)
    {
        printf("binary equivlent:");
        to_binary(number);
        putchar('\n');
        printf("enter an integer (q to quit):\n");
    }
    printf("Done.\n");
    return 0;
}
