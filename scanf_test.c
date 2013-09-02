#include<stdio.h>
#include<string.h>

int main(void)
{
    char name[20];
    printf("name:");
    scanf("%s",name);
    printf("hello %s\nsizeof name:%zd\nstrlen name:%d\n",name,sizeof name,strlen(name));
    return 0;
}
