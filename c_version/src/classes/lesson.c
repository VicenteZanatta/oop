#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/commitment.h"
#include "../inc/constants.h"

typedef struct lession
{
    Commitment* commData;
    char name[NAME_STRING_LENGHT];
    char level[NAME_STRING_LENGHT]; //need to change for options

} Lesson;


Lesson* creatLesson(char* arg_idString, char arg_type, int arg_id, char* arg_date, 
                    char *arg_time, int arg_duration, int arg_priority, 
                    char* arg_name, char* arg_level){
                        
    Lesson* lesson = malloc(sizeof(Lesson));

    if(lesson == NULL){
        printf("ERROR WHILE CREATING LESSION [%s]", arg_idString);
        return NULL;
    }
    
    Commitment* comm = creatCommitment(arg_idString, arg_type, arg_id, arg_date, 
                                        arg_time, arg_duration, arg_priority, EVENT_FACTOR);
    if(comm == NULL)
        return NULL;

    lesson->commData = comm;  
    
    snprintf(lesson->name, NAME_STRING_LENGHT, arg_name);
    snprintf(lesson->level, NAME_STRING_LENGHT, arg_level);    // level doesn't have lenght specified, and can only assume 3 possible options

    return lesson;

}

void printLesson(Lesson* Lesson){

    if(Lesson == NULL)
        return;

    printCommitment(Lesson->commData);
    printf("\n%s", Lesson->name);
    printf("\n%s\n", Lesson->level);

}

void destroyLesson(Commitment* com){

    Lesson* lesson = (Lesson*) com;

    destroyCommitment(lesson->commData);

    free(lesson);

}