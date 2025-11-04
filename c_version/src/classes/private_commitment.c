#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "classes/pp_commitment.h"
#include "util/constants.h"

typedef struct privateCommitment
{
    ppCommitment* ppCom;
    char reason[REASON_STRING_LENGHT];

}Private;

Private* creatPrivate(char* arg_idString, char arg_type, int arg_id, char* arg_date, 
                        char* arg_time, int arg_duration, int arg_priority, 
                        bool arg_postponeable, char* arg_reason){

    Private* pvt = malloc(sizeof(Private));

    pvt->ppCom = creatPPCommitment(arg_idString, arg_type, arg_id, 
                                 arg_date, arg_time, arg_duration, 
                                 arg_priority, PRIVATE_FACTOR, arg_postponeable);

    snprintf(pvt->reason, REASON_STRING_LENGHT, arg_reason);    
}
