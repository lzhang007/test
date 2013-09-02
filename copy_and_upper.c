#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(int argc,char *argv[])
{
    FILE *fs,*fd;
    int ch;

    if(argc != 3)
    {
        fprintf(stderr,"usage: %s src des\n",argv[0]);
        exit(1);
    }
    if((fs = fopen(argv[1],"r")) == NULL)
    {
        fprintf(stderr,"can't open file %s",argv[1]);
        exit(2);
    }
    if((fd = fopen(argv[2],"w")) == NULL)
    {
        fprintf(stderr,"can't open file %s",argv[2]);
        exit(2);
    }
    while((ch = getc(fs)) != EOF)
    {
        if(isalpha(ch))
        {
            ch = toupper(ch);
        }
        putc(ch,fd);
    }
    fclose(fs);
    fclose(fd);
    fprintf(stderr,"done");
    return 0;

}
