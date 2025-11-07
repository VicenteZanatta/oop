#include <iostream>
#include "util/linked_list.hpp"
#include "util/file_input.hpp"

std::string const INPUT_FILE_NAME = "exemplo01/agenda.txt";

int main(){
    List* commitmentList = new List();

    if (readInputFile(INPUT_FILE_NAME, commitmentList) != 0) {
        std::cout << "Failed to read input file!" << std::endl;
        delete commitmentList;
        return 1;
    }

    std::cout << "Elementos antes da ordenação: " << commitmentList->getCount() << std::endl;

    commitmentList->sortByDateTime();

    std::cout << "Elementos após a ordenação: " << commitmentList->getCount() << std::endl;

    std::cout << "Compromissos ordenados por data e hora:" << std::endl;
    commitmentList->printList();

    delete commitmentList;
    return 0;
}