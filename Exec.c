#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	pid_t pid;
	int i;
	if (argc != 3)
	{
		printf("\nInsufficient arguments to load program\n");
		printf("\nUsage: ./a.exe <path> <cmd>\n");
		exit(-1);
	}
	switch( pid = fork())
	{
		case -1: printf("\nFork failed! Unable to create process\n");
				exit(-1);
		case 0: printf("Child process:\n");
				i = execl(argv[1], argv[2], 0);
				if (i < 0)
				{
					printf("\nProgram not loaded using exec system call\n",argv[2]);
					exit(-1);
				}
		default: wait(NULL);
				 printf("\nChild terminated\n");
				 exit(0);
	}
}