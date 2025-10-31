#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/commitment.h"

typedef struct commitment{

    char idString[8];       // id in string type for print "A000000"
    char type;              // first caracter of idString
    int id;                 // 6 digits from idString 
    char date[11];          // format dd/mm/yyyy
    char time[6];           // format hh:mm
    int duration;           // in minutes
    int priority;       
    void* specific_Data;    // pointer for class contaning specific data struct for each type of commitment
 
}Commitment;

Commitment* initCommitment() {
    Commitment* com = malloc(sizeof(Commitment));
    return com;
}

Commitment* registerCommitment(char* idString, char type, int id, char *date, char *time, int duration, int priority) {
    
    Commitment* com = initCommitment();
    
    if (com == NULL) 
        return;

    snprintf(com->idString, sizeof(com->idString), "%s", idString );
    com->type = type;
    com->id = id;
    snprintf(com->date, sizeof(com->date), "%s", date );
    snprintf(com->time, sizeof(com->time), "%s", time );
    com->duration = duration;
    com->priority = priority;

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


