#include<stdio.h>

int main(void)
{
    printf("print int test\n");
    printf("int 20 %%6d:%6d\n",20);
    printf("int 20 %%-6d:%-6d\n",20);

    printf("int 20 %%+6d:%+6d\n",20);
    printf("int 20 %%06d:%06d\n",20);
    printf("int 20 %%#o:%#o\n",20);
    printf("int 20 %%#x:%#x\n",20);
    return 0;
}
