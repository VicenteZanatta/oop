#include <iostream>
#include "util/commitment_list.hpp"
#include "util/file_input.hpp"
#include "util/merge_sort_template.hpp"
#include "util/filter.hpp"
#include "util/removed_comm_list.hpp"
#include "util/quick_sort_template.hpp"

#define CONFIRMED_FILE      "relatconfirmados.txt"
#define POSTPONADED_FILE    "relatadiados.txt"
#define CANCELED_FILE       "relatcancelados.txt"
#define ALL_FILE            "relatcompromissos.txt"

int main(int argc, char* argv[]){

    std::string inputFileName = argv[1];

    std::ofstream* confirmedFile = new std::ofstream(CONFIRMED_FILE);
    std::ofstream* postponadedFile = new std::ofstream(POSTPONADED_FILE);
    std::ofstream* canceledFile = new std::ofstream(CANCELED_FILE);
    std::ofstream* allFile = new std::ofstream(ALL_FILE);
    
    CommitmentList* commitmentList = new CommitmentList();
    CommitmentList* confirmedList = new CommitmentList();
    CommitmentList* postponedList = new CommitmentList();
    CommitmentList* canceledList = new CommitmentList();

    if (readInputFile(inputFileName, commitmentList) != 0) {
        std::cout << "Failed to read input file: " << inputFileName << std::endl;
        delete commitmentList;
        delete confirmedList;
        delete postponedList;
        delete canceledList;
        delete confirmedFile;
        delete postponadedFile;
        delete canceledFile;
        delete allFile;
        return 1;
    }

    QuickSortTemplate<CommitmentList, Commitment>::sortByPriority(commitmentList);

    Filter filter;
    filter.filterCommitments(commitmentList, confirmedList, postponedList, canceledList);

    QuickSortTemplate<CommitmentList, Commitment>::sortByDateTime(confirmedList);
    QuickSortTemplate<CommitmentList, Commitment>::sortById(commitmentList);
        
    commitmentList->printListOfAll(allFile);
    confirmedList->printListOfConfirmed(confirmedFile);
    postponedList->printListOfPostponaded(postponadedFile);
    canceledList->printListOfCanceled(canceledFile);

    delete commitmentList;
    delete confirmedList;
    delete postponedList;
    delete canceledList;
    delete confirmedFile;
    delete postponadedFile;
    delete canceledFile;
    delete allFile;    
    
    return 0;
}

void initObjects(){
    
}