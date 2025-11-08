#include <iostream>
#include "util/removed_comm_list.hpp"

RemovedCommitmentsList::RemovedComm::RemovedComm(Commitment* commitment, const std::string& removerId)
    : removedCommitment(commitment), moreImportantId(removerId) 
{
}

RemovedCommitmentsList::RemovedCommitmentsList() 
{
}

RemovedCommitmentsList::~RemovedCommitmentsList() 
{
}
    
void RemovedCommitmentsList::addRemovedCommitment(Commitment* commitment, const std::string& removerId)
{
    if (!commitment) return;
    
    RemovedComm* removedComm = new RemovedComm(commitment, removerId);
    removedList.addNode(removedComm);
}

void RemovedCommitmentsList::printRemovedCommitments() const 
{
    if (removedList.isEmpty()) {
        return;
    }
    
    LinkedListTemplate<RemovedComm>::Node* current = removedList.getHead();
    while (current) {
        Commitment* commitment = current->data->removedCommitment;
        std::string removerId = current->data->moreImportantId;
        
        std::cout << commitment->getId() << std::endl;
        std::cout << commitment->getDescription() << std::endl;
        std::cout << commitment->getPriority() << std::endl;
        std::cout << removerId << std::endl;
        
        current = current->getNext();
    }
}