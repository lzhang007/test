#include<stdio.h>

int main()
{
    enum color {red,orange=10,yellow,green,bule};
    enum color me;
    for(me = red;me <= bule;me++)
        printf("%d\t",me);
    puts("");
    return 0;
}
