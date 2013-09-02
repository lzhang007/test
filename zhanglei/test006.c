#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<sys/time.h>
#include<sys/resource.h>
#include<unistd.h>
int main()
{
    int prio;
    pid_t pid;
    pid = fork();
    if (pid < 0)
    {
        printf("fork error\n");
    }
    else if (pid == 0)
    {
         if( execl("/usr/bin/find","find","/","-name","hda*",NULL) < 0)
         {
            printf("execl error\n");
         }
    }		
    else
    {
        prio = getpriority(PRIO_PROCESS,pid);
        if(setpriority(PRIO_PROCESS,pid,prio + 5) < 0)
        {
            printf("set priority error\n");
        }else
        {
            printf("set priority success\n");
        }
        wait(NULL);
        printf("child process over\n");
    }
    exit(EXIT_SUCCESS);
}
