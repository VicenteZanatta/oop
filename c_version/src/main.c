#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../inc/commitment.h"

#define LINE_LENGHT 128
#define FILE_NAME "agenda.txt" 

int main(){

    Commitment* com; //pointer for commitment struct used for creating elements for the list
    
    if (readFileInput() != 0 )  //functions retunr 0 if exec if sucess
        return 0;               //if return diff than 0 stop program exec to avoid problems
    
    
    /*com = initCommitment();
    registerCommitment(com, 'A', 000001, "20/12/2025", "09:10", 45, 1);
    printCommitment(com);*/

    return 0;
}

int readFileInput(){

    FILE *input_file = fopen(FILE_NAME, "r"); // creat pointer for file reading
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
