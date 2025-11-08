#ifndef FILTER_HPP
#define FILTER_HPP

#include "util/commitment_list.hpp"
#include "util/removed_comm_list.hpp"

class Filter 
{
private:
    bool hasConflict(Commitment* a, Commitment* b);
    bool hasTimeConflict(Commitment* a, Commitment* b);
    
    void handleConflict(CommitmentList::Node* currentNode, 
                       CommitmentList::Node* nextNode,
                       CommitmentList* confirmedList,
                       RemovedCommitmentsList* postponedList,
                       RemovedCommitmentsList* canceledList,
                       CommitmentList* commitmentList);

public:
    void filterCommitments(CommitmentList* commitmentList, 
                          CommitmentList* confirmedList,
                          RemovedCommitmentsList* postponedList,
                          RemovedCommitmentsList* canceledList);
};

#endif