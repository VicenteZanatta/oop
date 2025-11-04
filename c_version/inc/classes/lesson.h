#ifndef LESSON_H
#define LESSON_H

#include "../inc/commitment.h"

typedef struct lesson Lesson;

Lesson* creatLesson(char *IdChar, char type, int id, 
                        char *date, char *time, int duration,
                        int priority, char* name, char* level);

void printLesson(Commitment* com);

#endif