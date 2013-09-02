#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFSIZE 1024
#define SLEN 50

void append(FILE *,FILE *);

int main()
{
    FILE *fa,*fs;
    int files = 0;
    char file_app[SLEN],file_src[SLEN];

    puts("enter name of destination file:");
    gets(file_app);
    if((fa = fopen(file_app,"a")) == NULL)
    {
        fprintf(stderr,"can't open file %s.\n",file_app);
        exit(1);
    }
    if(setvbuf(fa,NULL,_IOFBF,BUFSIZE) != 0)
    {
        fprintf(stderr,"can't set buffer for file %s\n",file_app);
        exit(1);
    }
    puts("enter the name of first source file:");
    while(gets(file_src) != NULL && file_src[0] != '\0')
    {
        if(strcmp(file_app,file_src) == 0)
        {
            fputs("can't append file to itself\n",stdout);
        }
        else if((fs = fopen(file_src,"r")) == NULL)
        {
            fputs("can't open src file\n",stderr);
        }
        else
        {
            if(setvbuf(fs,NULL,_IOFBF,BUFSIZE) != 0)
            {
                fprintf(stderr,"can't set buffer for file %s\n",file_src);
                fclose(fs);
                continue;
            }
            append(fa,fs);
            fclose(fs);
            files++;
            printf("file %s appended.\n",file_src);
            puts("next file(empty line to quit)");
        }
    }
    printf("Done,%d files appended.\n",files);
    fclose(fa);
    return 0;
}

void append(FILE *fa,FILE *fs)
{
    size_t bytes;
    static char buffer[BUFSIZE];
    while((bytes = fread(buffer,sizeof(char),BUFSIZE,fs)) > 0)
        fwrite(buffer,sizeof(char),bytes,fa);
}
