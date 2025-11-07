#ifndef FILTER_HPP
#define FILTER_HPP

#include "util/linked_list.hpp"
#include "util/removed_comm_list.hpp"
#include "classes/ppCommitment.hpp"

class Filter 
{
private:
    bool hasConflict(Commitment* a, Commitment* b);             //used to see if nodes have time conflict and return true if they have
    bool hasTimeConflict(Commitment* a, Commitment* b);         //used to simplifie serach for conflicts, returs true if "b" starts during "a" is ocorring  
    int calculatePriorityScore(Commitment* commitment);         //get and calculate the priorityScore = priority*priorityFactor;
    List::Node* handleConflict(List::Node* currentNode, List::Node* nextNode,
                                RemovedCommitmentList* postponedList,
                                RemovedCommitmentList* canceledList);  //will return node that wasn´t removed and add remove/postponade commitment to respective Removed Commitment List 

public:
    void filterCommitments(List* commitmentList, List* confirmedList, //analize every node with next in a already sorted list
                            RemovedCommitmentList* postponedList,
                            RemovedCommitmentList* canceledList);

};

#endif