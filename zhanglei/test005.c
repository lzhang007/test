#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
    pid_t pid;
    pid = fork();
    if (pid < 0)
    {
        printf("fork error\n");
    }
    else if (pid == 0)
    {
//        printf("Hello,I'm child process\n");
         if( execl("./test005plus","test005plus",NULL) < 0)
         {
            printf("execl error\n");
         }
    }		
    else
    {
        wait(NULL);
        printf("Hello,I'm parent process\n");
    }
    exit(EXIT_SUCCESS);
}
