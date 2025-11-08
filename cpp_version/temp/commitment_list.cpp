#include <iostream>
#include "util/commitment_list.hpp"

CommitmentList::CommitmentList() = default;

CommitmentList::~CommitmentList() = default;

void CommitmentList::addCommitment(Commitment* commitment) {
    commitmentList.addNode(commitment);
}

void CommitmentList::removeCommitment(Commitment* commitment) {
    auto current = commitmentList.getHead();
    while (current) {
        if (current->data == commitment) {
            commitmentList.removeNode(current);
            return;
        }
        current = current->getNext();
    }
}

void CommitmentList::printCommitmentList() const {
    if (commitmentList.isEmpty()) {
        return;
    }
    
    LinkedListTemplate<Commitment>::Node* current = commitmentList.getHead();
    while (current) {
        Commitment* commitment = current->data;
        
        std::cout << commitment->getDayInt() << "/" << commitment->getMonthInt() << "/" << commitment->getYearInt();
        std::cout << " " << commitment->getStartHour() << ":" << commitment->getStartMinute() << std::endl;
        std::cout << commitment->getId() << std::endl;
        std::cout << commitment->getDescription() << std::endl;
        
        current = current->getNext();
    }
}

void CommitmentList::printConfirmedList() const {
    if (commitmentList.isEmpty()) {
        return;
    }
    
    LinkedListTemplate<Commitment>::Node* current = commitmentList.getHead();
    while (current) {
        Commitment* commitment = current->data;
        
        std::cout << commitment->getId() << ": " << commitment->getDescription() << std::endl;
        std::cout << "Início: " << commitment->getDayInt() << "/" << commitment->getMonthInt() << "/" << commitment->getYearInt();
        std::cout << " " << commitment->getStartHour() << ":" << commitment->getStartMinute() << std::endl;
        std::cout << "Fim: " << commitment->getDayInt() << "/" << commitment->getMonthInt() << "/" << commitment->getYearInt();
        std::cout << " " << commitment->getFinishHour() << ":" << commitment->getFinishMinute() << std::endl;
        std::cout << "Prioridade: " << commitment->getPriority() << std::endl;
        
        current = current->getNext();
    }
}

void CommitmentList::clear() {
    commitmentList.clearWithData();
}

void CommitmentList::clearWithoutData() {
    commitmentList.clear();
}