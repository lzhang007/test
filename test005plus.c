#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	int pid,fd;
        pid = getpid();
        fd = open ("SIX_FIFO",O_WRONLY);
	printf("pid",pid);
        write(fd,&pid,sizeof(pid));
        close(fd);
	exit(0);
}
