#include<stdio.h>
#include<stdlib.h>

#define FLEN 50

int main()
{
    char file_name[FLEN];
    char ch;
    FILE *fp;
    long count,last;

    puts("enter the name of file to be processed:");
    gets(file_name);
    if((fp = fopen(file_name,"r")) == NULL)
    {
        fprintf(stderr,"can't open file : %s.\n",file_name);
        exit(1);
    }

    fseek(fp,0L,SEEK_END);
    last = ftell(fp);
    for (count = 1L; count <= last; count++)
    {
        fseek(fp,-count,SEEK_END);
        ch = getc(fp);
        if(ch != '\n')
        {
            putchar(ch);
        }
    }
    putchar('\n');
    fclose(fp);
    return 0;
}
