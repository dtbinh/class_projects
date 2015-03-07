#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#define MAX_LINE 80 /* The maximum length command */
int main(void)
{
    int pidvalue;
    //string input;
    char cmds[10][MAX_LINE/2 + 1];
    int compareLimit = MAX_LINE/2 + 1;
    int current = 0;
    char *args0[MAX_LINE/2 + 1]; /* command line arguments */
    char *args1[MAX_LINE/2 + 1];
    char *args2[MAX_LINE/2 + 1];
    int should_run = 1; /* flag to determine when to exit program */
    while (should_run) { printf("osh>"); fflush(stdout);
        /**
         * After reading user input, the steps are:
         * (1) fork a child process using fork()
         * (2) the child process will invoke execvp()
         * (3) if command included &, parent will invoke wait() */
        printf("scanning in");
        scanf("%s", &args0);
        scanf("%s", &args1);
        scanf("%s", &args2);
        printf("scanning done");
        if(strncmp(args0, "!!", compareLimit))
        {
            if (strncmp (cmds[current], "", compareLimit))
            {
                printf("no previous arguments");
            }
            else
            {
                execlp("cmds[current]", "cmds[current]", NULL);
                current++;
                //cmds[current][0] = args;
            }
        }
        if(strncmp(args0, "!", compareLimit))
        {
            for (int i; i < 10; i++) {
                //printf(cmds[i][0]);
            }
        }
        else
        {
            pidvalue = fork();
            printf("pidvalue = %d\n",pidvalue);
            if (pidvalue == 0) /* this is the child process */
            {
                execlp("args", "args", NULL);
                current++;
                //cmds[current][0] = args;
                exit(0);    /* should never get here, terminate*/
            }
        }
    }
    return 0;
}
