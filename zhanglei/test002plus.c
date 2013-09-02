#include<stdio.h>

int main()
{
	double i,result = 1; 
	for(i = 1; i < 10000000; i++ )
	{
		result *= i;
	}
	printf("child process\n");
	return 0;
}
