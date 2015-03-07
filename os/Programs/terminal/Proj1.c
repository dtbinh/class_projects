#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 80

int main(void)
{
    char *args[MAX_LINE/2 + 1];
    char **history[10];
    char stor[100];
    int should_run = 1;
    int status;
    int pID;
    int current = 0;
    int population = 0;
    
    while (should_run) {
        printf("osh> ");
        fflush(stdout);
        
        int count = 0;
        
        scanf("%[^\n]%*c", stor);
        
        char *result = strtok(stor, " ");
        
        while (result != NULL)
        {
            args[count] = result;
            result = strtok(NULL, " ");
            count++;
        }
        
        args[count] = NULL;
        
        if(strcmp(args[0], "!!")==0)
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
                if (population != 0) {
                    
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
                int convert = *args[1] - '0';
                convert--;
                if (convert >= 0 && convert < 10 && convert < population)
                    return execvp(history[convert][0], history[convert]);
                else
                    printf("The value entered is outside of the history size");
            }
            else
            {
                wait(&status);
            }
        }
        if(strcmp(args[0], "history")==0)
        {
            
            if (population > 0) {
                
                for (int i = 0; i < 10; i++)
                {
                    if (i < population) {
                        printf("running three \n");
                        printf("%d", population-i);
                        int j = 0;
                        while (history[i][j] != NULL) {
                            printf(" %s", history[i][j]);
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
            
            /*
             int k = 0;
             while (args[k] != NULL) {
             printf (" %s", args[k]);
             k++;
             }
             */
            printf("Running four \n");
            
            int l = 0;
            char *arg[80];
            history[current] = arg;
            while (args[l] != NULL) {
                printf("Running four loop \n");
                history[current][l] = args[l];
                //printf("%s", history[current][l]);
                //strcpy(history[current][l], args[l]);
                l++;
            }
            
            //history[current] = args;
            /*
             if (population > 0) {
             printf("%s", history[current-1][0]);
             printf("%s", history[current][0]);
             }
             */
            
            if (current != 9)
            {
                current++;
                if (population < 10)
                    population ++;
            }
            
            else
            {
                current = 0;
                if (population < 10) {
                    population++;
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
