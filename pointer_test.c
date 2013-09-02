#include<stdio.h>

int main(void)
{
    int a = 20;
    printf("a = %d,&a = %p,sizeof(&a)=%d\n",a,&a,sizeof(&a));
    char* s;
    int* i;
    double *d;
    printf("%d.%d,%d\n",sizeof(s),sizeof(i),sizeof(d));
    return 0;
}
