#include<stdio.h>
#include<stdlib.h>
#include<sys/times.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<time.h>
#include<unistd.h>

void time_print(char *,clock_t);

int main(void)
{
		pid_t pid;
		clock_t start,end;
		struct tms t_start,t_end;
		start = times(&t_start);
//		system("grep the /usr/src/linux-source-2.6.39.4/Documentation/*/* > /dev/null 2> /dev/null");	
		pid = fork();
		if (pid < 0)
		{
			printf("fork error");
		}
		else if (pid == 0)
		{
			if ( execl("./test002plus","test002plus",NULL) < 0 )
			{
				printf("error on execl");
			}
		}		
		else
		{
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
