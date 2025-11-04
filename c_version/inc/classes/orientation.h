#ifndef ORIENTATION_H
#define ORIENTATION_H

#include <stdbool.h>
#include "classes/commitment.h"


typedef struct orientation Orientation;

Orientation* creatOrientation(char* arg_idString, char arg_type, int arg_id, 
                                char* arg_date, char* arg_time, int arg_duration, 
                                int arg_priority,  bool postponeable, char* arg_studentName, char* arg_level);

void destroyOrientation(Commitment* com);

#endif