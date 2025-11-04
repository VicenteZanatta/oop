#ifndef DEPT_MEETING_H
#define DEPT_MEETING_H

#include "classes/commitment.h"

typedef struct departamentMeeting DeptMeeting;

DeptMeeting* creatDeptMeeting(char* arg_idString, char arg_type, int arg_id, 
                                char* arg_date, char* arg_time, int arg_duration, 
                                int arg_priority, bool arg_postponeable);

void destroyDeptMeeting(Commitment* com);

#endif