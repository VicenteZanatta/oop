#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/classes/commitment.h"
#include "../inc/util/constants.h"

typedef struct commitment{

    char idString[ID_STRING_LENGHT];    // id in string type for print "A000000"
    char type;                          // first caracter of idString
    int id;                             // 6 digits from idString 
    char date[DATE_STRING_LENGHT];      // format dd/mm/yyyy
    char time[TIME_STRING_LENGHT];      // format hh:mm
    int duration;                       // in minutes
    int priority;
    int priorityFactor;       
    void* specific_Data;                // pointer for class contaning specific data struct for each type of commitment

    void (*destroy)(struct commitment*); //destruct method

}Commitment;

Commitment* creatCommitment(char* arg_idString, char arg_type, int arg_id, char *arg_date, char *arg_time, 
                            int arg_duration, int arg_priority, int arg_priorityFac) {
    
    Commitment* com = malloc(sizeof(Commitment));

    if(com == NULL){
        printf("ERROR WHILE CREATING [%s] COMMITMENT", arg_idString);
        return NULL;    
    }
    
    if (com == NULL) 
        return NULL;

    snprintf(com->idString, sizeof(com->idString), "%s", arg_idString);
    com->type = arg_type;
    com->id = arg_id;
    snprintf(com->date, sizeof(com->date), "%s", arg_date);
    snprintf(com->time, sizeof(com->time), "%s", arg_time);
    com->duration = arg_duration;
    com->priority = arg_priority;
    com->priorityFactor = arg_priorityFac;

    return com;
}

void printCommitment(Commitment* com) {
    
    if (com == NULL)
        printf("ERROR WHILE PRINTING [%s] COMMITIMENT", com->idString); 

    printf("\nID: %s", com->idString);
    printf("\nDate: %s", com->date);
    printf("\nTime: %s", com->time);
    printf("\nDuration: %d", com->duration);
    printf("\nPriority: %d", com->priority);
}

void increaseMultiplier(Commitment* com){

    com->priorityFactor += 1;
}

void destroyCommitment(Commitment* com){

    free(com);
}

