#include <iostream>
#include "util/filter.hpp"

void Filter::filterCommitments(CommitmentList* commitmentList, CommitmentList* confirmedList,     
                            RemovedCommitmentsList* postponedList,
                            RemovedCommitmentsList* canceledList)
{
    if(commitmentList->isEmpty())
        return;
    
    confirmedList->clearWithoutData();
    
    CommitmentList::Node* curr = commitmentList->getHead();
    
    while (curr && commitmentList->getNext(curr)) {
        CommitmentList::Node* next = commitmentList->getNext(curr);
        Commitment* currentCommitment = commitmentList->getData(curr);
        Commitment* nextCommitment = commitmentList->getData(next);
        
        if(hasConflict(currentCommitment, nextCommitment)) {
            handleConflict(curr, next, confirmedList, postponedList, canceledList, commitmentList);
            curr = commitmentList->getNext(curr);
        } else {
            confirmedList->addCommitment(currentCommitment);
            curr = next;
        }
    }
    
    if (curr) {
        confirmedList->addCommitment(commitmentList->getData(curr));
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

    return (hasTimeConflict(a, b) || hasTimeConflict(b, a));
}

bool Filter::hasTimeConflict(Commitment* a, Commitment* b)
{
    int aStart = a->getStartHour() * 60 + a->getStartMinute();
    int aEnd = a->getFinishHour() * 60 + a->getFinishMinute();
    int bStart = b->getStartHour() * 60 + b->getStartMinute();
    int bEnd = b->getFinishHour() * 60 + b->getFinishMinute();
    
    return (aStart < bEnd && bStart < aEnd);
}

void Filter::handleConflict(CommitmentList::Node* current, 
                           CommitmentList::Node* next, 
                           CommitmentList* confirmedList,
                           RemovedCommitmentsList* postponedList,
                           RemovedCommitmentsList* canceledList,
                           CommitmentList* commitmentList)
{
    Commitment* currComm = commitmentList->getData(current);
    Commitment* nextComm = commitmentList->getData(next);
    
    Commitment* toRemove = nullptr;
    Commitment* confirmed = nullptr;
    
    if(currComm->getIsPostponable() && !nextComm->getIsPostponable()) {
        toRemove = currComm;
        confirmed = nextComm;
    }
    else if(!currComm->getIsPostponable() && nextComm->getIsPostponable()) {
        toRemove = nextComm;
        confirmed = currComm;
    }
    else if(currComm->getPriorityScore() == nextComm->getPriorityScore()) {
        if(currComm->getId() < nextComm->getId()) {
            toRemove = currComm;
            confirmed = nextComm;
        } else {
            toRemove = nextComm;
            confirmed = currComm;
        }
    }
    else if(currComm->getPriorityScore() > nextComm->getPriorityScore()) {
        toRemove = nextComm;
        confirmed = currComm;
    }
    else {
        toRemove = currComm;
        confirmed = nextComm;
    }
    
    if(toRemove->getIsPostponable())
        postponedList->addRemovedCommitment(toRemove, confirmed->getId());

        
    confirmedList->addCommitment(confirmed);
    canceledList->addRemovedCommitment(toRemove, confirmed->getId());    
    commitmentList->removeCommitment(toRemove);



}