#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/commitment.h"

typedef struct commitment{

    char IDchar[8];         // id in char type for print "A000000"
    char type;              // first caracter of IDchar
    int id;                 // 6 digits from IDchar 
    char date[11];          // format dd/mm/yyyy
    char time[6];           // format hh:mm
    int duration;           // in minutes
    int priority;       
    void* specific_Data;    // pointer for class contaning specific data struct for each type of commitment
 
}Commitment;

/*
    char IDchar[8];         
    char type;              
    int id = 0;                  
    char date[10];          
    char time[5];           
    int duration = 0;           
    int priority = 0;

*/

Commitment* initCommitment() {
    Commitment* com = malloc(sizeof(Commitment));
    return com;
}

Commitment* registerCommitment(char type, int id, char *date, char *time, int duration, int priority) {
    
    Commitment* com = initCommitment();
    
    if (com == NULL) 
        return -1;

    com->type = type;
    com->id = id;

    strncpy(com->date, date, sizeof(com->date) - 1);
    com->date[sizeof(com->date) - 1] = '\0';

    strncpy(com->time, time, sizeof(com->time) - 1);
    com->time[sizeof(com->time) - 1] = '\0';

    com->duration = duration;
    com->priority = priority;

    return com;
}

void printCommitment(Commitment* com) {
    if (com == NULL) 
        return;

    printf("\ncommitment:");
    printf("\nType: %c", com->type);
    printf("\nID: %d", com->id);
    printf("\nDate: %s", com->date);
    printf("\nTime: %s", com->time);
    printf("\nDuration: %d", com->duration);
    printf("\nPriority: %d", com->priority);
}


