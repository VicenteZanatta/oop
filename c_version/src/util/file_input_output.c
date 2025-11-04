#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h> //nedd to use -lm for link pow function
#include <stdbool.h>
#include "../inc/lesson.h" 
#include "../inc/commitment.h"
#include "../inc/linked_list.h"
#include "../inc/orientation.h"
#include "../inc/constants.h"



#define LINE_LENGHT 128

int readInputFile(char* file_name, List* commitmentList);                    // function used to read input File and receive pointer for the Linked List used to manage commitments
Lesson* readLessonData(char* line_buffer, FILE* file_pointer);
void processCommitment(char* ID, FILE* file_pointer, List* commitmentList);  // function used do identify type of commitment, call data reading for different types and add created node to Linked List 
int convertToInt(char* charID);
void lineCleaner(char* line);
Orientation* readOrientation(char* line_buffer, FILE * file_pointer);



int readInputFile(char* file_name, List* commitmentList){

    FILE *input_file = fopen(file_name, "r"); // creat pointer for file reading
    char line_buffer[LINE_LENGHT];

    if(input_file == NULL){             //check for opening error
        printf("ERROR WHILE TRYING TO READ FILE");
        return 1;                       //return 1 in case of opening error
    }

    while (fgets(line_buffer, sizeof(line_buffer), input_file) != NULL)
    {
        if(line_buffer[0] != '\n')
            processCommitment(line_buffer, input_file, commitmentList);
    }

    fclose(input_file);
    return 0;
}

void processCommitment(char* ID, FILE* file_pointer, List* commitmentList){

    switch(ID[0]){
        case 'A':
            Lesson* LessonPointer = readLessonData(ID, file_pointer);
            addNode(LessonPointer, commitmentList);
            break;
        case 'O':
            Orientation* ortPointer = readOrientation(ID, file_pointer);
            addNode(ortPointer, commitmentList);
            break;
        default:
            printf("\nTYPE [%c] NOT IDENTIFIED\n", ID[0]);
            break;            
    }
}

int convertToInt(char* str)             
{
    int result = 0;

    for(size_t i = 0; i < strlen(str); i++){
        if (isdigit((unsigned char)str[i]))           // check if is digit, in order to add to result
            result = result * 10 + (str[i] - '0');
    }
    return result;
}

Lesson* readLessonData(char* line_buffer, FILE * file_pointer)
{
    //line_buffer has ID string 
    
    char idString[ID_STRING_LENGHT] = {0};         
    char type;              
    int id = 0;                  
    char date[DATE_STRING_LENGHT] = {0};          
    char time[TIME_STRING_LENGHT] = {0};             
    int duration = 0;
    char name[NAME_STRING_LENGHT] = {0};
    char level[NAME_STRING_LENGHT] = {0};     //the largest possible option contains 14 letters         
    int priority = 0;

    lineCleaner(line_buffer);
    snprintf(idString, sizeof(idString), "%s", line_buffer);
    type = idString[0];
    id = convertToInt(line_buffer);
    
    fgets(line_buffer, LINE_LENGHT, file_pointer);
    lineCleaner(line_buffer); 
    snprintf(date, sizeof(date), "%.10s", line_buffer );            
    snprintf(time, sizeof(time), "%.5s", line_buffer+11);             

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

    Lesson* LessonPointer = creatLesson(idString, type, id, date, time, duration, priority, name, level);

    return LessonPointer;
 
}

Orientation* readOrientation(char* line_buffer, FILE * file_pointer)
{

    char idString[ID_STRING_LENGHT] = {0};         
    char type;              
    int id = 0;                  
    char date[DATE_STRING_LENGHT] = {0};          
    char time[TIME_STRING_LENGHT] = {0};             
    int duration = 0;
    char studentName[NAME_STRING_LENGHT] = {0};
    char level[NAME_STRING_LENGHT] = {0};     //the largest possible option contains 14 letters         
    int priority = 0;
    bool postponable = false;

    lineCleaner(line_buffer);
    snprintf(idString, sizeof(idString), "%s", line_buffer);
    type = idString[0];
    id = convertToInt(line_buffer);
    
    fgets(line_buffer, LINE_LENGHT, file_pointer);
    lineCleaner(line_buffer); 
    snprintf(date, sizeof(date), "%.10s", line_buffer );            
    snprintf(time, sizeof(time), "%.5s", line_buffer+11);             

    fgets(line_buffer, LINE_LENGHT, file_pointer);
    lineCleaner(line_buffer);
    duration = convertToInt(line_buffer);

    fgets(line_buffer, LINE_LENGHT, file_pointer); //checks if commitment is postponable
    lineCleaner(line_buffer);
    if(!(strcmp(line_buffer, "true"))) // strcmp function return 0 if strings are equals
        postponable = true; 

    fgets(line_buffer, LINE_LENGHT, file_pointer);
    lineCleaner(line_buffer);
    snprintf(studentName, sizeof(studentName), "%s", line_buffer);

    fgets(line_buffer, LINE_LENGHT, file_pointer);
    lineCleaner(line_buffer);
    snprintf(level, sizeof(level), "%s", line_buffer);

    fgets(line_buffer, LINE_LENGHT, file_pointer);
    lineCleaner(line_buffer);
    priority = convertToInt(line_buffer);

    Orientation* ort = creatOrientation(idString, type, id, date, time, duration, 
                                            priority, postponable ,studentName, level);

    return ort;

}

void lineCleaner(char* line){              // removes '\n' from line, avoiding bugs

    int lastCharPosition = 0;
    
    lastCharPosition = strlen(line) - 1;    //fgets will put "\0" after firt "\n", if a line has "/n" it will be 1 charactert before and of string
    
    if(line[lastCharPosition] == '\n')
        line[lastCharPosition] = '\0';   
}







