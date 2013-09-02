/*count.c --using std io*/
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
    int ch;
    FILE *fp;
    long count = 0;

    if(argc != 2)
    {
        fprintf(stderr,"usage:%s filename\n",argv[0]);
        exit(1);
    }
    if((fp = fopen(argv[1],"r")) == NULL)
    {
        fprintf(stderr,"can't open file %s\n",argv[1]);
        exit(1);
    }
    while((ch = getc(fp)) != EOF)
    {
        putc(ch,stdout);
        count++;
    }
    fclose(fp);
    printf("File %s has %ld characters\n",argv[1],count);
    return 0;
}
