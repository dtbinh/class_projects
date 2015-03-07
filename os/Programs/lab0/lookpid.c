#include <stdio.h>
#include <stdlib.h>
main ( )
{
  int pid;

  printf("hello \n");
  pid = fork ( );
  if (pid == -1)
    {
      perror("bad fork");
      exit(1);
    }
  if (pid == 0)
    {
      printf("I am the child process \n");
    }
  else
    {
      printf(" I am the parent process \n");
    }
}
