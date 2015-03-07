#include <stdio.h>
#include <stdlib.h>

int main (void){
  /* the child process's new program
     this program replaces the parent's program */
  printf("process[%d]: child in execution\n", getpid());
  sleep(1);
  printf("process[%d]: child terminating...\n", getpid());
  exit(25);
}
