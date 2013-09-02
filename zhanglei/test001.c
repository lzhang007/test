#include<unistd.h>
#include<sys/types.h>

int main()
{
	printf("pid is %d\n",getpid());
	printf("ppid is %d\n",getppid());
	printf("uid is %d\n",getuid());
	printf("euid is %d\n",geteuid());
	printf("gid is %d\n",getgid());
	printf("egid is %d\n",getegid());
	return 0;
}
