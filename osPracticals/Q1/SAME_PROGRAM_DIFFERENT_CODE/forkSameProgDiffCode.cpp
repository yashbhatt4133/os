/**
 * Write a program (using fork() and/or exec() commands)
 * where parent and child execute the same program, 
 * different code.
 * 
 * 20HCS4148 RAJ RAUNAK KUMAR
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
  pid_t pidFork = fork();

  if (pidFork < 0)
    fprintf(stderr, "Error in fork()\n");
  else if (pidFork > 0)
    printf("PARENT: Forked Child\n");
  else
  {
    printf("CHILD: Parent Process ID: %d\n", getppid());
    printf("CHILD: Process ID: %d\n", getpid());
    exit(0);
  }

  return 0;
}
