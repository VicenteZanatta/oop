#ifndef COMMITMENT_H
#define COMMITMENT_H

#include <stdio.h>

typedef struct commitment Commitment;

Commitment* initCommitment();
void registerCommitment(Commitment* com, char type, int id, char *date, char *time, int duration, int priority);
void printCommitment(Commitment* com);

#endif
