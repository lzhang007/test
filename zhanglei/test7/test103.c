#include <stdio.h>
#include<string.h>

int main()
{
    char *p = "asdfsdfdsg\nsadfsf\nsdf\n";
    int count = 0;
    while(1)
    {
        printf("%c",*p);
        if(*(p++) == '\0')
            break;
    }
    return 0;
}
