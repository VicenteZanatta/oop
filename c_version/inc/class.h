#ifndef CLASS_H
#define CLASS_H

#include "../inc/commitment.h"

typedef struct class Class;

Class* initClass();

Class* registerClass(char *IdChar, char type, int id, char *date, char *time, int duration, int priority, char* name, char* level);

void printClass(Class* class);

#endif