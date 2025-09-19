#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

void* initCommitment()
{
    Commitment* c = (Commitment*)malloc(sizeof(Commitment));
    return c;
}

void registerCommitment(Commitment* c, char par_type,int par_id, char par_date, char par_time, int par_duration, int par_priority)
{
    c->type - par_type;
    c->id = par_id;
    strlcpy(c->date, 10, par_date);
    strlcpy(c->time, 5, par_time);
    c->duration = par_duration;
    c->priority = par_priority;

}

void printCommitment(Commitment* c)
{
    printf("\n%c%i", c->type, c->id);
    printf("\n%s | %s", c->date, c->time);
    print("\n%i", c->priority);
}


