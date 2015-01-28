#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

main(int argc, char *argv[])
{
	int file, n, length;
	char buffer[1000];
	
	if (argc != 2)
	{
		printf("\nInsufficient arguments");
		exit(-1);
	}
	
	file = open(argv[1], O_APPEND|O_WRONLY|O_CREAT, 0644);
	if ( file < 0)
	{
		perror(argv[1]);
		exit(-1);
	}
	printf("\n Press Ctrl+D at the end of a new line ");
	
	while ( (n = read(0, buffer, sizeof(buffer)))>0)
	{
		length = strlen(buffer);
		write(file, buffer, length);
	}
	close(file);
}