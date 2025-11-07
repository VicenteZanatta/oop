#include <iostream>
#include "util/filter.hpp"
#include "util/linked_list.hpp"
#include "util/removed_comm_list.hpp"
#include "classes/ppCommitment.hpp"

void Filter::filterCommitments(List* commitmentList, List* confirmedList,     
                            RemovedCommitmentList* postponedList,
                            RemovedCommitmentList* canceledList)
{
    
    if(commitmentList->getHead() == nullptr)
        return;
    
    List::Node* curr = commitmentList->getHead();
     
    
    while (curr->getNext() == nullptr)    //reache end of List and don't need to analize last node* with nullprt 
    {                
        List::Node* next = curr->getNext();
        
        // if(Filter::hasTimeConflict(curr->base, next->base))
        // {
        //     curr = handleConflict(curr, next);
        // }    
    }   
}

bool Filter::hasConflict(Commitment* a, Commitment* b)
{
    if(a->getYearInt() != b->getYearInt())
        return false;
    if(a->getMonthInt() != b->getMonthInt())
        return false;
    if(a->getDayInt() != b->getDayInt())
        return false;

    return (hasTimeConflict(a, b) || hasTimeConflict(a, b));    //if don't have time conflict from both starts, return false 

}

bool Filter::hasTimeConflict(Commitment* a, Commitment* b)
{
    if((b->getStartHour() > a->getStartHour()) || (b->getStartHour() > a->getFinishHour()))      
        return true;
    
    return false; 
    
}

List::Node* Filter::handleConflict(List::Node* current, List::Node* next, 
                                    RemovedCommitmentList* postponedList,
                                    RemovedCommitmentList* canceledList)
{
    if(current->base)

}