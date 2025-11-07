#include <iostream>
#include "util/removed_comm_list.hpp"

RemovedCommitmentList::RemovedCommitmentList() : List(), moreImportantCommitment("") {}

void RemovedCommitmentList::addRemovedCommitment(Commitment* commitment, const std::string& importantId) {
    moreImportantCommitment = importantId;
    addNode(commitment);
}

std::string RemovedCommitmentList::getMoreImportantCommitment() const {
    return moreImportantCommitment;
}

void RemovedCommitmentList::setMoreImportantCommitment(const std::string& importantId) {
    moreImportantCommitment = importantId;
}