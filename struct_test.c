#include<stdio.h>

int main()
{
    typedef struct people
    {
        char name[10];  
    }P,*P1;
    printf("sizeof(P) = %d\n",sizeof(P));
    printf("sizeof(P1) = %d\n",sizeof(P1));
    return 0;
}
