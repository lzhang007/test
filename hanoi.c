#include<stdio.h>

void hanoi(int, char, char, char);
int main(void)
{
    hanoi(10,'a','b','c');
    return 0;
}

void hanoi(int n,char start,char middle,char end)
{
    if(n == 1)
        printf("move 1 from %c to %c\n",start,end);
    else
    {
        hanoi(n-1,start,end,middle);
        printf("move %d from %c to %c\n",n,start,end);
        hanoi(n-1,middle,start,end);
    }
}
