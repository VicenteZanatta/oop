#include <iostream>
#include "util/filter.hpp"

void Filter::filterCommitments(CommitmentList* commitmentList, CommitmentList* confirmedList,     
                            CommitmentList* postponedList,
                            CommitmentList* canceledList)
{
    if(commitmentList->isEmpty())
        return;
        commitmentList->clear();
    
    Commitment* curr = commitmentList->get
    
    while (
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

void Filter::handleConflict(Commitment* a, 
                           Commitment* b, 
                           CommitmentList* confirmedList,
                           CommitmentList* postponedList,
                           CommitmentList* canceledList,
                           CommitmentList* commitmentList)
{
    //Commitment* a = commitmentList->getData(current);
    //Commitment* b = commitmentList->getData(next);
    
    Commitment* toRemove = nullptr;
    Commitment* confirmed = nullptr;
    
    if(a->getIsPostponable() && !b->getIsPostponable()) {
        postponedList->addCommitment(a);
        confirmedList->addCommitment(b);
    }
    else if(!a->getIsPostponable() && b->getIsPostponable()) {
        postponedList->addCommitment(b);
        confirmedList->addCommitment(a);
    }
    else if(a->getPriorityScore() == b->getPriorityScore()) {
        if(a->getId() < b->getId()) {
            toRemove = a;
            confirmed = b;
        } else {
            toRemove = b;
            confirmed = a;
        }
    }
    else if(a->getPriorityScore() > b->getPriorityScore()) {
        toRemove = b;
        confirmed = a;
    }
    else {
        toRemove = a;
        confirmed = b;
    }
    
    if(toRemove->getIsPostponable())


}