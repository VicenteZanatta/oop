#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "classes/commitment.h"
#include "classes/pp_commitment.h"
#include "util/constants.h"

typedef struct event{
    
    Commitment* Com;
    char name[NAME_STRING_LENGHT];
    char local[NAME_STRING_LENGHT];
    
}Event;


Event* creatEvent(char* arg_idString, char arg_type, int arg_id, 
                                char* arg_date, char* arg_time, int arg_duration, 
                                int arg_priority, bool arg_postponeable, 
                                char* arg_eventName, char* arg_local){
    
    Event* event = malloc(sizeof(Event*));

    event->Com = creatCommitment(arg_idString, arg_type, arg_id, arg_date, arg_time, 
                                    arg_duration, arg_priority, EVENT_FACTOR);

    snprintf(event->name, NAME_STRING_LENGHT, arg_eventName);
    snprintf(event->local, NAME_STRING_LENGHT, arg_local);

    return event;
}

void destroyEvent(Commitment* com){

    Event* event = (Event*)com;
    
    destroyCommitment(event->Com);

    free(event);
}
