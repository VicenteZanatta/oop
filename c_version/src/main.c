#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../inc/commitment.h"
#include "../inc/file_input_output.h"

#define SCHEDULER_INPUT_FILE "agenda_teste.txt" 


int main(){
    
    printf("\n A");
    if (readInputFile(SCHEDULER_INPUT_FILE) != 0 )      //functions retunr 0 if exec if sucess
        return 0;                                       //if return diff than 0 stop program exec to avoid problems
    printf("\n b");
    
    
    /*com = initCommitment();
    registerCommitment(com, 'A', 000001, "20/12/2025", "09:10", 45, 1);
    printCommitment(com);*/

    return 0;
}

