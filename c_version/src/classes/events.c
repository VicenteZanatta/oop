#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../inc/classes/commitment.h"
#include "../inc/classes/pp_commitment.h"
#include "../inc/util/constants.h"

typedef struct event{
    
    ppCommitment* ppCom;
    char name[NAME_STRING_LENGHT];
    char local[NAME_STRING_LENGHT];
    
}Event;


Event* creatEvent(char* arg_idString, char arg_type, int arg_id, 
                                char* arg_date, char* arg_time, int arg_duration, 
                                int arg_priority, bool arg_postponeable, 
                                char* arg_eventName, char* arg_local){
    
    Event* event = malloc(sizeof(Event*));

    event->ppCom = creatPPCommitment(arg_idString, arg_type, arg_id, arg_date, arg_time, 
                                    arg_duration, arg_priority, EVENT_FACTOR, 
                                    arg_postponeable);

    snprintf(event->name, NAME_STRING_LENGHT, arg_eventName);
    snprintf(event->local, NAME_STRING_LENGHT, arg_local);

    return event;
}

void destroyEvent(Commitment* com){

    Event* event = (Event*)com;
    
    destroyPPCommitment(event->ppCom);

    free(event);
}
