#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[])
{
	struct stat file;
	int n;
	if (argc != 2)
	{
		printf("Usage .. a.out <filename>\n");
		exit(-1);
	}
	if ((n = stat(argv[1], &file)) == -1)
	{
		perror(argv[1]);
		exit(-1);
	}
	printf("\n User id : %d", file.st_uid);
	printf("\n Group id is : %d",file.st_gid);
	printf("\n Block size is : %d", file.st_blksize);
	printf("\n Blocks allocated: %d",file.st_blocks);
	printf("\n Inode number: %d",file.st_ino);
	printf("\n Last accessed : %s",ctime(&(file.st_atime)));
	printf("\n Last modified : %d",ctime(&(file.st_mtime)));
	printf("\n File size : %d bytes",file.st_size);
	printf("\n Number of links : %d",file.st_nlink);
	
	printf("\n Permissions: \n");
	printf((S_ISDIR(file.st_mode)) ? "d" : "-");
	printf((file.st_mode & S_IRUSR) ? "r" : "-");
	printf((file.st_mode & S_IWUSR) ? "w" : "-");
	printf((file.st_mode & S_IXUSR) ? "x" : "-");
	printf((file.st_mode & S_IRGRP) ? "r" : "-");
	printf((file.st_mode & S_IWGRP) ? "w" : "-");
	printf((file.st_mode & S_IXGRP) ? "x" : "-");
	printf((file.st_mode & S_IROTH) ? "r" : "-");
	printf((file.st_mode & S_IWOTH) ? "w" : "-");
	printf((file.st_mode & S_IXOTH) ? "x" : "-");
	
	printf("\n");
	if (file.st_mode & S_IFREG)
		printf("\n File type : Regular");
	if (file.st_mode & S_IFDIR)
		printf("\n File type : Directory");
	
	
	
}