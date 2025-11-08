#include <iostream>
#include "util/commitment_list.hpp"
#include "util/file_input.hpp"
#include "util/merge_sort_template.hpp"
#include "util/filter.hpp"
#include "util/removed_comm_list.hpp"

int main(int argc, char* argv[]){

    std::string inputFileName = argv[1];
    
    CommitmentList* commitmentList = new CommitmentList();
    CommitmentList* confirmedList = new CommitmentList();
    RemovedCommitmentsList* postponedList = new RemovedCommitmentsList();
    RemovedCommitmentsList* canceledList = new RemovedCommitmentsList();

    if (readInputFile(inputFileName, commitmentList) != 0) {
        std::cout << "Failed to read input file: " << inputFileName << std::endl;
        delete commitmentList;
        delete confirmedList;
        delete postponedList;
        delete canceledList;
        return 1;
    }

    MergeSortTemplate<CommitmentList>::sortByDateTime(commitmentList);

    Filter filter;
    filter.filterCommitments(commitmentList, confirmedList, postponedList, canceledList);

    MergeSortTemplate<CommitmentList>::sortByDateTime(confirmedList);
    MergeSortTemplate<CommitmentList>::sortById(commitmentList);
    MergeSortTemplate<RemovedCommitmentsList>::sortByPriority(postponedList);
    MergeSortTemplate<RemovedCommitmentsList>::sortByDuration(canceledList);
    
    commitmentList->printCommitmentList("relatorio_completo.txt");
    confirmedList->printConfirmedList("relatorio_confirmados.txt");
    postponedList->printRemovedCommitments("relatorio_adiados.txt");
    canceledList->printRemovedCommitments("relatorio_cancelados.txt");

    delete commitmentList;
    delete confirmedList;
    delete postponedList;
    delete canceledList;
    
    return 0;
}