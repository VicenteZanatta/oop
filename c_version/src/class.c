#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/class.h"
#include "../inc/commitment.h"

typedef struct class
{
    Commitment* com;
    char name[50];
    char* level;
} Class;

Class* initClass(){

    Class* cla = malloc(sizeof(Class));
    Commitment* com = initCommitment();

    cla->com = com;

    return cla;
}


