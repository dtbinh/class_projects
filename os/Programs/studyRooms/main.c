//
//  main.c
//  studyRooms
//
//  Created by Jake Orben on 3/15/14.
//  Copyright (c) 2014 Jake Orben. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>

//initilizes system in strings
char stor[100], in0[100], in1[100], in2[100], in3[100], in4[100], in5[100], in6[100], in7[100];

//time constructor
typedef struct time {
    bool taken;
} time_u;

//node constructor (person)
typedef struct node {
    int ID;
    int priority;
    //0 is a student
    //1 is a teacher
    int classification;
} node_t;

//week day constructor
typedef struct weekDay {
    node_t personID[16];
    time_u time[16];
    int roomNum;
} weekDay_t;

//firday constructor
typedef struct friday {
    node_t personID[10];
    time_u time[10];
    int roomNum;
} friday_t;

//saturday constructor
typedef struct saturday {
    node_t personID[9];
    time_u time[9];
    int roomNum;
} saturday_t;

//sunday constructor
typedef struct sunday {
    node_t personID[12];
    time_u time[12];
    int roomNum;
} sunday_t;

//week constructor
typedef struct week {
    weekDay_t mon[26];
    friday_t fri[26];
    saturday_t sat[26];
    sunday_t sun[26];
} week_t;

//creates a week
week_t w(weekDay_t wd[], friday_t f[], saturday_t sd[], sunday_t sund[]){
    struct week this_week;
    
    for (int i = 0; i < 26; i++) {
        this_week.mon[i] = wd[i];
    }
    for (int i = 0; i < 26; i++) {
        this_week.fri[i] = f[i];
    }
    for (int i = 0; i < 26; i++) {
        this_week.sat[i] = sd[i];
    }
    for (int i = 0; i < 26; i++) {
        this_week.sun[i] = sund[i];
    }
    
    return this_week;
}

//creates a person
node_t p(int idIn, int priorityIn, int classificationIn) {
    
    struct node this_node;

    this_node.ID = idIn;
    this_node.priority = priorityIn;
    this_node.classification = classificationIn;
    
    return this_node;
}

//sets up weeks, has to be here because code compiles linearly
week_t c[4];

//runs the program, while the user is inputting data they remain in this loop
//also the loop called by POSIX thread
void *run(void *threadid){
    while(true){
    //used to escape if a user enters invalid hours
    top:
        //asks what user wants to do
        //almost everything has a while loop to deal with incorrect data
        printf("what would you like to do? Type command to list commands. \n");
        scanf("%[^\n]%*c", stor);
        if(strcmp(stor, "request")==0)
        {
            //taking in data for program
            printf("what is your ID? \n");
            scanf("%[^\n]%*c", in0);
            printf("what is your priority 1 lowest through 5 highest? \n");
            scanf("%[^\n]%*c", in1);
            if (atoi(in1) < 1 || atoi(in1) > 5){
                while (atoi(in1) < 1 || atoi(in1) > 5){
                    printf("invalid input, what is your priority 1 lowest through 5 highest? \n");
                    scanf("%[^\n]%*c", in1);
                }
            }
            //taking in data for program
            printf("what is your classification 0 for student and 1 for teacher? \n");
            scanf("%[^\n]%*c", in3);
            if (atoi(in3) < 0 || atoi(in3) > 1){
                while (atoi(in3) < 0 || atoi(in3) > 1){
                    printf("invalid input, what is your classification 0 for student and 1 for teacher? \n");
                    scanf("%[^\n]%*c", in3);
                }
            }
            //taking in data for program
            printf("what week would you like 1 through 4? \n");
            scanf("%[^\n]%*c", in2);
            if (atoi(in2) < 1 || atoi(in2) > 4){
                while (atoi(in2) < 1 || atoi(in2) > 4){
                    printf("invalid input, week would you like? \n");
                    scanf("%[^\n]%*c", in2);
                }
            }
            //taking in data for program
            printf("what hour would you like (in 24 hour format)? \n");
            scanf("%[^\n]%*c", in4);
            if (atoi(in4) < 1 || atoi(in4) > 24){
                while (atoi(in4) < 1 || atoi(in4) > 24){
                    printf("invalid input, what hour would you like (in 24 hour format)? \n");
                    scanf("%[^\n]%*c", in4);
                }
            }
            //taking in data for program
            printf("how long would you like between 1 and 3? \n");
            scanf("%[^\n]%*c", in5);
            if (atoi(in5) < 1 || atoi(in5) > 3){
                while (atoi(in5) < 1 || atoi(in5) > 3){
                    printf("invalid input, how long would you like between 1 and 3? \n");
                    scanf("%[^\n]%*c", in5);
                }
            }
            //taking in data for program
            printf("what room number would you like? \n");
            scanf("%[^\n]%*c", in6);
            if (atoi(in6) != 109 && atoi(in6) != 110 && atoi(in6) != 111 && atoi(in6) != 202 && atoi(in6) != 205 && atoi(in6) != 220 && atoi(in6) != 224 && atoi(in6) != 225 && atoi(in6) != 226 && atoi(in6) != 228 && atoi(in6) != 301 && atoi(in6) != 308 && atoi(in6) != 309 && atoi(in6) != 310 && atoi(in6) != 311 && atoi(in6) != 315 && atoi(in6) != 316 && atoi(in6) != 317 && atoi(in6) != 319 && atoi(in6) != 404 && atoi(in6) != 406 && atoi(in6) != 411 && atoi(in6) != 412 && atoi(in6) != 413 && atoi(in6) != 414 && atoi(in6) != 415){
                while (atoi(in6) != 109 && atoi(in6) != 110 && atoi(in6) != 111 && atoi(in6) != 202 && atoi(in6) != 205 && atoi(in6) != 220 && atoi(in6) != 224 && atoi(in6) != 225 && atoi(in6) != 226 && atoi(in6) != 228 && atoi(in6) != 301 && atoi(in6) != 308 && atoi(in6) != 309 && atoi(in6) != 310 && atoi(in6) != 311 && atoi(in6) != 315 && atoi(in6) != 316 && atoi(in6) != 317 && atoi(in6) != 319 && atoi(in6) != 404 && atoi(in6) != 406 && atoi(in6) != 411 && atoi(in6) != 412 && atoi(in6) != 413 && atoi(in6) != 414 && atoi(in6) != 415){
                    printf("invalid input, what room number would you like? \n");
                    scanf("%[^\n]%*c", in6);
                }
            }
            //taking in data for program
            printf("which day would you like? \n");
            scanf("%[^\n]%*c", in7);
            if (strcmp(in7, "monday")!=0 && strcmp(in7, "tuesday")!=0 && strcmp(in7, "wednesday")!=0 && strcmp(in7, "thursday")!=0 && strcmp(in7, "friday")!=0 && strcmp(in7, "saturday")!=0 && strcmp(in7, "sunday")!=0){
                while (strcmp(in7, "monday")!=0 && strcmp(in7, "tuesday")!=0 && strcmp(in7, "wednesday")!=0 && strcmp(in7, "thursday")!=0 && strcmp(in7, "friday")!=0 && strcmp(in7, "saturday")!=0 && strcmp(in7, "sunday")!=0){
                    printf("invalid input, which day would you like? \n");
                    scanf("%[^\n]%*c", in7);
                }
            }
            //if user wants to reserve a week day
            if (strcmp(in7, "monday")==0 || strcmp(in7, "tuesday")==0 || strcmp(in7, "wednesday")==0 || strcmp(in7, "thursday")==0){
                
                int roomNumber = 0;
                
                //translate room number into array value
                for (int i = 0; i < 26; i++) {
                    if (c[atoi(in2) - 1].mon[i].roomNum == atoi(in6))
                        roomNumber = i;
                }
                //checks for invalid time input
                for (int i = 0; i < atoi(in5); i++) {
                    if ((atoi(in4) - 8) < 0 || atoi(in4)-8 > 16){
                        printf("The time you have entered is invalid, returning to top of program. \n");
                        goto top;
                    }
                }
                //deals with input
                for (int i = atoi(in4)-8; i < atoi(in4)+atoi(in5)-8; i ++){
                    //if time is not taken
                    if (c[atoi(in2) - 1].mon[roomNumber].time[i].taken == false){
                        c[atoi(in2) - 1].mon[roomNumber].time[i].taken = true;
                        c[atoi(in2) - 1].mon[roomNumber].personID[i] = p(atoi(in0), atoi(in1), atoi(in3));
                    }
                    //if time is taken
                    else{
                        //higher priority gives overwright permission
                        if (c[atoi(in2) - 1].mon[roomNumber].personID[i].priority < atoi(in1)) {
                            printf("Priority override, the new request has a higher priority, previous user's time will be reduced or removed. \n");
                            c[atoi(in2) - 1].mon[roomNumber].personID[i] = p(atoi(in0), atoi(in1), atoi(in3));
                        }
                        //if priority is lower
                        else
                            printf("Your request cannot be met at this time, there is currently another user using the time requested. \n");
                    }
                }
            }
            
            //if user request friday
            if (strcmp(in7, "friday")==0) {
                
                int roomNumber = 0;
                
                //gets room index from room number
                for (int i = 0; i < 26; i++) {
                    if (c[atoi(in2) - 1].fri[i].roomNum == atoi(in6))
                        roomNumber = i;
                }
                
                //for invalid time input
                for (int i = 0; i < atoi(in5); i++) {
                    if ((atoi(in4) - 8) < 0 || atoi(in4)-8 > 10){
                        printf("The time you have entered is invalid returning to top. \n");
                        goto top;
                    }
                }
                
                //if time is free
                for (int i = atoi(in4)-8; i < atoi(in4)+atoi(in5)-8; i ++){
                    
                    if (c[atoi(in2) - 1].fri[roomNumber].time[i].taken == false){
                        c[atoi(in2) - 1].fri[roomNumber].time[i].taken = true;
                        c[atoi(in2) - 1].fri[roomNumber].personID[i] = p(atoi(in0), atoi(in1), atoi(in3));
                    }
                    
                    //if time is not free
                    else{
                        if (c[atoi(in2) - 1].fri[roomNumber].personID[i].priority < atoi(in1)) {
                            printf("Priority override, the new request has a higher priority, previous user's time will be reduced or removed. /n");
                            c[atoi(in2) - 1].fri[roomNumber].personID[i] = p(atoi(in0), atoi(in1), atoi(in3));
                        }
                        else
                            printf("Your request cannot be met at this time, there is currently another user using the time requested. \n");
                    }
                }
            }
            
            //if user requests saturday
            if (strcmp(in7, "saturday") == 0) {
                
                int roomNumber = 0;
                
                //gets room index from room number
                for (int i = 0; i < 26; i++) {
                    if (c[atoi(in2) - 1].sat[i].roomNum == atoi(in6))
                        roomNumber = i;
                }
                
                //checks for invalid input
                for (int i = 0; i < atoi(in5); i++) {
                    if ((atoi(in4) - 10) < 0 || atoi(in4)-10 > 9){
                        printf("The time you have entered is invalid, returning to top. \n");
                        goto top;
                    }
                }
                
                //if time is not taken
                for (int i = atoi(in4)-10; i < atoi(in4)+atoi(in5)-10; i ++){
                    
                    if (c[atoi(in2) - 1].sat[roomNumber].time[i].taken == false){
                        c[atoi(in2) - 1].sat[roomNumber].time[i].taken = true;
                        c[atoi(in2) - 1].sat[roomNumber].personID[i] = p(atoi(in0), atoi(in1), atoi(in3));
                    }
                    
                    //if time is taken
                    else {
                        if (c[atoi(in2) - 1].sat[roomNumber].personID[i].priority < atoi(in1)) {
                            printf("Priority override, the new request has a higher priority, previous user's time will be reduced or removed. \n");
                            c[atoi(in2) - 1].sat[roomNumber].personID[i] = p(atoi(in0), atoi(in1), atoi(in3));
                        }
                        else
                            printf("Your request cannot be met at this time, there is currently another user using the time requested. \n");
                    }
                }
            }
            
            //if user requests sunday
            if (strcmp(in7, "sunday") == 0) {
                
                int roomNumber = 0;
                
                //gets room index from room number
                for (int i = 0; i < 26; i++) {
                    if (c[atoi(in2) - 1].sun[i].roomNum == atoi(in6))
                        roomNumber = i;
                }
                
                //checks for invalid time
                for (int i = 0; i < atoi(in5); i++) {
                    if ((atoi(in4) - 11) < 0 || atoi(in4)-11 > 12){
                        printf("The time you have entered is invalid, returning to top. \n");
                        goto top;
                    }
                }
                
                //if time is not taken
                for (int i = atoi(in4)-11; i < atoi(in4)+atoi(in5)-11; i ++){
                    
                    if (c[atoi(in2) - 1].sun[roomNumber].time[i].taken == false){
                        c[atoi(in2) - 1].sun[roomNumber].time[i].taken = true;
                        c[atoi(in2) - 1].sun[roomNumber].personID[i] = p(atoi(in0), atoi(in1), atoi(in3));
                    }
                    
                    //if time is taken
                    else {
                        if (c[atoi(in2) - 1].sun[roomNumber].personID[i].priority < atoi(in1)) {
                            printf("Priority override, the new request has a higher priority, previous user's time will be reduced or removed. \n");
                            c[atoi(in2) - 1].sun[roomNumber].personID[i] = p(atoi(in0), atoi(in1), atoi(in3));
                        }
                        else
                            printf("Your request cannot be met at this time, there is currently another user using the time requested. \n");
                    }
                }
            }
        }
        //lists all of the currently taken times
        if(strcmp(stor, "list")==0){
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 26; j++){
                    for (int k = 0; k < 16; k++) {
                        if (c[i].mon[j].time[k].taken == true) {
                            printf("week %d, room %d monday time %d by id %d \n", i+1, c[i].mon[j].roomNum, k, c[i].mon[j].personID[k].ID);
                        }
                    }
                    for (int k = 0; k < 10; k++) {
                        if (c[i].fri[j].time[k].taken == true) {
                            printf("week %d, room %d monday time %d by id %d \n", i+1, c[i].mon[j].roomNum, k, c[i].mon[j].personID[k].ID);
                        }
                    }
                    for (int k = 0; k < 9; k++) {
                        if (c[i].sat[j].time[k].taken == true) {
                            printf("week %d, room %d monday time %d by id %d \n", i+1, c[i].mon[j].roomNum, k, c[i].mon[j].personID[k].ID);
                        }
                    }
                    for (int k = 0; k < 12; k++) {
                        if (c[i].sun[j].time[k].taken == true) {
                            printf("week %d, room %d monday time %d by id %d \n", i+1, c[i].mon[j].roomNum, k, c[i].mon[j].personID[k].ID);
                        }
                    }
                }
            }
        }
        //lists user commands
        if(strcmp(stor, "commands")==0){
            printf("reuqest (reserve time), list (prints table of reserved times), commdands (shows list of commands) and exit \n");
        }
        //exits program
        if(strcmp(stor, "exit")==0){
            pthread_exit(NULL);
            exit(0);
        }
        //catches any invalid input
        //runs after every command so that user always knows commands
        else
            printf("\n commands are as follows: reuqest (reserve time), list (prints table of reserved times), commdands (shows list of commands) and exit \n");
    }
}

int main() {
    
    //sets up room numbers for monday
    struct weekDay mon[26];
    mon[0].roomNum = 109;
    mon[1].roomNum = 110;
    mon[2].roomNum = 111;
    mon[3].roomNum = 202;
    mon[4].roomNum = 205;
    mon[5].roomNum = 220;
    mon[6].roomNum = 224;
    mon[7].roomNum = 225;
    mon[8].roomNum = 226;
    mon[9].roomNum = 228;
    mon[10].roomNum = 301;
    mon[11].roomNum = 308;
    mon[12].roomNum = 309;
    mon[13].roomNum = 310;
    mon[14].roomNum = 311;
    mon[15].roomNum = 315;
    mon[16].roomNum = 316;
    mon[17].roomNum = 317;
    mon[18].roomNum = 319;
    mon[19].roomNum = 404;
    mon[20].roomNum = 406;
    mon[21].roomNum = 411;
    mon[22].roomNum = 412;
    mon[23].roomNum = 413;
    mon[24].roomNum = 414;
    mon[25].roomNum = 415;
    
    //sets up room numbers for monday
    struct friday fri[26];
    fri[0].roomNum = 109;
    fri[1].roomNum = 110;
    fri[2].roomNum = 111;
    fri[3].roomNum = 202;
    fri[4].roomNum = 205;
    fri[5].roomNum = 220;
    fri[6].roomNum = 224;
    fri[7].roomNum = 225;
    fri[8].roomNum = 226;
    fri[9].roomNum = 228;
    fri[10].roomNum = 301;
    fri[11].roomNum = 308;
    fri[12].roomNum = 309;
    fri[13].roomNum = 310;
    fri[14].roomNum = 311;
    fri[15].roomNum = 315;
    fri[16].roomNum = 316;
    fri[17].roomNum = 317;
    fri[18].roomNum = 319;
    fri[19].roomNum = 404;
    fri[20].roomNum = 406;
    fri[21].roomNum = 411;
    fri[22].roomNum = 412;
    fri[23].roomNum = 413;
    fri[24].roomNum = 414;
    fri[25].roomNum = 415;
    
    //sets up room numbers for monday
    struct saturday sat[26];
    sat[0].roomNum = 109;
    sat[1].roomNum = 110;
    sat[2].roomNum = 111;
    sat[3].roomNum = 202;
    sat[4].roomNum = 205;
    sat[5].roomNum = 220;
    sat[6].roomNum = 224;
    sat[7].roomNum = 225;
    sat[8].roomNum = 226;
    sat[9].roomNum = 228;
    sat[10].roomNum = 301;
    sat[11].roomNum = 308;
    sat[12].roomNum = 309;
    sat[13].roomNum = 310;
    sat[14].roomNum = 311;
    sat[15].roomNum = 315;
    sat[16].roomNum = 316;
    sat[17].roomNum = 317;
    sat[18].roomNum = 319;
    sat[19].roomNum = 404;
    sat[20].roomNum = 406;
    sat[21].roomNum = 411;
    sat[22].roomNum = 412;
    sat[23].roomNum = 413;
    sat[24].roomNum = 414;
    sat[25].roomNum = 415;
    
    //sets up room numbers for monday
    struct sunday sun[26];
    sun[0].roomNum = 109;
    sun[1].roomNum = 110;
    sun[2].roomNum = 111;
    sun[3].roomNum = 202;
    sun[4].roomNum = 205;
    sun[5].roomNum = 220;
    sun[6].roomNum = 224;
    sun[7].roomNum = 225;
    sun[8].roomNum = 226;
    sun[9].roomNum = 228;
    sun[10].roomNum = 301;
    sun[11].roomNum = 308;
    sun[12].roomNum = 309;
    sun[13].roomNum = 310;
    sun[14].roomNum = 311;
    sun[15].roomNum = 315;
    sun[16].roomNum = 316;
    sun[17].roomNum = 317;
    sun[18].roomNum = 319;
    sun[19].roomNum = 404;
    sun[20].roomNum = 406;
    sun[21].roomNum = 411;
    sun[22].roomNum = 412;
    sun[23].roomNum = 413;
    sun[24].roomNum = 414;
    sun[25].roomNum = 415;
    
    //sets all values to false and -1
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 16; j++){
            mon[i].time[j].taken = false;
            mon[i].personID[j].classification = -1;
            mon[i].personID[j].ID = -1;
            mon[i].personID[j].priority = -1;
        }
    }
    
    //sets all values to false and -1
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 10; j++){
            fri[i].time[j].taken = false;
            fri[i].personID[j].classification = -1;
            fri[i].personID[j].ID = -1;
            fri[i].personID[j].priority = -1;
        }
    }
    
    //sets all values to false and -1
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 9; j++){
            sat[i].time[j].taken = false;
            sat[i].personID[j].classification = 0-1;
            sat[i].personID[j].ID = -1;
            sat[i].personID[j].priority = -1;
        }
    }
    
    //sets all values to false and -1
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 12; j++){
            sun[i].time[j].taken = false;
            sun[i].personID[j].classification = -1;
            sun[i].personID[j].ID = -1;
            sun[i].personID[j].priority = -1;
        }
    }
    
    //sets all values to false and -1
    for (int i = 0; i < 4; i++) {
        c[i] = w(mon, fri, sat, sun);
    }
    
    //creates pthread
    pthread_t threads[1];
    int rc;
    long t = 0;
    
    //can be altered to accecpt more than one user at a time, depening on number of threads set
    //for(t=0; t<5; t++){
        //printf("In main: creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, run, (void *)t);
        if (rc){
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    //}
    //exits pthread
    pthread_exit(NULL);
}