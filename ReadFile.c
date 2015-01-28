#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

main(int argc, char *argv[])
{
	int file, n;
	char buffer[1000];
	
	if (argc != 2)
	{
		printf("\nInsufficient arguments");
		exit(-1);
	}
	
	file = open(argv[1], O_RDONLY);
	if ( file == -1)
	{
		printf("\n File couldn't be retrieved : %s",argv[1]);
		exit(-1);
	}
	printf("n Contents of the file : %s is \n", argv[1]);
	while (read(file, buffer, sizeof(buffer))>0)
	{
		printf("%s ", buffer);
	}
	close(file);
}