#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
   
main() 
{ 
	 pid_t pid; 
	 int i = 0;
	 pid =  fork(); 
	if (pid < 0) {
			 printf("Process creation error");
			 exit(-1); 
	}
	else if (pid == 0) {
			 printf("\nChild process:"); 
			 for (i = 1; i < 10; i+=2)
			 {
				printf("\n %d",i);
			}
			printf("\nChild process ends");
	}
	 else{
			 wait(NULL);
			 printf("\nParent process:"); 
			 for (i = 0; i < 10; i+=2)
			 {
				printf("\n %d",i);
			}
			printf("\nParent process ends");
	}
 
 }