#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "classes/commitment.h"
#include "util/file_input_output.h"
#include "util/linked_list.h"

#define SCHEDULER_INPUT_FILE "agenda.txt" 


int main(){
    
    List* commitmentList = initList();

    
    if (readInputFile(SCHEDULER_INPUT_FILE, commitmentList) != 0 )      //functions retunr 0 if exec if sucess
        return 0;                                                       //if return diff than 0 stop program exec to avoid problems

    printList(commitmentList);   
    
    return 0;
}

