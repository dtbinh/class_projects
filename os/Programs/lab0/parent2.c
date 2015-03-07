#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
  int pidvalue;
    
    //bank of 10 forked children
    
  pidvalue = fork();
  printf("pidvalue = %d\n",pidvalue);
  if (pidvalue == 0) /* this is the child process */
    {
      printf("entered child process1\n");
      execlp("./child.out", "./child.out", NULL);
      printf("oh no, got here\n");
      exit(0);    /* should never get here, terminate*/
    }
  pidvalue = fork();
  printf("pidvalue = %d\n",pidvalue);
  if (pidvalue == 0) /* this is the child process */
    {
      printf("entered child process2\n");
      execlp("./child.out", "./child.out", NULL);
      printf("oh no, got here\n");
      exit(0);    /* should never get here, terminate*/
    }
  pidvalue = fork();
  printf("pidvalue = %d\n",pidvalue);
  if (pidvalue == 0) /* this is the child process */
    {
      printf("entered child process3\n");
      execlp("./child.out", "./child.out", NULL);
      printf("oh no, got here\n");
      exit(0);    /* should never get here, terminate*/
    }
  pidvalue = fork();
  printf("pidvalue = %d\n",pidvalue);
  if (pidvalue == 0) /* this is the child process */
    {
      printf("entered child process4\n");
      execlp("./child.out", "./child.out", NULL);
      printf("oh no, got here\n");
      exit(0);    /* should never get here, terminate*/
    }
  pidvalue = fork();
  printf("pidvalue = %d\n",pidvalue);
  if (pidvalue == 0) /* this is the child process */
    {
      printf("entered child process5\n");
      execlp("./child.out", "./child.out", NULL);
      printf("oh no, got here\n");
      exit(0);    /* should never get here, terminate*/
    }
  pidvalue = fork();
  printf("pidvalue = %d\n",pidvalue);
  if (pidvalue == 0) /* this is the child process */
    {
      printf("entered child process6\n");
      execlp("./child.out", "./child.out", NULL);
      printf("oh no, got here\n");
      exit(0);    /* should never get here, terminate*/
    }
  pidvalue = fork();
  printf("pidvalue = %d\n",pidvalue);
  if (pidvalue == 0) /* this is the child process */
    {
      printf("entered child process7\n");
      execlp("./child.out", "./child.out", NULL);
      printf("oh no, got here\n");
      exit(0);    /* should never get here, terminate*/
    }
  pidvalue = fork();
  printf("pidvalue = %d\n",pidvalue);
  if (pidvalue == 0) /* this is the child process */
    {
      printf("entered child process8\n");
      execlp("./child.out", "./child.out", NULL);
      printf("oh no, got here\n");
      exit(0);    /* should never get here, terminate*/
    }
  pidvalue = fork();
  printf("pidvalue = %d\n",pidvalue);
  if (pidvalue == 0) /* this is the child process */
    {
      printf("entered child process9\n");
      execlp("./child.out", "./child.out", NULL);
      printf("oh no, got here\n");
      exit(0);    /* should never get here, terminate*/
    }
  pidvalue = fork();
  printf("pidvalue = %d\n",pidvalue);
  if (pidvalue == 0) /* this is the child process */
    {
      printf("entered child process10\n");
      execlp("./child.out", "./child.out", NULL);
      printf("oh no, got here\n");
      exit(0);    /* should never get here, terminate*/
    }
  else  /* parent code here */
    { printf("process[%d]: parent in execution...\n", getpid());
      sleep(10);
      if (wait(NULL)> 0)  /* child terminating */
	printf("process id [%d]: parent process detects terminating child\n",
	       getpid());
      printf("process[%d]:parent terminating....\n",getpid());
    }

}
