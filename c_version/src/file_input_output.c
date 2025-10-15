#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> //nedd to use -lm for compile pow function
#include "../inc/class.h" 
#include "../inc/commitment.h"


#define LINE_LENGHT 128 

void readClassData(char* line_buffer, FILE* file_pointer);
void identifyCommType(char* ID, FILE* file_pointer);
int convertToInt(char* charID);
char* getDate(char* line_buffer);

int readInputFile(char* file_name){

    FILE *input_file = fopen(file_name, "r"); // creat pointer for file reading
    char line_buffer[LINE_LENGHT];

    if(input_file == NULL){             //check for opening error
        printf("ERRO AO LER ARQUIVO");
        return 1;                       //return 1 in case of opening error
    }

    while (fgets(line_buffer, sizeof(line_buffer), input_file) != NULL)
    {
        while ( line_buffer[0] != '\n')
        {
            identifyCommType(line_buffer, input_file); 
        }  
    }

    fclose(input_file);
    return 0;
}

int convertToInt(char* str)             
{
    int result = 0;

    while (*str) {
        if (isdigit((unsigned char)*str))           // check if is digit, in order to add to result
            result = result * 10 + (*str - '0');
        str++;
    }

    return result;
}

void readClassData(char* line_buffer, FILE * file_pointer)
{
    //line_buffer has ID string 

    char IDchar[8];         
    char type;              
    int id = 0;                  
    char date[11];          
    char time[6];           
    int duration = 0;
    char name[51];
    char* level;           
    int priority = 0;

    strlcpy(IDchar, line_buffer, sizeof(IDchar));
    type = IDchar[0];
    id = convertToInt(IDchar);

    fgets(line_buffer, sizeof(line_buffer), file_pointer); 
    strlcpy(date, line_buffer, sizeof(date));               // by usign sizeof(date), string in line_buffer will be truncated, only passing first 10 characters and '\n'
    strlcpy(time, line_buffer+11, sizeof(time));            // time string source starts after date string (11 characters long)

    fgets(line_buffer, sizeof(line_buffer), file_pointer);
    duration = convertToInt(line_buffer);

    fgets(line_buffer, sizeof(line_buffer), file_pointer);
    strlcpy(name, line_buffer, sizeof(name));

    fgets(line_buffer, sizeof(line_buffer), file_pointer);
    strlcpy(level, line_buffer, sizeof(level));

    fgets(line_buffer, sizeof(line_buffer), file_pointer);
    priority = convertToInt(priority);    
    
}

void identifyCommType(char* ID, FILE* file_pointer){

    switch(ID[0]){
        case 'A':
           readClassData(ID, file_pointer);       
            
    }
}




