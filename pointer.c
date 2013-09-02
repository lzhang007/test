#include<stdio.h>

int main(void)
{
    int urn[5] = {100,200,300,400};
    int * ptr1, * ptr2, * ptr3;
    ptr1 = urn;
    ptr2 = &urn[2];
    printf("ptr1 = %p,*ptr1 = %d,&ptr1 = %p\n",ptr1,*ptr1,&ptr1);
    ptr3 = ptr1 + 4;
    printf("ptr2 = %p,ptr1 + 4 = %p\n",ptr2,ptr3);
    printf("ptr3 - ptr1 = %d\n",ptr3 - ptr1);
    printf("*ptr3 + *ptr1 = %d\n",*ptr3 + *ptr1);
    return 0;
}
