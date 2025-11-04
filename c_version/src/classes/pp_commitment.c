#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../inc/classes/commitment.h"

// Class Postponable Commitments heritage from Class Commitment

typedef struct postponableCommitment{

    Commitment* com;
    bool postponable;

}ppCommitment; 

ppCommitment* creatPPCommitment(char* arg_idString, char arg_type, int arg_id, 
                                char* arg_date, char* arg_time, int arg_duration, 
                                int arg_priority,  int arg_priorityFactor, bool arg_postponeable){

    ppCommitment* ppCom = malloc(sizeof(ppCommitment));

    ppCom->com = creatCommitment(arg_idString, arg_type, arg_id, arg_date, arg_time, 
                                    arg_duration, arg_priority, arg_priorityFactor);
    
    ppCom->postponable = arg_postponeable;

    if(!(ppCom->postponable))         
        increaseMultiplier(ppCom->com);

    return ppCom;
                                       
}

void destroyPPCommitment(Commitment* Com){

    ppCommitment* ppCom = (ppCommitment*)ppCom;
    
    destroyCommitment(ppCom->com);

    free(ppCom);
}