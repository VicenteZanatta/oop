#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "classes/commitment.h"
#include "classes/pp_commitment.h"
#include "util/constants.h"

typedef struct departamentMeeting{

    ppCommitment* ppCom;

}DeptMeeting;


DeptMeeting* creatDeptMeeting(char* arg_idString, char arg_type, int arg_id, 
                                char* arg_date, char* arg_time, int arg_duration, 
                                int arg_priority, bool arg_postponeable){

    DeptMeeting* dptMeet = malloc(sizeof(DeptMeeting));

    dptMeet->ppCom = creatPPCommitment(arg_idString, arg_type, arg_id, arg_date, arg_time, 
                                        arg_duration, arg_priority, DEPT_MEETING_FACTOR, arg_postponeable);

    return dptMeet;
}

void destroyDeptMeeting(Commitment* com){

    DeptMeeting* dptMeet = (DeptMeeting*)com;
    
    destroyPPCommitment(dptMeet->ppCom);

    free(dptMeet);
}