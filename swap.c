#include<stdio.h>

void swap(int *,int *);
void deep_swap(int **,int **);
int main(void)
{
    int a = 2,b = 4;
    printf("a = %d,&a = %p,b = %d,&b = %p\n\n",a,&a,b,&b);
    swap(&a,&b);
    printf("a = %d,&a = %p,b = %d,&b = %p\n",a,&a,b,&b);
    int *ad,*bd;
    ad = &a;
    bd = &b;
    deep_swap(&ad,&bd);
    printf("a = %d,&a = %p,b = %d,&b = %p\n",a,&a,b,&b);
    return 0;
}

void swap(int * a,int * b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void deep_swap(int **a,int **b)
{
    int **temp;
    *temp = *a;
    *a = *b;
    *b = *temp;
}
