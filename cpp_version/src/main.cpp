#include <iostream>
#include "util/commitment_list.hpp"
#include "util/file_input.hpp"
#include "util/merge_sort_template.hpp"

std::string const INPUT_FILE_NAME = "exemplo01/agenda.txt";

int main(){
    CommitmentList* commitmentList = new CommitmentList();

    if (readInputFile(INPUT_FILE_NAME, commitmentList) != 0) {
        std::cout << "Failed to read input file!" << std::endl;
        delete commitmentList;
        return 1;
    }

    // Sort by date/time
    MergeSortTemplate<CommitmentList, Commitment>::sortByDateTime(commitmentList);
    std::cout << "=== SORTED BY DATE/TIME ===" << std::endl;
    commitmentList->printList();
    std::cout << "============================" << std::endl;
    
    // Sort by duration ascending
    MergeSortTemplate<CommitmentList, Commitment>::sortByDuration(commitmentList);
    std::cout << "=== SORTED BY DURATION (ASC) ===" << std::endl;
    commitmentList->printList();
    std::cout << "============================" << std::endl;
    
    // Sort by ID ascending
    MergeSortTemplate<CommitmentList, Commitment>::sortById(commitmentList);
    std::cout << "=== SORTED BY ID (ASC) ===" << std::endl;
    commitmentList->printList();
    std::cout << "============================" << std::endl;
    
    // Sort by priority descending
    MergeSortTemplate<CommitmentList, Commitment>::sortByPriority(commitmentList);
    std::cout << "=== SORTED BY PRIORITY (DESC) ===" << std::endl;
    commitmentList->printList();
    std::cout << "============================" << std::endl;

    delete commitmentList;
    return 0;
}