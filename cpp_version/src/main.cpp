#include <iostream>
#include "util/linked_list.hpp"
#include "util/file_input_output.hpp"

std::string const INPUT_FILE_NAME = "agenda.txt";

int main(){

    List* commitmentList = new List();

    readInputFile(INPUT_FILE_NAME, commitmentList);

    delete commitmentList;
    
    return 0;
}