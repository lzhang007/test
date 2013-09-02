#include<stdio.h>
#include<stdlib.h>
#include<sys/times.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<time.h>
#include<unistd.h>
#include<sys/resource.h>

void time_print(char *,clock_t);

int main(void)
{
    pid_t pid;
    clock_t start,end;
    struct tms t_start,t_end;
    start = times(&t_start);
    pid = fork();
    if (pid < 0)
    {
        printf("fork error");
    }
    else if (pid == 0)
    {
        int i,j;
        char ch[500][500];
        for(i = 0;i < 500;i++)
        {
            for(j = 0;j < 500;j++)
            {
                ch[i][j] = 'a';
            }
        }
        exit(0);
    }		
    else
    {
        if(setpriority(PRIO_PROCESS,pid,10) < 0)
        {
            printf("set priority error\n");
        }else
        {
            printf("set priority success\n");
        }
        wait(NULL);
    }	
    end = times(&t_end);
    time_print("elapsed:",end-start);
    puts("parent times");
    time_print("\tuser CPU",t_end.tms_utime);
    time_print("\tsys CPU",t_end.tms_stime);

    puts("child times");
    time_print("\tuser CPU",t_end.tms_cutime);
    time_print("\tsys CPU",t_end.tms_cstime);

    exit(EXIT_SUCCESS);
}

void time_print(char *str, clock_t time)
{
    long tps = sysconf(_SC_CLK_TCK);
    printf("%s: %6.2f secs\n",str,(float)time/tps);
}
