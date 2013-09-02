/*add_word.c*/

#include<stdio.h>
#include<stdlib.h>

#define MAX 40

int main()
{
    FILE *fp;
    char words[MAX];

    if((fp = fopen("words","a+")) == NULL)
    {
        fprintf(stderr,"can't open \"words\" file .\n");
        exit(1);
    }
    puts("enter words to add the file(press enter key at the begining of a line to terminate.)");
    //puts() will add '\n' at the end of it
    //gets() will ignore '\n'
    while(gets(words) != NULL && words[0] != '\0')
    {
        fprintf(fp,"%s",words);
    }

    puts("file contents:");
    rewind(fp);
    while(fscanf(fp,"%s",words) == 1)
    {
        puts(words);
    }

    if(fclose(fp) != 0)
    {
        fprintf(stderr,"error closing file.\n");
        exit(1);
    }
    return 0;
}
