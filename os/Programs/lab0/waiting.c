#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
main ()
{
  int status;
  int pid;

  pid = fork();
  if (pid == 0)
    {printf("hello ");
    }
  else
    {wait(&status);
      printf(" world\n");
    }
}
