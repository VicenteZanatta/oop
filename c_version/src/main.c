#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../inc/commitment.h"
#include "../inc/file_input_output.h"

#define FILE_NAME "agenda.txt" 


int main(){

    Commitment* com; //pointer for commitment struct used for creating elements for the list
    
    if (readInputFile(FILE_NAME) != 0 )  //functions retunr 0 if exec if sucess
        return 0;               //if return diff than 0 stop program exec to avoid problems
    
    
    /*com = initCommitment();
    registerCommitment(com, 'A', 000001, "20/12/2025", "09:10", 45, 1);
    printCommitment(com);*/

    return 0;
}

