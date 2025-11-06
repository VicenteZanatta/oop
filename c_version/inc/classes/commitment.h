#ifndef COMMITMENT_H
#define COMMITMENT_H

#include <stdio.h>

typedef struct commitment Commitment; 

Commitment* creatCommitment(char* idString, char type, int id, char *date, char *time, 
                            int duration, int priority, int priorityMuliplier);

void printCommitment(Commitment* com);

void increaseFactor(Commitment* com);

void destroyCommitment(Commitment* com);    //destruct method

void setDestroy(Commitment* com, void (*destroy)(Commitment*));

#endif
