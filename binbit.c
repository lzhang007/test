#include<stdio.h>

void itobs(int,char*);
void showBstr(const char*);

int main()
{
    char binStr[sizeof(int) * 8 + 1];
    int num;

    puts("enter a integer and see them in binary:");
    while(scanf("%d",&num) == 1)
    {
        itobs(num,binStr);
        printf("%d is :",num);
        showBstr(binStr);
        putchar('\n');
    }
    puts("bye!");
    return 0;
}
void itobs(int n,char *ps)
{
    int i;
    static size = 8 * sizeof(int);
    for(i = size - 1; i >= 0; i--)
    {
        ps[i] = (01 & n) + '0';
        n >>= 1;
    }
    ps[size] = '\0';
}
void showBstr(const char *ps)
{
    int i = 0;
    while(ps[i])
    {
        putchar(ps[i]);
        if( ++i % 4 == 0 && ps[i])
            putchar(' ');
    }
}
