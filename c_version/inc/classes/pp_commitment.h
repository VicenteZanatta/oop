#ifndef PPCOMMITMENT_H
#define PPCOMMITMENT_H

#include "classes/commitment.h"

typedef struct postponableCommitment ppCommitment;

ppCommitment* creatPPCommitment(char* arg_idString, char arg_type, int arg_id, 
                                char* arg_date, char* arg_time, int arg_duration, 
                                int arg_priority, int arg_priorityFactor, bool arg_postponeable);


void destroyPPCommitment(Commitment* com); //destruc method

#endif