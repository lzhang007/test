#include<stdio.h>

int main()
{
    int i = 12345;
    FILE *b,*s;
    b = fopen("bin","w");
    s = fopen("str","w");
    fprintf(s,"%d",i);
    fwrite(&i,sizeof(int),1,b);
    fclose(b);
    fclose(s);
    return 0;
}
