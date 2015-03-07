#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#define MAX_LINE 80 /* The maximum length command */
int main(void)
{
    char **log[10];
    int current = 0;
    char *args[MAX_LINE/2 + 1]; /* command line arguments */
    char cmd[MAX_LINE];
    int should_run = 1; /* flag to determine when to exit program */
    while (should_run) {
        printf("osh>");
        fflush(stdout);
        int i=0;
        /**
         * After reading user input, the steps are:
         * (1) fork a child process using fork()
         * (2) the child process will invoke execvp()
         * (3) if command included &, parent will invoke wait() */
        getline("%s", args);
        while (scan.next != "\n") {
            cmd = scanf(getline);
            args[i] = cmd;
            i++;
        }
        args[i] = NULL;
        /*
        if (strncmp(&args[0], "!!", 100))
        {
            //printf("one!!");
            execvp(&log[current-1][0], &log[current-1]);
        }
         
        if (strncmp(&args[0], "!", 100))
        {
            //printf("two!");
            execvp(&log[args[1]][0], &log[args[1]]);
        }
        
        if (strncmp(&args[0], "history", 100))
        {
            //printf("two!");
            for(int i = 0; i < 10; i++)
            {
                printf(10-i);
                printf(log[i]/n);
            }
        }
        
        //else
        //{
            log[current] = args;
            if (current != 9)
                current++;
            else
                current = 0;

            execvp(args[0], args);
            
            //printf("else");
        //}
         */
        
    }
    return 0;
}
