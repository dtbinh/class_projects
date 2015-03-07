#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 80

int main(void)
{
    //holds current command
    char *args[MAX_LINE/2 + 1];
    //holds history
    char history[10][MAX_LINE];
    //used to read in and store tokens
    char stor[100];
    int should_run = 1;
    int status;
    int pID;
    int current = 0;
    //used to determine if the array has been fully populated
    int population = 0;
    
    while (should_run) {
        printf("osh> ");
        fflush(stdout);
        
        int count = 0;
        
        //scans in keyboard input data
        
        scanf("%[^\n]%*c", stor);
        
        char *result = strtok(stor, " ");
        
        while (result != NULL)
        {
            args[count] = result;
            result = strtok(NULL, " ");
            count++;
        }
        
        //adds a null to the end of the argument needed for execvp
        
        args[count] = NULL;
        
        //if satement for last command
        
        if(strcmp(args[0], "!!")==0)
        {
            
            pID = fork();
            
            //forks a thread
            
            if(pID < 0)
            {
                printf("Fork Failed");
                return 1;
            }
            else if(pID == 0)
            {
                if (population != 0) {

                    //if current loaction is not zero
                    if (current != 0)
                    {
                        //transfers data to args, I was having trouble with using the history array
                        int q = 1;
                        strcpy(args[0], &history[current-1][0]);
                        while (args[q] != NULL) {
                            strcat(args[q], &history[current-1][q]);
                            q++;
                        }
                        //executes las command
                        return execvp(&history[current-1][0], args);
                    }
                    //if command is zero start at top of array
                    else
                    {
                        int y = 1;
                        strcpy(args[0], &history[current-1][0]);
                        while (args[y] != NULL) {
                            strcat(args[y], &history[current-1][y]);
                            y++;
                        }
                        //executes last command
                        return execvp(&history[9][0], args);
                    }
                }
                else
                {
                    printf("There is nothing in the history \n");
                }
            }
            else
            {
                wait(&status);
            }
            
        }
        //allows for any command in the circle buffer to be accessed
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
                //converts input string to int
                int convert = *args[1] - '0';
                //minus one because the number the people enter will be 1 to 10
                convert--;
                
                //transfers data to args, I was having trouble with using the history array
                int z = 1;
                strcpy(args[0], &history[convert][0]);
                while (args[z] != NULL) {
                    printf("Running four loop \n");
                    strcat(args[z], &history[convert][z]);
                    z++;
                }
                //checks to make sure that you do not access numbers outside of the array or greater than population
                if (convert >= 0 && convert < 10 && convert < population)
                    return execvp(&history[convert][0], args);
                else
                    printf("The value entered is outside of the history size \n");
            }
            else
            {
                wait(&status);
            }
        }
        //checks for history command from user
        if(strcmp(args[0], "history")==0)
        {
            //makes sure that there is population before calling history
            if (population > 0) {
                //cycles through array
                for (int i = 0; i < 10; i++)
                {
                    //makes sure that the location is smaller than the population
                    if (i < population) {
                        printf("%d", 1+i);
                        printf(" %s", history[i]);
                        printf("\n");
                    }
                }
            }
            else
                printf("there is nothing in the history");
        }
        //user command loop
        else{
            
            int l = 1;
            //coppies the first element into the history
            strcpy(&history[current][0], args[0]);
            while (args[l] != NULL) {
                //concatinates the rest of the elements to the end of the array
                strcat(&history[current][l], args[l]);
                l++;
            }
            
            //if array position is not at max
            if (current != 9)
            {
                //adds to the current location
                current++;
                //makes sure nothing excedes population
                if (population < 10)
                    population ++;
            }
            //if position is max
            else
            {
                //resets postion to zero, completing circle buffer
                current = 0;
                //makes sure nothing exceeds population
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
