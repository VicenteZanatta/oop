#ifndef EVENTS_H
#define EVENTS_H

#include "classes/commitment.h"

typedef struct event Event;

Event* creatEvent(char* arg_idString, char arg_type, int arg_id, 
                                char* arg_date, char* arg_time, int arg_duration, 
                                int arg_priority, bool arg_postponeable, 
                                char* arg_eventName, char* arg_local);

void destroyEvent(Commitment* com);

#endif