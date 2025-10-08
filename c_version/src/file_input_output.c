#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGHT 128 

int readInputFile(char* file_name){

    FILE *input_file = fopen(file_name, "r"); // creat pointer for file reading
    char line_buffer[LINE_LENGHT];

    if(input_file == NULL){             //check for opening error
        printf("ERRO AO LER ARQUIVO");
        return 1;                       //return 1 in case of opening error
    }

    while (fgets(line_buffer, sizeof(line_buffer), input_file) != NULL)
    {
        printf("\n");
        while ( line_buffer[0] != '\n')
        {
            printf("%s",line_buffer);
            fgets(line_buffer, sizeof(line_buffer), input_file);
        }  
    }

    fclose(input_file);
    return 0;
}

