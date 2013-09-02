#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char* str = (char*) malloc(10 * sizeof(char));
    while (1)
    {
        printf("\nplease input new command:('exit' to exit)");
        scanf("%s",str);
        if(strcmp(str,"exit") == 0)
        {
            break;
        }
        else
        {
            system(str);
        }
    }
    exit(EXIT_SUCCESS);
}
