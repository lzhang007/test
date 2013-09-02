#include<stdio.h>
#include<stdlib.h>

#define MAX 1024

int main(int argc,char *argv[])
{
    FILE *fa,*fb;
    char buffera[MAX];
    char bufferb[MAX];
    char *a,*b;
    if(argc != 3)
    {
        fprintf(stderr,"usage error");
        exit(1);
    }
    if( (fa = fopen(argv[1],"r")) == NULL)
    {
        fprintf(stderr,"can't open file");
        exit(2);
    }
    if( (fb = fopen(argv[2],"r")) == NULL)
    {
        fprintf(stderr,"can't open file");
        exit(2);
    }

    a = fgets(buffera,MAX,fa);
    b = fgets(bufferb,MAX,fb);
    while(1)   
    {
        if(a != NULL)
        {
            fputs(buffera,stdout);
            printf("aaa\n");
            a = fgets(buffera,MAX,fa);
        }
        if(b != NULL)
        {
            fputs(bufferb,stdout);
            printf("bbb\n");
            b = fgets(bufferb,MAX,fb);
        }
        if(a == NULL && b == NULL)
        {
            break;
        }
    }
    fclose(fa);
    fclose(fb);

    return 0;
}
