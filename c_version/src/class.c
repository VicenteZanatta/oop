#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/class.h"
#include "../inc/commitment.h"

#define CLASS_NAME_LENGHT 51 // max lenght 50 + '\0'
#define CLASS_LEVEL_LENGHT 20 

typedef struct class
{
    Commitment* commData;
    char name[CLASS_NAME_LENGHT];
    char level[CLASS_LEVEL_LENGHT];
} Class;


Class* registerClass(char* arg_idString, char arg_type, int arg_id, char* arg_date, char *arg_time, 
                                int arg_duration, int arg_priority, char* arg_name, char* arg_level)
{
    Class* class = malloc(sizeof(Class));

    if(class == NULL){
        printf("ERROR WHILE REGISTERING CLASS [%s]", arg_idString);
        return NULL;
    }
    
    Commitment* comm = registerCommitment(arg_idString, arg_type, arg_id, arg_date, arg_time, arg_duration, arg_priority);
    if(comm == NULL)
        return NULL;

    class->commData = comm;  
    
    snprintf(class->name, CLASS_NAME_LENGHT, arg_name);
    snprintf(class->level, CLASS_LEVEL_LENGHT, arg_level);    // level doesn't have lenght specified, and can only assume 3 possible options

    return class;

}

void printClass(Class* class){

    if(class == NULL)
        return;

    printCommitment(class->commData);
    printf("\n%s", class->name);
    printf("\n%s\n", class->level);

}