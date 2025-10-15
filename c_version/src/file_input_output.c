#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> //nedd to use -lm for compile pow function 

#define LINE_LENGHT 128 

void identifyClass(char* ID, FILE* file_pointer);
int convertToInt(char* charID);

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
            
            regitracomprimisso
            identifyClass(line_buffer, input_file); 
        }  
    }

    fclose(input_file);
    return 0;
}

int convertToInt(char* charID)
{
    int intID = 0;
    int digit = 0; 
    int decimalPlace = 0; 

    for (int i = 1; i <= 6; i++){

        digit = charID[i] - '0';  
        decimalPlace = pow(10, 6 - i);    
        intID += digit * decimalPlace;        
    }

    return intID;
}

void readAulaData(FILE * file_pointer, Aula  * pointer)
{

}

void identifyClass(char* ID, FILE* file_pointer){

    switch(ID[0]){
        case 'A':
           char IDvar = ID[0];
           int converToInt(ID);
           Aula * aula = CreateAula();
           readAulaData(file_pointer, aula);       

            
    }
}



