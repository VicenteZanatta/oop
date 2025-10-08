#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/commitment.h"

typedef struct commitment{

    char type;
    int id;
    char date[10]; //format dd/mm/yyyy
    char time[5]; //format hh:mm
    int duration; // in minutes
    int priority;
    void* specific_Data; //pointer for class contaning specific data struct for each type of commitment
 
}Commitment;

Commitment* initCommitment() {
    Commitment* com = malloc(sizeof(Commitment));
    return com;
}

void registerCommitment(Commitment* com, char type, int id, char *date, char *time, int duration, int priority) {
    if (com == NULL) return;

    com->type = type;
    com->id = id;

    strncpy(com->date, date, sizeof(com->date) - 1);
    com->date[sizeof(com->date) - 1] = '\0';

    strncpy(com->time, time, sizeof(com->time) - 1);
    com->time[sizeof(com->time) - 1] = '\0';

    com->duration = duration;
    com->priority = priority;
}

void printCommitment(Commitment* com) {
    if (com == NULL) return;

    printf("commitment:\n");
    printf("  Type: %c\n", com->type);
    printf("  ID: %d\n", com->id);
    printf("  Date: %s\n", com->date);
    printf("  Time: %s\n", com->time);
    printf("  Duration: %d\n", com->duration);
    printf("  Priority: %d\n", com->priority);
}


