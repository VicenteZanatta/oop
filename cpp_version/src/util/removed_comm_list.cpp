#include <iostream>
#include "util/removed_comm_list.hpp"

// RemovedComm struct implementation
RemovedCommitmentsList::RemovedComm::RemovedComm(Commitment* commitment, const std::string& removerId)
    : removedCommitment(commitment), moreImportantId(removerId) 
{
}

void RemovedCommitmentsList::RemovedComm::printInfo() const 
{
    std::cout << "Removed Commitment: " << removedCommitment->getId() 
              << " (Removed by: " << moreImportantId << ")" << std::endl;
}

// RemovedCommitmentsList class implementation
RemovedCommitmentsList::RemovedCommitmentsList() 
{
}

RemovedCommitmentsList::~RemovedCommitmentsList() 
{
    // The LinkedListTemplate destructor will automatically clean up all nodes
    // and the RemovedComm objects they contain
}
    
void RemovedCommitmentsList::addRemovedCommitment(Commitment* commitment, const std::string& removerId)
{
    if (!commitment) return;
    
    // Create a new RemovedComm object and add it to the list
    RemovedComm* removedComm = new RemovedComm(commitment, removerId);
    removedList.addNode(removedComm);
}

void RemovedCommitmentsList::printRemovedCommitments() const 
{
    std::cout << "=== REMOVED COMMITMENTS ===" << std::endl;
    
    if (removedList.isEmpty()) {
        std::cout << "No removed commitments." << std::endl;
        return;
    }
    
    // Use the printList method with a lambda function
    removedList.printList([](RemovedComm* removedComm) {
        removedComm->printInfo();
    });
    
    std::cout << "===========================" << std::endl;
}