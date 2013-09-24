#include<stdio.h>

int main()
{
    typedef int a[10];
    int typedef b[10];
    printf("%d   %d\n",sizeof(a),sizeof(b));
    return 0;
}
