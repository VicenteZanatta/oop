#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../inc/classes/commitment.h"
#include "../inc/classes/pp_commitment.h"
#include "../inc/util/constants.h"


typedef struct orientation
{
    ppCommitment* ppCom;
    char studentName[NAME_STRING_LENGHT];
    char level[NAME_STRING_LENGHT];

}Orientation;


Orientation* creatOrientation(char* arg_idString, char arg_type, int arg_id, 
                                char* arg_date, char* arg_time, int arg_duration, 
                                int arg_priority, bool arg_postponeable, char* arg_studentName, char* arg_level){

    Orientation* ort = malloc(sizeof(Orientation));

    ppCommitment* ppCom = creatPPCommitment(arg_idString, arg_type, arg_id, arg_date, 
                                         arg_time, arg_duration, arg_priority, ORIENTATION_FACTOR, arg_postponeable);

    ort->ppCom = ppCom;
    
    snprintf(ort->studentName, NAME_STRING_LENGHT, arg_studentName);
    snprintf(ort->level, NAME_STRING_LENGHT, arg_level);

    return ort;                                
}

void destroyOrientation(Commitment* com){

    Orientation* ort = (Orientation*)com;

    destroyPPCommitment(ort->ppCom);

    free(ort);   

}
