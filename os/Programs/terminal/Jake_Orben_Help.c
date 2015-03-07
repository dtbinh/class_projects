#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 80

int main(void)
{
    char *args[MAX_LINE/2 + 1];
    int should_run = 1;
    int status;
    int pID;
    char test[100];
    int current = 0;
    char history[10][MAX_LINE];   // note change here DK
    int cycle = 0;
    
    //char cla1[10], cla2[10], cla3[10];
    
    while (should_run) {
        printf("osh> ");
        fflush(stdout);
        
        int count = 0;
        
        scanf("%[^\n]%*c", test);
        
        char *result = strtok(test, " ");
        
        while (result != NULL)
        {
            //result = strtok(NULL, " ");
            args[count] = result;
            // printf("%s", args[count]);
            result = strtok(NULL, " ");
            count++;
        }
        
        args[count] = NULL;
        
        /*   if(strcmp(args[0], "!!")==0)        NOTE: all the history stuff is commented out right now
        {            
            pID = fork();
            
            if(pID < 0)
            {
                printf("Fork Failed");
                return 1;
            }
            else if(pID == 0)
            {
                printf("Running one \n");
                if (cycle != 0) {
                    
                    if (current != 0)
                        return execvp(history[current-1][0], history[current-1]);
                    else
                    {
                        return execvp(history[9][0], history[9]);
                    }
                }
                else
                {
                    printf("There is nothing in the history");
                }
            }
            else
            {
                wait(&status);
            }
            
        }
        
        if(strcmp(args[0], "!")==0)
        {
            pID = fork();
            
            if(pID < 0)
            {
                printf("Fork Failed");
                return 1;
            }
            else if(pID == 0)
            {
                printf("Running two \n");
                int tran = *args[1] - '0';
                if (tran >+ 0 && tran < 10 && tran < cycle)
                    return execvp(history[tran][0], history[tran]);
                else
                    printf("The value entered is outside of the history size");
            }
            else
            {
                wait(&status);
            }
        }					NOTE commented out until here
            */
        if(strcmp(args[0], "history")==0)
        {
            
            if (cycle > 0) {
                
                for (int i = 0; i < 10; i++)
                {
                    if (i < cycle) {
                        printf("running three \n");
                        printf("%d", 10-i);
                        int j = 0;
                        /* while (history[i][j] != NULL)*/ {
                            printf("%s", history[i]);
                            j++;
                        }
                        printf("\n");
                    }
                }
            }
            else
                printf("there is nothing in the history");
        }
        
        else{
            
            //printf ("%s", args[0]);
            
            strcpy(history[current], args[0]);   //NOTE the change here DK
            //printf("%s", history[current][0]);
            if (current != 9)
            {
                current++;
                if (cycle < 10)
                    cycle ++;
            }
            
            else
            {
                current = 0;
                if (cycle < 10) {
                    cycle++;
                }
            }
            
            pID = fork();
            
            if(pID < 0)
            {
                printf("Fork Failed");
                return 1;
            }
            else if(pID == 0)
            {
                printf("pw \n");
                return execvp(args[0], args);
            }
            else
            {
                wait(&status);
            }
        }
    }
    return 0;
}

