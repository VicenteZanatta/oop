#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h> //nedd to use -lm for link pow function
#include "../inc/class.h" 
#include "../inc/commitment.h"


#define LINE_LENGHT 128
/*#define ID_STRING_LENGTH 7
#define DATE_STRING_LENGTH 11
#define TIME_STRING_LENGTH 6
#define STUDENT_NAME_STRING_LENGTH 50
#define EVENT_NAME_STRING_LENGTH 50
#define PLACE_STRING_LENGTH 50
#define MOTIVE_STRING_LENGTH 50 */ 


void readClassData(char* line_buffer, FILE* file_pointer);
void identifyCommType(char* ID, FILE* file_pointer);
int convertToInt(char* charID);
void lineCleaner(char* line);

int readInputFile(char* file_name){

    int i = 0;
    int j = 0;
    
    FILE *input_file = fopen(file_name, "r"); // creat pointer for file reading
    char line_buffer[LINE_LENGHT];

    if(input_file == NULL){             //check for opening error
        printf("ERROR WHILE TRYING TO READ FILE");
        return 1;                       //return 1 in case of opening error
    }

    while (fgets(line_buffer, sizeof(line_buffer), input_file) != NULL)
    {
        if(line_buffer[0] != '\n'){
            identifyCommType(line_buffer, input_file);
            j++;
            }
        i++;
    }

    fclose(input_file);
    return 0;
}

int convertToInt(char* str)             
{
    int result = 0;
    int i = 0;

    for(int i = 0; i < strlen(str); i++){
        if (isdigit((unsigned char)str[i]))           // check if is digit, in order to add to result
            result = result * 10 + (str[i] - '0');
    }
    return result;
}

Class* readClassData(char* line_buffer, FILE * file_pointer)
{
    //line_buffer has ID string 
    
    char IDchar[8] = {0};         
    char type;              
    int id = 0;                  
    char date[11] = {0};          
    char time[6] = {0};             
    int duration = 0;
    char name[51] = {0};
    char level[15] = {0};     //the largest possible option contains 14 letters         
    int priority = 0;

    lineCleaner(line_buffer);
    snprintf(IDchar, sizeof(IDchar), "%s", line_buffer);
    type = IDchar[0];
    id = convertToInt(line_buffer);
    
    fgets(line_buffer, LINE_LENGHT, file_pointer);
    lineCleaner(line_buffer); 
    snprintf(date, sizeof(date), "%.10s", line_buffer );               
    snprintf(time, sizeof(time), "%.5s", line_buffer+11);             
    //printf("\n%s", date);
    //printf("\n%s", time);

    fgets(line_buffer, LINE_LENGHT, file_pointer);
    lineCleaner(line_buffer);
    duration = convertToInt(line_buffer);

    fgets(line_buffer, LINE_LENGHT, file_pointer);
    lineCleaner(line_buffer);
    snprintf(name, sizeof(name), "%s", line_buffer);

    fgets(line_buffer, LINE_LENGHT, file_pointer);
    lineCleaner(line_buffer);
    snprintf(level, sizeof(level), "%s", line_buffer);

    fgets(line_buffer, LINE_LENGHT, file_pointer);
    lineCleaner(line_buffer);
    priority = convertToInt(line_buffer);
 
}

void lineCleaner( char* line){              // removes '\n' from line, avoiding bugs

    int lastCharPosition = 0;
    
    lastCharPosition = strlen(line) - 1;    //fgets will put "\0" after firt "\n", if a line has "/n" it will be 1 charactert before and of string
    
    if(line[lastCharPosition] == '\n')
        line[lastCharPosition] = '\0';   
}


void identifyCommType(char* ID, FILE* file_pointer){


    switch(ID[0]){
        case 'A':
            Class* classPointer = readClassData(ID, file_pointer);
            break;
        default:
            printf("\nTYPE [%c] NOT IDENTIFIED\n", ID[0]);
            break;            
    }
}




