#include "util/removed_comm_list.hpp"

RemovedCommitmentsList::RemovedComm::RemovedComm(Commitment* commitment, const std::string& moreImportantId) 
    : removedCommitment(commitment), moreImportanId(moreImportantId) {}

void RemovedCommitmentsList::RemovedComm::printInfo() const {
    std::cout << "Commitment ID: " << removedCommitment->getId()
              << " | Removed by: " << moreImportanId << std::endl;
}

// Implementação da classe RemovedCommitmentsList
RemovedCommitmentsList::RemovedCommitmentsList() = default;

RemovedCommitmentsList::~RemovedCommitmentsList() = default;

void RemovedCommitmentsList::addRemovedCommitment(Commitment* commitment, const std::string& moreImportantId) {
    RemovedComm* record = new RemovedComm(commitment, moreImportantId);
    removedList.addNode(record);
}

void RemovedCommitmentsList::printRemovedCommitments() const {
    std::cout << "=== REMOVED COMMITMENTS ===" << std::endl;
    
    auto current = removedList.getHead();
    int count = 0;
    while (current) {
        current->data->printInfo();
        current = current->getNext();
        count++;
    }
    std::cout << "Total removed: " << count << std::endl;
    std::cout << "===========================" << std::endl;
}

bool RemovedCommitmentsList::isEmpty() const {
    return removedList.isEmpty();
}

void RemovedCommitmentsList::clear() {
    removedList.clear();
}