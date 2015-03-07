milhouse[99]% more hello.c
#include<stdio.h>

main ( )
{
  printf("hello \n");
  fork();
  printf("  I am a process \n");
}
milhouse[100]% cc hello.c
milhouse[101]% a.out
hello //why do you see only one hello?
I am a process //why do you see two statements?
  I am a process 
milhouse[102]%

